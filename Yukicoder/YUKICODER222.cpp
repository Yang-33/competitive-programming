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

/* -----  2018/08/23  Problem: yukicoder 222  / Link: http://yukicoder.me/problems/no/222  ----- */
/* ------問題------

真っ当な人間は、文字列 "x+y" を x + y として解釈して、文字列 "x-y" を x - y として解釈するだろう。
ところが、アリスは足し算と引き算を逆に認識している。
つまり、文字列 "x+y" を x - y として解釈して、文字列 "x-y" を x + y として解釈する。
入力された文字列に対して、アリスの解釈での演算の結果を出力してください。真っ当な人間は、文字列 "x+y" を x + y として解釈して、文字列 "x-y" を x - y として解釈するだろう。
ところが、アリスは足し算と引き算を逆に認識している。
つまり、文字列 "x+y" を x - y として解釈して、文字列 "x-y" を x + y として解釈する。
入力された文字列に対して、アリスの解釈での演算の結果を出力してください。

-----問題ここまで----- */
/* -----解説等-----

scanf()をすればいい、それはそう

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string s; cin >> s;
	int splitPos = 0;
	FOR(i, 1, SZ(s)) {
		if (!isdigit(s[i])) { splitPos = i; break; }
	}
	assert(splitPos != 0);
	int X = stoi(s.substr(0,splitPos));
	int Y = stoi(s.substr(splitPos+1, SZ(s) - splitPos));
	if (s[splitPos] == '+') {
		cout << X - Y << endl;
	}
	else {
		cout << X + Y << endl;
	}

	return 0;
}
