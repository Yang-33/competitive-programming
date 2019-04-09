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
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2019/04/09  Problem: ABC 023 C / Link: http://abc023.contest.atcoder.jp/tasks/abc023_c  ----- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL H, W, K; cin >> H >> W >> K;
	int N; cin >> N;
	vector<PLL>pos(N);
	for (int i = 0; i < N; ++i) {
		int h, w; cin >> h >> w;
		h--, w--;
		pos[i] = PLL(h, w);
	}
	map<LL, LL>ycnts, xcnts;
	FOR(i, 0, N) {
		ycnts[pos[i].first]++;
		xcnts[pos[i].second]++;
	}
	auto revmap = [](int H, const  map<LL, LL> & poscnt) {
		map<LL, LL>rev;
		LL zerocnt = H - SZ(poscnt);
		rev[0] += zerocnt;
		for (auto it : poscnt) {
			rev[it.second]++;
		}
		return rev;
	};

	auto xrev = revmap(W, xcnts);
	auto yrev = revmap(H, ycnts);
	LL ans = 0LL;
	for (auto yc : yrev) {
		LL yk = yc.first;
		ans += (xrev.find(K - yk) != xrev.end() ? xrev[K - yk] : 0)*yc.second;
	}
	DD(de(ans));
	LL ret = 0;
	FOR(i, 0, N) {
		if (xcnts[pos[i].second] + ycnts[pos[i].first] == K + 1)ans++;
		if (xcnts[pos[i].second] + ycnts[pos[i].first] == K)ans--;
	}
	DD(de(ret))
		DD(de(ans));

	cout << ans << "\n";

	return 0;
}
