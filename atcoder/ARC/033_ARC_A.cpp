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
//#pragma GCC optimize ("-O3") 
#ifdef YANG33
#include "mydebug.hpp"
#else
#define DD(x) 
#endif
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/10/27  Problem: ARC 033 A / Link: http://arc033.contest.atcoder.jp/tasks/arc033_a  ----- */
/* ------問題------

高橋君は、隠れた言葉を探す遊びが好きです。例えば、「じきゅうりょく」の中には「きゅうり」という言葉が隠れています。
高橋君は今、長さ N の文字列の中に隠れた言葉を探そうとしています。隠れた言葉の候補を列挙するためにまず、この文字列の「部分文字列」の個数を計算してみることにしました。
文字列 S の「部分文字列」とは、文字列 S に含まれるある区間を取り出した文字列のことです。例えば、「すぬけ」の部分文字列は「す」「ぬ」「け」「すぬ」「ぬけ」「すぬけ」の 6 つです。「すけ」や「ぬす」などは部分文字列ではないことに注意してください。
また、文字列 S には同じ文字が 2 回以上現れないことが分かっています。そのため「しょうぼうしょ」における「しょ」のように、異なる場所から取り出した文字列が一致することはありません。

-----問題ここまで----- */
/* -----解説等-----

\sum ^N i をすればよい

----解説ここまで---- */

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N; 
	cin >> N;
	ans = N * (N + 1) / 2;
	
	
	cout << ans << "\n";

	return 0;
}
