#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
#define FOR(i, s, e) for (ll(i) = (s); (i) < (e); (i)++)
#define pb push_back
const ll LINF = 1e16;

/* -----  2017/04/24  Problem: JOI予選 2014 6  / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0613  ----- */
/* ------問題------

みて

-----問題ここまで----- */
/* -----解説等-----

Aがとる・Bがとる・とらないの三つしか状態がなく、うれしいことにN=30なので
半分全列挙をすれば3^15≦1.5*10^7 でいい感じにできそうなことに気付く。
絶対値の差がDであるものを探すが、二分探索した範囲の集合は大きすぎるので、
セグ木を準備して区間の最大値をとってあげれば間に合う。
-LINFにしてなくて1敗した。

----解説ここまで---- */


ll x[35], y[35];
vector<pll>v[2];


/* [a,b) */
inline void dfs(int a, int b, int f, ll xx, ll yy) {
	if (a >= b) {
		v[f].pb(pll(xx, yy));
		return;
	}
	dfs(a + 1, b, f, xx, yy);
	dfs(a + 1, b, f, xx + x[a], yy + y[a]);
	dfs(a + 1, b, f, xx - x[a], yy - y[a]);
}


ll gn, dat[1 << 25];

void init(ll num) {
	while (gn < num) {
		gn *= 2;
	}
	FOR(i, 0, 2 * gn) {
		dat[i] = -LINF;
	}
}


void update(ll k, ll val) {
	k += gn - 1;
	dat[k] = val;
	while (k > 0) {
		k = (k - 1) / 2;
		dat[k] = max(dat[k * 2 + 1], dat[k * 2 + 2]);
	}
}



ll query(ll a, ll b, ll k, ll l, ll r) {
	if (r <= a || b <= l) return -LINF;
	if (a <= l && r <= b) return dat[k];
	else {
		ll vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
		ll vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
		return max(vl, vr);
	}

}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	ll N, D; cin >> N >> D;
	ll ans = 0LL;

	FOR(i, 0, N) {
		cin >> x[i] >> y[i];
	}

	dfs(0, N / 2, 0, 0, 0);
	dfs(N / 2, N, 1, 0, 0);
	sort(v[0].begin(), v[0].end());
	sort(v[1].begin(), v[1].end());
	gn = 1;
	init(v[1].size());

	FOR(i, 0, v[1].size()) {
		update(i, v[1][i].second);
	}
	ans = -LINF;
	FOR(i, 0, v[0].size()) {
		pll s = v[0][i];
		ll xx = s.first, yy = s.second;
		int l = lower_bound(v[1].begin(), v[1].end(), pll(-xx - D, (ll)-LINF)) - v[1].begin();
		int r = lower_bound(v[1].begin(), v[1].end(), pll(-xx + D, LLONG_MAX)) - v[1].begin();
		ans = max(ans, yy + query(l, r, 0, 0, gn));
	}

	cout << ans << endl;

	return 0;
}
