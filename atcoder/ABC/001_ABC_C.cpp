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

/* -----  2019/04/22  Problem: ABC 001 C / Link: http://abc001.contest.atcoder.jp/tasks/abc001_c  ----- */


int main() {

	string str;
	double deg, dis, power;
	int ans;

	cin >> deg >> dis;

	power = (dis / 60);

	if (power < 0.25)
		ans = 0;
	else if (power < 1.55)
		ans = 1;
	else if (power < 3.35)
		ans = 2;
	else if (power < 5.45)
		ans = 3;
	else if (power < 7.95)
		ans = 4;
	else if (power < 10.75)
		ans = 5;
	else if (power < 13.85)
		ans = 6;
	else if (power < 17.15)
		ans = 7;
	else if (power < 20.75)
		ans = 8;
	else if (power < 24.45)
		ans = 9;
	else if (power < 28.45)
		ans = 10;
	else if (power < 32.65)
		ans = 11;
	else
		ans = 12;

	if (ans == 0)
		str = "C";
	else if (deg <= 112 || deg > 3487)
		str = "N";
	else if (deg < 338)
		str = "NNE";
	else if (deg < 563)
		str = "NE";
	else if (deg < 788)
		str = "ENE";
	else if (deg < 1013)
		str = "E";
	else if (deg < 1238)
		str = "ESE";
	else if (deg < 1463)
		str = "SE";
	else if (deg < 1688)
		str = "SSE";
	else if (deg < 1913)
		str = "S";
	else if (deg < 2138)
		str = "SSW";
	else if (deg < 2363)
		str = "SW";
	else if (deg < 2588)
		str = "WSW";
	else if (deg < 2813)
		str = "W";
	else if (deg < 3038)
		str = "WNW";
	else if (deg < 3263)
		str = "NW";
	else if (deg < 3488)
		str = "NNW";

	cout << str << " " << ans << endl;


	return 0;
}

