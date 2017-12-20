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

/* -----  2017/12/20  Problem: AOJ 0357 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0357  ----- */
/* ------問題------

兄弟であるＡ君とＢ君は、毎年それぞれお年玉をもらっています。とても仲の良い２人は、２人のお年玉を足し合わせて半分ずつに分けています。２人がもらうお年玉の金額は、それぞれ1000 の倍数です。
Ａ君とＢ君がもらった金額が与えられたとき、１人当たりが得る金額を出力するプログラムを作成せよ。

-----問題ここまで----- */
/* -----解説等-----

平均値

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int a, b; cin >> a >> b;
	ans = (a+b) / 2;
	cout << ans << "\n";

	return 0;
}
