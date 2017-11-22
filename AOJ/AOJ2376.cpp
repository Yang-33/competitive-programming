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

/* -----  2017/11/22  Problem: AOJ 1304 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1304  ----- */
/* ------問題------

Taro と Hanako がゲームをしている.
最初に, 非連結な無向グラフ(二重辺や self loop を含まない) が与えられる. Taro と Hanako は交互に操作を行う. 操作では, 辺で直接つながれていない異なる2 頂点を選び, その間に辺を加える. グラフを連結にしたほうが負けである.
グラフには V 個の頂点がある. V×Vの行列が与えられる. 行列の (i,j)-成分が'Y' であるとき i と jの間には辺があり, 'N' であるときは辺が無い.
両者が最善に操作をしたとき, どちらが勝つかを出力せよ.

-----問題ここまで----- */
/* -----解説等-----

2人のプレイヤーは残りの辺を置くことのできる数によって、手を変える。DPで解けるらしい。(?)
がプレイヤーの高度について適切な方針は以下
最終的な二つのグループP,Qについてこれらに辺のマッチングは存在しない。
P,Qの組を決定することができればさらに残りの辺の数を求めることができる。
「残りの辺の数」は先手/後手にとっては奇数/偶数である方がよい。
各プレイヤーは現在のグラフとP,Qの組でそれぞれのうれしい偶奇を目指すことができるため、最終的なP*Qの偶奇のみを考えればよいことになる。
P*Qが奇数となるようにするためには現在バラバラな偶数要素を偶数または奇数要素とマージする。
一方偶数となるようにするためには奇数要素と奇数要素をマージしてしまえばよい。
したがって着目すべきは偶数要素がいくつあるか、奇数要素があるかどうか。
あとは例外を取り除けばよい。
例外はあと3つ以下しか連結成分がないとき。
偶数,奇数,奇数は先手必勝
奇数，奇数では残りの辺が偶数なら勝ち、奇数なら負け。
異なる場合は逆で勝ち。
たくさんあるときは先手に合わせて動けるため後手の勝ち。

----解説ここまで---- */


LL ans = 0LL;
LL f(LL n) { return n*(n - 1) / 2; }
int visit[1003];
int N;
int dfs(VS&m, int v, int p) {
	int ret = 0;
	visit[v] = 1;
	ret++;
	FOR(i, 0, N) {
		if (m[v][i] == 'Y' && !visit[i] && i != p) {
			ret += dfs(m, i, v);
		}
	}
	return ret;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string player[2] = { "Taro","Hanako" };

	cin >> N;
	VS m(N);
	FOR(i, 0, N) {
		cin >> m[i];
	}
	int edge = 0;
	FOR(i, 0, N) {
		FOR(j, 0, N) {
			if (m[i][j] == 'Y')edge++;
		}
	}
	edge /= 2;
	/*if (N % 2 == 1) {
	ans = !((N*(N - 1) / 2 - edge) % 2);
	}
	else {*/
	VI comp(2, 0);
	int left = N*(N - 1) / 2 - edge;
	FOR(i, 0, N) {
		if (!visit[i]) {
			comp[dfs(m, i, -1) % 2]++;
		}
	}
	ans = 1;
	if (comp[0] == 1 && comp[1] == 2) {
		ans = 0;
	}
	else if (left % 2 == 0) {
		if (comp[0] == 0 && comp[1] == 2)ans = 0;
	}
	else if (left % 2 == 1) {
		if (!(comp[0] == 0 && comp[1] == 2))ans = 0;
	}
	else ans = 1;

	//}

	//for (int N = 3; N < 100; N += 2) {
	//	LL ret = 0;
	//	FOR(i, 1, N / 2 + 1) {
	//		if (i == 1)ret = f(i) + f(N - i);
	//		else {
	//			assert(ret % 2 == ((f(i) + f(N - i)) % 2));
	//		}
	//	}
	//}

	cout << player[ans] << "\n";

	return 0;
}