#include <bits/stdc++.h>
using namespace std;

using VS = vector<string>;    using LL = long long;
using VI = vector<int>;       using VVI = vector<VI>;
using PII = pair<int, int>;   using PLL = pair<LL, LL>;
using VL = vector<LL>;        using VVL = vector<VL>;

#define ALL(a)  begin((a)),end((a))
#define RALL(a) (a).rbegin(), (a).rend()
#define SZ(a) int((a).size())
#define SORT(c) sort(ALL((c)))
#define RSORT(c) sort(RALL((c)))
#define UNIQ(c) (c).erase(unique(ALL((c))), end((c)))
#define FOR(i, s, e) for (int(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (int(i) = (s); (i) > (e); (i)--)
//#pragma GCC optimize ("-O3") 
#ifdef YANG33
#include "mydebug.hpp"
#else
#define DD(x) 
#endif
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);

/* -----  2019/07/21  Problem: AOJ 0131 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0131  ----- */

const int MAX_N = 105;
typedef bitset<MAX_N> mytype;
// O(HW) 0/1のmatrix : Ax=bのうち、|A|b|をわたす。n,mは|A|についての情報。
// |A|はxを使うか使わないかの0/1の係数と思えば良い。
// 答えを取り出す用のansを渡すこと (x=ansであるため)
bool xorgauss(int n, int m, mytype &ans, vector<mytype>& mat) {
	vector<int> where(m, -1);
	for (int col = 0, row = 0; col < m && row < n; col++) {
		for (int i = row; i < n; i++) {
			if (mat[i][col]) {
				swap(mat[i], mat[row]);
				break;
			}
		}
		if (!mat[row][col])
			continue;
		where[col] = row;
		for (int i = 0; i < n; i++)
			if (i != row && mat[i][col])
				mat[i] ^= mat[row];
		row++;
	}
	ans.reset();
	for (int i = 0; i < m; i++)
		if (where[i] != -1)
			ans[i] = mat[where[i]][m];
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = 0; j < m; j++)
			if (ans[j]) cnt ^= (int)mat[i][j];
		if (cnt != (int)mat[i][m])
			return false;
	}
	return true;
}

int main() {
	LL T; cin >> T;
	FOR(_, 0, T) {
		int N = 10;
		const int dy[4] = { 0, 1, 0, -1 };
		const int dx[4] = { 1, 0, -1, 0 };

		vector<mytype>mat(100); FOR(i, 0, 100)mat[i].reset();
		FOR(i, 0, N) {
			FOR(j, 0, N) {
				mat[i * N + j][i * N + j] = 1;
				FOR(k, 0, 4) {
					int ni = i + dx[k], nj = j + dy[k];
					if (ni < 0 || ni >= N || nj < 0 || nj >= N) continue;
					mat[i * N + j][ni * N + nj] = 1;
				}
				int state; cin >> state;
				mat[i*N + j][N*N] = state;
			}
		}

		mytype ans;
		bool res = xorgauss(N*N, N*N, ans, mat);
		assert(res);
		FOR(i, 0, N) {
			FOR(j, 0, N) {
				cout << ans[i*N + j] << " \n"[j + 1 == N];
			}
		}

	}

	return 0;
}
