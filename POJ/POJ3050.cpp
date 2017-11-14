#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
#include <cmath>
using namespace std;

typedef vector<string> VS;
typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PII;

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
#define debug(x) cout << #x << ": " << x << endl
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2017/11/15  Problem: POJ 3050 / Link: http://poj.org/problem?id=3050  ----- */
/* ------問題------

盤面を何度訪れていもいいので、6回訪れた経路の文字列は何通りあるか。

-----問題ここまで----- */
/* -----解説等-----

愚直にやる。全探索。

----解説ここまで---- */

LL N;
LL ans = 0LL;

void bfs(int i, int j,const VVI& str, set<int>&se) {
	queue<pair<int, pair<int, PII > > >q;
	q.push(MP(str[i][j], MP(1, MP(i, j))));
	while (!q.empty()) {
		pair<int, pair<int, PII > > a = q.front(); q.pop();
		int ss = a.first; int dep = a.second.first;
		PII p = a.second.second;
		if (dep == 6) {
			se.insert(ss);
			continue;

		}
		FOR(k, 0, 4) {
			int ny = p.first + DY[k], nx = p.second + DX[k];
			if (0 <= ny&&ny < 5 && 0 <= nx&&nx < 5)
				q.push(MP(ss * 10 + str[ny][nx], MP(dep + 1, MP(ny, nx))));
		}
	}
}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	N = 5;
	VVI a(5, VI(5, 0));
	FOR(i, 0, N) {
		FOR(j, 0, N) {
			cin >> a[i][j];
		}
	}

	set<int>se;
	int num;
	FOR(i, 0, N) {
		FOR(j, 0, N) {
			bfs(i, j, a, se);
		}
	}

	ans = SZ(se);
	cout << ans << "\n";

	return 0;
}
