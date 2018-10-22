#include <bits/stdc++.h>
using namespace std;

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
#define DEBUG(x) 
#endif
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/10/16  Problem: SPOJ COT / Link: https://www.spoj.com/problems/COT  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----



----解説ここまで---- */
int sc = 0;
struct PersistentSegmentTree {
	struct Monoid {
		int x;
		Monoid(int x = 0) :x(x) {}
	};
	Monoid f(Monoid &L, Monoid &R) {
		return Monoid(L.x + R.x);
	}
	struct Node {
		Monoid data;
		Node *l, *r;

		Node(Monoid &data) : data(data) {
			DEBUG(fmt("sc is:%d\n", ++sc))
		}
	};

	const Monoid E;
	int sz;

	PersistentSegmentTree(int n) :sz(n), E() {}

	Node *build(vector< Monoid > &v) {
		sz = (int)v.size();
		return build(0, (int)v.size(), v);
	}

	Node *merge(Node *l, Node *r) {
		Monoid xx = f(l->data, r->data);
		Node *t = new Node(xx);
		t->l = l;
		t->r = r;
		return t;
	}

	Node *build(int l, int r, vector< Monoid > &v) {
		if (l + 1 >= r) return new Node(v[l]);
		return merge(build(l, (l + r) >> 1, v), build((l + r) >> 1, r, v));
	}

	Node *update(int a, Monoid &x, Node *k, int l, int r) {
		if (r <= a || a + 1 <= l) {
			DEBUG(fmt("[%d,%d) is out of range\n", l, r))
				return k;
		}
		else if (a <= l && r <= a + 1) {
			Monoid ne = f(k->data, x);
			DEBUG(fmt("[%d,%d) is just Count is[%d]\n", l, r, ne.x));
			return new Node(ne);
		}
		else {
			DEBUG(fmt("[%d,%d) is merge\n", l, r));
			return merge(update(a, x, k->l, l, (l + r) >> 1), update(a, x, k->r, (l + r) >> 1, r));
		}
	}

	Node *update(Node *t, int k, Monoid &x) {
		return update(k, x, t, 0, sz);
	}

	Monoid query(int a, int b, Node *k, int l, int r) {
		if (r <= a || b <= l || !k) {
			return E;
		}
		else if (a <= l && r <= b) {
			return k->data;
		}
		else {
			Monoid vl = query(a, b, k->l, l, (l + r) >> 1);
			Monoid vr = query(a, b, k->r, (l + r) >> 1, r);
			return f(vl, vr);
		}
	}

	Monoid query(Node *t, int a, int b) {
		return query(a, b, t, 0, sz);
	}
};

#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define fd(i,a,b) for(int i=a; i>=b; i--)

#define N 111111
#define LN 19
int v[N], pa[N][LN], RM[N], depth[N], maxi = 0;
vector <int> adj[N];
map <int, int> M;

PersistentSegmentTree::Node *null;
PersistentSegmentTree::Node *root[N];
PersistentSegmentTree::Monoid zero;
PersistentSegmentTree::Monoid one(1);
PersistentSegmentTree seg(N);
void dfs(int cur, int prev)
{
	pa[cur][0] = prev;
	depth[cur] = (prev == -1 ? 0 : depth[prev] + 1);
	// Construct the segment tree for this node using parent segment tree	
	// This is the formula we derived
	root[cur] = seg.update((prev == -1 ? null : root[prev]), M[v[cur]], one);

	rep(i, (int)adj[cur].size())
		if (adj[cur][i] != prev)
			dfs(adj[cur][i], cur);
}

int LCA(int u, int v)
{
	if (depth[u] < depth[v])
		return LCA(v, u);

	int diff = depth[u] - depth[v];

	rep(i, LN)
		if ((diff >> i) & 1)
			u = pa[u][i];

	if (u != v)
	{
		fd(i, LN - 1, 0)
			if (pa[u][i] != pa[v][i])
			{
				u = pa[u][i];
				v = pa[v][i];
			}
		u = pa[u][0];
	}

	return u;
}
typedef PersistentSegmentTree::Node node;
int query(node *a, node *b, node *c, node *d, int l, int r, int k) {
	DEBUG(
		fmt("L(%d),R(%d),K(%d)\n", l, r, k);
	)
		if (l + 1 == r)
		{
			return l;
		}

	// This is the formula we derived
	int count = a->l->data.x + b->l->data.x - c->l->data.x - d->l->data.x;
	int m = (l + r) >> 1;

	// We have enough on left, so go left
	if (count >= k)
		return query(a->l, b->l, c->l, d->l, l, m, k);

	// We do not have enough on left, go right, remove left elements count
	return query(a->r, b->r, c->r, d->r, m, r, k - count);
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int n, m;
	scanf("%d%d", &n, &m);
	DEBUG(
		fmt("%d %d", n, m);
	)
		FOR(i, 0, n) {
		scanf("%d", &v[i]);
		M[v[i]];
	}

	maxi = 0;
	for (map <int, int > ::iterator it = M.begin(); it != M.end(); it++)
	{
		M[it->first] = maxi;
		RM[maxi] = it->first;
		maxi++;
	}
	// We compressed the given weights into the range [0..n)

	rep(i, n - 1) {
		adj[i].pb(i + 1);
		adj[i + 1].pb(i);
	}

	// Root the tree at some node.
	seg.sz = maxi;
	memset(pa, -1, sizeof pa);
	null = new PersistentSegmentTree::Node(zero);

	null->l = null->r = null;

	dfs(0, -1);

	// Build jump table for LCA in O( log N )
	rep(i, LN - 1)
		rep(j, n)
		if (pa[j][i] != -1)
			pa[j][i + 1] = pa[pa[j][i]][i];
	while (m--) {
		int u, v, k;
		scanf("%d%d%d", &u, &v, &k);
		u--; v--;

		int lca = LCA(u, v);
		DEBUG(debug(u, v, lca));
		// Four nodes we spoke about are u, v, lca, parent(lca)
		int ans = query(root[u], root[v], root[lca], (pa[lca][0] == -1 ? null : root[pa[lca][0]]), 0, maxi, k);

		// Reverse Map the values, that is, uncompress
		printf("%d\n", RM[ans]);
	}

	return 0;
}
