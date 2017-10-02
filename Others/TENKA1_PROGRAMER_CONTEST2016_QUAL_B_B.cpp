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

/* -----  2017/10/02  Problem: tenka1_programer_contest2016_qual_B_B  / Link: http://tenka1-2016-qualb.contest.atcoder.jp/tasks/tenka1_2016_qualB_b  ----- */
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

-----問題ここまで----- */
/* -----解説等-----

f(i,j,k):i番目の文字を見たときに括弧の対応がとれる可能性があり、深さがj,最後に変えた部分がkのときの最小手続き
とすると、なんか1,2を加えたりして、最後に訂正をすればいいことが分かる。
JAGのときに似てる！

----解説ここまで---- */

LL N = 102;
int dp[102][102][102];
LL ans = 0LL;
string S;
int f(int id, int dep, int last) {
	if (dep < 0)return INF;
	int &ret = dp[id][dep][last];
	if (id == (int)S.size()) {
		if (dep == 0)return last - id;
		else return INF;
	}
	if (ret != -1)return ret;
	ret = INF;
	if (S[id] == '(') {
		ret = min(ret, f(id + 1, dep + 1, last) + 1);
		ret = min(ret, f(id + 1, dep - 1, id) + 2);
	}
	else {
		ret = min(ret, f(id + 1, dep + 1, id) + 2);
		ret = min(ret, f(id + 1, dep - 1, last) + 1);
	}
	return ret;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> S;
	FOR(i, 0, N)FOR(j, 0, N)FOR(k, 0, N)dp[i][j][k] = -1;


	ans = f(0, 0, 0);
	cout << ans << "\n";

	return 0;
}

