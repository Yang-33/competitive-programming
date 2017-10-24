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

/* -----  2017/10/22  Problem: codefestival2017_qual_b D  / Link: https://beta.atcoder.jp/contests/code-festival-2017-qualc  ----- */
/* ------問題------

英小文字のみからなる文字列 s があります。 すぬけ君は、s をいくつかの空でない部分文字列へ分割しようとしています。 分割後の部分文字列を、左から順に s1, s2, …, sN とします (このとき、s=s1+s2+…+sN です)。 すぬけ君は、次の条件が成り立つように s を分割しようとしています。
各 i (1≤i≤N) について、si の文字を並べ替えて回文が得られる。
条件が成り立つように s を分割するとき、N の最小値を求めてください。

-----問題ここまで----- */
/* -----解説等-----

状態の遷移の線が全く分からなかった。
dpと一緒に文字列の情報を持たせるのではなく、DPに文字列の状態を持たせればよい。
並び替えて回文となるのは持っている文字列が全部偶数あるいは一つだけ奇数。
この状態をいどうしていくので、これでDPができる。
DP[x]:=文字列の状態がxであるときの最小値

----解説ここまで---- */

LL N;

LL ans = 0LL;
struct info {
	vector<int>c[26];
	int ok = 0;
};
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;
	int state = 0;
	VI dp(1 << 26, INF);
	dp[0] = 0;
	FOR(i, 0, SZ(s)) {
		state ^= 1 << (s[i] - 'a');
		dp[state] = dp[state]; //%2==0
		FOR(j, 0, 26) {// %2==1
			int temp = (state ^ (1 << j));
			dp[state] = min(dp[state], dp[temp] + 1);
		}
	}
	cout << (dp[state] ? dp[state] : 1) << endl;

	return 0;
}