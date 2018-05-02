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

/* -----  2018/05/02  Problem: AOJ 1337 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1337  ----- */
/* ------問題------

2次元平面上に枠がn個与えられる。この平面は何個に分割されるか。ただし枠同士が組み合わさってできる領域もカウントする。

-----問題ここまで----- */
/* -----解説等-----

適当に幅を等間隔で広げた状態で、座標圧縮する。
すると全部舐められる程度の領域がたくさんできるので、愚直にbfsで塗る。

----解説ここまで---- */

void bfs(int y, int x, VVI& masu) {// 点スタートで塗る
	queue<PII>q;
	q.push(PII(y, x));
	masu[y][x] = 1;
	int H = SZ(masu), W = SZ(masu[0]);

	while (!q.empty()) {
		PII p = q.front(); q.pop();
		int yy = p.first, xx = p.second;
		FOR(k, 0, 4) {
			int ny = yy + DY[k], nx = xx + DX[k];
			if (0 <= ny && ny < H && 0 <= nx && nx < W) {
				if (masu[ny][nx] != 1) {
					masu[ny][nx] = 1;
					q.push(PII(ny, nx));
				}
			}
		}
	}
}

LL N;


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	while (cin >> N, N) {

		VVI rect(N, VI(4, 0));// lx,rx, ty,dy
		FOR(i, 0, N) {
			int a, b, c, d;
			cin >> a >> b >> c >> d;
			rect[i] = VI({ 3*a,3 * b,3 * c,3 * d });
		}

		VI xs, ys;
		FOR(i, 0, N) {
			FOR(j, -1, 1 + 1) {
				xs.push_back(rect[i][0] + j);
				xs.push_back(rect[i][2] + j);
				ys.push_back(rect[i][1] + j);
				ys.push_back(rect[i][3] + j);
			}
		}
		VI cx = xs, cy = ys;
		SORT(cx), SORT(cy);
		//UNIQ(cx), UNIQ(cy);
		FOR(i, 0, N) {
			rect[i][0] = lower_bound(ALL(cx), rect[i][0]) - cx.begin();
			rect[i][2] = lower_bound(ALL(cx), rect[i][2]) - cx.begin();
			rect[i][1] = lower_bound(ALL(cy), rect[i][1]) - cy.begin();
			rect[i][3] = lower_bound(ALL(cy), rect[i][3]) - cy.begin();
		}
		// 愚直に塗ってOK
		int W = SZ(xs);
		int H = SZ(ys);
		VVI masu(H, VI(W, 0));
		FOR(i, 0, N) {
			// 枠を塗りつぶす
			{
				int baseyB = rect[i][1], baseyE = rect[i][3];
				FOR(x, rect[i][0], rect[i][2] + 1) {
					masu[baseyB][x] = 1;
					masu[baseyE][x] = 1;
				}
			}
			{
				int basexB = rect[i][0], basexE = rect[i][2];
				FOR(y, rect[i][3], rect[i][1] + 1) {
					masu[y][basexB] = 1;
					masu[y][basexE] = 1;
				}
			}
		}
		LL ans = 0LL;
		FOR(i, 0, H) {
			FOR(j, 0, W) {
				if (masu[i][j] !=1) {
					bfs(i, j, masu);
					ans++;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
