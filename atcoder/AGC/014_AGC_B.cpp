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

/* -----  2018/03/03  Problem: 014_agc_b / Link: https://agc014.contest.atcoder.jp/tasks/agc014_b?lang=en  ----- */
/* ------問題------

高橋君は木の問題が苦手です。そこで、青木君は高橋君の練習相手になってあげることにしました。
まず、高橋君は N 頂点からなる木を用意し、頂点に 1 から N の番号を付けました。 そして、各辺に 0 と書きました。
次に、青木君は高橋君に M 個のクエリを与えました。i 個目のクエリは以下のような内容です。
頂点 ai と頂点 bi を結ぶパス上の辺すべてに対して、書かれている数を 1 増やす。
全てのクエリを終えた後、高橋君は青木君にどの辺を見ても書かれている数が偶数になったと伝えました。 しかし、青木君は最初に高橋君が用意していた木を確認していなかったので、 高橋君が正しくクエリを処理できたか分かりませんでした。
青木君を助けるために、高橋くんの言う性質を満たす木が存在するかどうかを判定してください。

-----問題ここまで----- */
/* -----解説等-----

適当な根付き木を考えたとき、どのような場合でも登場回数が偶数回ならば辺は偶数の値になる。

----解説ここまで---- */

LL N, M ;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N>>M;
	VI ver(N);
	FOR(i, 0, M) {
		int a, b; cin >> a >> b;
		a--; b--;
		ver[a]++;
		ver[b]++;
	}

	ans = 1;
	FOR(i, 0, N) {
		if (ver[i] % 2)ans = 0;
	}
	if (ans) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << "\n";
	}

	return 0;
}
