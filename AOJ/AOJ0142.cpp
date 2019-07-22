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

/* -----  2019/07/21  Problem: AOJ 0142 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0142  ----- */



int main() {
	int N;
	while (cin >> N, N) {
		set<int>aset;
		for (int i = 1; i < N; ++i) {
			int k = (i*i) % N;
			aset.emplace(k);
		}
		vector<int>nums(N);
		for (auto it = aset.begin(); it != aset.end(); ++it) {
			for (auto jt = next(it); jt != aset.end(); ++jt) {
				int sa = *it - *jt;
				if (sa < 0)sa += N;
				if (sa > (N - 1) / 2)sa = N - sa;
				nums[sa]++;
			}
		}
		for (int i = 1; i <= (N - 1) / 2; ++i) {
			cout << nums[i] * 2 << endl;
		}
	}
}
