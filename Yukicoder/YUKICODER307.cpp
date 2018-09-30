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

/* -----  2018/09/30  Problem: yukicoder 307  / Link: http://yukicoder.me/problems/no/307  ----- */
/* ------問題------

縦Hマス、横Wマスの方眼紙のマスを2色のインクで塗りつぶすことを考えます。

上から数えてR行目、左から数えてC列目のマスを(R,C)と表記します。 一番左上は(1,1)、一番右下は(H,W)です。
マス(R,C)ははじめ、色AR,Cで塗られています。

あるマス(R,C)と、それに隣接するマス(R′,C′)は、2つのマスが同色であるとき、 「(R,C)と(R′,C′)は連結である」とします。
また、(R,C)と(R′,C′)が連結で、かつ、(R′,C′)と(R′′,C′′)が連結であるとき、 (R,C)と(R′′,C′′)も連結であるとします。
ここで「隣接する」とは、(R,C)と(R′,C′)の マンハッタン距離が1 である場合、 即ち(R′,C′) が (R+1,C),(R−1,C),(R,C+1),(R,C−1)のいずれかである場合を指します。
「マス(R,C)と連結である全てのマスを 色X で塗りつぶす」というクエリがQ個与えられます。
Q回の塗りつぶしを終えた後の方眼紙の各マスの色を出力してください。

要するにペイントソフトの「塗りつぶし」機能です。

-----問題ここまで----- */
/* -----解説等-----



----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int H, W; cin >> H >> W;
	VVI a(H, VI(W));
	FOR(i, 0, H) {
		FOR(j, 0, W) {
			cin >> a[i][j];
		}
	}
	int Q; cin >> Q;
	int f = 0;
	FOR(i, 0, Q) {
		int r, c, x; cin >> r >> c >> x;
		r--, c--;
		// comp(r,c) = x

		if (a[r][c] == x || (f&&i != Q - 1))continue;
		if (f && i == Q - 1) {
			a = VVI(H, VI(W, x)); break;
		}

		int cnt = 1;
		queue<PII>q;
		a[r][c] = x;
		q.push(PII(r, c));
		while (!q.empty()) {
			PII pos = q.front(); q.pop();
			FOR(k, 0, 4) {
				int ny = pos.first + DY[k], nx = pos.second + DX[k];
				if (0 <= ny && ny < H && 0 <= nx && nx < W) {
					if (a[ny][nx] != x) {
						a[ny][nx] = x;
						cnt++;
						q.push(PII(ny, nx));
					}
				}
			}
		}
		if (cnt == H * W)f = 1;
	}

	FOR(i, 0, H) {
		FOR(j, 0, W) {
			cout << a[i][j] << " \n"[j == W - 1];
		}
	}


	return 0;
}
