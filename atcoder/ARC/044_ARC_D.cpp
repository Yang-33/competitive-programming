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

/* -----  2018/11/01  Problem: ARC 044 D / Link: http://arc044.contest.atcoder.jp/tasks/arc044_d  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

suffixarrayについて再度考察をする。
suffixarrayについて、suffixでsortしたものは辞書順であり、
これを最小にすれば元の文字を辞書順最小にすることができる。
当然、suffixarray上で貪欲に文字を振り分けていきたいが、だめな時がある。
それは前のsuffixRankと今のsuffixRankにおいて、同じ文字とする場合には
それぞれの次の文字のrankを見る必要がある。
もしpre.nextsuffixRank < now.nextsuffixRankならば、問題はない。
なぜならpreの方はnowよりも辞書順で小さいので、次の文字を見ることで辞書順の制約を守ることができているからである。
一方でpre.nextsuffixRank > now.nextsuffixRankだったとすると、
preのほうがnowよりもsa配列上で先に見られるものであるはずだが矛盾しているので同じ文字にはできず、
alphabetで次のものを選択しないといけない。
これを前から実装するだけで良い。

すごい良い問題…

----解説ここまで---- */

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N;
	cin >> N;
	VI a(N + 1);
	VI suffixRank(N + 1);
	FOR(i, 0, N) {
		cin >> a[i];
		a[i]--;
		suffixRank[a[i]] = i + 1;
	}
	suffixRank[N] = 0;
	string ans(N, '@');
	char tops = 'A';
	int previous = 0;
	FOR(i, 0, N) {
		if (suffixRank[a[i] + 1] < previous)tops++;
		if (tops > 'Z') {
			ans = "-1";
			break;
		}
		ans[a[i]] = tops;
		previous = suffixRank[a[i] + 1];

	}


	cout << ans << "\n";

	return 0;
}