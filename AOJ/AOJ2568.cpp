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

/* -----  2018/06/13  Problem: AOJ 2568 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2568  ----- */
/* ------問題------

N<=10^5の0or1パラメータをもつ仕事が存在する。
2^N個の仕事のうち、次の条件を満たすものを同一視する。
・ある仕事Aのパラメータaについて、これが1
・ある仕事Bのパラメータbについて、これが1
・a,b以外の任意のパラメータcについてA,Bのcが両方0であるとはない
・a,bとしてパラメータx,yを選択したいとき、入力のリストを並び替えて、長さNの列x....yを作成できる。
　ただし、その列の隣接項は全てリストの組で表現できなければならない。

uniqueな仕事はいくつ存在するか、modをとって答えよ。

-----問題ここまで----- */
/* -----解説等-----

dpの気分になるが、不可能であることがわかる。
次に、自分で2^n個書いてみて発見を試みる。
すると、だいだいmergeできてしまうことがわかり、入力のリスト1組で半分の要素をmergeできることに気がつく。(01の連続からいい感じにつなぐことができる)
あとはよくわからないけど帳尻を合わせれば良い。(良くない)

----解説ここまで---- */


struct UnionFind {
	vector<int> data;
	UnionFind(int size) { init(size); }
	void init(int size) { data.clear(); data.resize(size, -1); }
	bool unite(int x, int y) {
		x = root(x); y = root(y);
		if (x != y) {
			if (data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
		}
		return x != y;
	}
	bool same(int x, int y) {
		return root(x) == root(y);
	}
	int root(int x) {
		return data[x] < 0 ? x : data[x] = root(data[x]);
	}
	int size(int x) {
		return -data[root(x)];
	}
};

void solve() {
	int N, M;
	while (cin >> N >> M, N) {
		UnionFind uf(N);
		FOR(i, 0, M) {
			int a, b;
			cin >> a >> b;
			a--, b--;
			uf.unite(a, b);
		}
		VL used(N, 0);
		int isgroup = 0;
		int cnt = 0;
		FOR(i, 0, N) {
			int root = uf.root(i);
			if (used[root])continue;
			cnt++;
			if (uf.size(root) != 1)isgroup = 1;
			used[root] = 1;
		}
		LL nene = 1;
		const LL mod = 1e9 + 7;

		FOR(i, 0, cnt) {
			nene *= 2;
			nene %= mod;
		}
		nene += isgroup;
		nene %= mod;
		cout << nene << endl;
	}

}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	solve();
	return 0;
}