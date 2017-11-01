#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define FOR(i,s,e) for(int i = s;i < e;i++)
#define debug(x) cout << #x << ": " << x << endl
const int INF = 1e9;
const ll LINF = (1LL << 60);
/* -----  2017/11/01  Problem: AOJ1140  / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1140&lang=jp  ----- */
/* ------問題------

家具が複数配置された長方形の部屋の床を掃除するロボットの経路計画を 行いたい．

掃除する床をロボットの大きさ（1 × 1）で分割したタイル平面を考える． そこには「きれいなタイル」と「汚れたタイル」があり，掃除ロボットが 「汚れたタイル」に乗ることで，きれいなタイルにすることができる． 部屋のいくつかのタイルには障害物（家具）が乗っており，ロボットはそれらのタイルに入ることはできない． ロボットは1回の移動で東西南北に1タイルのみ移動できる． ロボットは同じタイルに2回以上行ってもよい．

このとき部屋の「汚れたタイル」すべてを「きれいなタイル」にすることが 可能ならば，それに必要な最少移動回数を求めよ．

-----問題ここまで----- */
/* -----解説等-----

パット見経路探索だが、何回も距離の計算をするのは無駄。したがって保存する。
ゴミに番号を振っておけばこれは巡回セールスマン問題っぽい感じになるのであとはbitDPをすればよい。

----解説ここまで---- */

int W, H;
int masu[22][22];
int d[11][11];
int dp[1 << 11][11];
vector<pii>info;
string m[21];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };


int dist(int s, int t) { //infoの番号
	FOR(i, 0, 22)FOR(j, 0, 22)masu[i][j] = INF;

	int res = 0;

	queue<pii>q; q.push(pii(info[s]));
	masu[info[s].first][info[s].second] = 0;

	while (!q.empty()) {
		pii a = q.front(); q.pop();

		FOR(k, 0, 4) {
			int nx = a.second + dx[k]; int ny = a.first + dy[k];
			if (0 <= nx&&nx < W && 0 <= ny&&ny < H) {
				if (m[ny][nx] == 'x')continue;
				if (masu[ny][nx] > masu[a.first][a.second] + 1) {
					masu[ny][nx] = masu[a.first][a.second] + 1;
					q.push(pii(ny, nx));
				}
			}
		}
	}

	res = masu[info[t].first][info[t].second];
	return res;
}

int main() {
	cin.tie(0); ios::sync_with_stdio(false);
	while (1) {
		cin >> W >> H;
		if (W == 0 && H == 0)break;
		FOR(i, 0, 21)m[i].clear();
		FOR(i, 0, 11)FOR(j, 0, 11)d[i][j] = INF;
		FOR(j, 0, 11)FOR(i, 0, 1 << 11)dp[i][j] = INF;
		info.clear();

		FOR(i, 0, H) {
			cin >> m[i];
		}
		int c = 0;
		FOR(i, 0, H)FOR(j, 0, W)if (m[i][j] == 'o') { m[i][j] = c, c++; info.push_back(pii(i, j)); }
		FOR(i, 0, H) {
			FOR(j, 0, W) {
				if (m[i][j] == '*') {
					m[i][j] = c, c++;
					info.push_back(pii(i, j));
				}
			}
		}
		//table作成
		FOR(i, 0, info.size()) {
			FOR(j, i + 1, info.size()) {
				d[i][j] = d[j][i] = dist(i, j);
			}
		}

		dp[1][0] = 0;
		c = info.size();



		FOR(i, 0, 1 << c) {
			FOR(j, 0, c) {
				if ((i&(1 << j))) {
					FOR(k, 0, c) {
						if ((i&(1 << k)) == 0) {
							dp[i | (1 << k)][k] = min(dp[i | (1 << k)][k], dp[i][j] + d[j][k]);
						}
					}
				}
			}
		}
		int ans = INF;
		FOR(i, 1, c) {
			ans = min(ans, dp[(1 << c) - 1][i]);
		}
		cout << ((ans == INF) ? -1 : ans) << endl;
	}
	return 0;
}