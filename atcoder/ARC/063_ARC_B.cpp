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

/* -----  2018/02/15  Problem: 063_arc_b / Link: https://abc047.contest.atcoder.jp/tasks/arc063_b?lang=en  ----- */
/* ------問題------

N 個の町が一直線上に並んでいます。行商人の高橋君は町 1 から出発し、リンゴの売買をしながら町 N へと向かいます。
はじめ高橋君は町 1 におり、リンゴを 1 つも持っていません。高橋君は次のいずれかの行動を繰り返し行います。
移動: 町 i (i<N) にいるとき、町 i+1 へ移動する。
リンゴの売買: リンゴを好きな個数だけ売買する。ここで、町 i (1≦i≦N) ではリンゴの買値も売値もともに Ai 円とする。ここで Ai は相異なる整数です。
1 つの町で売買するリンゴの個数に制限はありませんが、旅の中で売買するリンゴの個数は合計で (買う個数と売る個数を合わせて) T 個以下にしなくてはなりません。
高橋君は旅の利益、すなわちリンゴを売った代金から買った代金を引いた値を最大にするように旅をするとします。旅が終わったときに持っていたリンゴの価値は考えず、旅の中で売買した金額だけを考えます。
この旅に先立って、青木君は任意の町 i に対して Ai を好きな非負整数 Ai' に変えるという操作を好きなだけ行うことができます。ただし、この操作は行うごとに |Ai−Ai'| のコストがかかります。操作後には異なる町の間でリンゴの値段が同じになっていても構いません。
青木君の目的はできるだけ少ない合計コストの操作で高橋君の利益を少なくとも 1 円下げることです。合計コストの最小値を求めてください。
ただし、元の状態で高橋君が 1 円以上の利益を上げられることは仮定して構いません。

-----問題ここまで----- */
/* -----解説等-----

最大利益を得ることができる場所が何個あるかをカウントし、これの数を出力すれば良い。

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL T;
	cin >> N>>T;
	VL a(N);
	FOR(i, 0, N) {
		cin >> a[i];
	}
	LL Mn = a[0];
	int scnt = 0;
	LL gmx = -1;
	FOR(i, 0, N) {
		if (Mn > a[i]) {
			Mn = a[i];
		}

		if (gmx == a[i] - Mn)scnt++;
		else if (gmx < a[i] - Mn) {
			gmx = a[i] - Mn;
			scnt = 1;
		}
	}

	ans = scnt;
	cout << ans << "\n";

	return 0;
}
