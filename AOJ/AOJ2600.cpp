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

/* -----  2017/06/21  Problem: AOJ 2600  / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2600&lang=jp ----- */
/* ------問題------

みて

-----問題ここまで----- */
/* -----解説等-----

片側が埋まってくれれば両側埋まっていることになる。
別にいもす法でなくとも座標の長さを管理してどっちかの辺がW,Hの幅になっていることを確認できればよい。
形として縦または横中心で埋まっていくものをすぐに考えられなかった。

----解説ここまで---- */

int N, H, W;
ll w[100010];
ll h[100010];
ll ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> W >> H;
	FOR(i, 0, N) {
		int x, y, wi;
		cin >> x >> y >> wi;
		h[max(0, y - wi)]++; h[min(y + wi , H )]--;
		w[max(0, x - wi)]++; w[min(x + wi , W )]--;
	//	cout << "max: " << max(0, x - wi) << " min:" << min(x + wi, W) << endl;
	//	cout << "max: " << max(0, y - wi) << " min:" << min(y + wi, W) << endl;
	}
	FOR(i, 0, H) {
		h[i + 1] += h[i];
	}
	FOR(i, 0, W) {
		w[i + 1] += w[i];
	}
	bool f = 0;

	FOR(i, 0, H) {
		//cout << h[i] << " ";
		if (h[i] <= 0)break;

		if (i == H - 1)f = 1;
	}//cout << endl;

	FOR(i, 0, W) {
		//cout << w[i] << " ";

		if (w[i] <= 0)break;
		if (i == W - 1)f = 1;

	}//cout << endl;

	if (f)
		cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
