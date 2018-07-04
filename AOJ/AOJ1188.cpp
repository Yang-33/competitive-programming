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

/* -----  2018/07/04  Problem: AOJ 1188 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/1188  ----- */
/* ------問題------

デモクラティア共和国の大統領は，以下のような複数段階の選挙により選ばれる．

大統領選挙の候補者は2名である．
第1段階の選挙では，有権者は選挙区ごとに投票する．有権者の過半数の票を得た候補者がその選挙区の勝者となる．有権者が投票するのはこの第1段階だけである．
第k段階 (k > 1) の選挙区は，複数の第k − 1段階の選挙区を含む．一方，第k − 1段階の各選挙区は，ちょうど一つの第k段階の選挙区に含まれる．そして，第k段階の選挙区の勝者は，この選挙区に含まれる第k − 1段階の選挙区のうち過半数で勝った候補者である．
最終段階の選挙区は全国区であり一つしかない．ここでの勝者が大統領に選ばれる．
この国の大統領選挙では，以下の仮定が成り立つ．

すべての有権者が，それぞれ一票を投じる．
第1段階の各選挙区の有権者数は奇数である．
第k段階 (k >1) の各選挙区に含まれる第k − 1段階の選挙区の数も奇数である．
したがって，すべての段階のすべての選挙区で，必ずどちらかの候補が勝つ (引き分けはない)．

あなたの仕事は，なるべく少ない得票数で大統領選挙に勝つ方法を求めるプログラムを作成することである． たとえば，最終段階の選挙区がちょうど三つの第1段階の選挙区を含んでおり，これらの第1段階の選挙区の有権者数がそれぞれ123名，4567名，89名だったとする． この場合，最初の選挙区で62票，3番目の選挙区で45票の計107票を獲得するのが，最も少ない得票数で勝つ方法になる． この場合，仮にもう一人の候補が2番目の選挙区で4567票すべてを獲得したとしても，敗者となることは避けられない． 不公平な選挙制度だと思うかもしれないが，これも現実として受け止めて欲しい．

-----問題ここまで----- */
/* -----解説等-----

上手にできた
並列区をwhile()で抜き出せると良い。

----解説ここまで---- */

LL parse(int& i, string& s) {
	VL ret;
	while (s[i] == '[') {
		i++;// [
		ret.push_back(parse(i, s));
		i++;// ]
	}
	if (isdigit(s[i])) {
		LL val = 0;
		while (isdigit(s[i])) {
			val *= 10; val += s[i] - '0'; i++;
		}
		ret.push_back(val/2+1);
	}

	SORT(ret);
	LL ans = 0;
	FOR(i, 0, SZ(ret) / 2 + 1) {
		ans += ret[i];
	}
	return ans;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;
	FOR(shuri, 0, T) {
		int i = 0;
		string s; cin >> s;
		cout << parse(i, s) << endl;
	}

	return 0;
}
