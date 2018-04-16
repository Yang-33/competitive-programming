#include <bits/stdc++.h>
using namespace std;

using VS = vector<string>;    using LL = long long;
using VI = vector<int>;       using VVI = vector<VI>;
using PII = pair<int, int>;   using PLL = pair<LL, LL>;
using VL = vector<LL>;        using VVL = vector<VL>;

#define ALL(a)  begin((a)),end((a))
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define EB emplace_back
#define MP make_pair
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

/* -----  2018/04/16  Problem: yukicoder 080  / Link: http://yukicoder.me/problems/no/080  ----- */
/* ------問題------

A君は四角形を描こうとしています。
描く四角形は正方形か長方形でなければなりません。
また、どの辺の長さも整数cmでなければなりません。
A君の持っている鉛筆はあとちょうどDcmしか線が引けなさそうです。
A君が描ける最も大きな四角形の面積を答えなさい。
なお、四角形が描けないときの面積は0とせよ

-----問題ここまで----- */
/* -----解説等-----

方程式を書くとO(1)
面倒くさいのでO(N)

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	FOR(i, 1, N/2) {
		int j = (N - 2 * i)/2;
		LL ret = i*j;
		ans = max(ans, ret);
	}
	cout << ans << "\n";

	return 0;
}
