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

/* -----  2019/02/24  Problem: ABC 119 B / Link: http://abc119.contest.atcoder.jp/tasks/abc119_b  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

変換できますか？という問題．
あとから型を変えてあげれば良い．

----解説ここまで---- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N; cin >> N;
	double ans = 0;
	FOR(i, 0, N) {
		string a, b;
		cin >> a >> b;
		if (b == "JPY") {
			ans += stoll(a);
		}
		else {
			ans += 380000.0*stod(a);
		}
	}


	cout << fixed << setprecision(10) << ans << "\n";

	return 0;
}
