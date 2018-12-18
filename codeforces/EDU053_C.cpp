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

/* -----  2018/10/25  Problem: EDU053 C / Link: __CONTEST_URL__  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

連続性

----解説ここまで---- */

int N;
char S[200011];
int TX, TY;

int X[200011], Y[200011];

bool ok(int i, int r) {
	int x = X[i] + X[N] - X[r];
	int y = Y[i] + Y[N] - Y[r];
	return abs(TX - x) + abs(TY - y) <= r - i;
}
int main() {


	scanf("%d", &N);
	scanf("%s", S);
	scanf("%d%d", &TX, &TY);

	if (N < abs(TX) + abs(TY) || N % 2 != (abs(TX) + abs(TY)) % 2) {
		puts("-1");
		return 0 ;
	}

	FOR(i, 0, N) {
		X[i + 1] = X[i];
		Y[i + 1] = Y[i];
		if (S[i] == 'U') Y[i + 1]++;
		if (S[i] == 'D') Y[i + 1]--;
		if (S[i] == 'R') X[i + 1]++;
		if (S[i] == 'L') X[i + 1]--;
	}

	int ans = N + 1;
	int r = 0;
	FOR(i, 0, N + 1) {
		r = max(r, i);
		while (r < N && !ok(i, r)) r++;
		if (ok(i, r)) ans = min(ans, r - i);
	}
	if (ans == N + 1) ans = -1;
	printf("%d\n", ans);
	return 0;
}
