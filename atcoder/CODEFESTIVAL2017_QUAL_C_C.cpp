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

/* -----  2017/10/22  Problem: codefestival2017_qual_b C  / Link: https://beta.atcoder.jp/contests/code-festival-2017-qualc  ----- */
/* ------問題------

英小文字のみからなる文字列 s があります。 すぬけ君は、次の操作を繰り返し行うことができます。
s の任意の位置 (先頭および末尾を含む) をひとつ選び、英小文字 x をひとつ挿入する。
すぬけ君の目標は、s を回文にすることです。 すぬけ君の目標が達成可能か判定し、達成可能ならば必要な操作回数の最小値を求めてください。

-----問題ここまで----- */
/* -----解説等-----

xを入れることができないことを考えると、見ている文字列が必ず回文でなければならない。
xを入れることで解決できるのは左右からのindexを進めていくときに、片側にxがあるとき。
この時に限り、xをいれたとして今発見できているxをpassできる。
これで中央までindexが移動したときのみ、回文になる。
したがって左右からしゃくとり的なノリをしていけばいいことが分かる。(しゃくとりではない)

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;
	VI cnt(30, 0);
	int flag = 1;
	FOR(i, 0, SZ(s))cnt[s[i] - 'a']++;
	for (int l = 0,  r = SZ(s) - 1; l < r;) {
		if (s[l] == s[r]) { l++; r--; }
		else if (s[r] == 'x') { ans++; cnt['x' - 'a']++; r--; }
		else if (s[l] == 'x') { ans++; cnt['x' - 'a']++; l++; }
		else { flag = 0; break; }
	}

	if (flag == 0)cout << "-1" << endl;
	else cout << ans << "\n";

	return 0;
}