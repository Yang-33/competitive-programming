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

/* -----  2018/10/02  Problem: yukicoder 323  / Link: http://yukicoder.me/problems/no/323  ----- */
/* ------問題------

太郎君は長方形の空き地で雪だるまを作っていて、今は雪球を転がしているところです。

空き地をH行,W列のマス目で表します。第i(0≤i≤H−1)行、第j(0≤j≤W−1)列のマスをマス(i,j)と呼びます。

はじめ、雪球はマス(Si,Sj)にあり、その大きさはAです。
太郎君は雪球を上下左右いずれかの隣接したマスに移動させることができます。ただし空き地の外に出てはいけません。
このとき、移動先のマスに雪が積もっていれば雪球の大きさは1増え、そうでなければ雪球の大きさは1減ります。
雪球の大きさが0以下になると、雪球は溶けてしまいます。つまり、雪球の大きさは常に1以上でなければなりません。

太郎君が雪球の大きさをちょうどBにしてマス(Gi,Gj)に運ぶことが可能か判定してください。

-----問題ここまで----- */
/* -----解説等-----

上限全くわからないけど、盤面が小さいの適当に幅優先探索を書けば良い

----解説ここまで---- */

LL ans = 0LL;
bool d[3003][51][51];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int H, W; cin >> H >> W;
	int A; PII s; cin >> A >> s.first >> s.second;
	int B; PII t; cin >> B >> t.first >> t.second;
	VS vs(H);
	FOR(i, 0, H) {
		cin >> vs[i];
	}

	const int Max = 2000;
	auto f = [&]() {

		using tp = tuple<int, int, int>;
		queue<tp>q;
		d[A][s.first][s.second] = 1;
		q.push(tp(A, s.first, s.second));
		while (!q.empty()) {
			int dist, y, x;
			tie(dist, y, x) = q.front(); q.pop();

#define IN(a,b,c) (a<=b&&b<c)
			FOR(k, 0, 4) {
				int ny = y + DY[k], nx = x + DX[k];
				if (IN(0, ny, H) && IN(0, nx, W)) {
					int c = (vs[ny][nx] == '*' ? 1 : -1);
					int nd = dist + c;
					if (nd > Max || nd <= 0)continue;
					if (!d[nd][ny][nx]) {
						d[nd][ny][nx] = 1;
						q.push(tp(nd, ny, nx));
						if (nd == B && PII(ny, nx) == t) { return 1; }
					}
				}
			}

		}
		return 0;
	};
	ans = f();
	cout << (ans ? "Yes" : "No") << "\n";

	return 0;
}
