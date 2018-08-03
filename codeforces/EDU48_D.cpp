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
#define debug(x) cerr << #x << ": " << x << endl
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/08/03  Problem: edu48 D / Link: http://codeforces.com/contest/1016/problem/D  ----- */
/* ------問題------

xor を行、列で計算したときの結果がH+W個与えられる。
これをなんでもいいので復元可能か判定し、復元可能ならその結果を記せ。

-----問題ここまで----- */
/* -----解説等-----

2進数でみたとき、独立しているので行列式をたてて、xorgaussを実装してこれを投げる。

----解説ここまで---- */



int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int H, W; cin >> H >> W;
	VI a(H), b(W);
	FOR(i, 0, H) {
		cin >> a[i];
	}
	FOR(i, 0, W) {
		cin >> b[i];
	}

	VVI matrix(H, VI(W, 0));
	int flag = 1;
	mytype x;
	for (LL m = 1; m <= (1LL << 30); m <<= 1) {
		vector<mytype> mat(MAX_N * 2);

		FOR(i, 0, H) {
			if (a[i] & (m))
				mat[i][H*W] = 1;
		}
		FOR(j, 0, W) {
			if (b[j] & m) {
				mat[H + j][H*W] = 1;
			}
		}
		FOR(i, 0, H) {//a[i]について
			FOR(j, 0, W) {
				mat[i][W*i + j] = 1;
			}
		}
		FOR(j, 0, W) { //b[j]について
			FOR(i, 0, H) {
				mat[H + j][W*i + j] = 1;
			}
		}
		// ここsolver
		flag &= !!xorgauss(H + W, H*W, x, mat);
		FOR(i, 0, H) {
			FOR(j, 0, W) {
				if (x[W*i + j])
					matrix[i][j] |= m;
			}
		}

	}
	if (flag) {
		cout << "YES" << endl;
		FOR(i, 0, H) {
			FOR(j, 0, W) {
				cout << matrix[i][j] << " \n"[j == W - 1];
			}
		}
	}
	else {
		cout << "NO" << endl;
	}


	return 0;
}



