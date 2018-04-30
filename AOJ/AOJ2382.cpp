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

/* -----  2018/04/20  Problem: AOJ 2382 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2382  ----- */
/* ------問題------

キングスライムの合体
壁かスライムにぶつかるまで移動する。
最小何回で合体できるか。

-----問題ここまで----- */
/* -----解説等-----

一直線上に並んでいるときを考えると、明らかにN-1回必要。
並んでいない時を考えると、独立した成分だけ更に必要。
壁に接しているスライムが存在しないとすると、以下のようにまとめられる。
縦横で合体可能なスライムをまとめる。最終的な独立しているスライムの数をMとすると、
N-M + M + M-1 = N+M-1

スライムは合体しており、一つの壁に集まるので、壁に接しているスライムも一匹。もし存在すれば-1できる。
(壁に向かって動かなくていいので)

最終的にはUnionFindでmergeすると簡単。

入力まちがえたけど…

----解説ここまで---- */

struct UnionFind {
	vector<int> data;
	UnionFind(int n) { data.assign(n, -1); }
	bool unionSet(int x, int y) {
		x = root(x); y = root(y);
		if (x != y) {
			if (data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
		}
		return x != y;
	}
	bool same(int x, int y) { return root(x) == root(y); }
	int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
	int size(int x) { return -data[root(x)]; }
};

LL N, W, H;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> W >> H;

	VI x(N), y(N);
	int Wall = 0;
	FOR(i, 0, N) {
		cin >> x[i] >> y[i];
		if (x[i] == 1 || y[i] == 1 || x[i] == W || y[i] == H)Wall = 1;
	}
	UnionFind uf(N);

	map<int, int>Xs;
	map<int, int>Ys;
	vector<bool> usex(W+1, 0);
	vector<bool> usey(H+1, 0);
	FOR(i, 0, N) { // mergeを
		if (usex[x[i]])
			uf.unionSet(Xs[x[i]], i);
		Xs[x[i]] = i;
		if (usey[y[i]])
			uf.unionSet(Ys[y[i]], i);
		Ys[y[i]] = i;
		usex[x[i]] = 1;
		usey[y[i]] = 1;
	}


	set<int>se;
	FOR(i, 0, N) {
		se.insert(uf.root(i));
	}
	int sz = SZ(se);
	if (sz != 1) {
		ans = N - 1 + sz - Wall;
	}
	else {
		ans = N - 1;
	}
	cout << ans << "\n";

	return 0;
}
