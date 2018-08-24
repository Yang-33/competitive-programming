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

/* -----  2018/08/24  Problem: yukicoder 227  / Link: http://yukicoder.me/problems/no/227  ----- */
/* ------問題------

5枚のカードが配られます。それぞれのカードには、1以上13以下のいずれかの整数が書かれています。カードに書かれている整数の組み合わせによって役が決まります。
配られた5枚のカードが、以下のいずれの役に該当するかを調べてください。複数の役に該当する場合は、以下で先に記述した方の役に該当するものとします。

FULL HOUSE
ある数をちょうど3つと、別の数をちょうど2つ含む。
THREE CARD
ある数をちょうど3つ含む。
TWO PAIR
ある数をちょうど2つと、別の数をちょうど2つ含む。
ONE PAIR
ある数をちょうど2つ含む。

-----問題ここまで----- */
/* -----解説等-----

three pairって書いていた(ええ

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N = 5;
	VI a(N); FOR(i, 0, N)cin >> a[i];
	SORT(a);
	VI b(14, 0); FOR(i, 0, N)b[a[i]]++;
	int two = 0; int three = 0;
	FOR(i, 1, 14) {
		if (b[i] == 2)two++;
		else if (b[i] == 3)three++;
	}
	string ans;
	if (two == 1 && !three)ans = "ONE PAIR";
	else if (two == 2)ans = "TWO PAIR";
	else if (!two && three)ans = "THREE CARD";
	else if (two && three)ans = "FULL HOUSE";
	else ans = "NO HAND";
	cout << ans << "\n";

	return 0;
}
