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

/* -----  2018/04/10  Problem: yukicoder 032  / Link: http://yukicoder.me/problems/no/032  ----- */
/* ------問題------

太郎君はいつも小銭を貯金していて、硬貨を貯金箱に入れています。
貯金箱の中身がある程度たまったので、
太郎君は銀行に行って両替をしてもらうことにしました。

太郎君の国では通貨として1000円札の紙幣と、100円、25円、1円の硬貨があります。
それ以外の金額の紙幣や硬貨はありません。

両替は、
・1円硬貨25枚で25円硬貨1枚に
・25円硬貨4枚で100円硬貨1枚に
・100円硬貨10枚で1000円札1枚に
それぞれ替えることができます。

入力に、貯金箱の中身としてそれぞれの硬貨の枚数が与えられるので、
硬貨の枚数が最も少なくなるように両替したとき、
最終的に太郎君が所持する硬貨の合計枚数を出力してください。

両替は手数料無く何度でもすることができます。
また、両替の前後で総額が変化してはいけません。

-----問題ここまで----- */
/* -----解説等-----



----解説ここまで---- */


LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	
	int c100, c25, c1;
	cin >> c100>>c25>>c1;
	c25 += c1 / 25; c1 %= 25;
	c100 += c25 / 4; c25 %= 4;
	c100 %= 10;
	ans = c100 + c25 + c1;
	cout << ans << "\n";

	return 0;
}
