#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define FOR(i, s, e) for (int(i) = (s); (i) < (e); (i)++)
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

/* -----  2017/05/01  Problem: JOI予選 2012 5  / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0580  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

広すぎるので座標圧縮をする。必要な情報は各軸における最近接点との距離であるからこれを値として格納すればよい。
直方体が存在する領域を圧縮座標上で加算して,K以上の点の体積をあとで全部足して間に合う。
きれいに実装できてうれしい。

----解説ここまで---- */

vector<ll>compress(ll  *point1, ll  *point2, ll N) {
	vector<ll>xs;
	FOR(i, 0, N) {
		xs.pb(point1[i]);
		xs.pb(point2[i]);
	}
	sort(xs.begin(), xs.end());
	xs.erase(unique(xs.begin(), xs.end()), xs.end());

	FOR(i, 0, N) {
		point1[i] = find(xs.begin(), xs.end(), point1[i]) - xs.begin();
		point2[i] = find(xs.begin(), xs.end(), point2[i]) - xs.begin();
	}
	vector<ll> kukan;
	FOR(i, 0, xs.size() - 1) {
		kukan.pb(xs[i + 1] - xs[i]);
	}

	return kukan;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	ll N, K;
	ll x1[55], x2[55];
	ll y1[55], y2[55];
	ll z1[55], z2[55];
	ll ans = 0LL;

	cin >> N >> K;
	FOR(i, 0, N) {
		cin >> x1[i] >> y1[i] >> z1[i] >> x2[i] >> y2[i] >> z2[i];
	}
	vector<ll >X, Y, Z;
	X = compress(x1, x2, N);
	Y = compress(y1, y2, N);
	Z = compress(z1, z2, N);
	ll area[105][105][105];
	FOR(i, 0, 105)FOR(j, 0, 105)FOR(k, 0, 105)area[i][j][k] = 0;

	FOR(i, 0, N) {
		FOR(xx, x1[i], x2[i])
			FOR(yy, y1[i], y2[i])
			FOR(zz, z1[i], z2[i]) {
			area[xx][yy][zz]++;
		}
	}

	ans = 0;
	FOR(xx, 0, X.size()) {
		FOR(yy, 0, Y.size()) {
			FOR(zz, 0, Z.size()) {
				if (area[xx][yy][zz] >= K)ans += X[xx] * Y[yy] * Z[zz];
			}
		}
	}

	cout << ans << endl;

	return 0;
}
