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

/* -----  2019/07/23  Problem: AOJ 0167 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0167  ----- */


int mergecount(vector<int> &a) {
	int count = 0;
	int n = a.size();
	if (n > 1) {
		vector<int> b(a.begin(), a.begin() + n / 2);
		vector<int> c(a.begin() + n / 2, a.end());
		count += mergecount(b);
		count += mergecount(c);
		for (int i = 0, j = 0, k = 0; i < n; ++i)
			if (k == c.size())       a[i] = b[j++];
			else if (j == b.size())  a[i] = c[k++];
			else if (b[j] <= c[k])   a[i] = b[j++];
			else { a[i] = c[k++]; count += n / 2 - j; }
	}
	return count;
}

int main() {
	int N;
	while (cin >> N, N) {
		vector<int> a(N);
		for (int i = 0; i < N; ++i) {
			cin >> a[i];
		}
		cout << mergecount(a) << "\n";
	}


	return 0;
}