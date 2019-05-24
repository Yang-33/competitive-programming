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
//#pragma GCC optimize ("-O3") 
#ifdef YANG33
#include "mydebug.hpp"
#else
#define DD(x) 
#endif
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);

/* -----  2019/05/18  Problem: GCJ2019_R2 A / Link: __CONTEST_URL__  ----- */


// name: new element part 1
void solve(int testcasenum) {

	// 1 or 2
	int N; cin >> N;
	vector<PII>a(N);
	FOR(i, 0, N) {
		int x, y; cin >> x >> y;
		a[i] = PII(x, y);
	}

	vector<PII>uku;
	FOR(i, 0, N) {
		FOR(j, 0, N) {
			if (i == j)continue;
			if (a[i].first > a[j].first && a[i].second < a[j].second) {
				LL x = a[i].first - a[j].first;
				LL y = a[i].second - a[j].second;
				LL g = __gcd(x, y);
				uku.push_back(PII(x / g, y / g));
			}
		}
	}
	SORT(uku); UNIQ(uku);

	int ans = SZ(uku) + 1;


	cout << "Case #" << testcasenum << ": " << ans << endl;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);


	int T; cin >> T;
	FOR(c, 0, T) {
		solve(c + 1);
	}

	return 0;
}
