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
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/04/19  Problem: yukicoder 092  / Link: http://yukicoder.me/problems/no/092  ----- */
/* ------問題------

Yuki City は N 個の町と M 本の道路からなる。
町は 1 から N まで番号が振られている。
道路は双方向に通行でき、それぞれ通行料金が設定されている。

さて、Yuki City 警察のあなたはある指名手配犯を追っている。
長らく犯人の居場所を掴めなかったあなただが、つい先日有力な情報を手に入れた。
その情報とは、犯人が支払った通行料金のうち、直近 K 回分を時系列順に並べたものである。
あなたはこの情報を使い、犯人が今いる可能性のある町を絞り込みたい。

警察官であると同時に天才プログラマーでもあるあなたは、プログラムによってこの問題を解こうと考えた。

-----問題ここまで----- */
/* -----解説等-----

同じコストがあれば、次のコストもチェックして良い。というDPをすればよい。  
O(MK)

----解説ここまで---- */

LL N, M, K;

LL ans = 0LL;

template<typename T>using VV = vector<vector<T>>;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> M >> K;
	vector<vector<PII>>G(N);
	FOR(i, 0, M) {
		int a, b, c; cin >> a >> b >> c;
		a--, b--;
		G[a].emplace_back(b, c);
		G[b].emplace_back(a, c);
	}

	VI d(K);
	FOR(i, 0, K) {
		cin >> d[i];
	}
	VV<int>dp(K + 1, VI(N, 0));
	FOR(i, 0, N)dp[0][i] = 1;
	FOR(k, 0, K) {
		FOR(i, 0, N) {
			if (dp[k][i]) {
				FOR(j, 0, SZ(G[i])) {
					int c = G[i][j].second;
					int nv = G[i][j].first;
					if (c == d[k])
						dp[k + 1][nv] = dp[k][i];
				}
			}
		}
	}
	VI a;
	FOR(i, 0, N) {
		ans += dp[K][i];
		if(dp[K][i])a.push_back(i+1);
	}

	cout << ans << "\n";
	FOR(i, 0, SZ(a)) {
		cout << a[i] << " \n"[i == SZ(a) - 1];
	}
	return 0;
}
