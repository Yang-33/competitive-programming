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

/* -----  2017/12/06  Problem: codefestival2017_team_relay_j / Link: https://cf17-relay-open.contest.atcoder.jp/tasks/relay2_j ----- */
/* ------問題------

2N 個の壺があります。このうち i 個目の壺 (1≤i≤2N) の市場価格は pi 円です。
これから、あなたとダックスフンドのルンルンは交互に壺を一つずつ取っていきます。あなたから始めて、すべての壺があなたかルンルンに取られるまで続けます。ルンルンは壺の市場価格がわからないので、毎回、残っている壺の中から無作為に等確率で一つを選びます。あなたはこのルンルンの行動と、壺の市場価格を知っています。
あなたの目的は、取る壺の市場価格の合計を S 円としたとき、S の期待値を最大化することです。最適な戦略を取ったときの S の期待値を求めてください。

-----問題ここまで----- */
/* -----解説等-----

るんるんと自分の取るものにかかる割合は、少し考えるとお山になることがわかるので、これはできる。
自分は高いものから回収していけばいいので、2*Nに対して、 自分 + るんるん  = 2*Nである。

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	N *= 2;
	VI a(N);
	FOR(i, 0, N) {
		cin >> a[i];
	}
	SORT(a);
	LL sum = 0;
	FOR(i, 0, N) {
		sum += 1LL *i* a[i];
	}
	cout << fixed << setprecision(15) << 1.0*sum / (N - 1) << endl;

	return 0;
}
