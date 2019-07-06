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

/* -----  2019/07/07  Problem: AOJ 2547 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/2547  ----- */

template<typename T1, typename T2> inline void chmax(T1 &a, T2 b) { if (a < b) a = b; }

template<typename T>
T largestrectangle(vector<T> &v) {
	int n = v.size();
	T res = 0;
	using P = pair<int, T>;
	stack<P> sp;
	sp.emplace(-1, T(0));
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int j = i;
		while (sp.top().second > v[i]) {
			j = sp.top().first;
			chmax(res, (i - j)*sp.top().second);
			cnt++;
			sp.pop();
		}
		if (sp.top().second < v[i]) sp.emplace(j, v[i]);
	}
	while (!sp.empty()) {
		chmax(res, (n - sp.top().first)*sp.top().second);
		if (sp.top().first != -1)cnt++;
		sp.pop();
	}
	return cnt;
	//return res;
}

inline int readint() { int in; scanf("%d", &in); return in; }
int main() {

	int N = readint();
	vector<int> a(N);
	for (int i = 0; i < N; ++i) {
		a[i] = readint();
	}
	int ans = largestrectangle(a);
	printf("%d\n", ans);

	return 0;
}
