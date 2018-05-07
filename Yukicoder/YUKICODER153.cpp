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
#define debug(x) cerr << #x << ": " << x << endl
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/05/05  Problem: yukicoder 153  / Link: http://yukicoder.me/problems/no/153  ----- */
/* ------問題------

N個の石が積まれた山が1つある。
A君とB君が交互に石を分けるゲームを行う。
分けるときに石を2つの山か3つの山に分ける。

xを正の整数とするとき、

2x個の石をx個とx個に分ける。
2x+1個の石をx個とx+1個に分ける。
3x個の石をx個とx個とx個に分ける、
3x+1個の石をx個とx個とx+1個に分ける。
3x+2個の石をx個とx+1個とx+1個に分ける。

以上の操作を選んでできるものとする。

-----問題ここまで----- */
/* -----解説等-----

grundy数をやっていく。
[記事](http://yang33-kassa.hatenablog.com/entry/2017/12/21/202812)

----解説ここまで---- */

int f(int n, VI& grundy) {
	if (grundy[n] != -1)return grundy[n];

	set<int>se;

	if (n >= 2) {
		se.insert(f((n + 1) / 2, grundy) ^ f(n / 2, grundy));
	}
	if (n >= 3) {
		if (n % 3 == 1)se.insert(f(n / 3 + 1, grundy));
		else se.insert(f(n / 3, grundy));
	}

	int subg = 0;
	while (se.count(subg))subg++;
	return grundy[n] = subg;
}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N; cin >> N;

	VI grundy(N + 1, -1);
	grundy[0] = grundy[1] = 0;
	int ans = f(N, grundy);
	cout << (ans != 0 ? "A" : "B") << "\n";

	return 0;
}
