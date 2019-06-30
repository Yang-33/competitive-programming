#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9;
int masu[100][100];
int dist[100][100];
int d[4] = { 1,0,-1,0 };
int main() {
	int N;
	while (cin >> N, N) {
		fill(*masu, *masu + 100 * 100, 1);

		int A, B, C, D; cin >> A >> B >> C >> D;
		A--; B--; C--; D--;
		for (int x = A; x <= C; x++) {
			for (int y = B; y <= D; y++) {
				masu[x][y] = 0;
			}
		}

		int ans = 0;
		int X, Y; cin >> X >> Y;
		X--; Y--;
		for (int i = 0; i < N; i++) {
			int nextX, nextY; cin >> nextX >> nextY;
			nextX--; nextY--;

			fill(*dist, *dist + 100 * 100, INF);
			queue<pii> q;
			q.push({ X,Y });
			dist[X][Y] = 0;
			while (q.size()) {
				int nx, ny; tie(nx, ny) = q.front(); q.pop();
				for (int k = 0; k < 4; k++) {
					int nnx = nx + d[k];
					int nny = ny + d[k ^ 1];

					if (nnx < 0 || nnx >= 100 || nny < 0 || nny >= 100) continue;
					if (dist[nnx][nny] > dist[nx][ny] + masu[nnx][nny]) {
						dist[nnx][nny] = dist[nx][ny] + masu[nnx][nny];
						q.push({ nnx,nny });
					}
				}
			}
			ans += dist[nextX][nextY];
			X = nextX;
			Y = nextY;
		}
		cout << ans << endl;
	}
}