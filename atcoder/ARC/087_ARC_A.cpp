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

/* -----  2017/12/16  Problem: ARC 087 A / Link: http://arc087.contest.atcoder.jp/tasks/arc087_a  ----- */
/* ------問題------

長さ N の正整数の列 a=(a1,a2,…,aN) が与えられます。 あなたの目標は、a のうちいくつかの要素を取り除き、a を 良い数列 にすることです。
ここで、数列 b が 良い数列 であるとは、次の条件が成り立つことです。
•b の各要素 x について、b に値 x はちょうど x 個含まれる。
例えば、(3,3,3), (4,2,4,1,4,2,4), () (空の数列) は良い数列です。 一方、(3,3,3,3), (2,4,1,4,2) は良い数列ではありません。
a を良い数列にするために取り除くべき要素の個数の最小値を求めてください。


-----問題ここまで----- */
/* -----解説等-----

少ないときはダメで、多いときはすり減らせばよい。

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	VL a(N);
	FOR(i, 0, N) {
		cin >> a[i];
	}
	SORT(a);
	map<LL, LL>m;
	FOR(i, 0, N) {
		m[a[i]]++;
	}
	UNIQ(a);

	FOR(i, 0, SZ(a)) {
		if (m[a[i]]<a[i])ans += m[a[i]];
		if(m[a[i]]>a[i])ans += m[a[i]]-a[i];
	}
	cout << ans << "\n";

	return 0;
}
