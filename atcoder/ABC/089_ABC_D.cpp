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

/* -----  2019/03/11  Problem: ABC 089 D / Link: http://abc089.contest.atcoder.jp/tasks/abc089_d  ----- */

struct Cumusum {
	vector<LL>csum;

	Cumusum(vector<LL>&a) {
		csum.assign((int)a.size() + 1, 0);
		for (int i = 0; i < (int)a.size(); i++) {
			csum[i + 1] = csum[i] + a[i];
		}
	}
	LL query(int l, int r) {
		return csum[r] - csum[l];
	}
};
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL H, W, D; cin >> H >> W >> D;
	vector<vector<LL>> a(H, vector<LL>(W));
	vector<PII>reva(H*W);
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			cin >> a[i][j];
			a[i][j]--;
			reva[a[i][j]] = PII(i, j);
		}
	}
	// L<=R
	vector<Cumusum> cumvec;
	auto f = [&](int s, int t) {
		LL x = reva[s].first - reva[t].first;
		LL y = reva[s].second - reva[t].second;
		LL c = abs(x) + abs(y);
		return c;
	};
	FOR(i, 0, D) {
		vector<LL>cost;
		for (int j = i; j + D < H * W; j += D) {
			int nx = j + D;
			cost.push_back(f(j, nx));
		}
		cost.push_back(0);
		cumvec.push_back(Cumusum(cost));
	}
	int Q; cin >> Q;

	FOR(_, 0, Q) {
		LL L, R; cin >> L >> R;
		L--, R--;
		LL ans = cumvec[L%D].query(L / D, R / D);
		cout << (ans) << "\n";
	}




	return 0;
}
