#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define FOR(i, s, e) for (ll(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (ll(i) = (s); (i) > (e); (i)--)
#define debug(x) cout << #x << ": " << x << endl
#define mp make_pair
#define pb push_back
const ll MOD = 1000000007;
const int INF = 1e9;
const ll LINF = 1e16;
const double PI = acos(-1.0);
int dx[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2017/10/28  Problem: ICPC2012国内予選A / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1179&lang=jp  ----- */
/* ------問題------

ミレニアム
賢王が新しい暦を定めた．「明日を1年1月1日と定める．1年には1月から10月までの10ヶ月があり，大の月から始まる．
ふつうの年は，1月が大の月，2月は小の月，3月は大の月，そして最後の10月は小の月というように，大の月と小の月が交互に訪れる．
大の月の日数は20日，小の月の日数は19日である．しかし，3年，6年，9年，…のように，3で割り切れる年には，小の月は訪れず，10すべての月を大の月とする．」

幾年月が流れた．やがて1000年1月1日のミレニアム記念日の祝賀式において，誕生してからの日数が王立のくじ引きで選ばれた数と一致する国民に景品を与えることになった．
国民らを手助けして，生まれた日からミレニアム記念日までの日数を計算するプログラムを奉ぜよ．

-----問題ここまで----- */
/* -----解説等-----

気合で計算する。
O(MDY)=10^7程度なので、むりくり計算していても多分間にあう。

----解説ここまで---- */

ll N;

ll ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);


	cin >> N;
	FOR(i, 0, N) {
		ans = 0;
		int y, m, d; cin >> y >> m >> d;
		ans += d;
		ans += (m - 1) * 20;
		if (y % 3)ans -= ((m-1) / 2);
		ans += (y-1 ) * 195;
		ans += ((y-1) / 3) * 5;
		cout << 196471 - ans << endl;
	}

	return 0;
}
