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

/* -----  2018/07/07  Problem: AOJ 2881 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/2881  ----- */
/* ------問題------

平成31年4月30日をもって現行の元号である平成が終了し，その翌日より新しい元号が始まることになった．平成最後の日の翌日は新元号元年5月1日になる．
ACM-ICPC OB/OGの会 (Japanese Alumni Group; JAG) が開発するシステムでは，日付が和暦（元号とそれに続く年数によって年を表現する日本の暦）を用いて "平成 y 年 m 月 d 日" という形式でデータベースに保存されている．この保存形式は変更することができないため，JAGは元号が変更されないと仮定して和暦で表した日付をデータベースに保存し，出力の際に日付を正しい元号を用いた形式に変換することにした．
あなたの仕事はJAGのデータベースに保存されている日付を，平成または新元号を用いた日付に変換するプログラムを書くことである．新元号はまだ発表されていないため，"?" を用いて表すことにする．

-----問題ここまで----- */
/* -----解説等-----

問題を読む

----解説ここまで---- */

void solve() {
	string s; int Y, M, D;
	while (cin >> s >> Y >> M >> D, s != "#") {
		if (Y > 31) {
			cout << "? " << Y - 30 << " " << M << " " << D << endl;
		}
		else if (Y == 31 && M > 4) {
			cout << "? " << Y - 30 << " " << M << " " << D << endl;
		}
		else {
			cout << "HEISEI " << Y << " " << M << " " << D << endl;
		}
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	solve();

	return 0;
}