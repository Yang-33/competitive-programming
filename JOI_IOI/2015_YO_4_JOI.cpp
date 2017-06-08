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

/* -----  2017/04/17  Problem: JOI予選 2015 4  / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0622  ----- */
/* ------問題------

みて

-----問題ここまで----- */
/* -----解説等-----

最初バグがとれずに解けなかった。寝かせたらすっきり解けた。
固まる可能性がある地点を記録しておき、ここに来た人の位置を書き換えてあげてもう記録したことをメモしておけばよい。d(i)=0
d(i)=0とならなかった人たちは移動するだけなのでこれを求めればよい。

----解説ここまで---- */

#define NN 100010

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	ll N, T, Q;

	ll ans = 0LL;
	ll a[NN], d[NN], human[NN];

	cin >> N >> T >> Q;
	FOR(i, 0, N) {
		cin >> a[i] >> d[i];
	}
	FOR(i, 0, Q) {
		cin >> human[i];
	}
	vector<ll> point;
	FOR(i, 0, N - 1) {
		if (d[i] == 1 && d[i + 1] == 2 &&  a[i + 1] - a[i] <= 2*T) {
			d[i] = d[i + 1] = 0;
			a[i] = a[i + 1] = (a[i] + a[i + 1]) / 2;
			point.push_back(a[i]);
		}
	}
	//d 1-> 2<-
	FOR(i, 0, N) {
		if (d[i]) {
			int p = lower_bound(point.begin(), point.end(), a[i]) - point.begin();
			if (p < point.size() && d[i] == 1 && point[p] <= a[i] + T) {
				a[i] = point[p];
				d[i] = 0;
			}
			
			else if (0 <= p - 1 && d[i] == 2 && a[i] - T <= point[p - 1]) {
				a[i] = point[p - 1];
				d[i] = 0;
			}

		}

	}

	FOR(_i, 0, Q) {
		ll x;
		int i = human[_i]-1;
		if (d[i] == 1) x = a[i] + T;
		else if (d[i] == 2)x = a[i] - T;
		else x = a[i];
		cout<<x <<endl;
	}

	return 0;
}
