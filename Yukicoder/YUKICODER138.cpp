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

/* -----  2018/05/02  Problem: yukicoder 138  / Link: http://yukicoder.me/problems/no/138  ----- */
/* ------問題------

世の中的にはgcc 4.8.1が化石と言われているらしいです。

ここで、化石と言われてるバージョンが特定の文字列の形式A.B.C (A,B,Cはそれぞれ0以上100以下の整数である)で与えられるので、同じ形式で与えられたバージョンが化石かどうか判定してください。
化石のバージョンの場合は「YES」、化石のバージョンではない場合「NO」を出力してください

化石のバージョンとは、指定したバージョンと同じか、もしくはそれより古いものとする。
古いバージョンとは、「.」で区切られたものの、より左に書かれた数値が小さいかどうかとする。

例えば、4.8.1より 4.7.9のほうが古く、4.8.1より 4.9.0や5.0.1のほうが新しいとする

-----問題ここまで----- */
/* -----解説等-----

可能であれば、S進法にすると簡単。

----解説ここまで---- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int a, b, c;
	scanf("%d.%d.%d", &a, &b, &c);
	int v1 = 101 * 101 * a + 101 * b + c;
	scanf("%d.%d.%d", &a, &b, &c);
	int v2 = 101 * 101 * a + 101 * b + c;
	string ans = (v1 >= v2 ? "YES" : "NO");
	cout << ans << "\n";

	return 0;
}
