#include <bits/stdc++.h>
using namespace std;

using VS = vector<string>;    using LL = long long;
using VI = vector<int>;       using VVI = vector<VI>;
using PLL = pair<LL, LL>;
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

/* -----  2018/08/18  Problem: edu049 C / Link: __CONTEST_URL__  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

要はa/b+b/aなので、比が最も1に近いものを全探索すれば良い

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	using PII = pair<LL, LL>;
	int T; scanf("%d", &T);
	FOR(_, 0, T) {
		scanf("%lld", &N);
		VI a(N);
		FOR(i, 0, N) {
			scanf("%d", &a[i]);
		}
//		VI b(1e4 + 1, 0);
		map<int, int>b;
		FOR(i, 0, N) {
			b[a[i]]++;
		}
		VI c;
		for (const auto&it : b) {
			int num = it.second / 2;
			FOR(j, 0, num)c.push_back(it.first);
		}
		PII ansset = PII(c[0], c[1]);

		// a ans , b chal
		auto f = [](const PII& a, const PII& b) {
			return b.first*b.second*(a.first*a.first + a.second*a.second) > a.first*a.second*(b.first*b.first + b.second*b.second);
		};
		// solve (c sorted)
		FOR(i, 0, SZ(c)) {
			if (i != SZ(c) - 1) {// ->
				if (f(ansset, PII(c[i], c[i + 1]))) {
					ansset = PII(c[i], c[i + 1]);
				}
			}
			if (i != 0) {// <-
				if (f(ansset, PII(c[i], c[i - 1]))) {
					ansset = PII(c[i], c[i - 1]);
				}
			}

		}

		cout << ansset.first << " " << ansset.second << " ";
		cout << ansset.first << " " << ansset.second << endl;

	}

	return 0;
}