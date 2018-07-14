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

/* -----  2018/07/14  Problem: edu47_c_codeforces / Link: __CONTEST_URL__  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

和を最大化したいが、O(1)でわかる

----解説ここまで---- */


int main() {

	LL N,M;
	scanf("%lld%lld", &N, &M);
	VI x(M), d(M);
	double ans = 0;
	LL sum = 0;
	FOR(i, 0, M) {
		scanf("%d%d", &x[i], &d[i]);
		
		ans += x[i];
		if (d[i] > 0) {
			sum += (LL)d[i]*(N*(N-1))/2LL;
		}
		else if (d[i]) {
			if (N%2) {
				sum += (LL)d[i]*(N/2)*(N/2+1);
			}
			else {
				sum += (LL)d[i] * ((N-1) / 2)*((N-1) / 2 + 1);
				sum += (LL)d[i] * (N-N/2);

			}
		}

	}
	ans += (double)sum / (double)(N);
	cout << fixed<< setprecision(10)<<ans << "\n";

	return 0;
}
