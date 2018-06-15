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
const int INF = 1e9;                          const LL LINF = 1e18;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/06/16  Problem: AOJ 2559 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2559  ----- */
/* ------問題------

MSTを作った際に、ある辺を使わなかったとする。そのときのmstは。
また、全域木をつくれないときは-1を出力せよ。

-----問題ここまで----- */
/* -----解説等-----

まず最小全域木につかわれる辺を考えます。
これでない辺のときはコストが変わりません。
次に、使われている辺を考えます。
x-yを使わないとき、もとのグラフGでこれをつなぐことができる辺が存在するならば、x,yをつなぐ最小コストを得たいことになります。
使われなかった辺について考えると、辺の両端がmstのpathを示していることがわかる。(連結できなかったので)
したがって、可能性としてこのpath内の辺を使用しなかったときはこの未使用の辺を使いうる。
このことからpathを更新すれば良いことと、絶対に未使用辺を2本以上使用することは無いことがわかる。
linkcuttreeによくわからない最小コストを保存するものを書けば良い。
辺なのでうまくでき無さそうだけど、点取得のみなので辺属性を頂点の間においてidを保存しておけばできる。
これはHL分解でも簡単にかけそう。

----解説ここまで---- */


struct LCNode {
	using NP = LCNode*;
	static NP last;

	/* main data block */
	long long  d, Min;
	long long lz;
	/* block end */

	NP init_last() {
		sz = 0; 
		lz = LINF; 
		d = Min = LINF;
		return this;
	}
	void init_node(LL d) {
		sz = 1; rev = false;
		lz = LINF;
		this->d = Min = d;
	}
	void update() {
		sz = 1 + l->sz + r->sz;
		Min = min(d, min(l->Min, r->Min));
	}
	void push() {
		if (rev) {
			if (l != last) {
				l->revdata();
			}
			if (r != last) {
				r->revdata();
			}
			rev = false;
		}
		if (lz!=LINF) {
			if (l != last) {
				l->lzdata(lz);
			}
			if (r != last) {
				r->lzdata(lz);
			}
			lz = LINF;
		}
	}
	void revdata() {
		rev ^= true; swap(l, r);
	}
	void lzdata(long long x) {
		d = min(d, x);
		Min = min(Min, x);
		lz = min(lz, x);
	}

	NP p, l, r;
	int sz;
	bool rev;
	LCNode() : p(nullptr), l(last), r(last) {}
	inline int pos() {
		if (p) {
			if (p->l == this) return -1;
			if (p->r == this) return 1;
		}
		return 0;
	}
	void rot() {
		NP q = p->p;
		int pps = p->pos();
		if (pps == -1) q->l = this;
		if (pps == 1) q->r = this;
		if (p->l == this) {
			p->l = r;
			if (r) r->p = p;
			r = p;
		}
		else {
			p->r = l;
			if (l) l->p = p;
			l = p;
		}
		p->p = this;
		p->update(); update();
		p = q;
		if (q) q->update();
	}
	void splay() {
		supush();
		int ps;
		while ((ps = pos())) {
			int pps = p->pos();
			if (!pps) {
				rot();
			}
			else if (ps == pps) {
				p->rot(); rot();
			}
			else {
				rot(); rot();
			}
		}
	}
	void expose() {
		NP u = this, ur = last;
		do {
			u->splay();
			u->r = ur;
			u->update();
			ur = u;
		} while ((u = u->p));
		splay();
	}
	void supush() {
		if (pos()) p->supush();
		push();
	}
	void link(NP r) {
		evert(); r->expose();
		p = r;
	}
	void cut() {
		expose();
		l->p = NULL;
		l = last;
		update();
	}
	void evert() {
		expose(); revdata();
	}

	NP parent() {
		expose();
		NP u = this->l;
		if (u == last) return last;
		u->push();
		while (u->r != last) {
			u = u->r;
			u->push();
		}
		u->expose();
		return u;
	}

	NP root() {
		expose();
		NP u = this;
		while (u->l != last) {
			u = u->l;
			u->push();
		}
		u->expose();
		return u;
	}


	NP lca(NP n) {
		n->expose();
		expose();
		NP t = n;
		while (n->p != nullptr) {
			if (!n->pos()) t = n->p;
			n = n->p;
		}
		return (this == n) ? t : nullptr;
	}
};
LCNode::NP LCNode::last = (new LCNode())->init_last();

const int MN = 100005;
LCNode lctV[MN];
LCNode lctE[MN];

int main() {
	
	
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, E;
	cin >> N >> E;

	FOR(i, 0, N) {
		lctV[i] = LCNode();
		lctE[i] = LCNode();
		lctV[i].init_node(LINF);
		lctE[i].init_node(LINF);
	}
	using tp = tuple<int, int, int, int>;
	vector<tp>edges;
	VI Ws(E);
	FOR(i, 0, E) {
		int a, b, c;
		cin >> a >> b >> c;
		Ws[i] = c;
		edges.emplace_back(c, a, b, i);
	}
	SORT(edges);
	LL mst = 0;
	VL ans(E, LINF);
	int cnt = 0;
	VI saveEdgeId(E,-1);
	int edgeId = 0;
	FOR(i, 0, E) {
		int c, a, b, idx;
		tie(c, a, b, idx) = edges[i];
		a--, b--;
		if (lctV[a].lca(&lctV[b]) == nullptr) {
			mst += c;
			cnt++;
			saveEdgeId[idx] = edgeId;
			// idx番目の辺がどのnodeに対応するかを保存
			lctV[a].evert();
			lctV[a].link(&lctE[edgeId]);
			lctV[b].evert();
			lctV[b].link(&lctE[edgeId]);

			edgeId++;
		}
		else {// path update
			lctV[a].evert();
			lctV[b].expose();
			lctV[b].lzdata(c);
			ans[idx] = -1;
		}
	}


	if (cnt != N - 1) {
		FOR(i, 0, E) {
			cout << -1 << endl;
		}
		return 0;
	}

	FOR(i, 0, E) {//そもそも使われない辺はmstそのまま、使われる辺は、代用が存在する、しないのどちらか
		if (ans[i] == -1) { // unuse
			cout << mst << endl;
		}
		else {
			int idx = saveEdgeId[i];
			lctE[idx].evert();
			lctE[idx].expose();
			LL val = lctE[idx].Min;
			if (val >= LINF) { // cant change
				cout << -1 << endl;
			}
			else {
				cout << mst - Ws[i] + val << endl;
			}
		}
	}

	return 0;
}
