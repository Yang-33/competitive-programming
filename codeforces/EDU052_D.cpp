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

/* -----  2018/10/11  Problem: EDU052 D / Link: __CONTEST_URL__  ----- */
/* ------問題------

i->i+1への遷移をN*Nまで繰り返す。ただし遷移はナイト、ルーク、ビショップのみ。
移動コストはそれぞれ同等で、また1ターン使用することでコマを変更することができる。
この時、移動コストと交換回数を最小化したときの答えは?

-----問題ここまで----- */
/* -----解説等-----

なぜ枝刈りし始めたのか謎...
あるあるダイクストラでは?
時間に余裕があるので1マスごとに移動して良い。

----解説ここまで---- */

PII dist[102][11][11][3];

int main() {

	int N; cin >> N;
	VVI a(N, VI(N));
	fill(***dist, ***dist + 102 * 11 * 11 * 3, PII(INF, INF));
	using  tp = tuple<PII, int, int, int, int>;
	priority_queue<tp, vector<tp>, greater<tp>>pq;
	auto PUSH = [&](int num, int i, int j, int t, PII val) {
		if (dist[num][i][j][t] > val) {
			dist[num][i][j][t] = val;
			pq.push(tp(val, num, i, j, t));
		}
	};

	FOR(i, 0, N) {
		FOR(j, 0, N) {
			cin >> a[i][j];
			a[i][j]--;
			if (a[i][j] == 0) {
				FOR(k, 0, 3) {
					PUSH(0, i, j, k, PII(0, 0));
				}
			}
		}
	}
#define IN(n) (0<=n&&n<N)
	const int NY[8] = { 1,2,2,1, -1,-2,-2,-1 };
	const int NX[8] = { -2,-1,1,2, 2,1,-1,-2 };
	const int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };
	const int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };
	while (!pq.empty()) {
		PII cd; int cn, cy, cx, ct;
		tie(cd, cn, cy, cx, ct) = pq.top(); pq.pop();
		// 必ず値をコピーして使う
		if (ct == 0) { // Knight
			FOR(k, 0, 8) {
				PII nd(cd);
				nd.first += 1;
				int ny = cy + NY[k], nx = cx + NX[k];
				int nt(ct);
				if (IN(ny)&IN(nx)) {
					int nn = cn + (a[ny][nx] == cn + 1);
					PUSH(nn, ny, nx, nt, nd);
				}
			}
		}
		else if (ct == 1) { // Rook(0..3)
			FOR(W, 0, N) {
				FOR(k, 0, 4) {
					PII nd(cd);
					nd.first += 1;
					int ny = cy + DY[k] * W, nx = cx + DX[k] * W;
					int nt(ct);
					if (IN(ny)&IN(nx)) {
						int nn = cn + (a[ny][nx] == cn + 1);
						PUSH(nn, ny, nx, nt, nd);
					}

				}
			}
		}
		else if (ct == 2) { // Bishop(4..7)
			FOR(W, 0, N) {
				FOR(k, 4, 8) {
					PII nd(cd);
					nd.first += 1;
					int ny = cy + DY[k] * W, nx = cx + DX[k] * W;
					int nt(ct);
					if (IN(ny)&IN(nx)) {
						int nn = cn + (a[ny][nx] == cn + 1);
						PUSH(nn, ny, nx, nt, nd);
					}

				}
			}

		}

		// replace
		FOR(i, 0, 3) {
			if (i == ct)continue;
			PII d(cd);
			d.first += 1;
			d.second += 1;
			PUSH(cn, cy, cx, i, d);
		}
	}
	PII ans = PII(INF, INF);
	FOR(i, 0, 3) {
		FOR(y, 0, N) {
			FOR(x, 0, N) {
				ans = min(ans, dist[N*N - 1][y][x][i]);
			}
		}
	}
	cout << ans.first << " " << ans.second << endl;


	return 0;
}
