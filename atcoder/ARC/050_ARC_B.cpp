#include<iostream>
using namespace std;

typedef long long ll;


/* -----  2017/03/15  Problem: ARC050 / Link: http://arc050.contest.atcoder.jp/tasks/arc050_b ----- */
/* ------問題------

高橋君は赤い花を R 本、青い花を B 本持っています。高橋君は次の 2 種類の花束を作ることができます。
x 本の赤い花と 1 本の青い花からなる花束
1 本の赤い花と y 本の青い花からなる花束
高橋君が作ることのできる花束の個数の最大値を求めてください。すべての花を使い切る必要はありません。

-----問題ここまで----- */
/* -----解説等-----

合計でZ=P+Q個欲しいとする。制約から、
x*P + 1*Q ≦ R
1*P + y*Q ≦ B

ここで
Z = P + Q であったから、

Z + (x-1)*P ≦ R
Z + (y-1)*Q ≦ B

となりZのみに依存した式がP,Qへの式となって現わすことができる。
あとはこれを二分探索してやればよい。

三分探索もできるが安全ではなく、ある程度解の存在しうる区間を特定したらその付近を全探索した方がいいみたい。

----解説ここまで---- */

ll N;
ll R, B, x, y;
ll ans = 0LL;

bool f(ll Z) {
	if (Z > R) return false;
	if (Z > B) return false;
	ll a = (R - Z) / (x - 1), b = (B - Z) / (y - 1);
	return a + b >= Z;
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> R >> B >> x >> y;
	ll l = 0, r = 1e18;
	while (r - l > 1) {
		ll mid = (l + r) / 2;
		if (f(mid))l = mid;
		else r = mid;
	}
	ans = l;
	cout << ans << endl;

	return 0;
}