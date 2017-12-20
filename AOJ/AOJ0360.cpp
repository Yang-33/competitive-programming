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

/* -----  2017/12/20  Problem: AOJ 0360 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0360  ----- */
/* ------問題------

ＰＣＫ研究所が運用するスーパーコンピュータ「エル」は、研究所外部の企業や大学などの依頼に応じて様々な計算を行っています。エルの使用には予約が必要で、予約の際は開始時刻と終了時刻を指定します。ただし、異なる予約が重複してはいけません。

新しい予約が、すでに存在する予約のどれかと重複するかを報告するプログラムを作成せよ。ただし、ある予約の終了時刻と、別の予約の開始時刻が同じ場合は重複しないと考えて良い。また、すべての時刻は、エルの運用開始からの経過分数で与えられる。

-----問題ここまで----- */
/* -----解説等-----

imos法とかでやる。
やらなくてもよさそう

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int a, b; cin >> a >> b;
	cin >> N;
	VI m(1003, 0);
	FOR(i, 0, N) {
		int s, t; cin >> s >> t;
		m[s]++;
		m[t]--;
	}
	FOR(i, 0, 1000) {
		m[i + 1] += m[i];
	}
	ans = 0;
	FOR(i, a, b) {
		if (m[i] != 0)ans = 1;
	}
	cout << ans << "\n";

	return 0;
}
