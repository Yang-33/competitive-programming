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
#define debug(x) cerr << #x << ": " << x <<", \t"
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/05/26  Problem: world_code_sprint_13 G / Link: https://www.hackerrank.com/contests/world-codesprint-13/challenges/dynamic-trees/problem  ----- */
/* ------問題------

N頂点の木がある。
クエリがQ回与えられる。以下の動作をサポートせよ。
T(x):頂点xの色を反転させる。
C(x,y):xの親をyに変更する
K(x,y,k):x->yへのパスについて、k番目の黒い点の頂点番号を出力する。

-----問題ここまで----- */
/* -----解説等-----

親の変更がたくさんあるので、静的なデータ構造では無理そう。
そこで48時間かけてLC木/平衡二分探索木を勉強する。
すると、クエリについて以下のようにできる。
T:一点変更/範囲変更をする前にevert(x),update(x,!c)
C:cut&link
K:木上の二分探索(パスが平衡二分探索木なので道をたどるだけ)

LC木では、遅延非可換群の計算/親の変更/パスの変更/link/cutができるので
Kが一番大変である。
Kは左、自分、右の順で見なければならないので、クエリ毎にk-1する。
yを根にしてxから見ると、最も深いところからの情報を得ることができる。
あとは二分探索のノリで下れば良い

LC木について、操作は気をつける必要がある。
(updateするときはevert,expose,lzdata)
(link/cut)は親の向きを保存する

----解説ここまで---- */

int Gid = 1;
struct LCNode {
	using NP = LCNode*;
	static NP last;

	/* main data block */
	long long  d, dsm, ma;
	long long lz;
	int id;
	/* block end */

	NP init_last() {
		sz = 0; // Important
		lz = 0; // Important
		d = dsm = ma = 0;
		return this;
	}
	void init_node(int d) {
		sz = 1; rev = false; // Important
		lz = 0; // Important
		id = Gid++;
		this->d = dsm = ma = d;
	}
	void update() {
		sz = 1 + l->sz + r->sz; // Important
		dsm = d + l->dsm + r->dsm;
		ma = max(d, max(l->ma, r->ma));
	}
	void push() {
		assert(this != last);
		if (rev) { // Important
			if (l != last) {
				l->revdata();
			}
			if (r != last) {
				r->revdata();
			}
			rev = false;
		}
		if (lz) {
			if (l != last) {
				l->lzdata(lz);
			}
			if (r != last) {
				r->lzdata(lz);
			}
			lz = 0;
		}
	}
	void revdata() {
		rev ^= true;
		swap(l, r); // Important
					// if non abelian, swapdata.(forward, backward)
	}
	void lzdata(long long x) {
		d = x;
		dsm = x*sz;
		ma = x;
		lz = x;
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
	// 0 index kth
	// 深い方から来ている、なるべく浅い方によせたい
	// 右に決定したとき、node + l->nodeは足して良い
	// が、浅い方からもできるのではという試み -> はい何も理解していない、
	// これは不可能(部分木が条件分岐に使えていない)
	int search(int k) {
		push();
		if (l != last && k < l->dsm) {
			return l->search(k);
		}
		if (l != last)k -= l->dsm;
		if (k == 0 && d) {
			splay();
			return id;
		}
		k -= d;
		return r->search(k);
	}
};
LCNode::NP LCNode::last = (new LCNode())->init_last();

const int MN = 100005;
LCNode node[MN];
int color[MN];
int par[MN];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);


	int N, Q;
	scanf("%d%d", &N, &Q);

	FOR(i, 0, N) {
		scanf("%d", &color[i]);
		node[i] = LCNode();
		node[i].init_node(color[i]);
	}
	FOR(i, 1, N) {
		scanf("%d", &par[i]);
		par[i]--;
		//node[i].evert();
		node[i].link(&node[par[i]]);
	}
	FOR(kim, 0, Q) {
		char c[2]; scanf("%s", c);
		if (c[0] == 'T') { //toggle
			int col; scanf("%d", &col); col--;
			node[col].evert();
			node[col].expose();
			node[col].lzdata(!color[col]);
			color[col] = !color[col];
		}
		else if (c[0] == 'C') { // evert(0)か、親方向にevert(親)する
			int a, b; scanf("%d%d", &a, &b); a--, b--;
			int pOfa = par[a];
			node[0].evert();
			//			node[pOfa].evert();
			node[a].cut();
			node[0].evert();
			node[a].link(&node[b]);
			par[a] = b;
		}
		else if (c[0] == 'K') {
			int a, b, k; scanf("%d%d%d", &a, &b, &k); a--, b--;
			node[a].evert();
			node[b].expose();
			if (node[b].dsm < k)printf("-1\n");
			else printf("%d\n", node[b].search(k - 1));
		}

	}


	return 0;
}