#include<iostream>
#include<algorithm>
using namespace std;

typedef long long ll;
#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
const ll LINF = 1e17;

/* -----  2017/03/15  Problem: ARC047 B / Link: http://arc047.contest.atcoder.jp/tasks/arc047_b ----- */
/* ------問題------

座標平面上に N 個の点があります。
これらの点は全て、x 座標 と y 座標の値が共に整数です。つまり格子点上にあります。
そのうえ、これらの点は全て、ある点 P とのマンハッタン距離が同じであることがわかっています。
ここで、マンハッタン距離とは、 2 つの点の座標がそれぞれ (a,b),(c,d) であるとき、 |a−c|+|b−d| で計算される距離のことです。
そして、点 P も格子点上にあります。
点 P としてあり得る点を 1 つ挙げてください。

-----問題ここまで----- */
/* -----解説等-----

マンハッタン距離が等しいものは四辺が等しいひし形上にすべての辺が置かれる。
正方形であれば各辺の大きさから中心を特定することができる。
ので、まずこのひし形上の点をすべて正方形に変換する。(x,y) -> (x+y,x-y)
その後正方形上の最大辺を取得し、この半分の大きさが端点からの距離となる。
最大辺を求めたら、中心が取得できたことになるのでひし形を復元し、各頂点に対して本当にマンハッタン距離が等しいかを確認し、正しいならばこれを出力
もし正しくないならば中心のの過程が間違っていることになるので候補を変更し、もう一度確認する。


----解説ここまで---- */

ll N;
ll x[100010], y[100010];
ll xx[2], yy[2];

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;

	xx[0] = yy[0] = LINF;
	xx[1] = yy[1] = -LINF;

	FOR(i, 0, N) {
		cin >> x[i] >> y[i];
		ll a = x[i] + y[i];
		ll b = x[i] - y[i];
		xx[0] = min(a, xx[0]);
		xx[1] = max(a, xx[1]);
		yy[0] = min(b, yy[0]);
		yy[1] = max(b, yy[1]);
	}

	ll D = max(xx[1] - xx[0], yy[1] - yy[0]) / 2;

	FOR(i, 0, 2)FOR(j, 0, 2) {

		ll s = xx[i] + D*(i == 0 ? 1 : -1);
		ll t = yy[j] + D*(j == 0 ? 1 : -1);
		ll ax = (s + t) / 2, ay = (s - t) / 2;
		ll d = -1;
		bool ng = false;
		FOR(k, 0, N) {
			ll DD = abs(ax - x[k]) + abs(ay - y[k]);
			if (d != -1 && d != DD) ng = true;
			d = DD;
		}
		if (!ng) {
			cout << ax << " " << ay << endl;
			return 0;
		}

	}

}