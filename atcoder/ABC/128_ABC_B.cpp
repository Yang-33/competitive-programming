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

/* -----  2019/05/26  Problem: ABC 128 B / Link: http://abc128.contest.atcoder.jp/tasks/abc128_b  ----- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N;
	cin >> N;
	vector<pair<string, PII>>A;
	FOR(i, 0, N) {
		string s; cin >> s;
		int a; cin >> a;
		A.push_back(pair<string, PII>(s, PII(-a, i)));
	}
	SORT(A);
	VI ans(N);
	FOR(i, 0, N) {
		auto it = A[i];
		ans[it.second.second] = i;
		cout << it.second.second + 1 << endl;
	}
	FOR(i, 0, N) {
	//	cout << ans[i] + 1 << endl;
	}

	return 0;
}
