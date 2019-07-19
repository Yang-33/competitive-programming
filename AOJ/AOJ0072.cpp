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
#define DD(x) 
#endif
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);

/* -----  2019/07/19  Problem: AOJ 0072 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0072  ----- */


stringstream deletecommma(string line) {
	istringstream ss(line);
	string s;
	stringstream input;
	while (getline(ss, s, ',')) {
		input << s; input << " ";
	}
	return input;
}

template<typename edgeT>
struct normalMST {
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
	int n;
	using edgetp = tuple<edgeT, int, int>;
	vector<edgetp>edges;
	UnionFind uf;
	normalMST(int n) :n(n), uf(n) {}
	void add_edge(int a, int b, edgeT c) {
		edges.emplace_back(c, a, b);
	}
	edgeT build() {
		sort(edges.begin(), edges.end());
		edgeT sum = 0;
		for (auto &it : edges) {
			edgeT c; int a, b;
			tie(c, a, b) = it;
			if (uf.same(a, b))continue;
			sum += c;
			uf.unionSet(a, b);
		}

		return sum;
	}
};
int main() {
	int N;
	while (cin >> N, N) {
		normalMST<int> G(N);
		int M; cin >> M;
		FOR(i, 0, M) {
			string in; cin >> in;
			auto input = deletecommma(in);
			int a, b, c; input >> a >> b >> c;
			c /= 100; c--;
			G.add_edge(a, b, c);
		}
		cout << G.build() << "\n";
	}
	return 0;
}