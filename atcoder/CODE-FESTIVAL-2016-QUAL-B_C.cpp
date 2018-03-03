#include <bits/stdc++.h>
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

/* -----  2018/03/03  Problem: code-festival-2016-qual-b_c / Link: https://code-festival-2016-qualb.contest.atcoder.jp/tasks/codefestival_2016_qualB_c?lang=en  ----- */
/* ------問題------

xy平面上の0≦x≦W,0≦y≦Hをみたす領域にあるx,yともに整数である点すべてに、ひとつずつ家があります。
x座標が等しくy座標の差が1であるか、y座標が等しくx座標の差が1であるような2点の組のうち、両方の点に家が存在するような全てのものに対し、その2点の間には舗装されていない道路があります。
座標(i,j)と(i+1,j)にある家の間の道路を舗装するのにはjの値にかかわらずコストがpi、 座標(i,j)と(i,j+1)にある家の間の道路を舗装するのにはiの値にかかわらずコストがqjかかります。
高橋君は、このうちいくつかの道路を舗装し、舗装された道路のみを通って任意の2つの家の間を行き来できるようにしたいです。 かかるコストの総和の最小値を求めてください。

-----問題ここまで----- */
/* -----解説等-----

辺の値はsortしても問題ない。
小さいものをたくさん使ってみても問題は無いので貪欲でやる。
縦に辺を置くときは置いた後に横の辺は一つだけ使わなくてもよい、
横に辺を置くときは置いた後にたっての辺は一つだけ使わなくても良い
ことがわかるのでこれをかく

----解説ここまで---- */

LL W, H;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> W >> H;
	vector<PLL> a;
	FOR(i, 0, W) {
		int v; cin >> v;
		a.push_back(PLL(v, 0));
	}
	FOR(i, 0, H) {
		int v; cin >> v;
		a.push_back(PLL(v, 1));
	}

	SORT(a);
	H++, W++;

	FOR(i, 0, SZ(a)) {
		if (a[i].second == 0) {
			ans += H*a[i].first;
			W--;
		}
		else {
			ans += W*a[i].first;
			H--;
		}
	}

	cout << ans << "\n";

	return 0;
}
