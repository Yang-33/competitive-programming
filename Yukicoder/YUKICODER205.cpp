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

/* -----  2018/08/02  Problem: yukicoder 205  / Link: http://yukicoder.me/problems/no/205  ----- */
/* ------問題------

N 個の文字列 S1,...,SN が与えられる。 これらの文字列を以下のような手順でマージして、１つの文字列にする。

文字列 T を空文字列に初期化する。
S1,...,SN から空文字列ではない文字列 Skをどれかひとつ選ぶ、そのような文字列がない場合は 文字列 T を結果として返して終了する。
Sk の最初の一文字を文字列 Tの一番最後に追加する。
Sk から最初の一文字を削除する。
2. に戻る。
上記のマージで生成されうる文字列の中で、辞書順最小のものを答えよ。

-----問題ここまで----- */
/* -----解説等-----

prioryty_queueがこれをそのまま表した感じ。
文字列の辞書順最小はstring内で定義されているのでできる。

----解説ここまで---- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N; cin >> N;
	priority_queue<string, VS, greater<string>>pq;
	FOR(i, 0, N) {
		string s; cin >> s;
		s += string(1, '|');
		pq.push(s);
	}
	string ans = "";
	while (!pq.empty()) {
		string s = pq.top(); pq.pop();
		if (s[0] == '|')continue;
		ans += string(1, s[0]);
		pq.push(s.substr(1));
	}

	cout << ans << "\n";

	return 0;
}
