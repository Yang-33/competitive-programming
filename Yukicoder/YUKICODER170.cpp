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

/* -----  2018/07/26  Problem: yukicoder 170  / Link: http://yukicoder.me/problems/no/170  ----- */
/* ------問題------

入力に8文字以内の文字列Sが与えられる。
この文字列Sを構成する文字のうち、「任意の隣り合う2つの文字を入れ替える」操作を任意回行うことができるとき、
作ることができる文字列の種類の数を求めてください。

ただし、入力文字列Sと同一の文字列は数に含まないものとします。

-----問題ここまで----- */
/* -----解説等-----

全部列挙しました

----解説ここまで---- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);


	string s; cin >> s;
	set<string>Se;
	SORT(s);
	do {
		Se.insert(s);

	} while (next_permutation(ALL(s)));
	int ans = SZ(Se)-1;
	cout << ans << "\n";

	return 0;
}
