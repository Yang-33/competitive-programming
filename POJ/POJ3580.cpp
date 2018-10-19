#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <set>
#include <sstream>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <climits>
#include <list>
#include <fstream>
#include <functional>
using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef vector<string> VS;

#define ALL(a)  a.begin(),a.end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define EB emplace_back
#define MP make_pair
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

/* -----  2018/10/13  Problem: POJ 3580 / Link: http://poj.org/problem?id=3580  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----



----解説ここまで---- */

#include <assert.h>
struct RBST {
};

void solve_AOJ_DSL2A() {
	int N, Q;
	scanf("%d %d", &N, &Q);
	const int MAX_I = INT_MAX;
	vector<RBST::ND>a(N, RBST::ND(MAX_I));
	RBST seg;
	RBST::RbstNode* root = seg.build(a);

	FOR(i, 0, Q) {
		int c, x, y;
		scanf("%d%d%d", &c, &x, &y);
		if (c == 0) {
			seg.update(root, x, x + 1, RBST::LZ(y));
		}
		else {
			printf("%d\n", seg.query(root, x, y + 1).x);
		}
	}
}

void solve_AOJ_DSL2B() {
	int N, Q;
	scanf("%d %d", &N, &Q);
	vector<RBST::ND>a(N, RBST::ND(0));
	RBST seg;
	RBST::RbstNode* root = seg.build(a);
	FOR(i, 0, Q) {
		int c, x, y;
		scanf("%d%d%d", &c, &x, &y);
		x--;
		if (c == 0) {
			seg.update(root, x, x + 1, RBST::LZ(y));
		}
		else {
			y--;
			printf("%d\n", seg.query(root, x, y + 1).x);
		}
	}
}

void solve_AOJ_DSL2D() {
	int N, Q;
	scanf("%d %d", &N, &Q);
	vector<RBST::ND>a(N, RBST::ND());
	RBST seg;
	RBST::RbstNode* root = seg.build(a);

	FOR(i, 0, Q) {
		int c;
		scanf("%d", &c);
		if (c == 0) {
			int s, t, x;
			scanf("%d%d%d", &s, &t, &x);
			seg.update(root, s, t + 1, RBST::LZ(x));
		}
		else {
			int s;
			scanf("%d", &s);
			printf("%d\n", seg.query(root, s, s + 1).x);
		}
	}
}

void solve_AOJ_DSL2E() {
	int N, Q;
	scanf("%d %d", &N, &Q);
	vector<RBST::ND>a(N, RBST::ND());
	RBST seg;
	RBST::RbstNode* root = seg.build(a);
	FOR(i, 0, Q) {
		int c;
		scanf("%d", &c);
		if (c == 0) {
			int s, t, x;
			scanf("%d%d%d", &s, &t, &x);
			s--, t--;
			seg.update(root, s, t + 1, RBST::LZ(x));
		}
		else {
			int s;
			scanf("%d", &s);
			s--;
			printf("%d\n", seg.query(root, s, s + 1).x);
		}
		//seg.dump(root);
	}
}

void solve_AOJ_DSL2F() {
	int N, Q;
	scanf("%d %d", &N, &Q);
	vector<RBST::ND>a(N, RBST::ND());
	RBST seg;
	RBST::RbstNode* root = seg.build(a);
	FOR(i, 0, Q) {
		int c;
		scanf("%d", &c);
		if (c == 0) {
			int s, t, x;
			scanf("%d%d%d", &s, &t, &x);
			seg.update(root, s, t + 1, RBST::LZ(x));
		}
		else {
			int s, t;
			scanf("%d%d", &s, &t);
			printf("%d\n", seg.query(root, s, t + 1).x);
		}
	}
}

void solve_AOJ_DSL2G() {
	int N, Q;
	scanf("%d %d", &N, &Q);
	vector<RBST::ND>a(N, RBST::ND());
	RBST seg;
	RBST::RbstNode* root = seg.build(a);
	FOR(i, 0, Q) {
		int c;
		scanf("%d", &c);
		if (c == 0) {
			int s, t, x;
			scanf("%d%d%d", &s, &t, &x);
			s--, t--;
			seg.update(root, s, t + 1, RBST::LZ(x));
		}
		else {
			int s, t;
			scanf("%d%d", &s, &t);
			s--, t--;
			printf("%lld\n", seg.query(root, s, t + 1).x);
		}
	}
}

void solve_AOJ_DSL2H() {
	int N, Q;
	scanf("%d %d", &N, &Q);
	vector<RBST::ND>a(N, RBST::ND(0));
	RBST seg;
	RBST::RbstNode* root = seg.build(a);
	FOR(i, 0, Q) {
		int c;
		scanf("%d", &c);
		if (c == 0) {
			int s, t, x;
			scanf("%d%d%d", &s, &t, &x);
			seg.update(root, s, t + 1, RBST::LZ(x));
		}
		else {
			int s, t;
			scanf("%d%d", &s, &t);
			printf("%lld\n", seg.query(root, s, t + 1).x);
		}
		//	seg.dump(root);
	}
}

void solve_AOJ_DSL2I() {
	int N, Q;
	scanf("%d %d", &N, &Q);
	vector<RBST::ND>a(N, RBST::ND(0));
	RBST seg;
	RBST::RbstNode* root = seg.build(a);
	FOR(i, 0, Q) {
		int c;
		scanf("%d", &c);
		if (c == 0) {
			int s, t, x;
			scanf("%d%d%d", &s, &t, &x);
			seg.update(root, s, t + 1, RBST::LZ(x));
		}
		else {
			int s, t;
			scanf("%d%d", &s, &t);
			printf("%lld\n", seg.query(root, s, t + 1).x);
		}
		//	seg.dump(root);
	}
}

void test_reverse() {
	int N, Q;
	scanf("%d %d", &N, &Q);
	vector<RBST::ND>a(N, RBST::ND(0));
	FOR(i, 0, N) {
		a[i].x = i;
	}
	RBST seg;
	RBST::RbstNode* root = seg.build(a);
	FOR(i, 0, Q) {
		{
			int s, t;
			scanf("%d%d", &s, &t);
			seg.reverse(root, s, t);
		}
		seg.dump(root);
	}
}

void test_revolveR() {
	int N, Q;
	scanf("%d %d", &N, &Q);
	vector<RBST::ND>a(N, RBST::ND(0));
	FOR(i, 0, N) {
		a[i].x = i;
	}
	RBST seg;
	RBST::RbstNode* root = seg.build(a);
	FOR(i, 0, Q) {
		{
			int s, t, k;
			scanf("%d%d%d", &s, &t, &k);
			seg.revolveR(root, s, t, k);
		}
		seg.dump(root);
	}
}
void test_revolveL() {
	int N, Q;
	scanf("%d %d", &N, &Q);
	vector<RBST::ND>a(N, RBST::ND(0));
	FOR(i, 0, N) {
		a[i].x = i;
	}
	RBST seg;
	RBST::RbstNode* root = seg.build(a);
	FOR(i, 0, Q) {
		{
			int s, t, k;
			scanf("%d%d%d", &s, &t, &k);
			seg.revolveL(root, s, t, k);
		}
		seg.dump(root);
	}
}

void solve_AOJ_1508() {
	int N, Q;
	scanf("%d %d", &N, &Q);
	vector<RBST::ND>a(N, RBST::ND(0));
	FOR(i, 0, N) {
		scanf("%d", &a[i].x);
	}
	RBST seg;
	RBST::RbstNode* root = seg.build(a);
	FOR(i, 0, Q) {
		int c; scanf("%d", &c);
		if (c == 0) {
			int s, t;
			scanf("%d%d", &s, &t);
			seg.revolveR(root, s, t + 1, 1);
		}
		else if (c == 1) {
			int s, t;
			scanf("%d%d", &s, &t);
			printf("%d\n", seg.query(root, s, t + 1).x);

		}
		else {
			int s, t;
			scanf("%d%d", &s, &t);
			seg.update(root, s, s + 1, RBST::LZ(t));
		}
		//seg.dump(root);
	}
}

void solve_POJ_3580() {
	int N;
	scanf("%d", &N);
	vector<RBST::ND>ar(N, RBST::ND(0));
	FOR(i, 0, N) {
		scanf("%lld", &ar[i].x);
	}
	RBST seg;
	RBST::RbstNode* root = seg.build(ar);
	//seg.dump(root);

	int Q; scanf("%d", &Q);
	char s[10];
	int x, y, a;
	FOR(_, 0, Q) {
		scanf("%s", s);
		//		FOR(i, 0, 10) s[i] = toupper(s[i]);
		if (s[0] == 'A') {// ADD
			scanf("%d%d%d", &x, &y, &a); x--, y--;
			seg.update(root, x, y + 1, a);
		}
		else if (s[0] == 'R' && s[3] == 'E') { //reverse
			scanf("%d%d", &x, &y); x--, y--;
			seg.reverse(root, x, y + 1);
		}
		else if (s[0] == 'R' && s[3] == 'O') { // resolveR
			scanf("%d%d%d", &x, &y, &a); x--, y--;
			seg.revolveR(root, x, y + 1, a);
		}
		else if (s[0] == 'I') { // INSERT
			scanf("%d%d", &x, &a);
			root = seg.insert(root, x, RBST::ND(a));
		}
		else if (s[0] == 'D') { // ERASE
			scanf("%d", &x); x--;
			root = seg.erase(root, x);
		}
		else if (s[0] == 'M') { // MIN
			scanf("%d%d", &x, &y); x--, y--;
			printf("%lld\n", seg.query(root, x, y + 1).x);
		}
		//seg.dump(root);
	}
}

int main() {

	//solve_AOJ_DSL2A();
	//solve_AOJ_DSL2B();
	//solve_AOJ_DSL2D();
	//solve_AOJ_DSL2E();
	//solve_AOJ_DSL2F();
	//solve_AOJ_DSL2G();
	//solve_AOJ_DSL2H();
	//solve_AOJ_DSL2I();

	//test_reverse();
	//test_revolveR();
	//test_revolveL();

	//solve_AOJ_1508();
	solve_POJ_3580();


	return 0;
}
