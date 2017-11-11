#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <set>
#include <sstream>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <climits>
#include <list>
#include <fstream>
using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef vector<string> VS;

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
int DX[9] = { 0, 0, 1, -1,0 ,1, 1, -1, -1 };    int DY[9] = { 1, -1, 0, 0,0, 1, -1, 1, -1 };

/* -----  2017/11/11  Problem: POJ 3669 / Link: http://poj.org/problem?id=3669  ----- */
/* ------問題------

流星群が時刻Tに(x,y)へふってきて、マンハッタン距離が1までの場所は、T秒後はいけなくなる。
0,0にいるあなたは何秒後に絶対安全といえる場所に行くことができるか。

-----問題ここまで----- */
/* -----解説等-----

以降立ち入ることのできない時刻を盤面に記録した後、その後別の盤面からこれを参照しつつ、BFSをやればよい。
問題には明示されていないが、
300,300よりも広い場所に逃げれることがあるので注意

----解説ここまで---- */

LL N;
int W = 400;
int H = 400;
LL ans = 0LL;
bool IN(int y, int x) { return (0 <= x&&x < W && 0 <= y&&y < H); }


int bfs(VVI &den) {
	if (den[0][0] == INF)return 0;

	VVI dist(H, VI(W, -1));
	queue<PII>q;
	if (den[0][0] > 0) {
		q.push(PII(0, 0));
		dist[0][0] = 0;
	}
	while (!q.empty()) {
		PII a = q.front(); q.pop();
		int y = a.first, x = a.second;
		FOR(k, 0, 4) {
			int ny = y + DY[k], nx = x + DX[k];
			if (IN(ny, nx) && dist[ny][nx] == -1&&den[ny][nx]>dist[y][x]+1) {
				dist[ny][nx] = dist[y][x] + 1;
				if (den[ny][nx] == INF)return dist[ny][nx];
				q.push(PII(ny, nx));
			}
		}
	}

	return -1;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	VVI den(H, VI(W, INF));
	cin >> N;
	FOR(i, 0, N) {
		int x, y, t; cin >> x >> y >> t;
		FOR(k, 0, 5) {
			int ny = y + DY[k], nx = x + DX[k];
			if (IN(ny,nx)){
				den[ny][nx] = min(den[ny][nx], t);
			}
		}
	}
	ans = bfs(den);
	cout << ans << "\n";

	return 0;
}
