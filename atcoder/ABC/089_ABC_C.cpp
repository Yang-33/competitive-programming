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

/* -----  2019/03/11  Problem: ABC 089 C / Link: http://abc089.contest.atcoder.jp/tasks/abc089_c  ----- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N; 
	cin >> N;
	vector<string> a(N);
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
	}
	string ss = "MARCH";
	map<char, int>M;
	FOR(i, 0, 5) {
		M[ss[i]] = i;
	}
	VL cnt(5);
	FOR(i, 0, N) {
		if (M.find(a[i].front()) != M.end()) {
			cnt[M[a[i].front()]]++;
		}
	}

	LL ans = 0LL;
	FOR(i, 0, 5)FOR(j, 0, i)FOR(k, 0, j) {
		ans += cnt[i] * cnt[j] * cnt[k];
	}
	
	cout << (ans) << "\n";

	return 0;
}
