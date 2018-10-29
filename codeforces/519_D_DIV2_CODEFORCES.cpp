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
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/10/29  Problem: CodeForces519 D div2 / Link: http://codeforces.com/contest/1043/problem/D  ----- */
/* ------問題------

数列の連続一致数

-----問題ここまで----- */
/* -----解説等-----

10個みながらしゃくとりをする　おわり
ロリハキラーがなくてよかった。

----解説ここまで---- */

int a[10][100005];
int pos[10][100005];
int N, M;
using uLL = unsigned long long;
const uLL _base = 1e9 + 7;
uLL hashed[10][100010];
uLL power[100010];
struct RollingHash {
	vector<uLL> hashed, power;
	uLL get(int l, int r) { // [l, r)
		return((hashed[r] - hashed[l] * power[r - l]));
	}
	uLL connect(int h1, int h2, int h2len) {
		return(h1 * power[h2len] + h2);
	}
};
bool ok(int num,int sz) {//num からsz個連続か?
	sz++;
	if (sz == 1)return true;
	int L = pos[0][num];
	int R = pos[0][num] + sz;
// RがNいじょうならだめ
	if (R > N)return false;
	uLL Hash = ((hashed[0][R] - hashed[0][L] * power[R - L]));
	DD(de(num, sz, L, R));
	FOR(i, 1, M) {
		int LL = pos[i][num];
		int RR = pos[i][num]+sz;
		DD(de(LL, RR));
		if (RR > N)return false;
		uLL Hash2 = ((hashed[i][RR] - hashed[i][LL] * power[RR - LL]));
		if (Hash != Hash2)return false;
	}
	return true;
}

int main() {
	power[0] = 1;
	for (int i = 0; i < 100005; i++) {
		power[i + 1] = power[i] * _base;
	}



	scanf("%d%d", &N, &M);
	FOR(i, 0, M) {
		FOR(j, 0, N) {
			scanf("%d", &a[i][j]);
			a[i][j]--;
			pos[i][a[i][j]] = j;
		}
		FOR(j, 0, N) {
			hashed[i][j+1] = (hashed[i][j] + a[i][j]) * _base;
		}
	}


	LL ans = 0;
	// 同時にしゃくとりをする
	for (int l = 0, r = 0; l < N; l++) {
		while (r<N&&ok(a[0][l],r-l)){
			r++;
		}
		// [l,r)
		DD(de(l, r));
		ans +=r-l;
	}

	cout << ans << "\n";

	return 0;
}
