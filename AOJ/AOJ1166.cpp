#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define FOR(i,s,e) for(int (i) = (s) ;(i) < (e) ;(i)++)
#define debug(x) cout << #x << ": " << x << endl
#define ALL(x) (x).begin(),(x).end()

const int INF = 1e9;
const ll LINF = 1e16;
/* -----  2017/06/27  Problem: ICPC‘“à—\‘I2010 B / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1165&lang=jp  ----- */
/* ------–â‘è------

–À˜H‚Ì’Tõ

-----–â‘è‚±‚±‚Ü‚Å----- */
/* -----‰ðà“™-----

Šæ’£‚Á‚Äã‰º¶‰E‚Ì•Ó‚ð’£‚éB
kim‚ª‰ð‚¢‚½B

----‰ðà‚±‚±‚Ü‚Å---- */
int main() {
	cin.tie(0); ios::sync_with_stdio(false);
	while (1) {
		int w, h; cin >> w >> h;
		if (w == 0 && h == 0) break;
		vector<vector<int>> migi(h + 2, vector<int>(w + 2, 1));
		vector<vector<int>> sita(h + 2, vector<int>(w + 2, 1));

		for (int i = 1; i <= h; i++) {
			for (int j1 = 1; j1 <= w-1; j1++) {
				cin >> migi[i][j1];
			}
			migi[i][w] = 1;
			
			for (int j2 = 1; j2 <= w; j2++) {
				if (i != h) {
					cin >> sita[i][j2];
				}
				else {
					sita[i][j2] = 1;
				}
			}
		}
		/*
		for (int i = 0; i <= h+1; i++) {
			for (int j = 0; j <= w+1; j++) {
				cout << migi[i][j] << " ";
			}
			cout << endl;
			for (int j = 0; j <= w+1; j++) {
				cout << sita[i][j] << " ";
			}
			cout << endl;
		}
		*/
		vector<vector<int>> dist(h+2, vector<int>(w+2,INF));
		dist[1][1] = 1;
		queue<pair<int,int>> q;
		q.push({ 1,1 });
		while (!q.empty()) {
			auto p = q.front(); q.pop();
			int x = p.first, y = p.second;

			if (migi[x][y] == 0) {
				if (dist[x][y] + 1 < dist[x][y + 1]) {
					dist[x][y + 1] = dist[x][y] + 1;
					q.push({ x,y + 1 });
				}
			}
			if (sita[x][y] == 0) {
				if (dist[x][y] + 1 < dist[x + 1][y]) {
					dist[x + 1][y] = dist[x][y] + 1;
					q.push({ x + 1,y });
				}
			}
			if (migi[x][y - 1] == 0) {
				if (dist[x][y] + 1 < dist[x][y - 1]) {
					dist[x][y - 1] = dist[x][y] + 1;
					q.push({ x,y - 1 });
				}
			}
			if (sita[x - 1][y] == 0) {
				if (dist[x][y] + 1 < dist[x - 1][y]) {
					dist[x - 1][y] = dist[x][y] + 1;
					q.push({ x - 1,y });
				}
			}
		}

		if (dist[h][w] == INF) {
			cout << 0 << endl;
		}
		else {
			cout << dist[h][w] << endl;
		}
	}
	return 0;
}