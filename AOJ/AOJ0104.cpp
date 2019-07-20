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

/* -----  2019/07/20  Problem: AOJ 0104 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0104  ----- */

const int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };
const int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };
const string dir = "v^><";
int main() {
	int H, W;
	while (cin >> H >> W, H) {
		vector<string> s(H);
		for (int i = 0; i < H; ++i) {
			cin >> s[i];
		}
		VVI checked(H, VI(W, 0));

		int Y = 0, X = 0;
		checked[Y][X] = 1;
		string ans = "";
		while (1) {
			int dc = dir.find(s[Y][X]);
			if (dc == string::npos) {
				ans = to_string(X) + " " + to_string(Y);
				break;
			}
			int ny = Y + DY[dc], nx = X + DX[dc];
			if (checked[ny][nx]) {
				ans = "LOOP";
				break;
			}
			checked[ny][nx] = 1;
			Y = ny, X = nx;
		}

		cout << (ans) << "\n";
	}


	return 0;
}
