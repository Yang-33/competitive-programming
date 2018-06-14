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

/* -----  2018/06/14  Problem: IOI_Road-Development / Link: https://www.ioi-jp.org/camp/2015/2015-sp-tasks/2015-sp-d2.pdf + atcoder  ----- */
/* ------問題------

実際に行ったグラフの辺の建築と、行わなかった建築がある。
建築は以下：
1:二点間を移動可能であれば未舗装の辺を舗装する。(辺のコスト和を出力)
2:二点間を移動可能でなければ未舗装の辺をはる。(コストなし)
行った建築の途中に、行われなかった建築が来るので、
もしそれを単独で行っていた際に(後に影響しないという意味)
どれだけコストが掛かったかを出力せよ。

-----問題ここまで----- */
/* -----解説等-----

建築では最終的に森ができる。したがって建築コストを求める際は木のpathの和を求めるということになる。
問題文の読解が50%、実装方針が49%、実装1%っぽい。
辺のnode,頂点のnodeをmergeしたりするという感じで良さそう。
辺の値を1,頂点を0とする。これで木を構築し、(頂点)-(辺)-(頂点)
としてつなぐ。次に実際の建築でコストを求める必要はなく、pathの値を全部0にする。
行われなかった建築ではpathの和を求めれば良い。
hldはクエリ先読みででできるのかな？

----解説ここまで---- */


struct LCNode {
	using NP = LCNode*;
	static NP last;
	long long  d, dsm, ma;
	long long lz;
	NP init_last() {
		sz = 0;
		lz = 0;
		d = dsm = ma = 0;
		return this;
	}
	void init_node(int d) {
		sz = 1; rev = false;
		lz = -1;
		this->d = dsm = ma = d;
	}
	void update() {
		sz = 1 + l->sz + r->sz;
		dsm = d + l->dsm + r->dsm;
		ma = max(d, max(l->ma, r->ma));
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
		if (lz != -1) { // !
			if (l != last) {
				l->lzdata(lz);
			}
			if (r != last) {
				r->lzdata(lz);
			}
			lz = -1;
		}
	}
	void revdata() {
		rev ^= true; swap(l, r);
	}
	void lzdata(long long x) {
		d = x;
		dsm = x*sz;
		ma = x;
		lz = x;
	}
	NP sea(int k) {
		push();
		if (k < l->dsm) {
			return l->sea(k);
		}
		k -= l->dsm;
		if (k == 0 && d == 1) {
			splay();
			return this;
		}
		k -= d;
		return r->sea(k);
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

const int MN = 100100;
LCNode lctV[MN];
LCNode lctE[MN];
#define FOR(i,s,t ) for(int i = s; i < t ;i ++)



int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, Q;
	cin >> N >> Q;
	FOR(i, 0, MN) {
		lctV[i] = LCNode();
		lctV[i].init_node(0);
	}
	FOR(i, 0, MN) {
		lctE[i] = LCNode();
		lctE[i].init_node(1);
	}
	int id = 1;
	FOR(q, 0, Q) {
		int t, a, b;
		cin >> t >> a >> b;
		a--, b--;
		if (t == 1) { //exe
			if (lctV[a].lca(&lctV[b]) == nullptr) {// add edge
				lctV[a].evert();
				lctV[a].link(&lctE[id]);
				lctE[id].link(&lctV[b]);
				id++;
			}
			else { // cost to 0
				lctV[a].evert();
				lctV[b].expose();
				lctV[b].lzdata(0);
			}
		}
		else { //dis
			if (lctV[a].lca(&lctV[b]) == nullptr) {// add edge
				cout << -1 << endl;
			}
			else { // cost
				lctV[a].evert();
				lctV[b].expose();
				cout << lctV[b].dsm << endl;
			}
		}
	}

	return 0;
}