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

/* -----  2019/07/20  Problem: AOJ 0113 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0113  ----- */


int main() {

	LL P, Q;
	while (cin >> P >> Q) {
		VL visit(Q, -1);
		visit[P] = 0;
		for (int i = 0; ; i++) {
			P *= 10, cout << P / Q, P %= Q; // 割り算そのもの
			if (P == 0) {
				cout << endl;
				break;
			}
			if (visit[P] != -1) { // 鳩ノ巣原理というか閉路
				cout << endl;
				FOR(j, 0, visit[P]) {
					cout << " ";
				}
				FOR(j, visit[P], i + 1) {
					cout << "^";
				}
				cout << endl;
				break;
			}
			visit[P] = i + 1;
		}
	}

	return 0;
}
