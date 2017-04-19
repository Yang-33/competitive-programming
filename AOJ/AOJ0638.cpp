#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define FOR(i, s, e) for (int (i) = (s); (i) < (e); (i)++)
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

/* -----  2017/04/19  Problem:  / Link:   ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

値で二分探索かついいかんじに配置するためにどちらにも属する可能性のある領域は
後でチェックするという方針でやっていたら実装が爆発したので諦めた。
列の最大値やその位置をとっておいて、低い側の値を見たときにこれに反するものがないようにする。
上から順に差大きい側でない位置を記憶しそれを大きくしていくことだけを許せば階段状の形になる。
回転させればこれを場合分けなしで考慮なく解くことができる。
回転は天才すぎる。

----解説ここまで---- */


ll H, W, minn, maxn;
ll a[2005][2005];
ll ans;
bool f(ll x) {
	int num = 0;
	FOR(i, 0, H) {
		FOR(j, 0, W) {
			if (a[i][j] < maxn - x) {
				num = max(num, j + 1);
			}
		}
		FOR(j, 0, W) {
			if (a[i][j] > minn + x) {
				if (j < num)return false;
			}
		}
	}
	return 1;
}

void swapA() {
	FOR(i, 0, H / 2) {
		FOR(j, 0, W)swap(a[i][j], a[H - 1 - i][j]);
	}
}
void swapB() {
	FOR(i, 0, H) {
		FOR(j, 0, W / 2)swap(a[i][j], a[i][W - 1 - j]);
	}
}

ll solve() {
	ll l = -1, r = 1e9 + 1e8;
	FOR(i, 0, 30) {
		ll mid = (l + r) / 2;
		//cout << l << " " << r << endl;
		if (f(mid))r = mid;
		else l = mid;
	}
	return r;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> H >> W;
	minn = LINF; maxn = -LINF;
	FOR(i, 0, H) {
		FOR(j, 0, W) {
			cin >> a[i][j];
			minn = min(minn, a[i][j]);
			maxn = max(maxn, a[i][j]);
		}
	}

	ans = solve();
	swapA();
	ans = min(ans, solve());
	swapB();
	ans = min(ans, solve());
	swapA();
	ans = min(ans, solve());

	cout << ans << endl;

	return 0;
}
