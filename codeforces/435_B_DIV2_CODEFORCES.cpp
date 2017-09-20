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


/* -----  2017/09/19  Problem: CodeForces435 B div2 / Link: http:codeforces.com/contest/862/problem/B ----- */
/* ------–â‘è------



-----–â‘è‚±‚±‚Ü‚Å----- */
/* -----‰ðà“™-----



----‰ðà‚±‚±‚Ü‚Å---- */


LL N;

LL ans = 0LL;
vector<int> G[100005];
vector<PII>pv;

int dfs(int now, int dep, int p) {
	if (dep % 2 == 0) {
		pv.push_back(PII(now, SZ(G[now])));
	}
	FOR(i, 0, SZ(G[now])) {
		if (G[now][i] == p)continue;
		dfs(G[now][i], dep + 1, now);
	}

}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	FOR(i, 0, N-1) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	dfs(0,0,-1);
	
	FOR(i, 0, SZ(pv)) {
		int pos = pv[i].first;
		int rin = pv[i].second;
		ans += (N - SZ(pv) - rin);
		//out << pos << " " << N - SZ(pv) - rin << endl;
	}
	cout << ans << "\n";

	return 0;
}