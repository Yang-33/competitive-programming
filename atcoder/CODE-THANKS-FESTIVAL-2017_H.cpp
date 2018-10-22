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
//#pragma GCC optimize ("-O3") 
#ifdef YANG33
#include "mydebug.hpp"
#else
#define DEBUG(x) 
#endif
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/10/20  Problem: codethanksfestival2017 H / Link: https://code-thanks-festival-2017-open.contest.atcoder.jp/tasks/code_thanks_festival_2017_h  ----- */
/* ------問題------

最初、{1},{2},…,{N} という N 個の集合が与えられます。
この後に、集合を併合する操作が M 回行われます。
時刻 i(1≦i≦M) 回目の操作では 要素 ai を持つ集合と 要素 bi を持つ集合を併合します。
ただし、要素 ai と要素 bi が既に同じ集合に属している場合には何も起こりません。

次に、Q 個の質問クエリが与えられ、j(1≦j≦Q) 番目の質問クエリの内容は以下の通りです。

｢要素 xj と 要素 yj が同じ集合に併合されるのは何回目の操作後ですか?｣
M 回の操作後に 要素 xj と 要素 yj が 同じ集合に属さない場合には、-1 を出力してください。
そうでない場合、K(1≦K≦M) 回目の操作後に要素 xj と 要素 yj が同じ集合に属するので、最小の K を出力してください。

-----問題ここまで----- */
/* -----解説等-----



----解説ここまで---- */

class UnionFind {
	vector<pair<int, int>> tree;
	int count;
public:
	UnionFind(const int size) :tree(size, { 1,std::numeric_limits<int>::max() }), count(0) {}
	int find(int ver, int x) {
		while (tree[x].second <= ver) {
			x = tree[x].first;
		}
		return x;
	}
	int unite(int x, int y) {
		++count;
		x = find(count, x);
		y = find(count, y);
		if (x == y) return count;
		if (tree[x].first < tree[y].first) swap(x, y);
		tree[x].first += tree[y].first;
		tree[y] = { x,count };
		return count;
	}
	bool same(int ver, int x, int y) {
		return find(ver, x) == find(ver, y);
	}
};

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, M; cin >> N >> M;
	UnionFind rtuf(N);
	FOR(i, 0, M) {
		int a, b; cin >> a >> b;
		a--, b--;
		rtuf.unite(a, b);
	}
	LL Q; cin >> Q;
	FOR(_, 0, Q) {
		int a, b; cin >> a >> b;
		a--, b--;
		int L = 0, R = M + 1;
		while (R-L>1){
			int mid = (R + L) / 2;
			if (rtuf.same(mid, a, b)) {
				R = mid;
			}
			else {
				L = mid;
			}
		}
		if (R == M + 1)cout << -1 << endl;
		else cout << R << endl;
	}



	return 0;
}
