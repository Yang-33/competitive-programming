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

/* -----  2018/08/03  Problem: edu48 A / Link: http://codeforces.com/contests/1016  ----- */
/* ------問題------

.

-----問題ここまで----- */
/* -----解説等-----

わからないけどmodをしていくっぽい

----解説ここまで---- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	
	LL N,M;
	cin >> N>>M;
	LL sum = 0;
	FOR(i, 0, N) {
		LL a; cin >> a;
		sum += a;
		LL ret = sum / M;
		cout << ret <<" \n"[i==N-1];
		sum %= M;
	}

	return 0;
}
