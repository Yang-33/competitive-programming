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

/* -----  2018/06/12  Problem: AOJ 1150 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1150  ----- */
/* ------問題------

17:00, 特別捜査官 Jack が敵のキャンプから脱出を開始した． 最寄りの安全地帯に逃れるには，途中にある崖を登る必要がある． その急な崖はブロックで覆われており， Jack はブロックに足を置きながら崖を登ることになる． 表面が滑りやすいブロックに進むには時間をかける必要があり， もろいブロックは体重で崩れてしまうので避ける必要がある． あなたの使命は，崖を登りきるために必要な最短の時間を求めるプログラムを作成することである．
図 D-1 は，あなたが受け取るであろう崖に関する地形データの例を図示したものである． 崖は，正方形のブロックで覆われており， Jack の崖登りは， 崖下の地面から， 一番下の段の 'S' とマークされたブロックに片足を置くことで開始される． 最初のステップは，左右のどちらの足であっても良い． ブロックにマークされた数字は，そのブロックの「滑りやすさ」を意味する． t (1 ≤ t ≤ 9) とマークされたブロックに足を安全に置くには， t 単位時間が必要となる． 'X' でマークされたブロックには Jack は足を置くことはできない． どちらかの足が，最上段の 'T' とマークされたブロックに到着した時点で崖登り完了で ある．

-----問題ここまで----- */
/* -----解説等-----

前処理をちゃんとやればあとは最短路するだけ。
状態の管理は今どっちの足をついているかをみればよい。

----解説ここまで---- */

int DY[9] = { 2,1,1,0,0,0,-1,-1,-2 };
int DX[9] = { 1,1,2,1,2,3, 1, 2, 1 };

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int W, H;
	while (cin >> W >> H, W) {
		vector<VVI>dist(H, VVI(W, VI(2, INF)));
		VVI masu(H, VI(W));
		using tp = tuple<int, int, int, int>;
		priority_queue<tp, vector<tp>, greater<tp>>q;
		set<PII>ts;
		FOR(i, 0, H) {
			FOR(j, 0, W) {
				char c; cin >> c;
				if (c == 'X') {
					masu[i][j] = INF;
				}
				else if (c == 'S') {
					masu[i][j] = 0;
					dist[i][j][0] = dist[i][j][1] = 0;
					q.push(tp(0, i, j, 0));
					q.push(tp(0, i, j, 1));
				}
				else if (c == 'T') {
					masu[i][j] = 0;
					ts.insert(PII(i, j));
				}
				else {
					masu[i][j] = c - '0';
				}
			}
		}
		LL ans = -1;
		while (!q.empty()) {
			int d, y, x, side;
			tie(d, y, x, side) = q.top(); q.pop();
			if (ts.find(PII(y, x)) != ts.end()) {
				ans = d;
				break;
			}
			if (dist[y][x][side] < d)continue;

			// side to !side
			// cost add nx
			FOR(k, 0, 9) {
				int ny = y + (DY[k]); int nx = x + (side ? -DX[k] : DX[k]);
				if (0 <= ny && ny < H && 0 <= nx && nx < W) {
					if (dist[ny][nx][!side] > dist[y][x][side] + masu[ny][nx]) {
						dist[ny][nx][!side] = dist[y][x][side] + masu[ny][nx];
						q.push(tp(dist[ny][nx][!side], ny, nx, !side));
					}
				}
			}
		}
		cout << ans << "\n";
	}

	return 0;
}
