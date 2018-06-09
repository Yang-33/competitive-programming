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

/* -----  2018/06/10  Problem: AOJ 2342 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2342  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

がんばる(がんばるしかないので)

----解説ここまで---- */

struct state {
	int y, x, dir, bs, s;
	state() { y = x = dir = bs = s = 0; }
	state(int a, int b, int c, int d, int e) :y(a), x(b), dir(c), bs(d), s(e) {}
};

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int H, W, A;
	cin >> H >> W >> A;
	VS vs(H);
	FOR(i, 0, H) {
		cin >> vs[i];
	}

	PII S, T;
	FOR(i, 0, H) {
		FOR(j, 0, W) {
			if (vs[i][j] == 'S')S = PII(i, j);
			if (vs[i][j] == 'G')T = PII(i, j);
		}
	}

	static int dp[101][101][4][11][11];
	fill(****dp, ****dp + 101 * 101 * 4 * 11 * 11, INF);
	dp[S.first][S.second][0][0][0] = 0;
	queue<state> que;
	que.push(state{ S.first, S.second, 0, 0, 0 });

	int dy[] = { 1,0,-1,0 };
	int dx[] = { 0,1,0,-1 };
	while (!que.empty()) {
		state q = que.front();
		que.pop();

		for (int k = 1; k < 1000; k++) {
			int ny = q.y + dy[q.dir] * k;
			int nx = q.x + dx[q.dir] * k;
			// y : %2==0 , x: %2==1

			if (q.dir == 2 && PII(ny, nx) == S)break;
			if (PII(ny, nx) == S)continue;

			if (!(0 <= nx && nx < W && 0 <= ny  && ny < H))break;
			{
				if (vs[ny][nx] == '#')break;

				int bsnum, snum;

				if (q.dir % 2 == 0) {
					bsnum = 0, snum = 1;
				}
				else {
					bsnum = 1, snum = 0;
				}

				if (q.bs + bsnum <= A && q.s + snum <= A) {
					if (dp[ny][nx][(q.dir + 3) % 4][q.bs + bsnum][q.s + snum] == INF) {
						dp[ny][nx][(q.dir + 3) % 4][q.bs + bsnum][q.s + snum] = dp[q.y][q.x][q.dir][q.bs][q.s] + 1;
						que.push(state{ ny, nx, (q.dir + 3) % 4, q.bs + bsnum, q.s + snum });
					}
				}

				if (q.dir % 2 == 1) {
					bsnum = 0, snum = 1;
				}
				else {
					bsnum = 1, snum = 0;
				}

				if (q.bs + bsnum <= A && q.s + snum <= A) {
					if (dp[ny][nx][(q.dir + 1) % 4][q.bs + bsnum][q.s + snum] == INF) {
						dp[ny][nx][(q.dir + 1) % 4][q.bs + bsnum][q.s + snum] = dp[q.y][q.x][q.dir][q.bs][q.s] + 1;
						que.push(state{ ny, nx, (q.dir + 1) % 4, q.bs + bsnum, q.s + snum });
					}
				}
			}
		}
	}

	int ans = INF;
	FOR(i, 0, 4) {
		for (int k = 1;; k++) {
			int ny = T.first + dy[i] * k;
			int nx = T.second + dx[i] * k;

			if (0 <= nx && nx < W && 0 <= ny  && ny < H) {
				if (vs[ny][nx] == '#')break;

				if (i == 0 && PII(ny, nx) == S)break;
				//debug(ans);
				FOR(l, 0, A + 1) {
					FOR(m, 0, A + 1) {
						ans = min(ans, dp[ny][nx][(i + 2) % 4][l][m]);
					}
				}
				//debug(ans);
			}
			else break;
		}
	}
	if (ans > 2 * A) {
		cout << -1 << endl;
	}
	else {
		cout << ans << endl;
	}
}