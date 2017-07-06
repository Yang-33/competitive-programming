#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define FOR(i, s, e) for (ll(i) = (s); (i) < (e); (i)++)
#define debug(x) cout << #x << ": " << x << endl

/* -----  2017/07/07  Problem: AOJ 2609 jag summer 2013 Wave Atacck (NU contest 14 B)/ Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2609  ----- */
/* ------問題------

W*Hの箱の中で、(X,Y)から衝撃波が来る。この衝撃波は速度Vで衝撃波を全方向に出し、T秒までこの衝撃波は有効である。
(P,Q)にいる人に何回当たるか。
v×t≤10^6
2≤w,h≤10^8
0<x,p<w
0<y,q<h
(x,y)≠(p,q)

-----問題ここまで----- */
/* -----解説等-----

衝撃波が折り返して反射してくるのを考えるのがとても大変なので、円は折り返さないとする。その代わり箱をたくさん作り、
辺を折り返した際に対称になるような位置に伯爵がいるとする。このとき、問題は(X,Y)を中心とした円の中にどれだけ点が存在するか
という問題に書き換えられる。円の半径はTVである。伯爵の位置についてみると、
最初の箱を基準にした際にX座標は ...,-4W-P,-4W+P,-2W-P, -2W+P -P,P,2W-P,2W+P,4W-P,4W+P,...
Y座標も同様に周期2の座標しかないことが分かる。

Xの幅についてVT≦10^6,箱のサイズは2≦Wであるから各x座標についてその縦列にある点の数を数える。
その列の円の重なる部分のY座標は、列のX座標と衝撃波の発射地点から分かる。円が非常に小さい場合を除いて、この円の下には必ず点があるので
これは高さをHで割れば点の個数が分かる。
その次の点についてこの点が含まれるかどうかは分からないのでこれについては具体的な座標を求めて円に含まれるかを検査する。
これを上下左右について場合分けをして点の数を足していけばよい。

この話は円の下からX,Y軸までは必ず覆われている前提であったので、
例外処理は右上の領域について、最も円の中心に近い点が円に含まれない場合はカウントをしないとすればよい。

幾何よりかはゴリゴリの算数っぽい。

----解説ここまで---- */

ll W, H, V, T, X, Y, P, Q;
ll ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> W >> H >> V >> T >> X >> Y >> P >> Q;
	ll width = V*T + X;

	width = (width + W - 1) / W;

	//sの右側
	ll r = V*T;
	FOR(i, 0, width) {
		ll x;
		if (i % 2 == 0) { x = (i + 1) / 2 * 2 * W + P; }
		else { x = (i + 1) / 2 * 2 * W - P; }
		//上
		ll dx = x - X;
		double  kyoukaiY = sqrt(r*r - dx*dx) + Y;
		if (pow(X - x, 2) + pow(Y - Q, 2) > r*r)continue;
		//一つ目の点が内側にないときはそもそもどの点も内包されない


		ll hnum = kyoukaiY / H;
		ans += hnum;
		ll y, dy;
		if (hnum % 2 == 0) { //奇数番目が入るかわからない
			y = hnum*H + Q;
			dy = y - Y;
		}
		else { // 偶数番目が入るかわからない
			y = ((hnum + 1) / 2) * 2 * H - Q;
			dy = y - Y;
		}

		if ((r*r >= dx*dx + dy*dy)) {
			ans++;
		}

		//下
		dx = x - X;
		kyoukaiY = sqrt(r*r - dx*dx) - Y;
		if (kyoukaiY < 0)continue;
		hnum = kyoukaiY / H;
		ans += hnum;

		if (hnum % 2 == 0) { //奇数番目が入るかわからない
			y = hnum*H + Q;
			dy = y + Y;
		}
		else { // 偶数番目が入るかわからない
			y = ((hnum + 1) / 2) * 2 * H - Q;
			dy = y + Y;
		}

		if ((r*r >= dx*dx + dy*dy)) {
			ans++;
		}
	}


	//左
	width = abs(-r + X);
	width = (width + W - 1) / W;
	FOR(i, 0, width) {
		ll x;
		if (i % 2 == 0) { x = -((i + 1) / 2 * 2 * W + P); }// 左と同じ
		else { x = -((i + 1) / 2 * 2 * W - P); }

		ll dx = abs(x) + X;
		ll y, dy;

		//上
		double kyoukaiY = sqrt(r*r - dx*dx) + Y;
		ll hnum = kyoukaiY / H;
		ans += hnum;
		if (hnum % 2 == 0) {// 次奇数番目が入るかのチェック
			y = hnum*H + Q;
			dy = y - Y;
		}
		else {// 次奇偶数番目が入るかのチェック
			y = ((hnum + 1) / 2) * 2 * H - Q;
			dy = y - Y;
		}

		if ((r*r >= dx*dx + dy*dy)) {
			ans++;
		}

		//下
		dx = abs(x) + X;

		kyoukaiY = sqrt(r*r - dx*dx) - Y;
		if (kyoukaiY < 0)continue;
		hnum = kyoukaiY / H;
		ans += hnum;

		if (hnum % 2 == 0) { //奇数番目が入るかわからない
			y = hnum*H + Q;
			dy = y + Y;

		}
		else { // 偶数番目が入るかわからない
			y = ((hnum + 1) / 2) * 2 * H - Q;
			dy = y + Y;
		}

		if ((r*r >= dx*dx + dy*dy)) {
			ans++;
		}

	}

	cout << ans << endl;

	return 0;
}