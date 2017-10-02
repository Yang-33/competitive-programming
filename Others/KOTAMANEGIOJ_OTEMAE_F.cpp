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

/* -----  2017/08/01  Problem: KotamanegiOJ_Otemae F  / Link: https://kotamanegi.com/JudgeSystem/Problems/view/index.php?page=44  ----- */
/* ------問題------

kotamanegi君は座標が(1,1)~(H,W)で表される玉ねぎ畑にいて、(y,x)にある玉ねぎを収穫したいと考えています。
玉ねぎ畑は土壌が不安定なので、畑内を移動する際に、場所によって疲れ方が違います。
kotamanegi君は一回の移動でx座標が1違う点か、y座標が1違う点に移動できます。
また、y=iにおける移動ではyiだけ疲れ、x=jにおける移動ではxjだけ疲れます。
また、畑の一部には大たまねぎ(yl≦i≦yr,xl≦j≦xrを満たす長方形の区画に存在)があるので、その区画には移動できません 。
kotamanegi君は出来るだけ疲れたくないので、最も疲れない移動をしたときに疲労度を求めてください。
また、kotamanegi君は始め(1,1)にいます。

-----問題ここまで----- */
/* -----解説等-----

ダイクストラ。
サンプルまちがっとるやんけ！

----解説ここまで---- */

ll N;

ll ans = LINF;
ll W, H, Ty, Tx;
int cx[1003];
int cy[1003];
ll yl, yr, xl, xr;
ll masu[1003][1003];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> H >> W >> Tx >> Ty;
	FOR(i, 1, H + 1) {
		cin >> cx[i];
	}
	FOR(i, 1, W + 1) {
		cin >> cy[i];
	}
	cin >> xl >> xr >> yl >> yr;
	FOR(i, 0, H+1)FOR(j, 0, W+1) {
		masu[i][j] = LINF;
	}
	masu[1][1] = 0;
	using tt = tuple<ll, ll, ll>;
	priority_queue<tt, vector<tt>, greater<tt>>q;
	q.push(tt(0, 1, 1));

	while (!q.empty()) {
		tt a = q.top(); q.pop();
		ll d, x, y;
		tie(d, y, x) = a;
		if (masu[x][y] < d)continue;

		FOR(i, 0, 4) {
			int nx = x + dx[i]; int ny = y + dy[i];
			if (!(1 <= nx&&nx <= H && 1 <= ny&&ny <= W))continue;

			if (xl <= nx && nx <= xr&&yl <= ny && ny <= yr)continue;
			ll nc;
			if (i < 2) {//y
				nc = cx[x];
			}
			else {//x
				nc = cy[y];
			}
			if (masu[nx][ny] > d + nc) {
				masu[nx][ny] = d + nc;
				q.push(tt(masu[nx][ny], ny, nx));
			}
		}
	}

	/*FOR(i, 1, H + 1) {
		FOR(j, 1, W + 1) {
			cout << masu[i][j] << " ";
		}cout << endl;
	}*/
	ans = masu[Tx][Ty];

	if (ans == LINF)ans = -1;
	cout << ans << endl;

	return 0;
}
