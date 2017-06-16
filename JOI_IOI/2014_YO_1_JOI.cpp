#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
const int INF = 1e9;

/* -----  2017/04/24  Problem: JOI予選 2014 1  / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0608  ----- */
/* ------問題------

みて

-----問題ここまで----- */
/* -----解説等-----

追加料金がない場合だけ条件分岐をさせて、二社の最小値をとればよい。

----解説ここまで---- */



int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	ll N;

	ll ans = INF;
	ll a, b, c, d, e;
	cin >> a >> b >> c >> d >> e;
	
	ll x;
	if (e <= c)x = b;
	else x = b + d*(e - c);
	ans = min(a*e, x);
	cout << ans << endl;

	return 0;
}
