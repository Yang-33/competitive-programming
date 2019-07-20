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

/* -----  2019/07/20  Problem: AOJ 0114 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0114  ----- */

long long  gcd(long long  a, long long  b) { return b ? gcd(b, a%b) : a; }
long long  lcm(long long  a, long long  b) { return a / gcd(a, b) * b; }

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
	int N = 3;
	VL a(N), m(N);
	string in;
	while (getline(cin, in)) {
		auto input = deletecommma(in);
		FOR(i, 0, N) {
			input >> a[i] >> m[i];
		}
		if (a.front() == 0)break;
		VL b(N);
		FOR(i, 0, N) {
			LL x = 1;
			LL cnt = 0;
			while (1) {
				cnt++;
				LL nx = (a[i] * x) % m[i];
				if (nx == 1) {
					b[i] = cnt;
					break;
				}
				x = nx;
			}
		}

		LL ans = lcm(b[0], lcm(b[1], b[2]));
		cout << (ans) << "\n";
	}


	return 0;
}
