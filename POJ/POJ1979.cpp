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
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
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
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2017/11/10  Problem: POJ 1979 / Link: http://poj.org/problem?id=1979  ----- */
/* ------問題------

H*Wの盤面が与えられる。
"#",".","@"があり、@は始点、#は障害物、.はマスである。
始点から到達しうるマスは何マスか。


-----問題ここまで----- */
/* -----解説等-----

BFS!

----解説ここまで---- */



int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);


	LL H, W;


	while (cin >> W >> H, W) {
		LL ans = 0LL;

		VS masu(H);
		VVI visit(H, VI(W, 0));
		int sy, sx;
		FOR(i, 0, H) {
			cin >> masu[i];
			FOR(j, 0, W) {
				if (masu[i][j] == '@') {
					sy = i;
					sx = j;
					ans++;
				}
			}
		}

		queue<PII>q;
		q.push(PII(sy, sx));

		visit[sy][sx] = 1;

#define IN(y,x) (0<=y&&y<H&&0<=x&&x<W)

		while (!q.empty()) {
			PII a = q.front(); q.pop();
			int oy = a.first, ox = a.second;
			FOR(k, 0, 4) {
				int ny = oy + DY[k], nx = ox + DX[k];
				if (IN(ny, nx) && masu[ny][nx] == '.'&&visit[ny][nx]==0) {
					visit[ny][nx] = 1;
					ans++;
					q.push(PII(ny, nx));
				}
			}


		}

		cout << ans << "\n";
	}
	return 0;
}
