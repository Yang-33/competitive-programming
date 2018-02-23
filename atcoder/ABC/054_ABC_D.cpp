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

/* -----  2018/02/15  Problem: 054_abc_d / Link: https://abc054.contest.atcoder.jp/tasks/abc054_d?lang=en  ----- */
/* ------問題------

イルカは、微量の物質Cを生成したいと考えています。
物質Cを生成するためには、タイプAの物質とタイプBの物質の混合比が Ma:Mb となる溶液を用意する必要があります。
しかし、イルカは薬品を1つも持っていないため、薬局へ薬品を買いに行くことにしました。
薬局では、N 種類の薬品を取り扱っており、各薬品 i の在庫はちょうど1つです。
各薬品 i は、タイプAの物質 ai グラム、タイプBの物質 bi グラム含んでおり、価格 ci 円で売られています。 
イルカは、いくつかの薬品を薬局で買います。買った薬品は全て使わなければなりません。
物質Cを生成するために、必要な最小予算を求めてください。 
薬局で売られている薬品の組み合わせで、物質Cを生成できない場合はそれを報告してください。

-----問題ここまで----- */
/* -----解説等-----

半分全列挙かなと思ったけどマージ検索がわからなかったのでDPでできる。
更新順番は後ろからやると良くて、dp[aの重さ][bの重さ]:=コスト最小
として最後にindexを検索すれば良い。

半分全列挙はできて、map上で検索すれば良い。

----解説ここまで---- */

LL N,A,B;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N>>A>>B;
	VI a(N), b(N), c(N);
	FOR(i, 0, N) {
		cin >> a[i] >> b[i] >> c[i];
	}

	VVI dp(401, VI(401, INF));

	dp[0][0] = 0;
	FOR(i, 0, N) {
		FORR(aa, 400, 0-1) {
			FORR(bb, 400, 0-1) {
				if(aa+a[i]<=400&&bb+b[i]<=400)dp[aa+a[i]][bb+b[i]] = min(dp[aa+a[i]][bb+b[i]], dp[aa][bb] + c[i]);
			}
		}
	}
	ans = INF;
	FOR(i, 1, 401) {
		if (A*i<=400 && B*i<=400) {
			ans = min(ans, (long long )dp[A*i][B*i]);
		}
	}
	if (ans == INF)ans = -1;
	cout << ans << "\n";

	return 0;
}
