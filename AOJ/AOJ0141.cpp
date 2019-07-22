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

/* -----  2019/07/21  Problem: AOJ 0141 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0141  ----- */


int main() {
	int T; cin >> T;
	FOR(_, 0, T) {
		if (_)cout << endl;
		int N; cin >> N;
		int H = N + 4, W = N + 4;
		VS masu(H, string(W, ' ')); {
			FOR(i, 0, H) {
				masu[i].front() = masu[i].back() = '#';
			}
			FOR(i, 0, W) {
				masu.front()[i] = masu.back()[i] = '#';
			}
		}
		const int DY[] = { -1,0,1,0 };
		const int DX[] = { 0,1,0,-1 };
		auto go = [&](int y, int x) {
			if (masu[y][x] == '#')return false;
			else return true;
		};
		int Y = N + 1, X = 2;
		int dir = 0;
		masu[Y][X] = '#';
		map<PII, int>m;
		for (;;) {
			m[PII(Y, X)]++;
			if (m[PII(Y, X)] == 3)break;
			{
				int ny = Y + DY[dir], nx = X + DX[dir];
				FOR(k, 3, 6) {
					int nd = (dir + k) % 4;
					int nny = ny + DY[nd];
					int nnx = nx + DX[nd];
					if (masu[nny][nnx] == '#') {
						dir++, dir %= 4;
						goto NX;
					}
				}
			}
			{
				Y += DY[dir]; X += DX[dir];
				masu[Y][X] = '#';
			}
		NX:;
		}
		FOR(i, 2, N + 2) {
			FOR(j, 2, N + 2) {
				cout << masu[i][j];
			}cout << endl;
		}
	}

}