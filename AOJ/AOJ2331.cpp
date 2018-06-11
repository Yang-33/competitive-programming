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

/* -----  2018/06/10  Problem: AOJ 2331 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2331  ----- */
/* ------問題------

明日から、待ちに待った夏休みが始まります。なのでわたしは、友だちを誘って、海に遊びに行くこ とに決めました。
けれども、わたしの友だちには、恥ずかしがりやさんが多いです。その人たちは、あまり多くの人が いっしょに来ると知ったら、きっと嫌がるでしょう。
ほかにも、わたしの友だちには、目立ちたがりやさんも多いです。その人たちは、いっしょに来る人 があまり多くないと知れば、きっと嫌がるでしょう。
それと、わたしの友だちには、いつもは目立ちたがりやなのに実は恥ずかしがりやさんな人もいま す。その人たちは、いっしょに来る人が多すぎても少なすぎても、きっと嫌がるでしょう。
こういうのは、大勢で行った方が楽しいはずです。だからわたしは、できるだけたくさんの友だちを 誘いたいと思っています。けれども、嫌がる友だちを無理やり連れていくのはよくありません。
いったい、わたしは最大で何人の友だちを誘うことができるのでしょうか。
わたしは、こういう頭を使いそうな問題が大の苦手です。なので、あなたにお願いがあります。もし よろしければ、わたしの代わりにこの問題を解いていただけないでしょうか。いえ、決して無理にと は言いません。けれど、もし解いていただるのでしたら、わたしはとても嬉しいです。

-----問題ここまで----- */
/* -----解説等-----

条件をまとめると以下。
Q:iさんは[a:b]人なら参加したい。
したがって、p人集められるかを判定すれば良い。
p人集められるかは、そこに参加しうる人数を記録しておけばいいので、この操作は区間足し込みになる。
静的なのでimos法でOK.

----解説ここまで---- */

int main() {
	int N; cin >> N;
	VI a(N), b(N);
	FOR(i, 0, N) {
		cin >> a[i] >> b[i];
		a[i]--, b[i]--;
	}
	VL imo(120000, 0);
	FOR(i, 0, N) {
		imo[a[i]]++;
		imo[b[i] + 1]--;
	}
	LL ans = 0;
	FOR(i, 0, 110000) {
		imo[i + 1] += imo[i];
		if (imo[i] >= i)
			ans = max(ans, (LL)i);
	}
	cout << ans << endl;

	return 0;
}