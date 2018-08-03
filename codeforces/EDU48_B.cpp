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

/* -----  2018/08/03  Problem: edu48 B / Link: __CONTEST_URL__  ----- */
/* ------問題------

|S|[L:R]中にTが何回発生するかというクエリに答えよ。

-----問題ここまで----- */
/* -----解説等-----

先に累積和を持って、T個ずれたものを作れば区間内の一致数をO(1)で答えることができる。
が、間に合いそうなのでロリハで押し通る
またはSAでもできそう？

----解説ここまで---- */

using uLL = unsigned long long;
const uLL _base = 1e9 + 7;
struct RollingHash {
	vector<uLL> hashed, power;
	RollingHash(const string& s) {
		int sz = s.size();
		hashed.assign(sz + 1, 0);
		power.assign(sz + 1, 0);

		power[0] = 1;
		for (int i = 0; i < sz; i++) {
			power[i + 1] = power[i] * _base;
		}
		for (int i = 0; i < sz; i++) {
			hashed[i + 1] = (hashed[i] + s[i]) * _base;
		}
	}
	uLL get(int l, int r) { // [l, r)
		return((hashed[r] - hashed[l] * power[r - l]));
	}
	uLL connect(int h1, int h2, int h2len) {
		return(h1 * power[h2len] + h2);
	}

};




int main() {

	int N, M, Q; 
	scanf("%d%d%d", &N, &M, &Q);
	string s, t; cin >> s >> t;
	// クエリに答える。
	RollingHash rs(s), rt(t);
	int ans = 0;
	uLL thash = rt.get(0, SZ(t));

	FOR(_, 0, Q) {
		ans = 0;
		int a, b;  scanf("%d%d", &a, &b);
		a--, b--;
		FOR(i, a, b - SZ(t) + 2) {
			if (rs.get(i, i + SZ(t) ) == thash)ans++;
		}

		cout << ans << "\n";
	}

	return 0;
}
