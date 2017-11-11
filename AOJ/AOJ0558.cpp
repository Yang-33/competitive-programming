#include "bits/stdc++.h"
using namespace std;

using VS = vector<string>;    using LL = long long;
using VI = vector<int>;       using VVI = vector<VI>;
using PII = pair<int, int>;   using PLL = pair<LL, LL>;
using VL = vector<LL>;        using VVL = vector<VL>;

#define ALL(a)  begin((a)),end((a))
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define EB emplace_back
#define MP make_pair
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

/* -----  2017/11/11  Problem: AOJ 0558 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0558  ----- */
/* ------問題------

今年も JOI 町のチーズ工場がチーズの生産を始め，ねずみが巣から顔を出した．JOI 町は東西南北に区画整理されていて，各区画は巣，チーズ工場，障害物，空き地のいずれかである．ねずみは巣から出発して全てのチーズ工場を訪れチーズを 1 個ずつ食べる．
この町には，N 個のチーズ工場があり，どの工場も１種類のチーズだけを生産している．チーズの硬さは工場によって異なっており，硬さ 1 から N までのチーズを生産するチーズ工場がちょうど 1 つずつある．
ねずみの最初の体力は 1 であり，チーズを 1 個食べるごとに体力が 1 増える．ただし，ねずみは自分の体力よりも硬いチーズを食べることはできない．
ねずみは，東西南北に隣り合う区画に 1 分で移動することができるが，障害物の区画には入ることができない．チーズ工場をチーズを食べずに通り過ぎることもできる．すべてのチーズを食べ終えるまでにかかる最短時間を求めるプログラムを書け．ただし，ねずみがチーズを食べるのにかかる時間は無視できる．

-----問題ここまで----- */
/* -----解説等-----

BFS的なのノリで、0->1,1->2の最短距離をだしていけばよい。
その距離の総和が答え。

----解説ここまで---- */

LL H, W, N;

LL ans = 0LL;

int dist(PII s, PII t, VS & masu) {
	VVI d(H, VI(W,INF));
	int sy = s.first, sx = s.second;
	int ty = t.first, tx = t.second;
	queue<PII>q;
	q.push(s);
	d[sy][sx] = 0;
	while (!q.empty()) {
		PII a = q.front(); q.pop();
		int y = a.first, x = a.second;
		FOR(k, 0, 4) {
			int ny = y + DY[k], nx = x + DX[k];
			if (0 <= ny&&ny < H && 0 <= nx&&nx < W && masu[ny][nx] != 'X') {
				if (d[ny][nx] > d[y][x] + 1) {
					d[ny][nx] = d[y][x] + 1;
					q.push(PII(ny, nx));
				}
			}
		}
	}

	return d[ty][tx];
}



int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> H >> W >> N;
	VS masu(H);
	vector<PII>point(N+1);
	FOR(i, 0, H) {
		cin >> masu[i];
		FOR(j, 0, W) {
			if (masu[i][j] == 'S')point[0] = PII(i, j), masu[i][j] = 'S';
			if (isdigit(masu[i][j]))point[masu[i][j] - '0'] = PII(i, j);
		}
	}

	FOR(from, 0, N) {
		ans += dist(point[from], point[from + 1],masu);
	}

	cout << ans << "\n";

	return 0;
}
