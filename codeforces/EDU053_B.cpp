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

/* -----  2018/10/25  Problem: EDU053 B / Link: __CONTEST_URL__  ----- */
/* ------問題------

本が上から順にaで並んでいる。
ithに、b[i]を取り出したい。
istep目でb[i]を取り出すまでに本を何個取る必要があるか?

-----問題ここまで----- */
/* -----解説等-----

何をすでに見たかを高速に判定しつつ、シュミレーションすればよい。

----解説ここまで---- */

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N;
	cin >> N;
	VI a(N), b(N);
	FOR(i, 0, N) {
		cin >> a[i];
	}
	FOR(i, 0, N) {
		cin >> b[i];
	}
	VI used(N + 1, 0);
	int pos = 0;
	FOR(i, 0, N) {
		int B = b[i];
		if (used[B]) {
			cout << 0 << " ";
			continue;
		}
		ans = 0;
		while (pos < N&&a[pos] != B) {
			used[a[pos]] = 1;
			pos++;
			ans++;
		}
		if (pos < N&&a[pos] == B) {
			ans++;
			pos++;
		}
		cout << ans << " ";
	}
	cout << endl;


	return 0;
}
