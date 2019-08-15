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

/* -----  2019/08/14  Problem: AOJ 0220 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0220  ----- */

string to_any_base_String(int base, unsigned int val, int size) //base進数表示
{
	int index = size - 1;
	string str(size, '0');
	while (val != 0) {
		str[index] = '0' + val % base;
		val /= base;
		index--;
	}
	return str;
}
int main() {

	double x;
	while (cin >> x, x >= 0) {
		int n = (int)x;
		int d = (x - n) * 16;
		bool ok = 1; {
			ok &= n < 256;
			ok &= d < 16;
			ok &= ((x - n) * 16 == d);
		}
		if (ok) {
			cout << to_any_base_String(2, n, 8) << ".";
			cout << to_any_base_String(2, d, 4) << "\n";
		}
		else puts("NA");
	}

	return 0;
}
