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

/* -----  2018/02/14  Problem: 062_arc_a / Link: https://arc062.contest.atcoder.jp/tasks/arc062_a?lang=en  ----- */
/* ------問題------

シカのAtCoDeerくんは選挙速報を見ています。
選挙には二人の候補高橋くんと青木くんが出ています。
速報では、現在の二人の得票数の比が表示されていますが、得票数そのものは表示されていません。
AtCoDeerくんは N 回画面を見て、 i(1≦i≦N) 回目に見たときに表示されている比は Ti:Ai でした。
ここで、AtCoDeerくんが選挙速報の画面を1回目に見た段階で既にどちらの候補にも少なくとも一票は入っていたことがわかっています。 
N 回目に画面を見たときの投票数(二人の得票数の和)として考えられるもののうち最小となるものを求めてください。
ただし、得票数が途中で減ることはありません。

-----問題ここまで----- */
/* -----解説等-----

比のbaseとなる値が何かを考えれば良い。
(前回のA) + K = base*A[i+1]
(前回のT) + K' = base*T[i+1]
であるから、baseはこれのうち大きい方。

----解説ここまで---- */


LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	LL A = 1, T = 1;
	FOR(i, 0, N) {
		int t, a; cin >> t >> a;
		if (i == 0)A = a, T = t;
		else {
			int x = max((A+a-1)/a,(T+t-1)/t);
			A = a*x;
			T = t*x;
		}
		
	}
	ans = A + T;
	cout << ans << "\n";

	return 0;
}
