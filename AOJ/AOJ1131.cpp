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

/* -----  2018/06/30  Problem: AOJ 1131 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/1131  ----- */
/* ------問題------

分子が1であり分母が正整数である分数を単位分数と呼ぶ． 正の有理数 p/q を有限個の単位分数の和として表現したものを， p/q の単位分数への「分割」と呼ぶ． 例えば， 1/2 + 1/6 は 2/3 の単位分数への分割である． 足し算の順序の違いは無視する． 例えば， 1/6 + 1/2 を 1/2 + 1/6 と区別しない．
与えられた四つの正整数 pと qと aと n に対して， p/q の単位分数への分割で以下の二つの条件を満たすものの個数を数えなさい．
分割は n個以下の単位分数の和である．
分割に含まれる単位分数の分母の積は a 以下である．
例えば， (p,q,a,n) = (2,3,120,3) ならば， 4と報告しなければならない．なぜならば，
2/3 = 1/3 + 1/3 = 1/2 + 1/6 = 1/4 + 1/4 + 1/6 = 1/3 + 1/6 + 1/6
で，条件を満たす分割が尽くされるからである．

-----問題ここまで----- */
/* -----解説等-----

適当に式変形すると、p/q = 1/x + 1/y は復元可能になるので再帰的に計算できればよい。

----解説ここまで---- */

LL ans;
int p, q, a, n;

void f(int idx, int mul, int dwup, VI& val) {
	int sum = 0;
	FOR(i, 0, idx) {
		sum += mul / val[i];
	}
	if (p*mul == q * sum)ans++;
	if (p*mul < sum*q)return;
	if (idx == n)return;
	FOR(i, dwup, a + 1) {
		if (i*mul <= a) {
			val[idx] = i;
			f(idx + 1, mul*i, i, val);
		}
		else
			break;
	}
}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);


	while (cin >> p >> q >> a >> n, p || q) {
		ans = 0;
		VI val(10, 0);
		f(0, 1, 1, val);
		cout << ans << endl;
	}

	return 0;
}