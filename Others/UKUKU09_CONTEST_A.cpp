#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define FOR(i, s, e) for (int(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (ll(i) = (s); (i) > (e); (i)--)
#define debug(x) cout << #x << ": " << x<<" "
#define mp make_pair
#define pb push_back
const ll MOD = 1000000007;
const int INF = 1e9;
const ll LINF = 1e16;
const double PI = acos(-1.0);
int dx[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2017/07/07  Problem: ukuku09_contest A  / Link: https://hoj.hamako-ths.ed.jp/onlinejudge/problems/766  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----
seg+座標圧縮+にぶたん

問題からsum[i]-sum[j]≧Pを考える。
累積和をキーにして、これをみたす(j,i)の組のうち区間長が最大になるものを見つけたい。
式変形を行いsum[i]-P≧sum[j]をみる。
順番にiを見ていくときに、欲しい累積和の最大値sum[j]がこれで決まったので
この最大値以下のうちindexが最小のものを見つける。
これは累積和を座標圧縮したものをソートして最小値のseg木にのせておけば簡単に見つけることができる。

----解説ここまで---- */


struct SegTree {
	ll N;
	vector<ll> dat;
	SegTree(ll _N) {
		N = 1;
		while (N < _N)N *= 2;
		dat = vector<ll>(N * 2 - 1, INT_MAX);
		// max値を入れておく、書き換えupdateはいいが加算addに注意
	}
	void add(ll k, ll val) {
		k += N - 1;
		dat[k] += val;
		while (k) { // 根まで再帰的に上る
			k = (k - 1) / 2;
			dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2]); // 結果をmerge
		}
	}

	void update(ll k, ll val) {
		k += N - 1;
		dat[k] = val;
		while (k) { // 根まで再帰的に上る
			k = (k - 1) / 2;
			dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2]); // merge
		}
	}
	// 区間[a,b)の評価
	ll query(ll a, ll b, ll k, ll l, ll r) {
		if (r == -1)r = N;
		if (r <= a || b <= l)return INT_MAX; // 区間が被らない 
		if (a <= l&&b >= r)return dat[k]; // 値を返す
		ll v1 = query(a, b, k * 2 + 1, l, (l + r) / 2);
		ll v2 = query(a, b, k * 2 + 2, (l + r) / 2, r);
		return min(v1, v2); //merge
	}
	inline ll query(ll a, ll b) {
		return query(a, b, 0, 0, N);
	}
};


ll N, P;
ll a[200005];
ll sum[200005];
bool f[200005];
ll ans = 0;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	scanf("%lld %lld", &N, &P);
	vector<ll>v;
	ll b = 0;
	v.push_back(0LL);

	for (int i = 0; i < N; i++) {
		scanf("%lld", &a[i]);
		sum[i + 1] = sum[i] + a[i];
		v.push_back(sum[i + 1]);
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	SegTree seg(v.size());

	FOR(i, 0, N + 1) f[i] = 0;

	FOR(i, 0, N + 1) {
		int x = lower_bound(v.begin(), v.end(), sum[i]) - v.begin();
		if (!f[x]) {
			f[x] = 1;
			seg.update(x, i);
		}

		int y = upper_bound(v.begin(), v.end(), sum[i] - P) - v.begin();
		int j = seg.query(0, y);
		if (j != INT_MAX)
			ans = max(ans, (ll)(i - j));
	}

	printf("%d\n", ans);
	return 0;
}
