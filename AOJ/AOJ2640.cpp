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

/* -----  2018/06/10  Problem: AOJ 2640 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2640  ----- */
/* ------問題------

A さんと B 君は，N × M の長方形のマス目状の地域に住んでいる．各マス目は道か壁か家のどれかである．この地域は，道が複雑で入り組んでいるので痴漢被害がよく起こることで有名であるため，この地域と外部との境界は全て壁で囲まれており，隔離されている．
B 君はなんとなく気が向いたので，A さんの家を眺めに行くことにした．しかし，不幸なことにB 君は明らかに怪しい顔をしているので，A さんの家に行く途中に少しでも痴漢の疑いがあるような行動を取ったらすぐに捕まってしまうだろう．特に，右手を壁から離して歩くことは絶対にやってはならない．B 君は，一瞬たりとも右手を離すことなく，A さんの家に辿り着くことが出来るだろうか？
B 君はつねに上下左右いずれかの方向を向いていて，B 君の右手が届く範囲はB 君の向いている方向に対して正面，斜め右前，右，斜め右後ろの4 マスのみである．B 君は，次のいずれかの行動を繰り返す．ただし，これらを同時に行うことは出来ない．

前方に壁がない場合，1 マス進む．
向いている方向を90 度右に変える．
向いている方向を90 度左に変える．
右手が接するマスを変える．ただし，この時にB 君は右手を離すことが出来ないので，変更前のマスと変更後のマスの間には共通した点を持っていなくてはならない．

-----問題ここまで----- */
/* -----解説等-----

最短路上で向きと手の位置を保持すれば良い。
それでいいのだけど、実装が無限に辛い
queueでやるので経路保存までしてたどる。

----解説ここまで---- */


struct State {
	int d, x, y, dir, hand;
	State() {}
	State(int d, int x, int y, int dir, int hand) :
		d(d), x(x), y(y), dir(dir), hand(hand) {}
	bool operator < (const State &s)const {
		return d > s.d;
	}
	bool operator == (const State &s)const {
		if (x != s.x) return 0;
		if (y != s.y) return 0;
		if (dir != s.dir) return 0;
		if (hand != s.hand) return 0;
		return 1;
	}
};

int H, W, _dir, sx, sy, gx, gy;
char field[55][55];
const int dx[] = { -1,0,1,0 };
const int dy[] = { 0,-1,0,1 };
const int dx2[4][4] = { { -1,-1,0,-1 },{ 0,1,1,1 },{ 1,1,0,-1 },{ 0,-1,-1,-1 } };
const int dy2[4][4] = { { 0,-1,-1,-1 },{ -1,-1,0,1 },{ 0,1,1,1 },{ 1,1,0,-1 } };

int getDir(char ch) {
	if (ch == '<') return 0;
	if (ch == '^') return 1;
	if (ch == '>') return 2;
	if (ch == 'v') return 3;
	return -1;
}

bool inField(int x, int y) {
	return (0 <= x && x < W && 0 <= y && y < H);
}
int d[55][55][4][4];

int solve() {
	State prev[55][55][4][4], gs;
	fill(***d, ***d + 55 * 55 * 4 * 4, INF);
	d[sy][sx][_dir][2] = 0;
	memset(prev, -1, sizeof(prev));
	priority_queue<State> Q;
	Q.push(State(0, sx, sy, _dir, 2));

	State ss = State(0, sx, sy, _dir, 2);
	bool can = false;

	while (!Q.empty()) {
		State s = Q.top(); Q.pop();
		int x = s.x, y = s.y, dir = s.dir, h = s.hand;
		if (x == gx && y == gy) {
			can = true; gs = s;
			break;
		}
		int ncost = d[y][x][dir][h] + 1;
		int nx = x + dx[dir], ny = y + dy[dir];
		if (inField(nx, ny) && field[ny][nx] != '#' && (h == 1 || h == 2)) {
			int nh = (h == 1 ? 2 : 3);
			if (ncost < d[ny][nx][dir][nh]) {
				d[ny][nx][dir][nh] = ncost;
				prev[ny][nx][dir][nh] = s;
				Q.push(State(ncost, nx, ny, dir, nh));
			}
		}

		int ndir = (dir + 1) % 4;
		if (h >= 2) {
			int nh = (h == 2 ? 0 : 1);
			if (ncost < d[y][x][ndir][nh]) {
				d[y][x][ndir][nh] = ncost;
				prev[y][x][ndir][nh] = s;
				Q.push(State(ncost, x, y, ndir, nh));
			}
		}

		ndir = (dir - 1 + 4) % 4;
		if (h <= 1) {
			int nh = (h == 0 ? 2 : 3);
			if (ncost < d[y][x][ndir][nh]) {
				d[y][x][ndir][nh] = ncost;
				prev[y][x][ndir][nh] = s;
				Q.push(State(ncost, x, y, ndir, nh));
			}
		}

		for (int i = 0; i < 4; i++) {
			if (abs(h - i) != 1 && !((i == 0 && h == 2) || (i == 2 && h == 0))) continue;
			int nx = x + dx2[dir][i];
			int ny = y + dy2[dir][i];
			if (!inField(nx, ny) || field[ny][nx] == '#') {
				if (ncost < d[y][x][dir][i]) {
					d[y][x][dir][i] = ncost;
					prev[y][x][dir][i] = s;
					Q.push(State(ncost, x, y, dir, i));
				}
			}
		}
	}

	if (!can) return -1;
	set<PII> st;
	for (;;) {
		int x = gs.x, y = gs.y, dir = gs.dir, h = gs.hand;
		st.insert(PII(x, y));
		if (gs == ss) break;
		gs = prev[y][x][dir][h];
	}
	return (st.size());
}

int main() {
	bool found = 0;
	cin >> H >> W;
	_dir = -1;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> field[i][j];
			_dir = max(_dir, getDir(field[i][j]));
			if (_dir >= 0 && !found) {
				found = 1;
				sx = j; sy = i;
			}
			if (field[i][j] == 'G') {
				field[i][j] = '.';
				gx = j; gy = i;
			}
		}
	}
	cout << solve() << endl;
	return 0;
}