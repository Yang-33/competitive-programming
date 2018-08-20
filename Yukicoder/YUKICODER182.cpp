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

/* -----  2018/07/30  Problem: yukicoder 182  / Link: http://yukicoder.me/problems/no/182  ----- */
/* ------問題------

kamipeipaa君は新しいものが大好きです。
kamipeipaa君はある日N個の整数A1,A2,A3,....,ANを見つけました。
整数Aiに対して，Ai=Ajとなるjがi以外に存在しなければ，Aiは新規性があるのではないかとkamipeipaa君は考えました。 
上記の条件を満たす整数がいくつあるかkamipeipaa君に教えてあげてください。

-----問題ここまで----- */
/* -----解説等-----

mapで個数を確認する。

----解説ここまで---- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N; cin >> N;
	map<int, int>Map;
	FOR(i, 0, N) {
		int a; cin >> a;
		Map[a]++;
	}
	LL ans = 0;
	for (const auto&it : Map) {
		if (it.second == 1)ans++;
	}
	cout << ans << "\n";

	return 0;
}
