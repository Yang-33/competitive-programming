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

/* -----  2018/09/23  Problem: yukicoder 275  / Link: http://yukicoder.me/problems/no/275  ----- */
/* ------問題------

N個の整数Aiが与えられるので、その中央値（メジアン）を求めてください。

中央値（メジアン）とは、小さい順に並べたとき中央に位置する値。
データが偶数個の場合は、中央に近い2つの値の算術平均（いわゆる普通の平均）をとる。
(Wikipediaから引用)
中央値: Wikipedia

小数第一位まで求めてください。
（数値が正しければ、0の小数桁が含まれてても良い）

-----問題ここまで----- */
/* -----解説等-----

sortしてまんなか。

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N; cin >> N;
	VI a(N);
	FOR(i, 0, N) {
		cin >> a[i];
	}
	SORT(a);
	double ans = (SZ(a) & 1 ? a[SZ(a) / 2]
		:(a[SZ(a)/2-1]+a[SZ(a)/2])/2.0 );
	cout << ans << "\n";

	return 0;
}
