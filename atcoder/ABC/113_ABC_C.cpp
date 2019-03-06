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
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2019/02/27  Problem: ABC 113 C / Link: http://abc113.contest.atcoder.jp/tasks/abc113_c  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----



----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, M; cin >> N >> M;
	vector<pair<int, string>> ans;
	vector<vector<PII>> P(N + 1);
	FOR(_, 0, M) {
		int p, y; cin >> p >> y;
		P[p].push_back(PII(y, _));
	}
	FOR(i, 0, N + 1) {
		SORT(P[i]);
		FOR(k, 0, SZ(P[i])) {
			stringstream ss;
			ss << setw(6) << setfill('0') << i;
			ss << setw(6) << setfill('0') << k + 1;
			string s;
			ss >> s;
			ans.emplace_back(make_pair(P[i][k].second, s));
		}
	}

	SORT(ans);
	for (auto it : ans) {
		cout << it.second << endl;
	}

	return 0;
}
