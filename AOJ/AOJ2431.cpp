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

/* -----  2018/06/10  Problem: AOJ 2431 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2431  ----- */
/* ------問題------

太郎君は引っ越しをすることになりました。
太郎君はたくさんの荷物を持っているので、荷物の運搬を引っ越し業者に頼むことにしました。
荷物はいろいろな重さの物があるので、わかりやすいように軽い方から順番に並べて置いてもらうように頼みましたが、
引っ越し業者の人はばらばらの順番で荷物を置いていってしまいました。そこで太郎君は荷物を並べ替えようとしましたが、
荷物は重いので運ぶのには体力が必要です。
それぞれの荷物は今ある場所から他の荷物の間や荷物の端など好きな場所に運ぶことができますが、
ある荷物を運ぶにはその荷物の重さと同じだけ体力を使います。太郎君はあまり体力がないので、
できるだけ体力を使わずに荷物を軽い方から順番に並べる方法を考えることにしました。

-----問題ここまで----- */
/* -----解説等-----

最重の列を保存したい。
したがって次を考える。
dp[i]:=ithを選択したときの最重の選択
O(N^2)の適当DPが思いつくが、範囲maxがあればいいのでO(NlogN)でこの問題が解ける。

----解説ここまで---- */
struct nd {
	long long v;
	nd(long long v = 0) :v(v) {} // ! e
};
struct SegmentTreeFastAry {
	nd merge(nd& l, nd& r) {
		nd ret;
		ret.v = max(l.v, r.v);
		return ret;
	}
	void updatepoint(nd& node, nd& nx) { // point update 
		node.v = nx.v;
	}
	void addpoint(nd& node, nd& nx) { // point add
		node.v += nx.v;
	}

	// -- setting -- // 
	int ARY_SIZE; nd node[1 << 20]; // 131072
	void init(int n) { ARY_SIZE = 1; while (ARY_SIZE < n) ARY_SIZE <<= 1; }
	SegmentTreeFastAry(int n) : ARY_SIZE(1) { init(n); }
	inline void update(int i, nd& val) {
		i += ARY_SIZE; updatepoint(node[i], val);
		while (i > 1) { i >>= 1;	node[i] = merge(node[i << 1], node[(i << 1) + 1]); }
	}
	inline void add(int i, nd& val) {
		i += ARY_SIZE; addpoint(node[i], val);
		while (i > 1) { i >>= 1; node[i] = merge(node[i << 1], node[(i << 1) + 1]); }
	}
	inline nd query(int l, int r) {
		if (l >= r) return nd(); nd vl = nd(), vr = nd();
		for (l += ARY_SIZE, r += ARY_SIZE; l != r; l >>= 1, r >>= 1) {
			if (l & 1) vl = merge(vl, node[l++]); if (r & 1) vr = merge(node[--r], vr);
		}	return merge(vl, vr);
	}
	nd operator[](int i) { return node[i + ARY_SIZE]; }
	void debugShow() { for (int i = ARY_SIZE; i < ARY_SIZE << 1; ++i) cerr << node[i].v << " "; cerr << "\n"; }
};
LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	SegmentTreeFastAry seg(N+10);
	FOR(i, 0, N) {
		LL w;
		cin >> w;
		LL ret = seg.query(0,w).v + w;
		nd a = nd(ret);
		seg.update(w, a);
	}
	ans = N*(N + 1) / 2 - seg.query(1, N+1).v;
	cout << ans << "\n";

	return 0;
}
