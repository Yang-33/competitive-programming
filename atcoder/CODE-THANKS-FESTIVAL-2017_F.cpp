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

/* -----  2018/03/03  Problem: code-thanks-festival-2017_f / Link: https://code-thanks-festival-2017.contest.atcoder.jp/tasks/code_thanks_festival_2017_f?lang=en  ----- */
/* ------問題------

N 個の正の整数が与えられ、i(1≦i≦N) 番目の正の整数は ai です。
N 個の整数のうち 0 個以上を選んで、選んだ全ての整数のビットごとの排他的論理和を計算します。
計算結果が K となるような整数の選び方の個数を 10^9+7 で割った余りを求めてください。
ただし、0 個選んだときのビットごとの排他的論理和は 0 とします。

-----問題ここまで----- */
/* -----解説等-----

状態が少ないかなあという気持ちでmap上のDPをすると通った

↓解説に書いてあったこと
1.sortして無駄な部分をへらして上界をあげながらDP
これはたぶんmapと同じ

2. Xorの性質から重複する値をまとめて計算するDP
偶数個選ぶか奇数個選ぶかの選択になり、DPの係数が2のべき乗になる
(組合せと二項定理の母関数から奇数と偶数の選択和は2のべき乗[高校数学])
これでDPを
dp[i][j]: b1, …, bi から、XOR が j となる整数の選び方の個数
とすればよい

----解説ここまで---- */

LL N, K;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> K;
	map<int, LL>Map;
	VI a(N);
	SORT(a);
	FOR(i, 0, N) {
		cin >> a[i];
	}
	Map[0] = 1;
	FOR(i, 0, N) {
		map<int, LL>Nx;
		for (auto m : Map) {
			int mask = m.first;
			LL cmb = m.second;
			(Nx[mask]+=cmb) %= MOD;
			(Nx[mask^a[i]]+=cmb) %= MOD;
		}
		Map = Nx;
	}
	ans = Map[K];

	cout << ans << "\n";

	return 0;
}
