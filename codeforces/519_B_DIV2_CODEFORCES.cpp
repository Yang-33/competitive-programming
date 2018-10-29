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

/* -----  2018/10/29  Problem: CodeForces519 B div2 / Link: http://codeforces.com/contest/1043/problem/B  ----- */
/* ------問題------

覚えてないけど周期が知りたい

-----問題ここまで----- */
/* -----解説等-----

小さいので全部試せば良い。

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N; 
	cin >> N;
	VL a(N);
	FOR(i, 0, N) {
		cin >> a[i];
	}

	VI x(N);
	x[0] = a[0];
	FOR(i, 1, N) {
		x[i] = a[i] - a[i - 1];
	}

	// 周期Sがただしいのかcheckする
	VI ans;
	FOR(s, 1, N + 1) {
		int ok = 1;
		FOR(j, s, N) {
			int i = j % s;
			if (x[i] != x[j])ok = 0;
		}

		if (ok)ans.push_back(s);
	}


	cout << SZ(ans) << endl;
	SORT(ans);
	FOR(i, 0, SZ(ans)) {
		cout << ans[i] << " \n"[i == SZ(ans) - 1];
	}

	return 0;
}
