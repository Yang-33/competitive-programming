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

/* -----  2018/06/16  Problem: AOJ 1295 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1295  ----- */
/* ------問題------

正面からみた図形と横から見た図形がある。
これを三次元上で表現するとき、図形を満たすような最小の構成は。

-----問題ここまで----- */
/* -----解説等-----

ある値について、必ず使用しなければならない気がするので大きい方を選択する。

正しさの理解ができなかったので一年生に教えてもらった。
二次元平面上で考えると対応が付き、これよりもよい方法がないことが示せる。

----解説ここまで---- */

void solve() {

	int A, B;
	while (cin >> A >> B, A || B) {
		VI a(30), b(30);
		FOR(i, 0, A) {
			int in; cin >> in;
			a[in]++;
		}
		FOR(i, 0, B) {
			int in; cin >> in;
			b[in]++;
		}
		int ans = 0;
		FOR(i, 0, 30) {
			ans += max(a[i], b[i])*i;
		}
		cout << ans << endl;
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	solve();
	return 0;
}