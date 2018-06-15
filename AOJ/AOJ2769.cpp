#include <bits/stdc++.h>
using namespace std;

using VS = vector<string>;    using LL = long long;
using VI = vector<int>;       using VVI = vector<VI>;
using PII = pair<int, int>;   using PLL = pair<LL, LL>;
using VL = vector<LL>;        using VVL = vector<VL>;

#define ALL(a)  begin((a)),end((a))
#define RALL(a) (a).rbegin(), (a).rend()
#define SZ(a) int((a).size())
#define SORT(c) sort(ALL((c)))
#define RSORT(c) sort(RALL((c)))
#define UNIQ(c) (c).erase(unique(ALL((c))), end((c)))
#define FOR(i, s, e) for (int(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (int(i) = (s); (i) > (e); (i)--)
#define debug(x) cerr << #x << ": " << x << endl
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/06/09  Problem: AOJ 2769 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2769  ----- */
/* ------問題------

2,8のみで構成される数字がある。Nをこれに分解する際、分解の個数を最大化したい。
何個に分解できるか。(mulset)

-----問題ここまで----- */
/* -----解説等-----

実は全然ないのですぐ終わる(最悪)

----解説ここまで---- */

using ll = LL;
vector<ll> goods;

ll dfs(ll n, ll cnt, ll k) {
	if (n == 1) return cnt;
	if (n % 2 == 1) return -1;
	for (int i = k; i < goods.size(); i++) {
		ll v = goods[i];
		if (v > n) break;
		if (n % v == 0) {
			ll d = dfs(n / v, cnt + 1, i);
			if (d > 0) return d;
		}
	}
	return -1;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	ll N;
	cin >> N;
	if (N == 1) {
		cout << -1 << endl;
		return 0;
	}
	queue<ll> que;
	goods.push_back(2);
	goods.push_back(8);
	que.push(2);
	que.push(8);
	ll a = 10;
	while (!que.empty()) {
		ll p = que.front();
		que.pop();
		if (p > N) break;
		while (a < p) a *= 10;
		goods.push_back(a * 2 + p);
		goods.push_back(a * 8 + p);
		que.push(a * 2 + p);
		que.push(a * 8 + p);
	}
	SORT(goods);

	cout << dfs(N, 0, 0) << endl;
	return 0;
}