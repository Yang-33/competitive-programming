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

/* -----  2018/06/30  Problem: AOJ 2577 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/2577  ----- */
/* ------問題------

世間ではXだとかYだとかで騒がしいけれど、これからの時代は"D"である。"パクリンモンスターD"は、秘密結社"R団"によって開発された"Dマシン"を使って"Dのひと"が財宝探索を行う大人気ゲームである。
このゲームでは、格子状マップのあるマスにいるDのひとが、隣接する上下左右のマスへの移動を繰り返し、財宝が存在するマスへの到達を目指す。 マップ上には財宝が存在するマスが1つだけある。 財宝が存在するマスは明らかにされていないため、Dマシンを使って存在する財宝のマスを絞り込んでから、財宝が存在するマスへ移動したい。
Dマシンを使うと、財宝が存在するマスを含む複数マスへの反応を示す。反応は、Dマシンを使ったときにDのひとが居たマスを基準に表現される。ただし、Dマシンは壊れていることがあり、Dマシンを使ったときに、財宝が存在し得ないマスへの反応を示すことがある。また、Dのひとが移動できない壁マスがマップ上に存在するため、財宝の存在するマスに移動できないこともある。DのひとはいろいろなマスでDマシンを使い、その反応を観測した。Dのひとは、財宝の存在するマスに到達できるだろうか。

-----問題ここまで----- */
/* -----解説等-----

やる(問題文…)

----解説ここまで---- */


int dy[] = { 0, -1, 0, 1 };
int dx[] = { -1, 0, 1, 0 };
void solve() {
	int H, W, D, N;
	cin >> H >> W >> D >> N;
	vector<string> t(H);
	FOR(i, 0, H) {
		cin >> t[i];
	}
	vector<int>r(D + 2);
	FOR(i, 0, D) {
		cin >> r[i + 1];
	}
	r[0] = -1;
	r[D + 1] = 1e9;
	vector<vector<int>>c(H, vector<int>(W));
	FOR(i, 0, H) {
		FOR(j, 0, W) {
			c[i][j] = 1;
		}
	}
	FOR(i, 0, H) {
		FOR(j, 0, W) {
			if (t[i][j] == '#')
				c[i][j] = false;
		}
	}
	FOR(kim, 0, N) {
		int x, y, s;
		cin >> x >> y >> s;
		FOR(i, 0, H) {
			FOR(j, 0, W) {
				int dx = abs(x - j);
				int dy = abs(y - i);
				if (r[s + 1] < dx || r[s + 1] < dy || (dx <= r[s] && dy <= r[s]))
					c[i][j] = false;
			}
		}
	}
	bool broken = true;
	FOR(i, 0, H) {
		FOR(j, 0, W) {
			if (c[i][j]) {
				broken = false;
			}
		}
	}
	if (broken) {
		cout << "Broken" << endl;
		return;
	}
	queue<pair<int, int> > que;
	FOR(i, 0, H) {
		FOR(j, 0, W) {
			if (t[i][j] == 'D')
				que.push(make_pair(i, j));
		}
	}
	while (!que.empty()) {
		pair<int, int> now = que.front();
		que.pop();
		if (now.first < 0 || H <= now.first || now.second < 0 || W <= now.second) continue;
		if (t[now.first][now.second] == '#') continue;
		t[now.first][now.second] = '#';
		FOR(k, 0, 4) {
			que.push(make_pair(now.first + dy[k], now.second + dx[k]));
		}
	}
	bool yes = true;
	bool no = true;
	FOR(i, 0, H) {
		FOR(j, 0, W) {
			if (c[i][j]) {
				if (t[i][j] == '#') no = false;
				else yes = false;
			}
		}
	}
	if (yes) {
		cout << "Yes" << endl;
	}
	else if (no) {
		cout << "No" << endl;
	}
	else {
		cout << "Unknown" << endl;
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	solve();

	return 0;
}