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

/* -----  2019/04/11  Problem: ABC 011 D / Link: http://abc011.contest.atcoder.jp/tasks/abc011_d  ----- */

vector<double>pw, fact;
double nCr(int a, int b) {
	return exp(pw[a] + fact[a] - fact[a - b] - fact[b]);
}

void init_fact(int N) {
	N++;
	pw.assign(N, 0); fact.assign(N, 0);
	FOR(i, 1, N) {
		pw[i] = pw[i - 1] + log(0.5);
		fact[i] = fact[i - 1] + log(i);
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	//pascals_triangle(2000);
	init_fact(2005);
	LL N, D, X, Y; cin >> N >> D >> X >> Y;
	X = abs(X), Y = abs(Y);
	if (X % D || Y % D) {
		cout << 0 << endl; return 0;
	}
	else if (N < (X + Y) / D) {
		cout << 0 << endl; return 0;
	}
	// ok

	double ans = 0;
	X /= D, Y /= D;
	FOR(tox, 0, N + 1) {
		int toy = N - tox;
		auto f = [&](int a, int b) {
			// 0 to a by bsteps
			int c = (b - a) / 2;
			if (b < a || b != a + 2 * c)return 0.0;
			return nCr(b, c);
		};
		ans += f(X, tox)*f(Y, toy)*nCr(N, tox);
	}

	cout << fixed << setprecision(10) << ans << endl;

	return 0;
}
