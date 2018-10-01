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

/* -----  2018/10/01  Problem: yukicoder 313  / Link: http://yukicoder.me/problems/no/313  ----- */
/* ------問題------

muwi さんは円周率の暗記が得意で，円周率を 20 万桁も覚えています．
しかし muwi さんも人間なので，20 万桁もの円周率を暗唱すると，必ずちょうど 1 桁の数字を間違えてしまいます．
あなたは muwi さんのために，間違っている数字を訂正するプログラムを作ってあげることにしました．
|S| = 200002

-----問題ここまで----- */
/* -----解説等-----

sample1を書き換えればよいと思ったけど、それでは提出できない。(おいおい)
差分だけわかれば良いことがわかると、間違っている方は2つの数字の出現回数について+1,-1となっていることに気がつく。
あとはこれを埋め込めば良い。

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string s; cin >> s;
	PII ans;
	VI a({ 20104,20063,19892,20011,19874,20199,19898,20163,19956,19841, });
	VI cnt(10, 0);
	for (char c : s) {
		if (isdigit(c)) {
			cnt[c - '0']++;
		}
	}
	FOR(i, 0, 10) {
		if (a[i] > cnt[i]) { ans.second = i; }
		if (a[i] < cnt[i]) { ans.first = i; }
	}


	cout << ans.first << " " << ans.second << endl;



	return 0;
}
