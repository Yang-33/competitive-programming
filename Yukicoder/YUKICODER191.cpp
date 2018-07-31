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

/* -----  2018/07/31  Problem: yukicoder 191  / Link: http://yukicoder.me/problems/no/191  ----- */
/* ------問題------

とある地域、ユキ県コダ市では市議会議員選挙が行われます。

市議会議員選挙に出馬するためには、供託金というものが必要となります。 (供託金:Wikipedia)
立候補するには供託金30万円を供託所に供託する必要があり、
候補者の得票数が有効投票総数の10分の1を上回っていれば全額返還され、
10分の1以下の場合は全額没収され市に納められます。
本来返還には手続きが必要ですが、ここでは自動的に返還されるものとします。

ユキ県コダ市ではN人が出馬し、それぞれの候補者はCi (1≤i≤N)票得票しました
このとき、選挙終了後にユキ県コダ市に納められる供託金の合計金額を求めてください。

(問題とは関係有りませんが、選挙の種類によって供託金の金額や没収基準は異なります)

-----問題ここまで----- */
/* -----解説等-----

総和の10分の1以下の数*30を出力する。

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N; cin >> N;
	VL a(N);
	FOR(i, 0, N) {
		cin >> a[i];
	}
	LL sum = accumulate(ALL(a), 0LL);
	LL ans = 0;
	FOR(i, 0, N) {
		if (sum >= 10 * a[i])ans++;
	}
	ans *= 30;
	cout << ans << "\n";

	return 0;
}
