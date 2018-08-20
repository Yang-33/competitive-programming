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

/* -----  2018/07/28  Problem: yukicoder 171  / Link: http://yukicoder.me/problems/no/171  ----- */
/* ------問題------

入力に1000文字以内の文字列Sが与えられる。
この文字列Sを構成する文字のうち、「任意の隣り合う2つの文字を入れ替える」操作を任意回行うことができるとき、
作ることができる文字列の種類の数をmod573 で求めてください。

ただし、入力文字列Sと同一の文字列は数に含まないものとします。
573は素数ではないことに注意してください。

-----問題ここまで----- */
/* -----解説等-----

重複の数え上げはN!/(a!b!c!)みたいにやれば良い。
これはcombinationの式に変えられるので変える。

----解説ここまで---- */
const int SIZE = 1010;
long long  comb[SIZE + 1][SIZE + 1];
/* nCk を求める */
void calcomb() {
	int  i, j;
	for (i = 0; i <= SIZE; i++) {
		for (j = 0; j <= i; j++) {
			if (j == 0 || j == i)
				comb[i][j] = 1;
			else
				comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j] % 573;
		}
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string s; cin >> s;
	LL ans = 1;

	VI alpha(26, 0);
	FOR(i, 0, SZ(s)) {
		alpha[s[i]-'A']++;
	}
	calcomb();
	int N = SZ(s);
	FOR(i, 0, 26) {
		int sz = alpha[i];
		ans *= comb[N][sz];
		ans %= 573;
		N -= sz;
	}
	ans = ans - 1 + 573;
	ans %= 573;
	cout << ans << "\n";

	return 0;
}
