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

/* -----  2019/04/13  Problem: GCJ2019_R1A C / Link: __CONTEST_URL__  ----- */

void print_possible(bool ok, int mode = 0) {
	if (mode == 0) {
		cout << ((ok ? "possible\n" : "impossible\n"));
	}
	else if (mode == 1) {
		cout << ((ok ? "Possible\n" : "Impossible\n"));
	}
	else if (mode == 2) {
		cout << ((ok ? "POSSIBLE\n" : "IMPOSSIBLE\n"));
	}
	else {
		assert(0);
	}
}

void minisolve(int H, int W) {
	if (H == 2 && W == 5) {
		cout << 1 << " " << 1 << endl;
		cout << 2 << " " << 3 << endl;
		cout << 1 << " " << 5 << endl;
		cout << 2 << " " << 2 << endl;
		cout << 1 << " " << 4 << endl;
		cout << 2 << " " << 1 << endl;
		cout << 1 << " " << 3 << endl;
		cout << 2 << " " << 5 << endl;
		cout << 1 << " " << 2 << endl;
		cout << 2 << " " << 4 << endl;
	}
	else if (H == 3 && W == 4) {
		cout << 1 << " " << 1 << endl;
		cout << 2 << " " << 3 << endl;
		cout << 3 << " " << 1 << endl;
		cout << 1 << " " << 2 << endl;
		cout << 2 << " " << 4 << endl;
		cout << 3 << " " << 2 << endl;
		cout << 1 << " " << 3 << endl;
		cout << 2 << " " << 1 << endl;
		cout << 3 << " " << 3 << endl;
		cout << 1 << " " << 4 << endl;
		cout << 2 << " " << 2 << endl;
		cout << 3 << " " << 4 << endl;
	}
	else if (H == 3 && W == 5) {
		cout << 1 << " " << 1 << endl;
		cout << 2 << " " << 3 << endl;
		cout << 1 << " " << 5 << endl;
		cout << 2 << " " << 1 << endl;
		cout << 1 << " " << 3 << endl;
		cout << 2 << " " << 5 << endl;
		cout << 3 << " " << 2 << endl;
		cout << 2 << " " << 4 << endl;
		cout << 3 << " " << 1 << endl;
		cout << 1 << " " << 2 << endl;
		cout << 3 << " " << 3 << endl;
		cout << 1 << " " << 4 << endl;
		cout << 3 << " " << 5 << endl;
		cout << 2 << " " << 2 << endl;
		cout << 3 << " " << 4 << endl;
	}
	else if (H == 4 && W == 3) {
		cout << 1 << " " << 1 << endl;
		cout << 2 << " " << 3 << endl;
		cout << 3 << " " << 1 << endl;
		cout << 1 << " " << 2 << endl;
		cout << 4 << " " << 3 << endl;
		cout << 2 << " " << 2 << endl;
		cout << 4 << " " << 1 << endl;
		cout << 3 << " " << 3 << endl;
		cout << 2 << " " << 1 << endl;
		cout << 4 << " " << 2 << endl;
		cout << 1 << " " << 3 << endl;
		cout << 3 << " " << 2 << endl;
	}
	else if (H == 4 && W == 4) {
		cout << 1 << " " << 1 << endl;
		cout << 2 << " " << 3 << endl;
		cout << 3 << " " << 1 << endl;
		cout << 1 << " " << 2 << endl;
		cout << 2 << " " << 4 << endl;
		cout << 3 << " " << 2 << endl;
		cout << 1 << " " << 3 << endl;
		cout << 3 << " " << 4 << endl;
		cout << 4 << " " << 2 << endl;
		cout << 1 << " " << 4 << endl;
		cout << 4 << " " << 3 << endl;
		cout << 2 << " " << 2 << endl;
		cout << 4 << " " << 1 << endl;
		cout << 3 << " " << 3 << endl;
		cout << 2 << " " << 1 << endl;
		cout << 4 << " " << 4 << endl;
	}
	else if (H == 4 && W == 5) {
		cout << 1 << " " << 1 << endl;
		cout << 2 << " " << 3 << endl;
		cout << 1 << " " << 5 << endl;
		cout << 2 << " " << 1 << endl;
		cout << 1 << " " << 3 << endl;
		cout << 2 << " " << 5 << endl;
		cout << 1 << " " << 2 << endl;
		cout << 2 << " " << 4 << endl;
		cout << 3 << " " << 1 << endl;
		cout << 1 << " " << 4 << endl;
		cout << 2 << " " << 2 << endl;
		cout << 4 << " " << 3 << endl;
		cout << 3 << " " << 5 << endl;
		cout << 4 << " " << 2 << endl;
		cout << 3 << " " << 4 << endl;
		cout << 4 << " " << 1 << endl;
		cout << 3 << " " << 3 << endl;
		cout << 4 << " " << 5 << endl;
		cout << 3 << " " << 2 << endl;
		cout << 4 << " " << 4 << endl;
	}
	else if (H == 5 && W == 2) {
		cout << 1 << " " << 1 << endl;
		cout << 3 << " " << 2 << endl;
		cout << 5 << " " << 1 << endl;
		cout << 2 << " " << 2 << endl;
		cout << 4 << " " << 1 << endl;
		cout << 1 << " " << 2 << endl;
		cout << 3 << " " << 1 << endl;
		cout << 5 << " " << 2 << endl;
		cout << 2 << " " << 1 << endl;
		cout << 4 << " " << 2 << endl;
	}
	else if (H == 5 && W == 3) {
		cout << 1 << " " << 1 << endl;
		cout << 2 << " " << 3 << endl;
		cout << 3 << " " << 1 << endl;
		cout << 1 << " " << 2 << endl;
		cout << 3 << " " << 3 << endl;
		cout << 4 << " " << 1 << endl;
		cout << 2 << " " << 2 << endl;
		cout << 4 << " " << 3 << endl;
		cout << 5 << " " << 1 << endl;
		cout << 3 << " " << 2 << endl;
		cout << 5 << " " << 3 << endl;
		cout << 2 << " " << 1 << endl;
		cout << 4 << " " << 2 << endl;
		cout << 1 << " " << 3 << endl;
		cout << 5 << " " << 2 << endl;
	}
	else if (H == 5 && W == 4) {
		cout << 1 << " " << 1 << endl;
		cout << 2 << " " << 3 << endl;
		cout << 3 << " " << 1 << endl;
		cout << 1 << " " << 2 << endl;
		cout << 2 << " " << 4 << endl;
		cout << 3 << " " << 2 << endl;
		cout << 1 << " " << 3 << endl;
		cout << 2 << " " << 1 << endl;
		cout << 1 << " " << 4 << endl;
		cout << 2 << " " << 2 << endl;
		cout << 4 << " " << 1 << endl;
		cout << 5 << " " << 3 << endl;
		cout << 3 << " " << 4 << endl;
		cout << 4 << " " << 2 << endl;
		cout << 5 << " " << 4 << endl;
		cout << 3 << " " << 3 << endl;
		cout << 5 << " " << 2 << endl;
		cout << 4 << " " << 4 << endl;
		cout << 5 << " " << 1 << endl;
		cout << 4 << " " << 3 << endl;
	}
	else if (H == 5 && W == 5) {
		cout << 1 << " " << 1 << endl;
		cout << 2 << " " << 3 << endl;
		cout << 1 << " " << 5 << endl;
		cout << 2 << " " << 1 << endl;
		cout << 1 << " " << 3 << endl;
		cout << 2 << " " << 5 << endl;
		cout << 1 << " " << 2 << endl;
		cout << 2 << " " << 4 << endl;
		cout << 3 << " " << 1 << endl;
		cout << 1 << " " << 4 << endl;
		cout << 2 << " " << 2 << endl;
		cout << 3 << " " << 4 << endl;
		cout << 4 << " " << 1 << endl;
		cout << 3 << " " << 3 << endl;
		cout << 4 << " " << 5 << endl;
		cout << 5 << " " << 1 << endl;
		cout << 4 << " " << 3 << endl;
		cout << 5 << " " << 5 << endl;
		cout << 4 << " " << 2 << endl;
		cout << 5 << " " << 4 << endl;
		cout << 3 << " " << 5 << endl;
		cout << 5 << " " << 2 << endl;
		cout << 4 << " " << 4 << endl;
		cout << 3 << " " << 2 << endl;
		cout << 5 << " " << 3 << endl;
	}
}
bool isok(int H,int W) {
	if (H == 1 && W == 1) {
		return 1;
	}
	else if (H == 2 && W == 5) {
		return 1;
	}
	else if (H == 3 && W == 4) {
		return 1;
	}
	else if (H == 3 && W == 5) {
		return 1;
	}
	else if (H == 4 && W == 3) {
		return 1;
	}
	else if (H == 4 && W == 4) {
		return 1;
	}
	else if (H == 4 && W == 5) {
		return 1;
	}
	else if (H == 5 && W == 2) {
		return 1;
	}
	else if (H == 5 && W == 3) {
		return 1;
	}
	else if (H == 5 && W == 4) {
		return 1;
	}
	else if (H == 5 && W == 5) {
		return 1;
	}
	else {
		return 0;
	}
}
void solve(int testcasenum) {
	int H, W; cin >> H >> W;
	if (H > W)swap(H, W);
	// H < W
	bool ans = isok(H,W);



	cout << "Case #" << testcasenum << ": ";
	print_possible(ans, 2);
	if (ans) {
		minisolve(H, W);
	}
}

int main() {

	int T; cin >> T;
	FOR(i, 0, T) {
		solve(i + 1);
	}

	return 0;
}
