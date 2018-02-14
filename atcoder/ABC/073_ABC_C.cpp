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

/* -----  2018/02/14  Problem: 073_abc_c / Link: https://abc073.contest.atcoder.jp/tasks/abc073_c?lang=en  ----- */
/* ------問題------

あなたは、joisinoお姉ちゃんと以下のようなゲームをしています。
•最初、何も書いていない紙がある。
•joisinoお姉ちゃんが一つの数字を言うので、その数字が紙に書いてあれば紙からその数字を消し、書いていなければその数字を紙に書く。これを N 回繰り返す。
•その後、紙に書かれている数字がいくつあるかを答える。
joisinoお姉ちゃんが言った数字が、言った順番に A1,…,AN として与えられるので、ゲーム終了後に紙に書かれている数字がいくつあるか答えてください。


-----問題ここまで----- */
/* -----解説等-----

値が大きいのでmapで管理して、反転することから奇数回登場するものの数を数えれば良い。
またはsortでやっていく

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	map<LL, LL>Map;
	FOR(i, 0, N) {
		LL a; cin >> a;
		Map[a]++;
	}

	for (map<LL, LL>::iterator it = Map.begin(); it != Map.end(); it++) {
		if ((*it).second % 2 == 1)ans++;
	}
	cout << ans << "\n";

	return 0;
}
