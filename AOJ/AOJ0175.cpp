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

/* -----  2019/07/24  Problem: AOJ 0175 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0175  ----- */

string to_any_base_String(int base, unsigned int val) //base進数表示
{
	const int size = 30;
	int index = size - 1;
	string str(size, '0');
	string ret = "";
	while (val != 0) {
		str[index] = '0' + val % base;
		ret += string(1, '0' + val % base);
		val /= base;
		index--;
	}
	reverse(ALL(ret));
	return ret;
	return str;
}

int main() {
	int N;
	while (cin >> N, N != -1) {
		string ans = (N > 0 ? to_any_base_String(4, N) : "0");
		cout << (ans) << "\n";
	}

	return 0;
}
