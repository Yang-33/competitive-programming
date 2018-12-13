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

/* -----  2018/12/13  Problem: ARC 005 A / Link: http://arc005.contest.atcoder.jp/tasks/arc005_a  ----- */
/* ------問題------

　高橋君は自分が大好きなので、自分の評判を調べるために自分の名前が入っているツイートを調べたいと考えました。しかし彼のフォロー数は多いので、タイムラインを 1 つずつ確認して自分に関係あるつぶやきを探すのは面倒です。

 　そこで高橋くんを手伝うために、与えられる文から高橋君を表す単語が現れる回数を数えてください。
  　ただし、単語の一部に高橋君を表す単語を含んでいた場合も、高橋君を表す単語と完全に一致しない限り、その単語を高橋君を表す単語として数えないでください。

   　以下の3単語が高橋君を表す単語です。
	TAKAHASHIKUN（高橋君をヘボン式ローマ字にして、全て大文字にしたもの）
	Takahashikun（高橋君をヘボン式ローマ字にして、先頭の 1 文字のみ大文字、残りは小文字にしたもの）
	takahashikun（高橋君をヘボン式ローマ字にして、全て小文字にしたもの）

-----問題ここまで----- */
/* -----解説等-----

やる

----解説ここまで---- */

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N;  cin >> N;
	string t[3] = { "TAKAHASHIKUN","Takahashikun","takahashikun" };
	FOR(_, 0, N) {
		string s; cin >> s;
		if (_ == N - 1)s = s.substr(0, SZ(s) - 1);
		int ok = 0;
		FOR(i, 0, 3) {
			ok |= s == t[i];
		}
		ans += ok;
	}
	
	
	
	cout << ans << "\n";

	return 0;
}
