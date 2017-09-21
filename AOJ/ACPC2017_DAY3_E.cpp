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

using P = pair<int, PII>;

/* -----  2017/09/20  Problem: ACPC2017_day3_e  / Link:   ----- */
/* ------ñ‚ëË------



-----ñ‚ëËÇ±Ç±Ç‹Ç≈----- */
/* -----âê‡ìô-----



----âê‡Ç±Ç±Ç‹Ç≈---- */
LL N;
struct BIT2D {
	int _H, _W;
	VVI data;
	BIT2D(int h, int w) {
		_H = h; _W = w;
		data = VVI(_W + 1, VI(_H + 1, 0));
	}
	void add(int a, int b, int val) {
		for (int x = a; x <= _W; x += x&-x) {
			for (int y = b; y <= _H; y += y&-y) {
				data[x][y] += val;
			}
		}
	}
	int _sum(int a, int b) {
		int ret = 0;
		for (int x = a; x > 0; x -= x & -x) {
			for (int y = b; y > 0; y -= y & -y) {
				ret += data[x][y];
			}
		}
		return ret;
	}
	int sum(int lx, int ly, int rx, int ry) {
		return _sum(rx, ry) - _sum(lx - 1, ry) - _sum(rx, ly - 1) + _sum(lx - 1, ly - 1);
	}
};

LL ans = 0LL;
int H, W, T, Q;

int main() {

	scanf("%d%d%d%d", &H, &W, &T, &Q);
	BIT2D yet(W, H);// 1index
	BIT2D done(W, H);// 1index


	queue<P> que;
	FOR(i, 0, Q) {
		int t, c, h1, w1, h2, w2;
		scanf("%d%d%d%d", &t, &c, &h1, &w1);

		while (!que.empty()) {
			P p = que.front();
			if (p.first + T <= t) {
				que.pop();
				int Y = p.second.first, X = p.second.second;
				yet.add(Y, X, -1);
				done.add(Y, X, 1);
			}
			else break;

		}

		if (c != 2) {
			if (c == 0) {
				if (yet.sum(h1, w1, h1, w1) == 0 && done.sum(h1, w1, h1, w1) == 0) {
					yet.add(h1, w1, 1);
					que.push({ t,PII(h1,w1) });
				}
			}
			else {//c ==1
				if (done.sum(h1, w1, h1, w1) == 1) {
					done.add(h1, w1, -1);
				}
			}
		}
		else {
			scanf("%d%d", &h2, &w2);
			printf("%d %d\n", done.sum(h1, w1, h2, w2), yet.sum(h1, w1, h2, w2));
		}

	}



	return 0;
}