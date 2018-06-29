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

/* -----  2018/06/30  Problem: AOJ 2576 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/2576  ----- */
/* ------問題------

'A','B','C','D','E'の5択からなるマークシート問題がある。
1つの解答欄は空欄1マス、もしくは2マスから構成されており、
それぞれの解答欄について、マス全てが想定されている解答と等しいとき、
解答欄に割り当てられた点数を得る。解答欄毎の解答と配点が与えられる。
D個のマスまで'D'とマークし、残りのマスを空マスにしなければならないとき、
得られる点数の最大値を求めよ。

-----問題ここまで----- */
/* -----解説等-----

D = one + twoで全探索すれば良い。or DP or 謎greedy

----解説ここまで---- */

using ll = LL;
void solve() {
	ll D; cin >> D;
	ll x; cin >> x;
	vector<PLL> events;
	vector<int>one, two;
	for (int i = 0; i < x; i++) {
		string a; ll p; cin >> a >> p;
		if (a == "D") {
			one.push_back(p);
		}
	}
	ll y; cin >> y;
	for (int i = 0; i < y; i++) {
		string a; ll p; cin >> a >> p;
		if (a == "DD") {
			two.push_back(p);
		}
	}
	sort(one.rbegin(), one.rend());
	sort(two.rbegin(), two.rend());

	int N = max(SZ(one), SZ(two)) + 1;
	N = max(N, (int)D + 1);
	vector<LL>onesum(N + 1, 0);
	vector<LL>twosum(N + 1, 0);
	FOR(i, 0, N) {
		onesum[i + 1] = onesum[i];
		twosum[i + 1] = twosum[i];
		if (i < SZ(one)) {
			onesum[i + 1] += one[i];
		}
		if (i < SZ(two)) {
			twosum[i + 1] += two[i];
		}
	}
	LL ans = 0;
	FOR(i, 0, D + 1) {
		ans = max(ans, onesum[i] + twosum[(D - i) / 2]);
	}
	cout << ans << endl;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	solve();

	return 0;
}