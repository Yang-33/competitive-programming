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

/* -----  2018/07/05  Problem: AOJ 3005 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/3005  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----



----解説ここまで---- */


struct UnionFind {
	vector<int> data;
	UnionFind(int n) { data.assign(n, -1); }
	bool unionSet(int x, int y) {
		x = root(x); y = root(y);
		if (x != y) {
			if (data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
		}
		return x != y;
	}
	bool same(int x, int y) { return root(x) == root(y); }
	int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
	int size(int x) { return -data[root(x)]; }
};
// UnionFind uf(n); uf.unionSet(i,j); if(uf.same(x,y))
#define IN(a, x, b) (a<=x && x<b)


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int H, W, K;
	cin >> W >> H >> K;
	map<PII, int>Point;
	VI x(K), y(K);
	int pc =1;
	FOR(i, 0, K) {
		cin >> x[i] >> y[i];
		Point[PII(y[i], x[i])] = pc++;
	}

	// uf
	UnionFind uf(K + 2 * (H + W));
	int A = pc++;
	int B = pc++;

	FOR(i, 0, K) {
		FOR(d, 0, 8) {
			int ny = y[i] + DY[d];
			int nx = x[i] + DX[d];
			if (!IN(0, nx, W) || !IN(0, ny, H)) {
				if (ny < 0) uf.unionSet(Point[PII(y[i], x[i])], A);
				if (nx < 0) uf.unionSet(Point[PII(y[i], x[i])], B);
				if (ny > H - 1) uf.unionSet(Point[PII(y[i], x[i])], B);
				if (nx > W - 1) uf.unionSet(Point[PII(y[i], x[i])], A);
			}
			else {
				if (Point.find(PII(ny, nx)) == Point.end()) continue;
				uf.unionSet(Point[PII(y[i],x[i])], Point[PII(ny, nx)]);
			}
		}
	}
	if (uf.same(A, B)) {
		cout << "0" << endl;
	}
	else {
		int f = 0;
		int dy[] = { -2,-2,-2,-2,-2,-1,0,1,2,2,2,2,2,1,0,-1 };
		int dx[] = { -2,-1,0,1,2,2,2,2,2,1,0,-1,-2,-2,-2,-2 };
		FOR(i, 0, K) {
			if (!uf.same(Point[PII(y[i], x[i])], A) && !uf.same(Point[PII(y[i], x[i])], B)) continue;
			int join = uf.same(Point[PII(y[i], x[i])], B);
			FOR(d, 0, 16) {
				int ny = y[i] + dy[d];
				int nx = x[i] + dx[d];
				if (!IN(0, nx, W) || !IN(0, ny, H)) {
					if ((ny < 0 && join == 1) ||
						(nx < 0 && join == 0) ||
						(ny > H - 1 && join == 0) ||
						(nx > W - 1 && join == 1)){
						f = 1;
					}
				}
				else {
					if (Point.find(PII(ny, nx)) == Point.end()) continue;
					if (uf.same(Point[PII(ny, nx)], A + !join)) {
						f = 1;
					}
				}
			}
		}
		cout << (f ? 1 : 2) << endl;
	}
	//debug(A);
	//debug(B);
	//int yy, xx;
	//while (cin >> yy >> xx) {
	//	cout << "debug:=" << Point[PII(yy, xx)] << endl;
	//}


	return 0;
}