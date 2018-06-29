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

/* -----  2018/06/30  Problem: AOJ 2578 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2578  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

dp,dpでdp(えぇ…)

----解説ここまで---- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);


	int S, T, U, N, O, D;
	cin >> S >> T >> U >> N >> O >> D;
	VI decPow(T), spCol(T);
	FOR(i, 0, T) {
		cin >> decPow[i] >> spCol[i];
	}
	VVI PowToColDP(U + 1, VI(101, -INF)); // ある体力消費におけるカロリーの最大値
	PowToColDP[0][0] = 0;
	FOR(i, 0, T) {
		FORR(u, U - 1, 0 - 1) {
			FOR(p, 0, 101) {
				if (PowToColDP[u][p] == -INF)continue;
				if (p + decPow[i] <= 100)
					PowToColDP[u + 1][p + decPow[i]] = max(PowToColDP[u + 1][p + decPow[i]], PowToColDP[u][p] + spCol[i]);
			}
		}
	}
	VI decPowDP = PowToColDP[U];
	VI happy(N), incCol(N);
	FOR(i, 0, N) {
		cin >> happy[i] >> incCol[i];
	}

	VI GetColDP(10001, 0); // あるカロリーにおける幸福度の最大
	FOR(i, 0, N) {
		FOR(c, 0, 10001) {
			if (c + incCol[i] <= 10000)GetColDP[c + incCol[i]] = max(GetColDP[c + incCol[i]], GetColDP[c] + happy[i]);
		}
	}
	FOR(c, 0, 10000) {
		GetColDP[c + 1] = max(GetColDP[c + 1], GetColDP[c]);
	}// あるカロリーまでにおける幸福度の最大にした



	// ここから本質DP
	// decPowDP,GetColDPを使ってD日をDP
	VVI DP(D + 1, VI(S + 1, -INF));
	DP[0][S] = 0;
	FOR(d, 0, D) {// 毎日O回復する
		FOR(s, 0, S + 1) {
			FOR(decs, 0, s + 1) {
				int MaxCol = decPowDP[decs];
				if (MaxCol < 0)continue;
				int nextS = min(S, s - decs + O);
				if (DP[d][s] == -INF)continue;
				DP[d + 1][nextS] = max(DP[d + 1][nextS], DP[d][s] + GetColDP[MaxCol]);
			}
		}
	}
	int ans = -1;
	FOR(i, 0, S + 1) {
		ans = max(ans, DP[D][i]);
	}
	cout << ans << endl;





	return 0;
}
