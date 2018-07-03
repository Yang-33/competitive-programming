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

/* -----  2018/07/01  Problem: AOJ 1001 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/1001  ----- */
/* ------問題------

二分木が、(,)を一つのノードであらわして表現される。
Union,intersectを実装せよ。

-----問題ここまで----- */
/* -----解説等-----

parseの段階で二分木にしてしまえば勝ち。

----解説ここまで---- */

struct Node {
	Node * l, *r;
	Node():l(nullptr),r(nullptr) {}
};
Node node[500];
int nodecnt = 1;

Node* parse(int & i ,string& s) {
	if (s[i] != '(') {
		return nullptr;
	}
	i++;
	Node *nnode = &node[nodecnt++];
	nnode->l = parse(i, s);
	i++;// , 
	nnode->r = parse(i, s);
	i++; // )
	return nnode;
}

Node* Intersect(Node* a, Node* b) {
	if (a->l && b->l) {
		a->l = Intersect(a->l, b->l);
	}
	else {
		a->l = nullptr;
	}
	if (a->r && b->r) {
		a->r = Intersect(a->r, b->r);
	}
	else {
		a->r = nullptr;
	}
	return a;
}
Node* Union(Node* a, Node* b) {
	if (a->l && b->l) {
		a->l = Union(a->l, b->l);
	}
	else if(b->l){
		a->l = b->l;
	}
	if (a->r && b->r) {
		a->r = Union(a->r, b->r);
	}
	else if (b->r) {
		a->r = b->r;
	}
	return a;
}

Node* solve(string & op, Node* a, Node* b) {
	if (op == "i") {
		return Intersect(a, b);
	}
	else {
		return Union(a, b);
	}

}

void Debug(Node* a) {
	cout << "(";
	if (a->l) {
		Debug(a->l);
	}
	cout << ",";
	if (a->r) {
		Debug(a->r);
	}
	cout << ")";
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string op, a, b;
	while (cin >> op >> a >> b) {
		nodecnt = 1;
		FOR(i, 0, 500) {
			node[i] = Node();
		}
		int i = 0;
		Node* A = parse(i,a);
		i = 0;
		Node* B = parse(i,b);
		Debug(solve(op, A,B));
		cout << endl;
	}

	return 0;
}
