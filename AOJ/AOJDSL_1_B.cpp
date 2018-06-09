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

/* -----  2018/06/07  Problem: AOJ DSL_1_B / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B  ----- */
/* ------問題------

重み付きUnion Find木
数列 A=a0,a1,...an−1 に対して、以下の情報・質問が与えられます。

relate(x,y,z): ay はaxよりz大きい
diff(x,y): ax とayの差、ay−ax を報告せよ

-----問題ここまで----- */
/* -----解説等-----

potential UnionFindを使う。
差分管理ができるとおもって良い
なんかアーベル群らしいよ

----解説ここまで---- */

template <typename T>
class Weighted_quick_find {
	vector<pair<int, T>> data;
	vector<vector<int>> all;// par and id
public:
	Weighted_quick_find(int n) : data(n), all(n, vector<int>(1)) {
		for (int i = 0; i < n; i++) {
			data[i].first = i;
			all[i][0] = i;
		}
	}
	void unite(int a, int b, T d) {// node[a] + d = node[b]
		if (same(a, b)) return;
		d += data[a].second - data[b].second;
		a = data[a].first;
		b = data[b].first;
		if (all[a].size() < all[b].size()) swap(a, b), d = -d;
		for (auto& id : all[b]) {
			data[id] = { a, data[id].second + d };
		}
		copy(all[b].begin(), all[b].end(), back_inserter(all[a]));
	}
	bool same(int a, int b) const {
		return data[a].first == data[b].first;
	}
	T dist(int a, int b) const { // diff node[b] - node[a]
		return data[b].second - data[a].second;
	}
};

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, Q;
	cin >> N >> Q;
	Weighted_quick_find<LL> wuf(N);

	FOR(i, 0, Q) {
		int a; cin >> a;
		if (!a) {
			int x, y, z; cin >> x >> y >> z;
			wuf.unite(x, y, z);
		}
		else {
			int x, y; cin >> x >> y;
			if (wuf.same(x, y)) {
				printf("%lld\n", wuf.dist(x, y));
			}
			else {
				puts("?");
			}
		}
	}

	return 0;
}
