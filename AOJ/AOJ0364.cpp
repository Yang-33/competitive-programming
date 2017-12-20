#include <bits/stdc++.h>
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

/* -----  2017/12/20  Problem: AOJ 0364 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0364  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----



----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int W, H; cin >> W >> H >> N;
	VI x(N, 0), y(N, 0);
	
	VL yy(W, 0);
	FOR(i, 0, N) {
		cin >> x[i] >> y[i];
		yy[x[i]] = max(yy[x[i]],(LL)y[i] );
	}
	ans = INF;
	LL ymax = 0;
	FORR(i, W - 1, 0 - 1) {
		ans = min(ans, i + ymax);
		ymax= max(ymax,yy[i]);
	}

	cout << ans << "\n";

	return 0;
}
