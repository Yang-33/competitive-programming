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

/* -----  2018/02/24  Problem: code-festival-2017-qual-a_c / Link: https://code-festival-2017-quala.contest.atcoder.jp/tasks/code_festival_2017_quala_c?lang=en  ----- */
/* ------問題------

縦 H 行、横 W 列の行列 A があります。 上から i 行目、左から j 列目の要素を aij とします。 各 aij は英小文字です。
すぬけ君は、A の要素を自由に並べ替え、縦 H 行、横 W 列の行列 A' を作ろうとしています。 このとき、次の条件が成り立つようにします。
A' のどの行およびどの列もそれぞれ回文になっている。
条件を満たす A' が存在するか判定してください。

-----問題ここまで----- */
/* -----解説等-----

対象になるためには4点対称な場所に置けば良い。
残りを考えると、H,Wのどちらかが奇数だと2個対、全部奇数で1点のみ1個だけをおける。
これを実際に確かめる。

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int H, W;
	cin >> H >> W;
	VS s(H);
	FOR(i, 0, H) {
		cin >> s[i];
	}
	VI a(26, 0);
	FOR(i, 0, H) {
		FOR(j, 0, W) {
			a[s[i][j] - 'a']++;
		}
	}
	ans = 1;
	int c1 = 0, c2 = 0;
	FOR(i, 0, 26) {
		if (a[i] % 4 == 2)c2++;
		if (a[i] % 2 == 1)c1++;
	}
	if (c1 > 1)ans = 0;
	if (c1 && ((H % 2 == 0) || (W % 2 == 0)))ans = 0;
	if (H % 2 == 1)c2 -= W / 2;
	if (W % 2 == 1)c2 -= H / 2;
	if (c2 > 0)ans = 0;

	cout << (ans ? "Yes" : "No") << "\n";

	return 0;
}
