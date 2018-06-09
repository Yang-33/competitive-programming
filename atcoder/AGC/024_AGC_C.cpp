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

// 300“_I

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N; cin >> N;
	VI a(N);
	FOR(i, 0, N) {
		cin >> a[i];
	}

	LL ans = 0;
	int ok = 1;
	FOR(i, 0, N) {
		if (i == 0) {
			if (a[i] != 0)ok = 0;
		}else{
			if (a[i - 1] + 1 == a[i]) {
				ans++;
			}
			else if (a[i - 1] == a[i]) {
				ans += a[i];
			}
			else if(a[i-1]>a[i]){
				ans += a[i];
			}
			else ok = 0;
		}
	}
	if (!ok)ans = -1;
	cout << ans << "\n";

	return 0;
}
