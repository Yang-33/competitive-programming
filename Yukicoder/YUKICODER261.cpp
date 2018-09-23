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

/* -----  2018/08/30  Problem: yukicoder 261  / Link: http://yukicoder.me/problems/no/261  ----- */
/* ------問題------

太郎君はまた数列 1,2,...,N を あみだくじ でシャッフルして遊んでいます。
以前は「同じあみだくじを使って最低何回シャッフルすると、元の列に戻るか」気になっていた太郎君ですが、 それが解決した今は「同じあみだくじを使って最低何回シャッフルすると、ある数列にすることができるか」気になっています。
例えば次のあみだくじは数列 1,2,3 を 3,1,2 へとシャッフルします。
このあみだくじを何回か使って 2,3,1 という数列にすることを考えます。
実際に何回か繰り返しシャッフルしてみましょう。
1,2,3 → 3,1,2 → 2,3,1
2回シャッフルすることで元の列を 2,3,1 にすることができました。
1つのあみだくじと、シャッフルして得たいQ個の数列が入力に与えられるので、 それぞれ最低何回シャッフルを繰り返せば得られるのか出力してください。 何度シャッフルを繰り返しても得ることのできない数列だった場合、−1を出力してください。
また、最低1回はシャッフルする必要があります。

-----問題ここまで----- */
/* -----解説等-----

まず与えられる巡回群はいくつかの巡回群に分けられる。
今回の問題は、これらの位数G(i)について、X = (iをA[i][j]にするための最小回数)+G(i)
を巡回群の数だけつくり、連立方程式を解くような問題に帰着できる。
これは、連立合同方程式なので中国剰余定理等を用いて解ける。

----解説ここまで---- */

inline long long addmod(long long a, long long m) {
	return (a % m + m) % m;
}

long long extGCD(long long a, long long b, long long &p, long long &q) {
	if (b == 0) { p = 1; q = 0; return a; }
	long long d = extGCD(b, a%b, q, p);
	q -= a / b * p;
	return d;
}

pair<long long, long long> ChineseRem(const vector<long long> &b, const vector<long long> &m) {
	long long r = 0, M = 1;
	for (int i = 0; i < (int)b.size(); ++i) {
		long long p, q;
		long long d = extGCD(M, m[i], p, q); 
		if ((b[i] - r) % d != 0) return make_pair(0, -1);
		long long tmp = (b[i] - r) / d * p % (m[i] / d);
		r += M * tmp;
		M *= m[i] / d;
	}
	return make_pair(addmod(r, M), M);
}

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

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, K; cin >> N >> K;
	VI a(N);
	FOR(i, 0, N)a[i] = i;
	FOR(i, 0, K) {
		int x, y; cin >> x >> y;
		swap(a[x - 1], a[y - 1]);
	}
	UnionFind uf(N);
	FOR(i, 0, N) {
		uf.unionSet(i, a[i]);
	}
	VVI mem(N);
	FOR(i, 0, N) {
		mem[i].push_back(a[i]);
		while (mem[i].front() != a[mem[i].back()]) {
			mem[i].push_back(a[mem[i].back()]);
		}
	}

	int Q; cin >> Q;
	FOR(_, 0, Q) {
		VI x(N);
		FOR(i, 0, N)cin >> x[i],x[i]--;
		VL b(N,-1), m(N);
		bool ok = 1;
		FOR(i, 0, N) {
			// iがx[i]になるまでの遷移回数がb[i]
			FOR(j, 0, SZ(mem[i])) {
				if (mem[i][j] == x[i]) {
					b[i] = j + 1;
					m[i] = uf.size(x[i]);
					break;
				}
			}
			if (b[i] == -1)ok = 0;
		}
		if (!ok)cout << -1 << endl;
		else {
			PLL res = ChineseRem(b, m);
			if (res == PLL(0, -1)) {
				cout << -1 << endl;
			}
			else {
				cout << (res.first==0?res.second:res.first) << endl;
			}
		}
	}

	return 0;
}
