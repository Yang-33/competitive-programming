#include <bits/stdc++.h>
using namespace std;

#define int long long 
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

/* -----  2019/03/24  Problem: google_kickstart2019_rounda B / Link: __CONTEST_URL__  ----- */
// parcles


inline bool IN(int y, int x, int H, int W) { return (0 <= y && y < H && 0 <= x && x < W); }
VVL fillgridbfs(const VS& s, int Height, int Width) {
	// many points 
	VVL d(Height, vector<LL>(Width, 1e9));

	queue<pair<int, pair<int, int>>>q;
	FOR(i, 0, Height) {
		FOR(j, 0, Width) {
			if (s[i][j] == '1') {
				d[i][j] = 0;
				q.push(make_pair(0, PII(i, j)));
			}
		}
	}

	while (!q.empty()) {
		pair<int, pair<int, int>>a = q.front(); q.pop();
		int dist = a.first; pair<int, int> pos = a.second;
		if (d[pos.first][pos.second] < dist)continue;
		FOR(k, 0, 4) {
			int ny = pos.first + DY[k]; int nx = pos.second + DX[k];
			if (IN(ny, nx, Height, Width)) {
				if (d[ny][nx] > d[pos.first][pos.second] + 1) {
					d[ny][nx] = d[pos.first][pos.second] + 1;
					q.push(make_pair(d[ny][nx], pair<int, int>(ny, nx)));
				}
			}
		}
	}

	return d;
}

struct ManhattanTransform {
	const int DY[4] = { 0,-1, 0 , 1 };
	const int DX[4] = { -1, 0, 1, 0 };
	int H, W;
	ManhattanTransform(int H, int W) :H(H), W(W) {}
	PII access_point(int y, int x) {
		return PII(x + y, x - y + (H - 1));
	}
	PII access_max() {
		return PII(W + H - 1, W + H - 1);
	}
	vector<PII>access_from_center(int y, int x, int k) {
		vector<PII>res;
		FOR(d, 0, 4) {
			int ny = y + DY[d] * k, nx = x + DX[d] * k;
			res.push_back(this->access_point(ny, nx));
		}
		return res;
	}
	PII rev(int y, int x) {
		return PII((H - 1 + y - x) / 2, (x + y + 1 - H) / 2);
	}
};


void solve(int testcasenum) {
	int H, W; cin >> H >> W;
	vector<string> s(H);
	for (int i = 0; i < H; ++i) {
		cin >> s[i];
	}

	const VVL fillgrid = fillgridbfs(s, H, W);

	auto f = [&](int X) {
		ManhattanTransform mh(H, W);
		PII my(-INF, INF);
		PII mx(-INF, INF);
		// カバーしなければならない部分について，共通部を求める
		FOR(i, 0, H) {
			FOR(j, 0, W) {
				if (fillgrid[i][j] > X) {
					PII tr = mh.access_point(i, j);
					my.first = max(my.first, tr.first - X);
					my.second = min(my.second, tr.first + X);

					mx.first = max(mx.first, tr.second - X);
					mx.second = min(mx.second, tr.second + X);
				}
			}
		}
		if (my.second == INF)return 1; // 必要なし

		FOR(tr_y, my.first, my.second + 1) {
			FOR(tr_x, mx.first, mx.second + 1) {
				PII rev = mh.rev(tr_y, tr_x);
				// 共通領域が元領域に存在&&元の座標に存在
				if (IN(rev.first, rev.second, H, W)
					&& PII(tr_y, tr_x) == mh.access_point(rev.first, rev.second)) {
					return 1;
				}
			}
		}
		return 0;
	};

	int L = 0 - 1, R = H + W + 1;
	while (R - L > 1) {
		int mid = (L + R) / 2;
		if (f(mid)) {
			R = mid;
		}
		else {
			L = mid;
		}
	}

	int ans = R;

	cout << "Case #" << testcasenum + 1 << ": " << ans << endl;
}
signed main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL T; cin >> T;
	FOR(_, 0, T) {
		solve(_);

	}

	return 0;
}
