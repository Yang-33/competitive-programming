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

/* -----  2018/07/05  Problem: AOJ 3003 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/3003  ----- */
/* ------問題------

がっちょ君は期末試験が近づくとやる気がなくなってしまい、しばしば学校を休むようになる。
期末試験まで残りN日である。
がっちょ君のi日目のやる気はXiであり、i日目に学校に行くために必要なやる気はYiである。
がっちょ君は Xi ≥ Yi となる日のみ学校に行く。
がっちょ君を心配したハジ君は、がっちょ君を励ますことで、可能な限り学校に行かせようと考えた。
ハジ君は最初、励まし力Pを持っている。
ハジ君がi日目に励まし力t(tは0以上の任意の実数)を消費してがっちょ君を励ますと、 がっちょ君のi日目のやる気はtだけ増加して、ハジ君の励まし力はtだけ減少する。さらに、i+1 ≤ Nのとき、i+1日目のがっちょ君のやる気Xi+1はmax(0, Xi+1 − t) に変化する。
ハジ君は自分の持っている励まし力を超えて励ますことはできない。

ハジ君が最適な励まし方をしたときの、がっちょ君が学校に行く最大日数を求めよ。

-----問題ここまで----- */
/* -----解説等-----

dp(i,t,p):=i日目で前日からの影響tをうけてあとp使えるときの、最大の日数
から、dpを改善していく。
まずtはi日目までに連続何日応援したかがわかれば一意に求められる。
dp(i,j,p):=Max(i日,j連続,残りp)
まだでかいが、答えが小さいことを考えると、最終的に
dp(i,j,k):=i日目にj回連続で応援を受けていて、k回登校したときに、必要な応援の最小量
とする。これはO(N^3+N^3)で解ける。
tableパートが全くわからなかった。

----解説ここまで---- */

using ll = LL;
#define int long long 
int dp[110][110][110];
void solve() {
	int N, P; cin >> N >> P;
	vector<int> x(N), y(N);
	FOR(i, 0, N) {
		cin >> x[i] >> y[i];
	}
	fill(**dp, **dp + 110 * 110 * 110, INF);
	dp[0][0][0] = 0;
	vector<vector<int>>table(N + 1, vector<int>(N + 1, 1e18));
	for (int i = 0; i < N; i++) table[i][0] = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 1; j <= i; j++) {
			ll Psum = 0;
			ll t = 0;
			for (int k = i - j; k < i; k++) {
				t = max(0LL, y[k] - max(0LL, x[k] - t));
				Psum += t;
			}
			//			table[i][j] = Psum;
			table[i][j] = t;
		}
	}

	FOR(i, 0, N) {
		FOR(j, 0, i + 1) {
			FOR(k, 0, N) {
				if (dp[i][j][k] == INF)continue;
				dp[i + 1][0][k] = min(dp[i + 1][0][k], dp[i][j][k]);// 無

				int val = table[i][j]; // i日目時点でのj回連続で応援しているときのやるきの減少
				int val2 = max(0LL, x[i] - val); //現在のやるき
				dp[i + 1][j + 1][k + 1] = min(dp[i + 1][j + 1][k + 1], dp[i][j][k] + max(0LL, y[i] - val2));
				// 応援していかせる

				if (val2 >= (y[i]))
					dp[i + 1][0][k + 1] = min(dp[i + 1][0][k + 1], dp[i][j][k]);
				// 勝手に行く


				//[i+1][j+1][k] =  必要なさそう
			}
		}
	}

	int ans = 0;
	FOR(i, 0, N + 1) {
		FOR(j, 0, N + 1) {
			if (dp[N][i][j] <= P) {
				ans = max(ans, j);
			}
		}
	}
	cout << ans << endl;
}

signed main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	solve();

	return 0;

}