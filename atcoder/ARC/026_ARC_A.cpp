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

/* -----  2018/11/07  Problem: ARC 026 A / Link: http://arc026.contest.atcoder.jp/tasks/arc026_a  ----- */
/* ------問題------

高橋君はプログラミングコンテストに参加しようとしています。このコンテストでは簡単な問題が N 問出題されます。高橋君は普段 1 問あたり A 分で解くことが出来ますが、ダイナミックなポーズをとりながら問題を解くことで 1 問あたり B 分で解くことが出来るようになります。ただし、ダイナミックなポーズには体力を著しく消耗してしまうので、1 回のプログラミングコンテストでは 5 問までしかダイナミックなポーズをとりながら解くことができません。高橋君は最短何分で N 問の問題を全て解くことが出来るでしょうか。

-----問題ここまで----- */
/* -----解説等-----

筋肉は強いため速く解けるという意味

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, A, B; cin >> N >> A >> B;
	// B< A
	int sub = min(N, 5LL);
	LL ans = sub * B + (N - sub)*A;
	cout << ans << "\n";

	return 0;
}