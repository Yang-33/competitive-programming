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

/* -----  2018/07/26  Problem: yukicoder 168  / Link: http://yukicoder.me/problems/no/168  ----- */
/* ------問題------

XY座標上にN個の異なる整数座標P1からPNがある。
A君は点と点を真っ直ぐな線でつないでP1からPNまでつなげたい。
(つなげる場合の順番は問わない。すべての点を通る必要はない。)
ある点と点についてものさしを当てて鉛筆で1回で真っ直ぐな線を引いてつなげる。
長さが足りない場合に2回以上に分けて線を引いてつなげてはならない。

A君の町には10cmの単位の長さでものさしが売られている。
10cmや20cmのものさしを買うことができる。
例えば、30cmのものさしを買うと30cm以下の長さの真っ直ぐな線が引ける。
A君は点をつなぐ目的を達成したいが、できればあまり長いものさしを買いたくはない。
点をつなぐ目的を達成するのにA君が買う最も短いものさしの長さはいくらか？

-----問題ここまで----- */
/* -----解説等-----

大きければとりあえず点はつなげるので、条件を満たすものの最小を求める。
これは二分探索でできる。
あとは適当にやる

----解説ここまで---- */

struct UnionFind {
	vector<int> data;
	UnionFind(int n) { data.assign(n, -1); }
	void clear(int n) { data.assign(n, -1); }
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


LL x[1003], y[1003];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N;
	scanf("%d", &N);
	FOR(i, 0, N) {
		scanf("%lld%lld", &x[i], &y[i]);
	}
	UnionFind uf(N);
	auto f = [&](LL val) {
		uf.clear(N);
		auto dist = [&](int i, int j) {
			return ((x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]));
		};
		FOR(i, 0, N) {
			FOR(j, i+1, N) {
				if (dist(i, j) <= val*val) {
					uf.unionSet(i, j);
				}
			}
		}
		return uf.same(0, N - 1);
	};
	LL L = 0; LL R = 2e9;
	while(R-L>1){
		LL mid = (L + R) / 2;
		(f(mid*10) ? R : L) = mid;
	}
	LL ans = R*10;
	cout << ans << "\n";

	return 0;
}
