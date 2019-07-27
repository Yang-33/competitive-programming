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
//#pragma GCC optimize ("-O3") 
#ifdef YANG33
#include "mydebug.hpp"
#else
#define DD(x) 
#endif
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);

/* -----  2019/07/27  Problem: AOJ 0194 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0194  ----- */
// まったりしなくて，入れない

typedef pair<int, int> Pi;
typedef pair<int, Pi> Pii;
#define fr first
#define sc second

int M, N, D, ns, nc, nj;
char temp['z' + 1], o;
int mas[20][20];
int go[20][20][20][20];
bool used[20][20][101];
Pi S, G;
int dy[] = { 0, 1, 0, -1 }, dx[] = { -1, 0, 1, 0 };

bool isover(int y, int x) {
	return y < 0 || y >= M || x < 0 || x >= N;
}

bool isred(int y, int x, int time, bool istate) {
	return ~mas[y][x] && !istate ^ time / mas[y][x] & 1;
}

int Dijkstra() {
	fill_n(**used, 20 * 20 * 101, false);
	priority_queue<Pii, vector<Pii>, greater<Pii> > que;
	que.push(Pii(0, S));
	while (!que.empty()) {
		Pii p = que.top();
		que.pop();
		if (p.sc == G)
			return p.fr;
		if (used[p.sc.fr][p.sc.sc][p.fr]++)
			continue;
		for (int i = 0; i < 4; i++) {
			int ny = p.sc.fr + dy[i], nx = p.sc.sc + dx[i];
			if (isover(ny, nx))
				continue;
			if (go[p.sc.fr][p.sc.sc][ny][nx] == -1)
				continue;
			int nexttime = p.fr + D + go[p.sc.fr][p.sc.sc][ny][nx];
			if (isred(ny, nx, nexttime, i & 1))
				continue;
			que.push(Pii(nexttime, Pi(ny, nx)));
		}
	}
	return -1;
}

int main() {

	for (int i = 'a', j = 1; i <= 'z'; i++, j++) {
		temp[i] = j;
	}

	while (cin >> M >> N, M) {

		fill_n(*mas, 400, -1);
		fill_n(***go, 20 * 20 * 20 * 20, 0);

		cin >> D;
		cin >> ns;
		for (int i = 0; i < ns; i++) {
			char h;
			int v, k;
			cin >> h >> o >> v >> k;
			mas[temp[h] - 1][v - 1] = k;
		}

		cin >> nc;
		for (int i = 0; i < nc; i++) {
			char h1, h2;
			int v1, v2;
			cin >> h1 >> o >> v1 >> h2 >> o >> v2;
			go[temp[h1] - 1][v1 - 1][temp[h2] - 1][v2 - 1] = -1;
			go[temp[h2] - 1][v2 - 1][temp[h1] - 1][v1 - 1] = -1;
		}

		cin >> nj;
		for (int i = 0; i < nj; i++) {
			char h1, h2;
			int v1, v2, d;
			cin >> h1 >> o >> v1 >> h2 >> o >> v2 >> d;
			go[temp[h1] - 1][v1 - 1][temp[h2] - 1][v2 - 1] = d;
			go[temp[h2] - 1][v2 - 1][temp[h1] - 1][v1 - 1] = d;
		}

		char h1, h2;
		int v1, v2;
		cin >> h1 >> o >> v1 >> h2 >> o >> v2;
		S = Pi(temp[h1] - 1, v1 - 1);
		G = Pi(temp[h2] - 1, v2 - 1);

		cout << Dijkstra() << endl;
	}
}