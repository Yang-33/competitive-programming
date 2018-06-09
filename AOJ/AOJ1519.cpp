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

/* -----  2018/06/09  Problem: AOJ 1519 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1519  ----- */
/* ------問題------

以下のクエリをさばけ。
1: a,b間の関係で、差分をCにする。ただしa+=c,b+=c.
2: 関係があればその差分を、なければエラーを出力せよ。

-----問題ここまで----- */
/* -----解説等-----

これができれば差分UFは良さそう。
経路圧縮で何をしているかを考えると簡単。
陽に変更するのはいつものUFと変わらなくて、差分計算のときに、+=Cした累積和をまとめた状態で引けば良い。(val=val-y+x)
また、根からの距離も、根がかわる木のとき同様に計算できるためx,y間の差分も計算できる。

----解説ここまで---- */

template<typename T>
class DiffUnionFind {
	T calc(int x) {
		int r = root(x);
		return dist[x] + diff[x] - diff[r]; // !
	}
	vector<int> par;
	vector<T>dist, diff;// 経路圧縮ではdistしか変化しない

public:
	DiffUnionFind(int n) {
		par.assign(n, -1);// par and size
		dist.assign(n, 0); // ! T'e
		diff.assign(n, 0); // ! T'e
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
		diff[x] += val; // !!
		diff[y] += val; // !!

		int rx = root(x), ry = root(y);
		val = val - (dist[y] + diff[y]) + (dist[x] + diff[x]); // !
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

	int N, Q;
	cin >> N >> Q;
	DiffUnionFind<long long> wuf(N);// need diff
	FOR(i, 0, Q) {
		string s;
		cin >> s;
		if (s == "IN") {
			long long  a, b, c; cin >> a >> b >> c;
			a--, b--;
			wuf.unionSet(a, b, c);
		}
		else {
			int a, b; cin >> a >> b;
			a--, b--;
			if (wuf.same(a, b)) {
				cout << wuf.comp(a, b).second << endl;
			}
			else {
				cout << "WARNING" << endl;
			}
		}
	}

	return 0;
}
