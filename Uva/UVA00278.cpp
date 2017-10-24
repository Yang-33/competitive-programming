#include "bits/stdc++.h"
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

/* -----  2017/10/18  Problem: Uva 00278  / Link: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=4&problem=214&mosmsg=Submission+received+with+ID+20195781  ----- */
/* ------問題------

H*Wルークキングクイーンナイト問題

-----問題ここまで----- */
/* -----解説等-----

各盤面で何個置けるか考えればよい。
クイーン、ルークはそれぞれ一つ置くごとにラインが上下左右に消えていく。
キングは周囲一マスを移動するだけなので、各ラインにひとつ飛ばしで置くことができる。
ナイトは盤面の半分より一個大きい値を持つことができる。(偶数値のときはそのまま)

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	FOR(i, 0, N) {
		char c;
		int x, y;
		cin >> c >> y >> x;
		if (c == 'k') { ans=ceil(x*y/2.0); }//半分overぐらい
		else if (c == 'K') { ans = (ceil(y / 2.0)*(ceil(x / 2.0))); }//なんか一個飛ばし
		else  { ans=min(x,y); }//移動範囲から小さい方
		cout << ans << "\n";
	}


	return 0;
}
