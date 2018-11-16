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

/* -----  2018/11/16  Problem: ARC 022 B / Link: http://arc022.contest.atcoder.jp/tasks/arc022_b  ----- */
/* ------問題------

高橋君は細長いお菓子を持っています。このお菓子は Ncm の長さのお菓子で、 1cm ごとにブロックに分かれています。それぞれのブロックには 105 種類の味うちのいずれかの味がついていて、左端から i 番目のブロックには Ai 番目の味がついています。
高橋君はこのお菓子から、出来るだけ長い「同じ味のブロックが 2 つ以上含まれない、ひと繋がりになった部分」を切り出したいと思っています。最大で何 cm の部分を切り出すことが出来るでしょうか。ただし、切る場所はブロックとブロックの境界の部分のみとします。

-----問題ここまで----- */
/* -----解説等-----

しゃくとり法をするだけ。
もう一生バグらなさそう

----解説ここまで---- */

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N; 
	cin >> N;
	VI a(N);
	FOR(i, 0, N) {
		cin >> a[i];
	}
	int R = 0;
	map<int, int>M;
	FOR(L, 0, N) {
		while (R<N&&M[a[R]] == 0) {
			M[a[R]]++;
			R++;
		}
		DD(de(L, R));
		ans = max(ans, (LL)R - L);
		M[a[L]]--;
	}
	
	
	cout << ans << "\n";

	return 0;
}
