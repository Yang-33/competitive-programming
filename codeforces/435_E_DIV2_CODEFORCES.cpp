#include "bits/stdc++.h"
using namespace std;

using VS = vector<string>;    using LL = long long;
using VI = vector<int>;       using VVI = vector<VI>;
using PII = pair<int, int>;   using PLL = pair<LL, LL>;
using VL = vector<LL>;        using VVL = vector<VL>;

#define ALL(a)  begin((a)),end((a))
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define EB emplace_back
#define MP make_pair
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


/* -----  2017/09/19  Problem: CodeForces435 E div2 / Link: http:codeforces.com/contest/862/problem/E ----- */
/* ------–â‘è------



-----–â‘è‚±‚±‚Ü‚Å----- */
/* -----‰ðà“™-----



----‰ðà‚±‚±‚Ü‚Å---- */


LL N,M,Q;
LL a[100005];
LL b[100005];
LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N>>M>>Q;
	FOR(i, 0, N) {
		cin >> a[i];
	}
	LL ma = -LINF, mi = LINF;
	LL sum = 0;
	FOR(i, 0, M) {
		cin >> b[i];
	}
	FOR(i, 0, N) {
		if (i % 2 == 0)sum -= b[i];
		else sum += b[i];
	}
	ma = max(ma, sum);
	mi = min(mi, sum);
	FOR(i, N, M) {
		if (i % 2 == 0)sum = sum - b[i];
		else sum = sum + b[i];
		if (N % 2 == 0)sum += b[i - N];
		else sum -= b[i - N];
		ma = max(ma, max(sum, -sum));
		mi = min(mi, min(sum, -sum));
	}

	//

	FOR(i, 0, Q) {
		LL l, r, add;
		cin >> l >> r >> add;
		// l,r,add

		cout << ans << "\n";
	}

	return 0;
}