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

/* -----  2018/11/24  Problem: CodeForces524 A div2 / Link: http://codeforces.com/contest/1080/problem/A  ----- */
/* ------問題------

N人に招待状を送る。
1人につき、R,G,B =(2,5,8)枚の折り紙が必要である。
折り紙やさんにはどの色についても1色K枚のセットが売っている。
最低何セット買わないといけないか？

-----問題ここまで----- */
/* -----解説等-----

ある色に必要な枚数をCとすると、その色の必要枚数はC*N枚なので、Kセットで買える分を切り上げて計算すれば良い。

----解説ここまで---- */

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, K;

	cin >> N >> K;
	ans = (2 * N + K - 1) / K + (5 * N + K - 1) / K + (8 * N + K - 1) / K;



	cout << ans << "\n";

	return 0;
}
