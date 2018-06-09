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

/* -----  2018/05/26  Problem: ioi_spring_2013_spaceship / Link: https://joisc2013-day4.contest.atcoder.jp/  ----- */
/* ------問題------

treeの動的cut,link,lca

-----問題ここまで----- */
/* -----解説等-----

link cut treeを勉強して、貼る

----解説ここまで---- */

struct node {
	node *l, *r, *p;
	int cnt, val, sum;
	int id;
	node() : l(0), r(0), p(0), cnt(0), val(0), sum(0) {}
};
bool isRoot(node * x) {
	return (x->p == 0 || (x->p->l != x && x->p->r != x));
}
void update(node * x) {
	x->cnt = 1;
	x->sum = x->val;
	if (x->l) {
		x->cnt += x->l->cnt;
		x->sum += x->l->sum;
	}
	if (x->r) {
		x->cnt += x->r->cnt;
		x->sum += x->r->sum;
	}
}
void  rotate(node * x) {
	node * p = x->p;
	if (x == p->l) {
		p->l = x->r;
		x->r = p;
		if (p->l)
			p->l->p = p;
	}
	else {
		p->r = x->l;
		x->l = p;
		if (p->r)
			p->r->p = p;
	}
	x->p = p->p;
	p->p = x;
	if (x->p) {
		if (p == x->p->l)x->p->l = x;
		else  if (p == x->p->r)x->p->r = x;
	}
	update(p); update(x);
}

void  splay(node * x) {
	while (!isRoot(x)) {
		node * p = x->p;
		if (!isRoot(p)) {
			if ((x == p->l) == (p == p->p->l))rotate(p);
			else rotate(x);
		}
		rotate(x);
	}
}

node  * access(node  * x) {
	splay(x);
	x->r = 0;
	update(x);

	node  * ret = x;
	while (x->p) {
		node  * y = x->p;
		ret = y;
		splay(y);
		y->r = x;
		update(y);
		splay(x);
	}
	return ret;
}
void  link(node  * x, node  * y) {// x->y
	access(x); access(y);
	x->l = y;
	y->p = x;
	update(x);
}
void cut(node * x) { // x --//--> p
	access(x);
	x->l->p = 0;
	x->l = 0;
	update(x);
}
node* lca(node * x, node * y) {
	access(x);
	return access(y);
}
node * findRoot(node * x) {
	access(x);
	while (x->l) x = x->l;
	splay(x);
	return x;
}
node * parent(node * x) {
	access(x);
	x = x->l;
	if (!x) return 0;
	while (x->r) x = x->r;
	splay(x);
	return x;
}
int depth(node * x) {
	access(x);
	if (x->l) return x->l->cnt;
	return 0;
}


int query(node * x) {
	if (!x) return 0;
	access(x);
	return x->sum;
}
//int query(node * x, node * y) {
//	node * p = lca(x, y);
//	return query(x) + query(y) - query(p) - query(parent(p));
//}

int query(node * x, node * y) {
	node * p = lca(y, x);
	int sum;
	access(x);
	splay(p);
	sum = p->val;
	if (p->r) sum += p->r->sum;

	access(y);
	splay(p);
	if (p->r) sum += p->r->sum;
	return sum;
}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);


	{
		int N, Q;
		cin >> N >> Q;
		node Node[N+1];
		FOR(i, 1, N+1) {
			Node[i].id = i;
		}
		FOR(i, 0, Q) {
			int t; cin >> t;
			if (t == 1) {// a->b link
				int a, b; cin >> a >> b;
				link(&Node[a], &Node[b]);
			}
			else if (t == 2) {// cut a
				int a; cin >> a;
				cut(&Node[a]);

			}else{ // -1 or lca
				int a, b; cin >> a >> b;
				node *ra = findRoot(&Node[a]);
				node *rb = findRoot(&Node[b]);
				if (ra == rb) {
					node *top = lca(&Node[a], &Node[b]);
					cout << top->id << endl;
				}
				else {
					cout << -1 << endl;
				}
			}
		}


	}
	//node Node[100];
	//VI a({ 1,2,3,4,5,6,7 });
	//FOR(i, 1, 16) {
	//	Node[i].val = 1;
	//	Node[i].id = i;
	//}
	//for (auto it : a) {
	//	link(&Node[it * 2], &Node[it]);
	//	link(&Node[it * 2 + 1], &Node[it]);
	//}

	//FOR(i, 1, 16) {
	//	debug(i);
	//	debug(query(&Node[i]));

	//	node *subtop = findRoot(&Node[i]);
	//	cout << "subtop id :" << subtop->id << ", \t";
	//	node *par = parent(&Node[i]);
	//	if (par) {
	//		cout << "parent id :" << par->id << ", \t";
	//	}
	//	else {
	//		cout << "This is top" << ", \t";
	//	}
	//	cout << "path[" << i << ":" << subtop->id << "]:=" << query(subtop, &Node[i]);
	//	cout << endl;
	//}
	//cout << "------------Bin search------------" << endl;

	//struct Query {
	//	int	S, T;
	//	int val;
	//	Query() {}
	//};
	//Query Q[100];
	//{
	//	Q[0].S = 1; Q[0].T = 4; Q[0].val = 2;
	//	//Q[1].S = 1; Q[1].T = 4; Q[1].val = 2;
	//	//Q[2].S = 1; Q[2].T = 4; Q[2].val = 2;
	//	//Q[3].S = 1; Q[3].T = 4; Q[3].val = 2;
	//	//Q[4].S = 1; Q[4].T = 4; Q[4].val = 2;
	//}
	//FOR(q, 0, 1) { // binsearch for R (not lca)
	//	int L, R;
	//	L = Q[q].S;
	//	R = Q[q].T;
	//	FOR(kim, 0, 10) {
	//		int M = 
	//	}
	//	// [S:ans] on path sum = val as ans
	//}
	///*int N, Q; cin >> N >> Q;

	//VI val(N);
	//FOR(i, 0, N) {
	//	cin >> val[i];
	//}*/


	return 0;
}
