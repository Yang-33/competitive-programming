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

/* -----  2018/02/14  Problem: 060_arc_a / Link: https://arc060.contest.atcoder.jp/tasks/arc060_a?lang=en  ----- */
/* ------問題------

高橋君は、N 枚のカードを持っています。
i (1≤i≤N) 番目のカードには、整数 xi が書かれています。
高橋君は、これらのカードの中から 1 枚以上を選び、 選んだカードに書かれた整数の平均をちょうど A にしたいと考えています。
そのようなカードの選び方が何通りあるか求めてください。

-----問題ここまで----- */
/* -----解説等-----

これ無理！となったけど、値の小ささからこれはDPができる。
dp[今何枚目までみたか][何枚取ったか][選択したカードの和]:=組合せ
とすれば典型DPとして解ける。O(val*N^3)

もう一個解法は存在して、平均をAにするのは、a[i]-Aをいくつか取ったときにその総和が0になる組み合わせ数
として考えれば、dp[今何枚目まで見たか][総和]:=組合せ
として計算できる。
これはO(val*N^2)でできる
これできるようにしないと！

----解説ここまで---- */

LL N, A;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> A;
	VI a(N);
	FOR(i, 0, N) {
		cin >> a[i];
	}
	vector<VVL> dp(N + 1, VVL(N + 1, VL(2501, 0)));
	dp[0][0][0] = 1;
	FOR(i, 0, N) {
		FOR(k, 0, N) {
			FOR(val, 0, 2501) {
				if(val+a[i]<=2500)dp[i + 1][k + 1][val + a[i]] += dp[i][k][val];
				dp[i + 1][k][val] += dp[i][k][val];
			}
		}
	}
	FOR(i, 1, N+1) {
		ans += dp[N][i][i*A];
	}

	cout << ans << "\n";

	return 0;
}
