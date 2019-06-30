#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9;

int dx[8] = { 1,1,1,0,-1,-1,-1,0 };
int dy[8] = { -1,0,1,1,1,0,-1,-1 };

ll calc(ll x, ll y) {
	if (x == 0 && y == 0) return 0;
	for (int k = 0; k < 8; k++) {
		if (dx[k] == x && dy[k] == y) {
			return 1;
		}
	}

	x = abs(x); y = abs(y);
	if (x % 2 == 0 && y % 2 == 0) {
		return x + y;
	}
	else if (x % 2 == 1 && y % 2 == 1) {
		return x + y - 1;
	}
	else {
		if (x == 0 || y == 0) {
			return x + y + 1;
		}
		return x + y;
	}
}

ll dist[100][100][100][100];
ll text(ll x, ll y) {
	ll base = 50;
	x = abs(x) + base; y = abs(y) + base;
	ll nx = base, ny = base;
	fill(***dist, ***dist + 100 * 100 * 100 * 100, INF);
	using Item = tuple<ll, ll, ll, ll>;
	queue<Item> q;
	q.push(Item(nx, ny, -1, -1));
	dist[nx][ny][0][0] = 0;
	while (q.size()) {
		ll nowx, nowy, tx, ty;
		tie(nowx, nowy, tx, ty) = q.front(); q.pop();
		for (int k = 0; k < 8; k++) {
			ll nextx = nowx + dx[k];
			ll nexty = nowy + dy[k];

			if (nextx < 5 || nextx >= 95 || nexty < 5 || nexty >= 95) {
				continue;
			}
			bool ng = false;
			if (nextx == tx && nexty == ty) ng = true;
			for (int kk = 0; kk < 8; kk++) {
				if (nextx == tx + dx[kk] && nexty == ty + dy[kk]) {
					ng = true;
				}
			}
			if (ng) continue;
			ll nexttx = nextx + dx[k];
			ll nextty = nexty + dy[k];
			if (dist[nextx][nexty][nexttx][nextty] > dist[nowx][nowy][tx][ty] + 1) {
				dist[nextx][nexty][nexttx][nextty] = dist[nowx][nowy][tx][ty] + 1;
				q.push(Item(nextx, nexty, nexttx, nextty));
			}
		}
	}
	ll ans = INF;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			ans = min(ans, dist[x][y][i][j]);
		}
	}
	return ans;
}
int main() {
	ll x, y;
	while (cin >> x >> y) {
		//cout << text(x, y) << endl;
		cout << calc(x, y) << endl;
	}
}