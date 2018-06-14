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
#define db(x) cerr<<#x<<":="<<x<<","
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/06/14  Problem: AOJ 2450 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2450  ----- */
/* ------問題------

N頂点の木がある。
以下のクエリをさばけ。
1:[a,b]のpathをcでぬりつぶす
2:[a,b]のpath上で連続している部分列のうち最大値をもつ列の値を出力

-----問題ここまで----- */
/* -----解説等-----

segtreeならどうしたいかを考える。これができればHLDorLCTreeで終わり。
列なら、
1:やるだけ
2:pre,suf,sum,mxをmerge4回でできそう。

HLDのときは、壊れそう(非可換なのでこわれるのは当然)
ネットワークの課金システムっぽくやればできそう(やらない)

mergeパートが大変だった(あたまがこわれるので)
mergeパートは以下(HLD解でも多分同様+列のmergeもしなきゃダメそう)
左からmergeするとする。
最終的に部分列maxがほしい。
これは列のprefix,suffix,部分列からなるもののうちに含まれる
merge則:
- prefix = a.sum+b.prefix, a.prefix
- suffix = b.sum+a.suffix, b.suffix
- sum = a.sum+ b.sum
- max = a.max, b.max, a.prefix+b.suffix
これをLC木に乗せるので3点に拡張する。
あとは全部書くだけ

☆ 向きのあるmerge関数を書いて内部で3点mergeできるようにしたほうが良さそう…

0.65msで通した。はやいHLDの倍ぐらいかかるのかな？

----解説ここまで---- */

const LL NIL = LINF;
struct LCNode {
	using NP = LCNode*;
	static NP last;

	/* main data block */

	long long  mx, sm, pre, suf;
	long long  v;
	long long lz;
	/* block end */

	NP init_last() {
		sz = 0; // Important
		lz = NIL; // Important
		mx = pre = suf = -INF;
		v = -INF;
		sm = 0;
		return this;
	}
	void init_node(int d) {
		sz = 1; rev = false; // Important
		lz = NIL; // Important
		mx = sm = pre = suf = v = d;
	}
	// push済みのdataに関してやる(mergeと一緒)
	void update() {
		
		sz = 1 + l->sz + r->sz; // Important
		sm = v + l->sm + r->sm;
		// l,c / c,rでやる
		// sm , mx, pre, suf
		pre = max({ l->pre, l->sm+v,l->sm + v + r->pre }); 
		suf = max({ r->suf, r->sm+v , r->sm + v + l->suf });
		mx = max({ v,sm , l->mx, r->mx, l->suf +v + r->pre, l->suf+v, v+r->pre });
	}
	// 遅延させるのでpush
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
		if (lz != NIL) {
			if (l != last) {
				l->lzdata(lz);
			}
			if (r != last) {
				r->lzdata(lz);
			}
			lz = NIL;
		}
	}
	void revdata() {
		rev ^= true; swap(l, r); // Important
		swap(suf, pre);
		// if not abelian, swap elem below
	}
	// 作用素とmonoidのmerge?
	void lzdata(long long x) {
		lz = x;
		v = x;
		if (x >= 0) {
			mx = sm = pre = suf = x*sz;
		}
		else {
			mx = pre = suf = x;
			sm = x*sz;
		}
	}
	/*--- setting ---*/

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
		assert(this != last);
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

	//tree func
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

const int MN = 200005;
LCNode lct[MN];
int getid(LCNode *x) {
	return (x - lct);
}

int main() {
	int N, Q;
	scanf("%d%d", &N, &Q);
	int w;
	FOR(i, 0, N) {
		scanf("%d", &w);
		lct[i] = LCNode();
		lct[i].init_node(w);
	}
	int a, b;
	FOR(i, 0, N - 1) {
		scanf("%d%d", &a, &b);
		a--, b--;
		lct[b].evert();
		lct[b].link(lct+a);
	}
	lct[0].evert();
	FOR(i, 0, N) {
		lct[i].expose();
	}
	int com, c;
	FOR(i, 0, Q) {
		scanf("%d%d%d%d", &com, &a, &b, &c);
		a--, b--;
		if (com == 1) {// update
			lct[a].evert();
			lct[b].expose();
			lct[b].lzdata(c);
		}
		else { // query
			lct[a].evert();
			lct[b].expose();
			printf("%lld\n", lct[b].mx);
		}
	}
}
