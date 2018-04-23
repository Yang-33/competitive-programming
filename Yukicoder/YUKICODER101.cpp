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

/* -----  2018/04/23  Problem: yukicoder 101  / Link: http://yukicoder.me/problems/no/101  ----- */
/* ------問題------

太郎君はあるあみだくじで何度シャッフルを繰り返せば元の数列の戻るのか気になりましたが、 わざわざ手であみだくじを辿っていくのは大変です。 太郎君の代わりに数列1,2,...,Nを元の数列1,2,...,Nに戻すために必要な最小のシャッフル回数Sを計算してあげてください。 ただし、シャッフルは少なくとも1回は行うものとします。

-----問題ここまで----- */
/* -----解説等-----

UnionFindとかdfsとかで、ループするために必要な最小サイズを求めておく。
このとき、各ループ数の最小公倍数が、すべてがもとに戻る回数である。

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

long long  gcd(long long  a, long long  b) { return b ? gcd(b, a%b) : a; }
long long  lcm(long long  a, long long  b) { return a / gcd(a, b) * b; }

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, K; cin >> N >> K;
	VI a(N); 
	iota(ALL(a), 0);

	FOR(i, 0, K) {
		int x, y; cin >> x >> y;
		x--, y--;
		swap(a[x], a[y]);
	}
	UnionFind uf(N);
	FOR(i, 0, N) {
		uf.unionSet(i,a[i]);
	}
	LL ans = 1;

	FOR(i, 0, N) {
		ans = lcm(ans, uf.size(i));
	}
	cout << ans << "\n";

	return 0;
}
