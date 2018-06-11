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

/* -----  2018/06/11  Problem: AOJ 1619 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1619  ----- */
/* ------問題------

太郎君は，近頃弁当作りにはまっている． 太郎君は今日新しい弁当レシピ本を手に入れたので，そこに書いてあるレシピをできるだけ多く試してみたいと思っている．
どのレシピに必要な材料も十分に手元にあるのだが，みんな 2 つ入りの真空パックになっている． 1 つだけ使って 1 つ残したら，残った方はすぐ腐ってしまう． かといって同じレシピの弁当を 2 つ作っても面白くない． だから彼は同じ弁当を複数作らず，しかも半端な材料が残らないようなレシピの組み合わせを選ぶことにした．
レシピ本には，同じ材料を使っても違うレシピの弁当も載っているかもしれないことに注意せよ．
この方針に従うと，今日太郎君は最大で何種類のレシピを試せるのだろうか．

-----問題ここまで----- */
/* -----解説等-----

全探索+DPを場合分けする
悔しい！

----解説ここまで---- */
void solveHANBUN(VVI & b) {
	int N = SZ(b);
	int M = SZ(b[0]);
	// N <=25 -> 500>=M>=25
	// 半分全列挙わからん
	int mp[501];
	int ans = 0;
	FOR(i, 0, 1 << N) {
		int flag = 1;
		int cnt = 0;
		fill(mp, mp + 501, 0);
		FOR(j, 0, N) {
			if (i & (1 << j)) {
				cnt++;
				FOR(k, 0, M) {
					mp[k] += b[j][k];
				}
			}

		}

		FOR(k, 0, M) {
			if (mp[k] % 2)flag = 0;
		}
		if (flag)ans = max(ans, cnt);
	}
	cout << ans << endl;
}
void solveMapDP(VVI & b) {
	// 本番なら全部こっちで良くないですか?良いですね
	int N = SZ(b);
	int M = SZ(b[0]);
	// N>=25 -> M<=25
	VL a(N);
	FOR(i, 0, N) {
		LL state = 0;
		FOR(j, 0, M) {
			if (b[i][j])state |= 1 << j;
		}
		a[i] = state;
	}

	VL dp(1 << M, -1);
	dp[0] = 0;
	FOR(i, 0, N) {
		VL nxdp = dp;
		FOR(k, 0, (1 << M)) {
			if (dp[k] == -1)continue;
			LL nx = k ^ a[i];
			nxdp[nx] = max(nxdp[nx], dp[k] + 1);
		}
		dp = nxdp;
	}
	cout << dp[0] << endl;
}


void solve() {
	int N, M;
	while (cin >> N >> M, M || M) {
		vector<vector<int>>b(N, vector<int>(M));

		FOR(i, 0, N) {
			string s;
			cin >> s;
			FOR(j, 0, M) {
				b[i][j] = s[j] == '1';
			}
		}

		if (N < M) {
			solveHANBUN(b);
		}
		else {
			solveMapDP(b);
		}
	}
}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	solve();
	return 0;
}