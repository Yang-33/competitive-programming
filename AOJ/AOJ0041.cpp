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

/* -----  2019/07/13  Problem: AOJ 0041 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0041  ----- */
int d[4];
const char *op = "+-*";

int cal(int a, int o, int b) {
	if (o == 0) return a + b;
	if (o == 1) return a - b;
	return a * b;
}

bool sol(int a, int b, int c) {
	if (cal(cal(cal(d[0], a, d[1]), b, d[2]), c, d[3]) == 10) {
		printf("(((%d %c %d) %c %d) %c %d)\n", d[0], op[a], d[1], op[b], d[2], op[c], d[3]);
		return true;
	}
	if (cal(cal(d[0], a, d[1]), b, cal(d[2], c, d[3])) == 10) {
		printf("((%d %c %d) %c (%d %c %d))\n", d[0], op[a], d[1], op[b], d[2], op[c], d[3]);
		return true;
	}
	if (cal(cal(d[0], a, cal(d[1], b, d[2])), c, d[3]) == 10) {
		printf("((%d %c (%d %c %d)) %c %d)\n", d[0], op[a], d[1], op[b], d[2], op[c], d[3]);
		return true;
	}
	return false;
}

bool jg() {
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			for (int k = 0; k < 3; ++k) {
				if (sol(i, j, k)) return true;
			}
		}
	}
}

int main() {
	for (;;) {
		scanf("%d %d %d %d", &d[0], &d[1], &d[2], &d[3]);
		if (d[0] == d[1] && d[1] == d[2] && d[2] == d[3] && d[0] == 0) break;
		sort(d, d + 4);
		bool f = 0;
		do {
			if (jg()) { f = 1; break; }
		} while (next_permutation(d, d + 4));
		if (f == 0) printf("0\n");
	}

	return 0;
}
