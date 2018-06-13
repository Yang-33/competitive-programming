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

/* -----  2018/06/13  Problem: AOJ 2447 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2447  ----- */
/* ------問題------

2階建ての迷路がある。
アルファベットのlower/upperが1/2階に設置してある。それぞれのアルファベットに対して*のマスが1/2階で移動可能/不可能になる。
階段を登る、switchを押す、移動にコスト1だけかかるとき、ゴールまでの最小移動コストを求めよ。

-----問題ここまで----- */
/* -----解説等-----

状態はdist[1/2階][y][x][a...jに対応するbinary]:=最短コスト
遷移がたくさんあるので頑張る
以下に注意：
スイッチを押さなくてもいい(チーム戦のときはよくわからなかった)
初期状態から検索し直すと簡単
わからないけどxorをとると-1になるパターンがあった(ア)

----解説ここまで---- */


int popcount2(int x) {//二進数中のbitが1の数
	int ret = 0;
	while (x) {
		x &= x - 1;
		++ret;
	}
	return ret;
}

int dist[2][50][50][1 << 10];
int masu[2][50][50];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int W, H;
	cin >> W >> H;
	VS m(H);
	FOR(i, 0, H) {
		cin >> m[i];
	}
	int S;
	cin >> S;
	VVI flipboard(H, VI(W, 0));//under 2^10
	FOR(s, 0, S) {
		FOR(i, 0, H) {
			string st; cin >> st;
			FOR(j, 0, W) {
				if (st[j] == '*')flipboard[i][j] |= 1 << s;
			}
		}
	}

	using tp = tuple<int, int, int, int, int>;
	queue<tp>q;
	fill(***dist, ***dist + 2 * 50 * 50 * 1024, INF);
	fill(**masu, **masu + 2 * 50 * 50, -1);

	PII t;
	FOR(i, 0, H) {
		FOR(j, 0, W) {
			if (m[i][j] == '%')q.push(tp(0, 0, i, j, 0)), dist[0][i][j][0] = 0;
			else if (m[i][j] == '&')t = PII(i, j);
		}
	}
	int ans = -1;
	while (!q.empty()) {
		int d, fl, y, x, state;
		tie(d, fl, y, x, state) = q.front(); q.pop();
		if (dist[fl][y][x][state] < d)continue;
		if (PII(y, x) == t) {
			ans = dist[fl][y][x][state];
			break;
		}
		else if (m[y][x] == '|') {
			if (dist[!fl][y][x][state] > dist[fl][y][x][state] + 1) {
				dist[!fl][y][x][state] = dist[fl][y][x][state] + 1;
				q.push(tp(dist[!fl][y][x][state], !fl, y, x, state));
			}
		}
		else if (islower(m[y][x]) || isupper(m[y][x])) {
			// switch
			int c = m[y][x] - (isupper(m[y][x]) ? 'A' : 'a');
			int nstate;
			if (state & (1 << c))nstate = state &~(1 << c);
			else nstate = state | (1 << c);
			int nf = fl;
			if (flipboard[y][x] & 1 << c)nf = !nf;
			if (dist[nf][y][x][nstate] > dist[fl][y][x][state] + 1) {
				dist[nf][y][x][nstate] = dist[fl][y][x][state] + 1;
				q.push(tp(dist[nf][y][x][nstate], nf, y, x, nstate));
			}
		}
		FOR(k, 0, 4) {
			int ny = y + DY[k], nx = x + DX[k];
			if (m[ny][nx] == '#')continue;
			char nc = m[ny][nx];
			int nf = !(nc == '_' || nc == '%' || nc == '&' || islower(nc));
			nf = (nf + popcount2(flipboard[ny][nx] & state)) % 2;
			if (nc == '|')nf = fl;
			if (fl == nf) {
				if (dist[fl][ny][nx][state] > dist[fl][y][x][state] + 1) {
					dist[fl][ny][nx][state] = dist[fl][y][x][state] + 1;
					q.push(tp(dist[fl][ny][nx][state], fl, ny, nx, state));
				}
			}
		}
	}

	cout << ans << "\n";
	return 0;
}
