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

/* -----  2019/04/04  Problem: ABC 044 D / Link: http://abc044.contest.atcoder.jp/tasks/abc044_d  ----- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	// nをb進数にして、その桁和がsになるようなbは存在するか?
	LL N, S; cin >> N >> S;
	LL ans = LINF;
	function<LL(LL, LL)> f = [&](LL b, LL n) {
		if (n < b)return n;
		else return f(b, n / b) + (n % b);
	};

	for (LL b = 2; b*b <= N; b++) {
		if (f(b, N) == S) {
			ans = min(ans, b);
		}
	}

	// 大きいbに対しては2桁であるから、式変形で解ける
	// xb+y = N, x+y=S
	// x+N-xb =S, b =(x+N-S )// x

	// x=0
	if (N == S)ans = min(ans, N + 1);
	for (LL x = 1; x*x <= N; x++) {
		LL b = (x + N - S) / x;
		LL y = S - x;
		if (b > 1 && x < b && y >= 0 && y < b&& f(b, N) == S) {
			ans = min(ans, b);
		}
	}
	if (ans == LINF)ans = -1;
	cout << ans << "\n";

	return 0;
}
