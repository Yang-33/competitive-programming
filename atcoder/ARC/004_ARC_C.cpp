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
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2019/04/04  Problem: ARC 004 C / Link: http://arc004.contest.atcoder.jp/tasks/arc004_c  ----- */

long long  gcd(long long  a, long long  b) { return b ? gcd(b, a%b) : a; }

int main() {

	LL X, Y;
	scanf("%lld/%lld", &X, &Y);
	LL g = gcd(X, Y);
	X /= g, Y /= g;
	DD(de(X,Y))
	vector<PLL>anss;
	FOR(i, 0, 3) {
		LL N = 2*X / Y + i;
		DD(de(N))
		if (N%Y == 0) {
			LL M = N * (N + 1) / 2 - N / Y*X;
			if (1 <= M && M <= N) {
				anss.push_back(PLL(N, M));
			}
		}
	}
	if (SZ(anss)) {
		for (auto it : anss) {
			cout << it.first << " " << it.second << endl;
		}
	}
	else {
		cout << "Impossible" << endl;
	}


	return 0;
}
