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

/* -----  2018/06/24  Problem: AOJ 1600 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1600  ----- */
/* ------問題------

国際競技プログラミング大学 (International Competitive Programming College) は，競技プログラミングの研究でよく知られた大学である． この大学の志願者は入学試験を受験しなくてはいけない．
入学試験の合格者は以下のように選ぶ．
どの合格者の得点も，どの不合格者の得点より高い．
合格者数 n は nmin 人以上，nmax 人以下とする． n はこの範囲内でギャップを最大とするものでなくてはいけない． ギャップとは合格者の最低点と不合格者の最高点の差である．
同じギャップになる n が複数あるときは，その中で n が最大になるように選ぶ．
Sample Input の最初のふたつの例を見てみよう． 最初の例では，nmin が 2, nmax が 4 で，5 人の受験者の得点が 100, 90, 82, 70, 65 となっている． 合格者を 2, 3, 4 人としたときのギャップは，それぞれ 8, 12, 5 となる． n としてはギャップが最大となる 3 を選ばなくてはいけない．

2 番目の例では，nmin が 2, nmax が 4 で，5 人の受験者の得点が 100, 90, 80, 75, 65 となっている． 合格者を 2, 3, 4 人としたときのギャップは，それぞれ 10, 5, 10 となる． ギャップは合格者 2 人および 4 人のときに最大となるが，n としてはそのうちの最大の 4 を選ばなくてはいけない．

あなたには，この規則に基づいて合格者数を計算するプログラムを作ってほしい．

-----問題ここまで----- */
/* -----解説等-----

そのままやっていけばよい

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, Nmin, Nmax;
	while (cin >> N >> Nmin >> Nmax, N) {
		VI a(N);
		FOR(i, 0, N) {
			cin >> a[i];
		}
		sort(a.rbegin(), a.rend());
		int ans = 0;
		int ansid = 0;
		FOR(p, Nmin, Nmax + 1) {
			int ret = 0;
			ret = abs(a[p - 1] - a[p]);
			if (ans <= ret) {
				ans = ret;
				ansid = max(ansid, p);
			}
			ans = max(ans, ret);
		}
		cout << ansid << endl;

	}

}