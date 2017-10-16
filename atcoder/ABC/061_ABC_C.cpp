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

/* -----  2017/10/16  Problem: nagoya_19_05 ABC061 C / Link: https://abc061.contest.atcoder.jp/tasks/abc061_c  ----- */
/* ------問題------

空の配列が 1 つあります。
この配列に、整数を配列に挿入する操作を N 回行います。
i(1≦i≦N) 回目の操作では、配列に整数 ai を bi 個挿入します。
N 回の挿入操作後の配列の中で、K 番目に小さい数を求めてください。
例えば、配列が {1,2,2,3,3,3} の時、4 番目に小さい数は 3 となります。

-----問題ここまで----- */
/* -----解説等-----

実際にシュミレーションしたくなったので、pairで管理して値を小さい順に作っていった。

----解説ここまで---- */

LL N,K;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N>>K;
	vector<PLL>v;
	FOR(i, 0, N) {
		LL a, b; cin >> a >> b;
		v.push_back(PLL(a, b));
	}
	SORT(v);
	FOR(i, 0, N) {
		LL val, num;
		val = v[i].first;
		num = v[i].second;
		ans += num;
		if (K <= ans) {
			cout << val << endl; return 0;
		}
	}

	return 0;
}