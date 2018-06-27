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

/* -----  2018/06/30  Problem: AOJ 2738 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2738  ----- */
/* ------問題------

時は進んで 2060 年，共に 70 歳を迎える前田さんと後藤さんは長い付き合いの友人であり，大学時代にACM-ICPCで共に戦った仲間でもある．
二人は今でもよく一緒にお茶を飲みつつ，競技プログラミングの話で盛り上がっている．
二人で一緒にお茶を飲む時，前田さんが 1 回Aと言うと，その発言の後に後藤さんがちょうど 1 回Unと返事をする習慣がいつのまにか出来た．
しかし最近後藤さんは物忘れや勘違いをすることが多く，前田さんがAと言っても，後藤さんはたまにUnの返事を忘れたり，余計に返事をしたりする．
ついこの間も前田さんと後藤さんはお茶を飲みながら，二人のお気に入りのデータ構造について話し込んでいたようだ．
この時の会話の中から，Aで表される前田さんの発言と，Unで表される後藤さんの返事のみからなる記録が時系列で与えられたとき，後藤さんが習慣通りに反応したとみなすことが出来るかチェックしてほしい．
注意点として，前田さんの発言に対し，後藤さんの返事が多少遅れても，後藤さんは習慣通りに反応したとみなせる場合がある，ということが挙げられる． 例えば，前田さんが2回連続してAと言った後，後藤さんが 2 回連続してUnと返事をして会話が終了した場合は，後藤さんが習慣通りの返事をしたとみなされる (Sample Input 2 参照)．
また，会話が終了した時点で，前田さんがAと言った回数と，後藤さんがUnと返事した回数が一致しても，後藤さんが習慣通りに返事をしたとはみなされない場合もあるので注意すること． 例えば，前田さんが1回Aと言った後，後藤さんが 2 回連続してUnと返事し，その後で前田さんが 1 回Aと言って会話が終了した場合は，後藤さんが習慣通りの返事をしたとはみなされない (Sample Input 3 参照)．

-----問題ここまで----- */
/* -----解説等-----

AよりもUnが多くなってないけない状況で数が合うかチェックすれば良い。

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N; cin >> N;
	int A = 0;
	int UN = 0;
	int res = 1;
	FOR(i, 0, N) {
		string s;
		cin >> s;
		if (s == "A") {
			A++;
		}
		else {
			UN++;
			if (A < UN)res = 0;
		}
	}
	res &= (A == UN);
	cout << (res ? "YES" : "NO") << endl;
	return 0;
}