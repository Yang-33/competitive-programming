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
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/11/07  Problem: ARC 026 D / Link: http://arc026.contest.atcoder.jp/tasks/arc026_d  ----- */
/* ------問題------

ダイナミック王国には N 個の村があり、0 から N−1 までの番号がついています。それらの村は M 本の道でひと繋がりになっていました。「ひと繋がりになっている」とは、どの村からどの村へもいくつかの道を辿って行くことが出来る状態のことを指します。ある日大規模な災害によって全ての道が壊れて、村と村の間の移動が出来なくなってしまいました。あなたは王様の高橋君から、道を修理してダイナミック王国の N 個の村をひと繋がりにする仕事を依頼されました。
あなたはまず、それぞれの道を修理するため必要な費用と時間を見積もりました。そして、修理する道を適切に選んだ時の「採算がとれる最低限の時給」の最小値を計算することにしました。「採算がとれる最低限の時給」とは、「道を修理するためにかかる時間の合計」×「時給」が「道を修理するためにかかる費用の合計」と等しくなる時の「時給」の金額の値を指します。
必ずしも全ての道を修理する必要はないことや、村をひと繋がりにするために必要のない道を修理しても良いことに注意して下さい。

-----問題ここまで----- */
/* -----解説等-----

典型そう。
平均値を最小化したい。
この時、適当な集合があって、\sum T[i]-X*C[i] <=0であればよいことになる。
これを二分探索する。
内容はこれを満たす最小全域木的なものがあるか、という問いになる。
最小全域木は作らないとダメだが、更に追加してもいい辺があって、これは負の辺。
負の辺も追加しないといけないことに全然気づけなかった。

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
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, M; cin >> N >> M;
	using VD = vector<double>;
	VI a(M), b(M); VD c(M), t(M);
	FOR(i, 0, M) {
		cin >> a[i] >> b[i] >> c[i] >> t[i];
	}
	auto f = [&](double X) {
		using tp = tuple<double, int, int>;
		vector<tp>edges(M);
		FOR(i, 0, M) {
			edges[i] = tp(c[i] - X * t[i], a[i], b[i]);
		}
		SORT(edges);
		double costSum = 0;
		UnionFind uf(N);
		for (auto edge : edges) {
			double co; int a, b;
			tie(co, a, b) = edge;
			if (uf.same(a, b)) {
				if (co <= 0.0)costSum += co;
				continue;
			}
			costSum += co;
			uf.unionSet(a, b);
		}
		// end
		if (uf.size(0) != N) { return false; }
		return costSum <= 0.0;
	};
	double L = 0, R = 1e18;
	FOR(i, 0, 100) {
		double mid = (L + R) / 2;
		if (f(mid)) {
			R = mid;
		}
		else {
			L = mid;
		}
	}

	double ans = R;
	cout << fixed << setprecision(10) << ans << endl;

	return 0;
}