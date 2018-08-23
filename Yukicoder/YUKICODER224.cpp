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

/* -----  2018/08/23  Problem: yukicoder 224  / Link: http://yukicoder.me/problems/no/224  ----- */
/* ------問題------

さnの2つの文字列S, Tが与えられます。文字列を構成する各文字は、'a'～'z'です。
今、Sに以下の操作を順次実施してTに変換したいです。
そのような一連の操作のうち、操作回数の最小となるものについて、その最小値を出力するプログラムを書いて下さい。

(操作)
Sの中から文字S[ i ]を1個選んで、その文字を'a'～'z'のいずれかの好きな文字に変更します

-----問題ここまで----- */
/* -----解説等-----

操作が変更しか無いので前から見ていけば良い。

----解説ここまで---- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N; cin >> N;
	string s, t;  cin >> s >> t;
	int ans = 0;
	FOR(i, 0, N) {
		if (s[i] != t[i])ans++;
	}

	cout << ans << "\n";

	return 0;
}
