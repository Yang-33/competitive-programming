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

/* -----  2018/04/10  Problem: yukicoder 037  / Link: http://yukicoder.me/problems/no/037  ----- */
/* ------問題------

Raymondは、遊園地に遊びに来ている。
遊園地の滞在時間はT時間で、各アトラクションの満足度が i番目のアトラクションに乗ったら、満足度Viが得られる。

しかし、遊園地は、どのアトラクションも行列であり、なかなか乗ることが出来ない。
i番目のアトラクションの行列は、ci時間並ぶことでアトラクションに乗れるとする。
(アトラクション自体の時間は行列の時間に含まれているとする）

しかし、Raymondは同じアトラクションにはあまり乗りたくない。
滞在時間中に同じアトラクションに乗った場合は、 満足度は「Viの半分小数切り捨て」しか得られず、その値を新たなViとする。
それ以降、また同じアトラクションに乗るたびに半減していく。

滞在時間の T時間の間に得られる最大の満足度を得たいとするとき、 その得られる満足度を求めてください。

-----問題ここまで----- */
/* -----解説等-----

dp[t]:=時刻tにおける満足度の最大値　を考える。
あるアトラクションについて10回以上は同じやつに乗れないので、
ある時間について、アトラクションに何回乗るかを一度に遷移させてやれば良い。
これは別々に分けることと一緒で、分けたものも時間が一緒なので、同じ時間幅に対しては
必ず値が高いものが加算されるのが、別々に分けてもいい理由である。

----解説ここまで---- */



int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL T, N;	cin >> T >> N;
	VI c(N), v(N);
	FOR(i, 0, N) {
		cin >> c[i];
	}
	FOR(i, 0, N) {
		cin >> v[i];
	}
	VI dp(T + 1, 0);
	FOR(i, 0, N) {
		FORR(t, T - 1, 0 - 1) {
			int sumT = 0;
			int sumV = 0;
			int V = v[i];
			FOR(j, 0, 10) {
				sumT += c[i];
				sumV += V;
				V /= 2;
				if (t + sumT <= T ) {
					dp[t + sumT] = max(dp[t + sumT], dp[t] + sumV);
				}

			}
		}
	}
	int ans = 0;
	FOR(t, 0, T + 1) {
		ans = max(ans, dp[t]);
	}
	cout << ans << "\n";

	return 0;
}
