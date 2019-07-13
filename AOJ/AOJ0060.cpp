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

/* -----  2019/07/14  Problem: AOJ 0060 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0060  ----- */

stringstream deletecommma(string line) {
	istringstream ss(line);
	string s;
	stringstream input;
	while (getline(ss, s, ' ')) {
		input << s; input << " ";
	}
	return input;
}
int main() {

	string in;
	while (getline(cin, in)) {
		auto input = deletecommma(in);
		int a, b, c; input >> a >> b >> c;
		int now = a + b, count = 0;

		for (int i = 1; i <= 10; i++) {
			if (i == a || i == b || i == c) continue;
			else {
				if (now + i <= 20) count++;
			}
		}

		if (count >= 4) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
