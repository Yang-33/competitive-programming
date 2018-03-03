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

/* -----  2018/03/03  Problem: 019_agc_b / Link: https://agc019.contest.atcoder.jp/tasks/agc019_b ----- */
/* ------問題------

英小文字からなる文字列 A=A1A2…An があります。
あなたは 1≤i≤j≤n であるような任意の二つの添字 i,j を選び、A のうち部分文字列 AiAi+1…Aj を反転することができます。
この操作は一回まで行うことができます。
これによって得られる文字列は何通りあるでしょうか？

-----問題ここまで----- */
/* -----解説等-----

アルファベットについての累積和を取ると、部分問題として見れるので、重複数え上げがないようにすればよい。
[str] +'a'のとき、aを含む反転をして一致するのは反転の区間の左端がaとなる場合である。
ex: strstrstr|abca| -> strstrstr|abca|
なぜなら、[str]内の計算で cを右端とした場合にbc->cbを事前に計算終えているからである。
したがって文字列の先頭から走査し、現在見ている文字を両端としない場合は反転をしてuniqueになることが保証あされるので、
これを答えとしてよい。
この方法では反転するものしか数えないので、全く反転しない場合の数1を加える。


----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;

	VVI cnt(SZ(s) + 1, VI(26, 0));
	FOR(i, 0, SZ(s)) {
		FOR(j, 0, 26) {
			cnt[i + 1][j] += cnt[i][j] + (s[i] - 'a' == j);
		}
	}
	ans = 1;
	FOR(i, 0, SZ(s)) {
		ans += i - cnt[i][s[i] - 'a'];
	}
	cout << ans << "\n";

	return 0;
}
