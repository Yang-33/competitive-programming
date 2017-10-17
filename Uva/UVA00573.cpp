#include "bits/stdc++.h"
using namespace std;

using VS = vector<string>;    using LL = long long;
using VI = vector<int>;       using VVI = vector<VI>;
using PII = pair<int, int>;   using PLL = pair<LL, LL>;
using VL = vector<LL>;        using VVL = vector<VL>;

#define ALL(a)  begin((a)),end((a))
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define EB emplace_back
#define MP make_pair
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

/* -----  2017/10/17  Problem: Uva 00573  / Link: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=7&page=show_problem&problem=514  ----- */
/* ------問題------

H,U,D,Fが与えられる。
Hに到達したい。一日にUだけあがるが、毎日F%ずつ減少していく。
夜にDだけ下がる。
over H,　あるいはless than 0 のときに結果を出力せよ。

-----問題ここまで----- */
/* -----解説等-----

やる。
なんかこれ出したときに
UVa壊れた…；；

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	
	double h, u, d, f;
	string s[2] = { "success","failure" };
	while (cin >> h >> u >> d >> f, h) {
		f /= 100;
		// 高さ　一日に上る　おちる　つかれ
		int i = 1, day = 1;
		double now;
		double U = u;
		now = 0;
		while (1) {
			now += U;
			if (now > h) { i = 0; break; };
			now -= d;
			if (now < 0)break;
			U -= f*u;
			if (U < 0)U = 0;
			day++;
		}

		cout << s[i] << " on day " << day << endl;
	}


	return 0;
}