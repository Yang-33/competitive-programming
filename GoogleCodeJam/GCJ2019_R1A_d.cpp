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

/* -----  2019/04/13  Problem: GCJ2019_R1A D / Link: __CONTEST_URL__  ----- */

// 生成する方
int H, W;
bool f(int h, int w, VVI& a, vector<PII>& keiro) {
	{
		int sum = 0;
		FOR(i, 0, H) {
			FOR(j, 0, W) {
				sum += a[i][j];
			}
		}
		if (sum == H * W) {
			return 1;
		}
	}
	FOR(i, 0, H) {
		FOR(j, 0, W) {
			if (i == h)continue;
			if (j == w)continue;
			if (h - w == i - j)continue;
			if (h + w == i + j)continue;
			if (a[i][j])continue;
			keiro.push_back(PII(i, j));
			a[i][j] = 1;
			bool res = f(i, j, a, keiro);
			if (res)return res;
			a[i][j] = 0;
			keiro.pop_back();

		}
	}
	return 0;
}
void test() {
	FOR(i, 0, H) {
		FOR(j, 0, W) {
			VVI a(H, VI(W, 0));
			if (i + j == 0)continue;
			vector<PII>keiro;
			keiro.push_back(PII(i, j));
			a[i][j] = 1;
			bool res = f(i, j, a, keiro);
			if (res) {
				cout << "POSSIBLE" << endl;
				for (auto it : keiro) {
					cout << it.first + 1 << " " << it.second + 1 << endl;
				}
				return;
			}
		}
	}
	cout << "IMPOSSIBLE" << endl;
}
void solve(int testcasenum) {
	cin >> H >> W;



	cout << "Case #" << testcasenum << ": ";
	test();
}

int main() {

	int T; cin >> T;
	FOR(i, 0, T) {
		solve(i + 1);
	}

	return 0;
}
