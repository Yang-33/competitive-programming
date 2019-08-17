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

/* -----  2019/08/17  Problem: AOJ 0234 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0234  ----- */


int W, H, F, M, O;
int fld[15][15];



int dist[15][15][1 << 10][50];


int main() {
	while (cin >> W >> H, W || H) {
		cin >> F >> M >> O; M--; O--;
		for (int i = 1; i <= H; i++) {
			for (int j = 0; j < W; j++) {
				cin >> fld[i][j];
			}
		}

		fill_n(***dist, 15 * 15 * (1 << 10) * 50, INF);
		struct node {
			int y, x, s, o, f;
			node(int y, int x, int s, int o, int f)
				:y(y), x(x), s(s), o(o), f(f) {}

			bool operator > (const node &d)const {
				return f > d.f;
			}
		};
		priority_queue<node, vector<node>, greater<node>>que;
		FOR(i, 0, W) {
			dist[0][i][1 << i][O] = 0;
			que.emplace(0, i, 1 << i, O, 0);
		}

		while (que.size()) {
			node d = que.top(); que.pop();
			if (dist[d.y][d.x][d.s][d.o] < d.f)continue;
			if (d.o == 0)continue;
			for (int i = -1; i <= 1; i += 2) {
				int ny = d.y, nx = d.x + i;
				if (nx < 0 || nx >= W)continue;
				int ns, no, nf;
				if (d.s >> nx & 1) {
					ns = d.s; no = d.o - 1; nf = d.f;
				}
				else {
					ns = d.s | (1 << nx);
					no = min(M, d.o - 1 + (fld[ny][nx] >= 0 ? fld[ny][nx] : 0));
					nf = d.f + (fld[ny][nx] >= 0 ? 0 : -fld[ny][nx]);
				}
				if (no < 0)continue;
				if (dist[ny][nx][ns][no] <= nf)continue;
				dist[ny][nx][ns][no] = nf;
				que.emplace(ny, nx, ns, no, nf);
			}

			int ny = d.y + 1, nx = d.x;
			if (ny > H)continue;
			int ns, no, nf;
			ns = 1 << nx;
			no = min(M, d.o - 1 + (fld[ny][nx] >= 0 ? fld[ny][nx] : 0));
			nf = d.f + (fld[ny][nx] >= 0 ? 0 : -fld[ny][nx]);
			if (no < 0)continue;
			if (dist[ny][nx][ns][no] <= nf)continue;
			dist[ny][nx][ns][no] = nf;
			que.emplace(ny, nx, ns, no, nf);
		}

		int mi = INF;
		for (int j = 0; j < W; j++) {
			for (int o = 0; o <= M; o++) {
				mi = min(mi, dist[H][j][1 << j][o]);
			}
		}

		if (mi > F)cout << "NA" << "\n";
		else cout << mi << "\n";
	}
	return 0;
}