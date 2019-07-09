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

/* -----  2018/11/22  Problem: AGC 020 C / Link: http://agc020.contest.atcoder.jp/tasks/agc020_c  ----- */
/* ------問題------

N 個の整数 A1, A2, ..., AN が与えられます。
A のすべての空でない部分列について、それぞれの和を考えます。このような和は 2N−1 個存在し、この個数は奇数です。
これらの和を昇順に並べたものを S1, S2, ..., S2N−1 とします。
これらの中央値、S2N−1 を求めてください。

-----問題ここまで----- */
/* -----解説等-----

bool dpをbitsetで1/32時間でやるやつ

----解説ここまで---- */

int read() { int in; scanf("%d", &in); return in; }
int main() {
	int N = read();
	VI a(N);
	FOR(i, 0, N) {
		a[i] = read();
	}
	int sum = accumulate(ALL(a), 0);
	const int sz = 2000 * 2000 + 1;
	bitset<sz>bit;
	bit[0] = 1;
	FOR(i, 0, N) {
		bit |= bit << a[i];
	}
	int mid = (sum + 1) / 2;
	FOR(i, mid, sz) {
		if (bit[i]) {
			cout << i << endl;
			return 0;
		}
	}

	return 0;
}
