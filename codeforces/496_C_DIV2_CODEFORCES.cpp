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

/* -----  2018/07/10  Problem: CodeForces496 C div2 / Link: http://codeforces.com/contest/1005/problem/C  ----- */
/* ------問題------

a[i]+a[j]==2^kになるものを良い組とする。
良い組にならないものの個数は?

-----問題ここまで----- */
/* -----解説等-----

2^kでの剰余で考える。
a[i]のペアがあるとき、これをcheckしておく。Nが大きいのでmapにのせて確認すれば良い。

----解説ここまで---- */
#include<unordered_map>
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N;
	int ans = 0;
	scanf("%d", &N);
	VL a(N);
	FOR(i, 0, N) {
		scanf("%d",&a[i]);
	}
	vector<bool> ok(N, 0);
	FOR(d, 1, 32) {
		vector<bool> b(N,0);
		unordered_map<LL, VI>Map;
		unordered_map<LL, int>M;
		LL TWO = 1LL << d;
		FOR(i, 0, N) {
			if (a[i] >= TWO)continue;
			b[i] = 1;
			Map[a[i]].push_back(i);
		}


		FOR(i, 0, N) {
			if (!b[i])continue;
			LL NX = abs(TWO - a[i]);
			if (M[NX]==1) {
				ok[i] = 1;
				continue;
			}
			if (Map[NX].size() == 0)continue;
			M[NX] = 1;
			if (NX == a[i] && SZ(Map[NX]) > 1)ok[i] = 1;
			for (auto it : Map[NX]) {
				if (it!=i) {
					ok[it] = 1;
				}
			}
		}
	}
	FOR(i, 0, N) {
		if (!ok[i])ans++;
	}
	cout << ans << "\n";

	return 0;
}
