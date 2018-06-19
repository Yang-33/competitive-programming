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

/* -----  2018/06/23  Problem: AOJ 2823 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2823  ----- */
/* ------問題------

ACM-ICPC OB/OGの会 (Japanese Alumni Group; JAG) には模擬コンテストで出題する問題のストックが N 問あり，それぞれの問題は 1 から N の整数で番号付けられている． それぞれの問題について難易度評価と推薦投票が行われており，問題 i の難易度は di で，推薦度は vi である． また，難易度の最大値は M である．
次のコンテストでは，難易度 1 から M の問題をそれぞれ 1 問ずつ，計 M 問出題する予定である． コンテストのクオリティを上げるために推薦度の合計が最大になるように問題を選定したい． ただし，JAG の作問力はすさまじいので，各難易度の問題が最低でも 1 問以上ずつあると仮定してよい．
あなたの仕事は，条件を満たすように問題を選定したときの推薦度の和の最大値を求めるプログラムを作成することである．

-----問題ここまで----- */
/* -----解説等-----

貪欲にやっていけばよい。

----解説ここまで---- */

using ll = LL;
int N, M;
ll solve() {
	ll res = 0;
	vector<vector<int>> G(M + 1);
	for (int i = 0; i < N; i++) {
		int d, v; cin >> d >> v;
		G[d].push_back(v);
	}
	for (auto& vec : G) sort(vec.begin(), vec.end());
	res = accumulate(G.begin() + 1, G.end(), 0LL, [](ll sum, vector<int>& vec) {return sum + *vec.rbegin(); });
	return res;
}
int main(void) {
	cin.tie(0); ios_base::sync_with_stdio(false);
	while (cin >> N >> M, N) {
		cout << solve() << endl;
	}
	return 0;
}
