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

/* -----  2019/07/23  Problem: AOJ 0156 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0156  ----- */


int main() {
	int H, W;
	while (cin >> W >> H, W || H) {
		vector<string> a(H);
		int si, sj;
		for (int i = 0; i < H; ++i) {
			cin >> a[i];
			FOR(j, 0, W) {
				if (a[i][j] == '&')  a[i][j] = '.', si = i, sj = j;
			}
		}
		DD(de(si, sj));
		vector<vector<int>> d(H, vector<int>(W, INF));
		queue<pair<int, pair<int, int>>> pq;
		const int DY[] = { 0,0,1,-1 };
		const int DX[] = { 1,-1,0,0 };
		auto isin = [](int b, int a, int c) {return  a <= b && b < c; };
		pq.push({ 0,{ si,sj } });
		int cnt = 0;
		while (!pq.empty()) {
			auto p = pq.front();    pq.pop();
			int cost = p.first, i = p.second.first, j = p.second.second;
			if (d[i][j] <= cost)   continue;
			d[i][j] = cost;
			for (int k = 0; k < 4; k++) {
				int ni = i + DY[k], nj = j + DX[k];
				if (!isin(ni, 0, H) || !isin(nj, 0, W))  continue;
				int ncost = cost + (a[i][j] == '.'&&a[ni][nj] == '#');
				if (d[ni][nj] > ncost)   pq.push({ ncost,{ ni,nj } });
			}
		}
		DD(de(cnt));
		int ans = 1 << 30;
		for (int i = 0; i < H; i++)  ans = min({ ans, d[i][0], d[i][W - 1] });
		for (int j = 0; j < W; j++)  ans = min({ ans, d[0][j], d[H - 1][j] });
		cout << ans << endl;
	}
}