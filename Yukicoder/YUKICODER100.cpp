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

/* -----  2018/04/19  Problem: yukicoder 100  / Link: http://yukicoder.me/problems/no/100  ----- */
/* ------問題------

N 本の縦線と、隣り合う縦線を水平に結ぶ横線からなるあみだくじを考える。
まったく同じ形のあみだくじを上下に 2 つ繋げたものを「直列あみだくじ」と呼ぶことにする。
あみだくじの出発点と到着点の対応が与えられるので、その対応を満たす「直列あみだくじ」が存在するか判定せよ。

-----問題ここまで----- */
/* -----解説等-----

巡回群について考える。奇数長の循環と、偶数長の循環に分かれる。
2回使って移動できるのは、まず奇数長のとき。
偶数長は単体ではできず、実験すると(全部試す)同じ長さの循環が2つあると目標の置換を作ることができる。
したがって偶数長の置換が、同じ長さについて全部偶数個あれば存在する。

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


LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	VI a(N);
	UnionFind uf(N);
	FOR(i, 0, N) {
		cin >> a[i], a[i]--;
		uf.unionSet(i, a[i]);
	}

	VI look(N, 0);
	map<int, int>Map;
	FOR(i, 0, N) {
		if (!look[uf.root(i)]) {
			look[uf.root(i)] = 1;
			Map[uf.size(i)]++;
		}
	}
	bool exist = 1;
	for (auto m : Map) {
		if (m.first % 2 == 0 && m.second % 2 == 1)exist = 0;
	}

	cout << (exist ? "Yes" : "No") << "\n";

	return 0;
}
