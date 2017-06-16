#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
#define FOR(i, s, e) for (ll(i) = (s); (i) < (e); (i)++)
const int INF = 1e9;
int dx[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2017/04/24  Problem: JOI予選 2014 5  / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0612  ----- */
/* ------問題------

みて

-----問題ここまで----- */
/* -----解説等-----

最初は何も考えずに逐次更新の方針で書いていたが必ずしも10回で状態の更新ができなくなるわけではないことにTLEしてから気がついた。
みるべきは各点は10回以内の更新で壊れるということで、'.'が与える影響を周りの点に伝播してあげればよい。
そうすることでかならず各点について１０回以内の更新で壊れる回数がわかる。
状態は((座標),いつ壊れるか)を持てばよさそう。
壊れる点を取り出して周りの点に加算していけばよい。

----解説ここまで---- */

struct State {
	int i, j, time;
};

int H, W;
char C[1005][1005];
int G[1005][1005];

int main() {

	cin.tie(0);
	ios_base::sync_with_stdio(false);


	cin >> H >> W;
	FOR(i, 0, H) {
		FOR(j, 0, W) {
			cin >> C[i][j];
		}
	}

	memset(G, 0, sizeof(G));
	queue<State> que;
	FOR(i, 0, H) {
		FOR(j, 0, W) {
			if (C[i][j] == '.') {
				G[i][j] = INF;
				continue;
			}
			FOR(k, 0, 8) {
				int ni = i + dy[k];
				int nj = j + dx[k];
				if (C[ni][nj] == '.') G[i][j]++;
			}
			if (G[i][j] >= C[i][j] - '0') {
				que.push({ i, j, 1 });
			}
		}
	}
	int res = 0;
	while (!que.empty()) {
		State s = que.front(); que.pop();
		res = s.time;
		FOR(k, 0, 8) {
			int ni = s.i + dy[k];
			int nj = s.j + dx[k];
			if (G[ni][nj] >= C[ni][nj] - '0') continue;
			G[ni][nj]++;
			if (G[ni][nj] >= C[ni][nj] - '0') {
				que.push({ ni, nj, s.time + 1 });
			}
		}
	}
	cout << res << endl;
	return 0;
}