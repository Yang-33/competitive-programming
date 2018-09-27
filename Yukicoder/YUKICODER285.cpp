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

/* -----  2018/09/26  Problem: yukicoder 285  / Link: http://yukicoder.me/problems/no/285  ----- */
/* ------問題------

ある国の通貨単位は「ユキコダ」である。
いまからDユキコダの品物を買おうとしている？
しかし、品物の金額に対して消費税率8%の消費税が加算される。
消費税加算後の金額はいくらか？
小数点以下も誤差なく正確に計算すること。
数値があっていれば、余計な小数桁が含まれていてもよい。
丸め誤差に注意してください。

-----問題ここまで----- */
/* -----解説等-----

誤差なあ

----解説ここまで---- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N; cin >> N;
	LL ans = N * 108;
	cout << ans / 100 << "." << (ans % 100)/10<< ans%10 << endl;
///	cout << fixed << setprecision(10) << ans << "\n";

	return 0;
}
