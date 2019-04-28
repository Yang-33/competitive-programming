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

/* -----  2019/04/13  Problem: ABC 124 D / Link: http://abc124.contest.atcoder.jp/tasks/abc124_d  ----- */

struct Cumusum {
	vector<LL>csum;
	Cumusum(vector<LL>&a) {
		csum.assign((int)a.size() + 1, 0);
		for (int i = 0; i < (int)a.size(); i++) {
			csum[i + 1] = csum[i] + a[i];
		}
	}
	Cumusum(vector<int>&a) {
		csum.assign((int)a.size() + 1, 0);
		for (int i = 0; i < (int)a.size(); i++) {
			csum[i + 1] = csum[i] + a[i];
		}
	}
	LL query(int l, int r) {
		if (r >= SZ(csum))r = SZ(csum) - 1;

		return csum[r] - csum[l];
	}
};


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, K; cin >> N >> K;
	string s; cin >> s;

	// to block
	char pre = s.front();
	VI ele; ele.push_back(0); ele.push_back(0);
	VI is_a; is_a.push_back(0); is_a.push_back(pre == '0');
	FOR(i, 0, N) {
		if (pre == s[i]) {
			ele.back()++;
		}
		else {
			ele.push_back(1);
			is_a.push_back(s[i] == '0');
			pre = s[i];
		}
	}
	ele.push_back(0);
	is_a.push_back(0);
	N = SZ(ele);
	Cumusum elesum(ele);
	DD(De(ele));
	DD(De(is_a));
	LL ans = 0LL;
	FOR(i, 0, N) {
		if (is_a[i] == 0)
			ans = max(ans, elesum.query(i, i + 2 * K + 1));
	}



	cout << (ans) << "\n";

	return 0;
}
