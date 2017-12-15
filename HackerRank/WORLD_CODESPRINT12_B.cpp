#include <bits/stdc++.h>
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

/* -----  2017/12/15  Problem: world_codesprint12 B / Link: __CONTEST_URL__  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----



----解説ここまで---- */

int DX[6] = {-1, 1, 2, 1, -1, -2};    int DY[6] = { -2,-2, 0, 2, 2, 0};
inline bool IN(int y, int x, int H, int W) { return (0 <= y&&y < H && 0 <= x&&x < W); }

pair<int,VS> bfs2D(pair<int, int> s, pair<int, int> t, int Height, int Width) {
	vector<vector<int> > d(Height, vector<int>(Width, 1e9));
	vector<vector<int> > prev(Height, vector<int>(Width, -1));


	d[s.first][s.second] = 0;
	queue<pair<int, pair<int, int>>>q;
	q.push(make_pair(0, s));

	while (!q.empty()) {
		pair<int, pair<int, int>>a = q.front(); q.pop();
		int dist = a.first; pair<int, int> pos = a.second;
		if (d[pos.first][pos.second] < dist)continue;
		FOR(k, 0, 6) {
			int ny = pos.first + DY[k]; int nx = pos.second + DX[k];
			if (IN(ny, nx, Height, Width)) {
				if (d[ny][nx] < 1e9)continue;
				if (d[ny][nx] > d[pos.first][pos.second] + 1) {
					d[ny][nx] = d[pos.first][pos.second] + 1;
					q.push(make_pair(d[ny][nx], pair<int, int>(ny, nx)));
					prev[ny][nx] = k; 
					if (ny == t.first&& nx == t.second)break;
				}
			}
		}
	}
	/*cout << "debg" << endl;
	FOR(i, 0, Width) {
		FOR(j, 0, Width)cout << (d[i][j] == 1e9 ? -1:d[i][j] ) << " ";
		cout << endl;
	}*/
	if (d[t.first][t.second] > 1e6)return pair<int,VS>(-1, VS());
	//return d[t.first][t.second]; // (int)
	//cout << d[t.first][t.second] << endl;
	vector<int>path;
	int y = t.first, x = t.second;
	for (; pair<int, int>(y, x) != s;) {
		int k = prev[y][x];
		//debug(k);
		path.push_back(k);
		y -= DY[k];
		x -= DX[k];
	}

	reverse(path.begin(), path.end()); 



	y = s.first, x = s.second;

	//cout << y << " " << x << endl; //s
	VS vs;
	string str[6] = {"UL","UR","R","LR","LL","L"};
	for (int i = 0; i < (int)path.size(); i++) {
		y += DY[path[i]], x += DX[path[i]]; //移動
		string s;
		s = str[path[i]];
		vs.push_back(s);
		//cout << y << " " << x << endl;
	}

	//cout << (int)path.size() << endl; //min dist

	return pair<int, VS>(SZ(path),vs);	
}
LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	PII s, t;
	cin >> s.first >> s.second;
	cin >> t.first >> t.second;
	pair<int, VS>a;
	a = bfs2D(s, t, N, N);
	ans = a.first;
	VS vs = a.second;
	if (ans == -1)cout << "Impossible" << endl;
	else {
		cout << ans << "\n";
		FOR(i, 0, ans) {
			cout << vs[i] << " ";
		}cout << endl;
	}
	return 0;
}
