#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define FOR(i,s,e) for(int (i) = (s) ;(i) < (e) ;(i)++)
#define debug(x) cout << #x << ": " << x << endl
#define ALL(x) (x).begin(),(x).end()

const int INF = 1e9;
const ll LINF = 1e16;


/* -----  2017/06/27  Problem: ICPC国内予選2010 D / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1165&lang=jp  ----- */
/* ------問題------

テトリス&重心

-----問題ここまで----- */
/* -----解説等-----

がんばる。
あるパーツよりも上のパーツを保持しておき、毎回重心の計算をすればいい。
1時間かかりました。

----解説ここまで---- */

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int W, H;
string masu[100];
/* 一パーツを出す */
vector<pii > getblock(char c, int sy, int sx) {
	vector<pii>res;
	queue<pii>q;
	q.push(pii(sy, sx));
	res.push_back(pii(sy, sx));

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		FOR(k, 0, 4) {
			int ny = y + dy[k];
			int nx = x + dx[k];
			if (!(0 <= nx&&nx < W && 0 <= ny&&ny < H))continue;
			if (masu[ny][nx] == c&&find(res.begin(), res.end(), pii(ny, nx)) == res.end()) {
				q.push(pii(ny, nx));
				res.push_back(pii(ny, nx));
			}
		}
	}
	return res;
}

bool f() {
	FOR(i, 0, H) {
		FOR(j, 0, W) {
			char c = masu[i][j];
			if (c == '.')continue;
			vector<pii>posv = getblock(c, i, j);
			int xl = 100; int xr = -1;
			//パーツのXr,Xlをとる
			FOR(k, 0, posv.size()) {
				int y = posv[k].first;
				int x = posv[k].second;
				if (y == H - 1) {//floor
					xl = min(xl, 2 * x);
					xr = max(xr, 2 * x + 2);
				}
				else {
					if (masu[y + 1][x] != '.'&&masu[y + 1][x] != c) {
						xl = min(xl, 2 * x);
						xr = max(xr, 2 * x + 2);
					}
				}
			}

			// 自身と上のパーツを集める
			vector<pii>upper = posv;
			for (;;) {
				bool fin = 1;
				FOR(k, 0, upper.size()) {
					int y = upper[k].first;
					int x = upper[k].second;
					if (y == 0)continue;
					char ret = masu[y - 1][x];
					if (ret == '.')continue;
					vector<pii>upblock = getblock(ret, y - 1, x);
					if (find(upper.begin(), upper.end(), upblock[0]) == upper.end()) {
						fin = 0;
						FOR(l, 0, upblock.size()) {
							upper.push_back(upblock[l]);
						}
						break;
					}

				}
				if (fin)break;
			}

			int sum = 0;
			FOR(k, 0, upper.size()) {
				sum += 2 * upper[k].second + 1;
			}
			//判定
			if (sum <= xl*upper.size() || sum >= xr*upper.size())return 0;
		}

	}
	return 1;
}

int main() {
	cin.tie(0); ios::sync_with_stdio(false);
	while (1) {
		cin >> W >> H;
		if (W == 0 && H == 0) break;
		FOR(i, 0, H)cin >> masu[i];
		bool flag;
		flag = f();
		if (flag) {
			cout << "STABLE" << endl;
		}
		else {
			cout << "UNSTABLE" << endl;
		}
	}
	return 0;
}