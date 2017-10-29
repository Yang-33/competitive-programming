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

/* -----  2017/10/03  Problem: AOJ 0025  / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0025&lang=jp ----- */
/* ------問題------

数あてゲーム

-----問題ここまで----- */
/* -----解説等-----

いわれたとおりにね。

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int a[4], b[4];
	while (cin>>a[0]>>a[1]>>a[2]>>a[3]>>b[0]>>b[1]>>b[2]>>b[3]) {
		set<int>se;
		FOR(i, 0, 4) {
			se.insert(b[i]);
		}
		int hit = 0; int bl = 0;
		FOR(i, 0, 4) {
			if (a[i] == b[i])hit++;
			else if (se.count(a[i]) >= 1)bl++;
		}
		cout << hit << " " << bl << endl;
	}

	return 0;
}
