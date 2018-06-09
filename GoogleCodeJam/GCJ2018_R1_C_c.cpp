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

/* -----  2018/05/05  Problem: GCJ2018_R1_C C / Link: __CONTEST_URL__  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

試しに最悪ケースを考えてみると、
解の上限が139なので、適当にdpをすると一見O(N^2)を書いても枝刈りっぽくすれば全然通る。

----解説ここまで---- */

int solve() {
	int N; scanf("%d", &N);
	VL w(N);
	FOR(i, 0, N) {
		scanf("%d",&w[i]);
	}
	VL dp(N + 1, 1e18);
	dp[0] = 0;
	int maxid = 1;
	FOR(i, 0, N) {
		FORR(l, min(i,maxid), 0-1) {
			if (dp[l] <= 6 * w[i]) {
				dp[l + 1] = min(dp[l + 1], dp[l] + w[i]);
				maxid =max(maxid, l+1);
			}
		}
	}
	int ret = 0;
	FOR(i, 1, N+1) {
		if (dp[i] < 1e18)ret = i;
	}

	return ret;
}


int main() {

	int Case; scanf("%d",&Case);
	FOR(ccaassee, 0, Case) {
		printf("Case #%d: %d\n",ccaassee+1,solve());
//		cout << "Case #" << ccaassee + 1 << ": " << solve() << "\n";
	}

	return 0;
}
