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

/* -----  2018/11/12  Problem: EDU054 E / Link: __CONTEST_URL__  ----- */
/* ------問題------

以下のクエリを処理せよ。
(v,d,x)頂点vの部分木に存在し、深さの差分がd以下であるような頂点全てにxを加算する。

-----問題ここまで----- */
/* -----解説等-----

影響範囲がd[i]であるような部分木は、dfsする際に根からの(深さについての直列)パスを見れば良い。
潜る際に足して出るときに戻せばいい感じに辻褄があう。

これは、更にちゃんと考えることができて、二次元に拡張する。(preorder, depth)としたとき、
ある頂点vからd[v]の距離というのは、[depth[v],depth[v]+d[v]]までに値を加算し、その範囲はin[v]からout[v]までとなる。
これは長方形に加算する動作に対応し、点の値は一点(x,y)をみるだけになる。
実際には実現が厳しいが、in[v]の順番に巡回していくとしたとき、out[v]で辻褄合わせが可能ということに着目すればよく、これは容易である。

今回はimos法っぽくやっているが、遅延セグ木で範囲加算を行えば木の巡回中に加算をやる必要はない。
->遅延セグ木解も書いた(BITで代用した)
これは、pre-orderでやったあと、out[v]を先に処理すれば正しいと言える。

----解説ここまで---- */
PII et[300005]; // V: seg.query(et[v].first, et[v].second), E:(et[v].first+1,et[v].second)
void calc(const vector<vector<int>>&G, int root = 0) {
	int k = 0;
	stack<PII> s;
	s.push(PII(root, -1));
	while (!s.empty()) {
		PII q = s.top(); s.pop();
		int x = q.first, p = q.second;
		if (x < 0 || !x&&p>0) {
			et[-x].second = k;
			continue;
		}
		s.push(PII(-x, -p));
		et[x].first = k++;
		for (int i = 0; i < (int)G[x].size(); i++) {
			int y = G[x][i];
			if (y == p) continue;
			s.push(PII(y, x));
		}
	}
}
// 半開区間 0index
template<class T>
struct RaBIT {
	int n; vector<T> bit0, bit1;
	RaBIT(int sz) :n(sz), bit0(n + 1, 0), bit1(n + 1, 0) {}

	T subsum(vector<T>& bit, int i) {
		T s = 0;
		while (i > 0) {
			(s += bit[i]);
			i -= i & -i;
		}
		return s;
	}
	void add(vector<T>& bit, int i, T x) {
		while (i <= n) {
			(bit[i] += x);
			i += i & -i;
		}
	}
	void rangeadd(int a, int b, T x) {
		a++;
		add(bit0, a, -(x * (a - 1)));
		add(bit1, a, x);
		add(bit0, b + 1, x * b);
		add(bit1, b + 1, -x);
	}
	T query(int a, int b) {
		a++;
		return ((subsum(bit1, b) * b + subsum(bit0, b))
			- (subsum(bit1, a - 1) * (a - 1) + subsum(bit0, a - 1)));
	}
};
void dfs(int v, int p, int dep, const VVI&G, VI&depth) {
	depth[v] = dep;
	for (int nx : G[v]) {
		if (nx != p) {
			dfs(nx, v, dep + 1, G, depth);
		}
	}
}
int main() {
	int N; scanf("%d", &N);
	VVI G(N);
	int a, b;
	FOR(i, 0, N - 1) {
		scanf("%d%d", &a, &b); a--, b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	calc(G, 0);
	VI depth(N, 0);
	dfs(0, -1, 0, G, depth);

	RaBIT<LL> seg(300010);
	int Q; scanf("%d", &Q);
	using tp = tuple<int, int, int>;
	vector<vector<tp>> ADD(N + 1); //order in[v]
	vector<vector<tp>> MINUS(N + 1); //order in[v]
	{
		int v, d, x;
		FOR(i, 0, Q) {
			scanf("%d%d%d", &v, &d, &x);
			v--;
			ADD[et[v].first].push_back(tp(depth[v], d, x));
			MINUS[et[v].second].push_back(tp(depth[v], d, x));
		}
	}
	DD(
	FOR(i, 0, N) {
		cout << et[i].first << "," << et[i].second << endl;
	}
	De(depth);

	);
	VL ans(N, 0);
	VI inv(N, 0);
	FOR(i, 0, N) {
		inv[et[i].first] = i;
	}
	FOR(in_v, 0, N) {
		for (auto it : MINUS[in_v]) {
			int s, len, x; tie(s, len, x) = it;
			int E = min(300005, s + len + 1);
			DD(de(s, E, -x));
			seg.rangeadd(s, E, -x);
		}
		DD(FOR(i, 0, N) {
			cout << seg.query(i, i + 1) << ", ";
		}cout << endl;)
		for (auto it : ADD[in_v]) {
			int s, len, x; tie(s, len, x) = it;
			int E = min(300005, s + len + 1);
			DD(de(s, E, x));
			seg.rangeadd(s, E, x);
		}
		DD(FOR(i, 0, N) {
			cout << seg.query(i, i + 1) << ", ";
		}cout << endl;)
		// ans
		ans[inv[in_v]] = seg.query(depth[inv[in_v]], depth[inv[in_v]] + 1);

	}


	FOR(i, 0, N) {
		printf("%lld ", ans[i]);
	}
	puts("");

	return 0;
}

//template<typename type>
//struct BIT { // 0-index
//	int N;
//	vector<type> data;
//	BIT(){}
//	void init(int n) {
//		N = n; data = vector<type>(n + 1, 0);
//	}
//	void add(int i, type w) { // a[i] += w
//		for (int x = i; x < N; x |= x + 1) {
//			data[x] += w;
//		}
//	}
//	type sum(int i) { // a[0] +...+ a[i-1] !!! [0,i)
//		type ret = 0;
//		for (int x = i - 1; x >= 0; x = (x&(x + 1)) - 1) {
//			ret += data[x];
//		}
//		return ret;
//	}
//	type sum(int l, int r) { //a[l]+...+a[r-1] !!! [l,r)
//		return sum(r) - sum(l);
//	}
//};
//
//VVI G;
//vector<vector<PII>>query;
//BIT<LL> bit;
//LL ans[300005];
//
//void dfs(int v, int p , int dep) {
//	for (PII it : query[v]) {
//		int d = it.first, x = it.second;
//		bit.add(dep, x);
//		bit.add(dep + d + 1, -x);
//	}
//	ans[v] = bit.sum(0, dep + 1);
//	for (int nx : G[v]) {
//		if (nx != p) {
//			dfs(nx, v, dep + 1);
//		}
//	}
//
//	for (PII it : query[v]) {
//		int d = it.first, x = it.second;
//		bit.add(dep, -x);
//		bit.add(dep + d + 1, x);
//	}
//}
//int main() {
//
//	int N; scanf("%d", &N);
//	G = VVI(N);
//	bit.init(N);
//	int a, b;
//	FOR(i, 0, N - 1) {
//		scanf("%d%d", &a, &b); a--, b--;
//		G[a].push_back(b);
//		G[b].push_back(a);
//	}
//	int Q; scanf("%d", &Q);
//	query = vector<vector<PII>>(N);
//	int v, d, x;
//	FOR(i, 0, Q) {
//		scanf("%d%d%d", &v, &d, &x);
//		v--;
//		query[v].push_back(PII(d, x));
//	}
//	dfs(0,-1,0);
//	FOR(i, 0, N) {
//		printf("%lld ", ans[i]);
//	}
//	puts("");
//
//	return 0;
//}
