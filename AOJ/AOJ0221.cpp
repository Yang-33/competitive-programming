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

/* -----  2019/08/14  Problem: AOJ 0221 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0221  ----- */


int main() {
	int M, N;
	while (cin >> M >> N, M) {
		bool v[1000] = {};
		int cur = 0, rest = M;

		for (int i = 1; i <= N; i++) {
			string x;
			cin >> x;

			if (rest > 1) {
				string ans;
				if (i % 15 == 0) ans = "FizzBuzz";
				else if (i % 3 == 0) ans = "Fizz";
				else if (i % 5 == 0) ans = "Buzz";
				else ans = to_string(i);

				if (x != ans) {
					v[cur] = true;
					--rest;
					while (v[cur]) cur = (cur + 1) % M;
				}
				else {
					cur = (cur + 1) % M;
					while (v[cur]) cur = (cur + 1) % M;
				}
			}
		}
		bool f = false;
		for (int i = 0; i < M; i++) {
			if (!v[i]) {
				if (f) cout << " ";
				cout << i + 1,f=1;
			}
		}
		cout << "\n";
	}
	return 0;
}
