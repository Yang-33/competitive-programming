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

/* -----  2018/12/15  Problem: EDU056 C / Link: __CONTEST_URL__  ----- */
/* ------問題------

b[i]が与えられる。
今倍の長さのa[i]をつくる。
b[i] = a[i]+a[N-i+1](1index)とする。
aが単調増加になるように作ることが保証されているので、その一例を示せ。

-----問題ここまで----- */
/* -----解説等-----

右から構築する。なるべく右に大きな値があれば良い。
つじつま合わせは伝搬する。
左においた値は左側から単調増加なので、右から削るように値を保存しておく。

----解説ここまで---- */

void solve(LL N,VL &b) {
	VL a(N);
	FOR(i, 0, N / 2) {
		a[N - 1 - i] = b[i];
	}
	DD(De(a, b));

	LL dsum = 0;
	FORR(i, N - 1, N / 2) {
		a[i - 1] -= dsum;
		a[N - 1 - (i - 1)] += dsum;
		if (a[i - 1] > a[i]) {
			LL diff = a[i - 1] - a[i];
			a[i - 1] -= diff;
			a[N - 1 - (i - 1)] += diff;
			dsum += diff;
		}
	}


	FOR(i, 0, N) {
		cout << a[i] << " \n"[i == N - 1];
	}
}
#include <time.h>
/*seed!*/
inline void InitRand() { srand((unsigned int)time(NULL)); }

/* 適当なlong long の乱数 */
long long myrand() {
	return abs(rand() * rand() + 2311 * rand() + 1992);
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N; cin >> N;
	VL b(N / 2);
	FOR(i, 0, N / 2) {
		cin >> b[i];
	}

	//int N = 8;
	//InitRand();
	//VL a(N), b(N);
	//FOR(i, 0, N) {
	//	a[i] = myrand() % N;
	//}
	//SORT(a);
	//FOR(i, 0, N/2) {
	//	b[i] = a[i] + a[N - i - 1];
	//}
//	DD(De(a,b));
	solve(N, b);

	return 0;
}
