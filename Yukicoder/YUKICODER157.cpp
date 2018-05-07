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

/* -----  2018/05/07  Problem: yukicoder 157  / Link: http://yukicoder.me/problems/no/157  ----- */
/* ------問題------

壁'#'と空洞'.'からなる横の幅がW、縦の幅がHの空間がある。
調べたところ壁の中に空洞のかたまりが2つあることがわかった。
壁'#'をいくつかどけることで2つの空洞のかたまりをつなげたい。
最小でいくつの壁'#'をどければ良いかを答えよ。

-----問題ここまで----- */
/* -----解説等-----

まず、片側を適当な色で塗る。
別のサイドから、適当な色までの最短距離を求めれば良い。

----解説ここまで---- */




void bfs(int y, int x, VS& s) {
	int H = SZ(s), W = SZ(s[0]);
	queue<PII>q;
	q.push(PII(y, x));
	s[y][x] = 'T';
	while (!q.empty()) {
		int i, j;
		tie(i, j) = q.front(); q.pop();
		FOR(k, 0, 4) {
			int ny = i + DY[k], nx = j + DX[k];
			if (0 <= ny&&ny < H && 0 <= nx&&nx < W && s[ny][nx] == '.') {
				s[ny][nx] = 'T';
				q.push(PII(ny, nx));
			}
		}
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int W, H; cin >> W >> H;
	VS s(H);
	FOR(i, 0, H) {
		cin >> s[i];
	}

	int f = 0;
	FOR(i, 0, H) {
		FOR(j, 0, W) {
			if (f)continue;
			if (s[i][j] == '.') {
				bfs(i, j, s);
				f = 1;
			}
		}
	}
	int ans = 100;
	queue<PII>q;
	VVI dist(H, VI(W, INF));
	FOR(i, 0, H) {
		FOR(j, 0, W) {
			if (s[i][j] == '.')q.push(PII(i, j)), dist[i][j] = 0;
		}
	}
	while (!q.empty()) {
		int y, x;
		tie(y, x) = q.front(); q.pop();
		FOR(k, 0, 4) {
			int ny = y + DY[k], nx = x + DX[k];
			if (0 <= ny&&ny < H && 0 <= nx&&nx < W) {

				if (dist[ny][nx] > dist[y][x] + 1) {
					dist[ny][nx] = dist[y][x] + 1;
					q.push(PII(ny, nx));

				}
				if (s[ny][nx] == 'T') {
					ans = min(ans, dist[ny][nx]);
				}
			}
		}
	}

	cout << ans - 1 << "\n";

	return 0;
}
