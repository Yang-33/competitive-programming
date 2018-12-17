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

/* -----  2018/12/15  Problem: ARC 003 A / Link: http://arc003.contest.atcoder.jp/tasks/arc003_a  ----- */
/* ------問題------

高橋君はアメリカに留学しようと考えており、成績表を提出することになりました。
アメリカ留学の成績表には、学力を測る指標であるGPAを表記する必要があります。
GPAとは各単位に対する評価(A,B,C,D,F)を点数に換算して平均した値で、点数への換算は以下のようになります。
A評価 → 4 点
B評価 → 3 点
C評価 → 2 点
D評価 → 1 点
F評価 → 0 点
全てF評価だった場合は、GPAは 0 になります。
高橋君の各単位に対する評価をもとにGPAを求めなさい。

-----問題ここまで----- */
/* -----解説等-----

これぐらい簡単にGPAが求められるシステムをくれ

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N; cin >> N;
	string s; cin >> s;
	map<char, int>M;
	M['A'] = 4;
	M['B'] = 3;
	M['C'] = 2;
	M['D'] = 1;
	M['F'] = 0;
	double ans = 0;
	for (auto c : s) {
		ans += M[c];
	}
	ans /= N;
	cout <<fixed<<setprecision(10)<< ans << "\n";

	return 0;
}
