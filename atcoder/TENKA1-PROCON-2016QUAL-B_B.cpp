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

/* -----  2018/02/26  Problem: tenka1-procon-2016qual-b_b / Link: https://tenka1-2016-qualb.contest.atcoder.jp/tasks/tenka1_2016_qualB_b  ----- */
/* ------問題------

天下一魔力発電所は不思議な魔術で電気を生み出すことができる発電所です。

魔力発電に用いる燃料は以下の様な文字列 S です。

S は ( と ) で構成されており、S の文字数は偶数です。

天下一ワープロでこの文字列を対応の取れた文字列に書き換えることで魔力発電に成功します。

対応が取れた文字列とは、以下の文字列です。

() は対応が取れた文字列である。
T が対応が取れた文字列であるとき、(T) も対応が取れた文字列である。
T, U が対応が取れた文字列であるとき、TUも対応が取れた文字列である。
天下一ワープロには以下 4 通りの操作があります。

はじめはカーソルは S の先頭の文字を指します。

カーソルを右に動かす（カーソルが末尾の文字を指す場合は動かない）
カーソルを左に動かす（カーソルが先頭の文字を指す場合は動かない）
カーソルが指す文字が ( のとき、その文字を ) に変更する
カーソルが指す文字が ) のとき、その文字を ( に変更する

発電所の責任者であるフデくんは最も少ない操作回数で文字列を対応が取れた文字列に書き換えたいです。

S が与えられるので、対応の取れた文字列に書き換える最も少ない操作回数を求めてください。

-----問題ここまで----- */
/* -----解説等-----

まず、1,(変更)のみでよい
JAG以降カッコの探索は再帰と決めている。
あとは再帰でシュミレーションしてできるね

----解説ここまで---- */

LL N;

LL ans = 0LL;
LL dp[102][102][102];


LL f(int i, int dep, int last, string &s) {
	if (dep < 0)return INF;
	if (i == N) {
		if (dep == 0)return last - i;
		else return INF;
	}

	LL &ret = dp[i][dep][last];
	if (ret != -1)return ret;

	ret = INF;
	if (s[i] == '(') {
		ret = min(ret, f(i + 1, dep + 1, last, s) + 1);// ->
		ret = min(ret, f(i + 1, dep - 1, i, s) + 2);// RP ( & ->
	}
	else {
		ret = min(ret, f(i + 1, dep - 1, last, s) + 1); // ->
		ret = min(ret, f(i + 1, dep + 1, i, s) + 2); // RP ( & ->
	}

	return ret;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);


	string s; cin >> s;
	fill(**dp, **dp + 102 * 102 * 102, -1);
	N = SZ(s);
	ans = f(0, 0, 0, s);
	cout << ans << "\n";

	return 0;
}
