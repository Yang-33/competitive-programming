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
#define FOR(i, s, e) for (LL(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (int(i) = (s); (i) > (e); (i)--)
#define debug(x) cerr << #x << ": " << x << endl
const int INF = 1e9;                          const LL LINF = 1e18;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/04/06  Problem: yukicoder 010  / Link: http://yukicoder.me/problems/no/010  ----- */
/* ------問題------

あなたは、Isaacから借りたノートをコピーしようとしてOCRにかけようとしている。
ある計算式をOCRしようとしたら、演算子を正しく認識されてなく、文字化けしていることに気づいた。
ここに出てくる演算子は+と*のみで、すべて?と表示されてしまっている。
元の数式の正しい数式を求めてください。
複数回答がある場合は、{+,*} の順の辞書列順の最初のものを求めてください。
例えば辞書順は
++ → +* → *+ → **　の順番である。

重要：この問題では優先順位は同じとし、左結合とする。
簡単に言うと左から順に処理するだけである。
例えば1 ? 2 ? 10 ? 1=31の場合 1+2*10+1が答えで
実際の世界では((1+2)*10)+1=31　となるので注意。

-----問題ここまで----- */
/* -----解説等-----

最小の情報を持たせるためにこれを2進数表現で保持する。(後で復元できるように)
dp[i][j]:= a[i]を使って、演算の選択をしたときに結果がjとなるような辞書順最小の演算結果
としてDP
1LL << x さん…でWAした。

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	LL total; cin >> total;
	VL a(N);
	FOR(i, 0, N) {
		cin >> a[i];
	}
	VVL dp(N, VL(total + 1, LINF));
	dp[0][a[0]] = 0;
	FOR(i, 1, N) {
		FOR(j, 0, total + 1) {
			if (dp[i-1][j] == LINF)continue;
			if(j+a[i] <=total)dp[i][j+a[i]] = min(dp[i][j+a[i]], dp[i-1][j] * 2);     // +
			if(j*a[i]<=total)dp[i][j*a[i]] = min(dp[i][j*a[i]], dp[i-1][j] * 2 + 1); // *
		}
	}
	// 復元 

	ans = dp[N-1][total];
	// N-1回
	FOR(i, 0, N - 1) {
		if (ans & (1LL << (N - i - 2))) {
			cout << "*";
		}
		else {
			cout << "+";
		}
	}

	cout << endl;
	//cout << ans << "\n";

	return 0;
}
