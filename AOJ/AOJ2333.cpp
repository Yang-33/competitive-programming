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

/* -----  2018/06/24  Problem: AOJ 2333 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2333  ----- */
/* ------問題------

僕には、たくさんの友達がいる。どの友達も、とても小さい。
僕は、よく友達と一緒に出かける。何人かの友達をリュックに入れて、一緒に出かける。
僕は毎朝、その日一緒に出かける友達を決める。空のリュックに、１人ずつ友達を入れていく。
僕は、あまり力が強くない。だから、同時に運べる友達の重さには限界がある。
僕は、重さの限界を超えないように友達を入れていく。どの順番で入れていくかは気分次第。
僕は、入れられる友達がまだ残っている限り、入れるのを止めない。決して止めない。
……ところで、リュックに入った友達の組み合わせは、全部で何パターンあるんだろう？

-----問題ここまで----- */
/* -----解説等-----

極大なつめかたの通り数

sortしたものについて考える。
ithを使うときは、W-a[i]をmaxとして考えれば良い。

ithを使わないときは、W-a[i]よりも大きい値をとればよい。
これはDPでできそう ？

ithの手前までは全部使って後は使ったり使わなかったりする、を全部調べる。
使わないものがあるとき、(W-a[i],W]をみればよい。(使うとあふれるようにすればよい)

えーこれ賢い

逆からやるとDP配列をそのまま使えて最高O(NW) !?

----解説ここまで---- */



void solve_1() {
	int N, W;
	cin >> N >> W;
	VI a(N);
	FOR(i, 0, N) {
		cin >> a[i];
	}

	SORT(a);

	VL sum(N + 1, 0);
	FOR(i, 0, N) {
		sum[i + 1] = sum[i] + a[i];
	}
	LL ans = sum[N] == W;
	FOR(i, 0, N) {
		VI dp(10010, 0);
		if (sum[i] > W)break;
		dp[sum[i]]++;// [0,i) (i,N-1]を考える。前は全部使って、あとは何でも良い
		FOR(j, i + 1, N) {
			for (int k = W; k >= sum[i] + a[j]; k--) {
				dp[k] += dp[k - a[j]];
				dp[k] %= MOD;
			}
		}
		FOR(j, W - a[i] + 1, W + 1) {
			ans += dp[j];
			ans %= MOD;
		}
	}

	cout << ans << "\n";
}

void solve_2() { // 同様だが逆からやると高速にできる

	int N, W;
	cin >> N >> W;
	VI a(N);
	LL sum = 0;
	FOR(i, 0, N) {
		cin >> a[i];
		sum += a[i];
	}

	RSORT(a);
	LL ans = 0;
	VL dp(10010, 0);
	dp[0] = 1;
	if (sum <= W)ans = 1;
	FOR(i, 0, N) {
		sum -= a[i];
		for (int j = max(0LL, W - sum - a[i] + 1); j <= W - sum; j++) {
			ans += dp[j];
			ans %= MOD;
		}
		for (int j = W - a[i]; j >= 0; j--) {
			dp[j + a[i]] += dp[j];
			dp[j + a[i]] %= MOD;
		}
	}

	
	cout << ans << "\n";


}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	//solve_1();
	solve_2();

	

	return 0;
}
