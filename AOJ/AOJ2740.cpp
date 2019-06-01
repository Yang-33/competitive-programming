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

/* -----  2019/05/30  Problem: AOJ 2740 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/2740  ----- */


// parse中に木を組み立てるみたいなことをする
// ぽいんたをかえす

// 木を降りるだけ
struct Tree {
	int num;
	Tree *L;
	Tree *R;
	Tree(int x) :num(x), L(nullptr), R(nullptr) {}
	Tree() :num(0), L(nullptr), R(nullptr) {}
	void Print() {
		cout << "(";
		if (L)L->Print();
		cout << ")";
		cout << "[" << num << "]";
		cout << "(";
		if (R)R->Print();
		cout << ")";
	}
};

// これなんでいるんだっけ?
Tree node[10000];
int nodecnt = 0;

Tree* parse(const string&s, int &id) {
	Tree *t = &node[nodecnt++];
	bool upd = 0;
	if (s[id] == '(') {
		upd = 1;
		id++;
		t->L = parse(s, id);
		id++;
	}
	if (s[id] == '[') {
		upd = 1;
		id++;
		int ret = 0;
		while (isdigit(s[id])) {
			ret *= 10;
			ret += s[id] - '0';
			id++;
		}
		t->num = ret;
		id++;
	}
	//assert(s[id] == '(');
	if (s[id] == '(') {
		upd = 1;
		id++;
		t->R = parse(s, id);
		id++;
	}
	if (upd) {
		return t;
	}
	else {
		return nullptr;
	}
}

void down(Tree* a, Tree* b) {
	cout << "(";
	if (a->L != nullptr && b->L != nullptr) {
		down(a->L, b->L);
	}
	cout << ")";
	cout << "[" << a->num + b->num << "]";
	cout << "(";
	if (a->R != nullptr && b->R != nullptr) {
		down(a->R, b->R);
	}
	cout << ")";
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	FOR(i, 0, 10000) {
		node[i] = Tree(0);
	}
	auto f = []() {
		string s; cin >> s;
		int id = 0;
		Tree *uku = parse(s, id);
		return uku;
	};
	Tree* A = f();
	Tree* B = f();
	//A->Print();
	//cout << endl;
	//B->Print();
	//cout << endl;
	down(A, B);
	cout << endl;

	//cout << (ans) << "\n";

	return 0;
}
