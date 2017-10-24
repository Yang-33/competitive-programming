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

/* -----  2017/10/22  Problem: codefestival2017_qual_b A  / Link: https://beta.atcoder.jp/contests/code-festival-2017-qualc  ----- */
/* ------問題------

すぬけ君は、あるプログラミングコンテストのためにジャッジシステムを作りました。

このジャッジシステムにプログラムを提出すると、文字列
S からある連続する
2 文字を取り出した文字列が結果として返ってきます (どの連続する
2 文字も結果として返ってくることがありえます)。
このジャッジシステムにプログラムを提出した結果として AC という文字列が返ってくることがありえるかどうか判定してください。

-----問題ここまで----- */
/* -----解説等-----

s.find("AC")

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;
	FOR(i, 0, SZ(s) - 1) {
		if (s[i] == 'A'&&s[i + 1] == 'C')ans++;
	}
	if (ans>0)cout << "Yes" << "\n";
	else cout << "No" << "\n";

	return 0;
}