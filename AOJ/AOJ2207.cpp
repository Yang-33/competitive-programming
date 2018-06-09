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

/* -----  2018/06/09  Problem: AOJ 2207 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2207  ----- */
/* ------問題------

数値の大きさを表す単位の関係が、以下のように与えられる。
ただしいか判定せよ。
Q: a = 10^x b 
a,b:name, -100<=x<=100

-----問題ここまで----- */
/* -----解説等-----

実際の値を持つと多倍長整数がいるので、指数だけとりだして差分UFをする。

----解説ここまで---- */

template<typename T>
class DiffUnionFind {
	T calc(int x) {
		int r = root(x);
		return dist[x]; // !
	}
	vector<int> par;
	vector<T>dist;

public:
	DiffUnionFind(int n) {
		par.assign(n, -1);// par and size
		dist.assign(n, 0); // ! T'e
	}
	int size(int x) { return -par[root(x)]; }
	bool same(int x, int y) { return root(x) == root(y); }

	// !
	int root(int x) {
		if (par[x] < 0)return x;
		int r = root(par[x]);
		dist[x] += dist[par[x]]; // abelian
		return par[x] = r;
	}
	void unionSet(int x, int y, T val) { // node[x] + val = node[y], 

		int rx = root(x), ry = root(y);
		val = val - (dist[y]) + (dist[x]); // !
		if (rx == ry)return;
		if (size(ry) < size(rx)) {
			swap(ry, rx);
			val = -val; // !
		}
		par[rx] += par[ry];
		par[ry] = rx;
		dist[ry] = val; // !

	}

	pair<bool, T>comp(int x, int y) {
		if (!same(x, y))return make_pair(false, 0);
		return make_pair(true, (calc(y) - calc(x)));// diff[r]はいらないかもしれない
	}
};


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	// 指数だけ取り出せば良い
		int N;
		while (cin >> N, N) {
			DiffUnionFind<long long> wuf(210);
			map<string, int>strToId;
			int idp = 1;
			int flag = 1;
			FOR(i, 0, N) {
				int one, x; string a, e, b;
				cin >> one >> a >> e;
				scanf(" 10^%d", &x);
				cin >> b;
				// a = x b
				if (strToId.find(a) == strToId.end())strToId[a] = idp++;
				if (strToId.find(b) == strToId.end())strToId[b] = idp++;
				if (wuf.same(strToId[a], strToId[b])) {
					long long ret = wuf.comp(strToId[a], strToId[b]).second;
					if (ret != x) {
						flag = 0;
					}
				}
				else {
					wuf.unionSet(strToId[a], strToId[b], x);
				}
			}

			cout << (flag ? "Yes" : "No") << endl;

		}

	return 0;
}
