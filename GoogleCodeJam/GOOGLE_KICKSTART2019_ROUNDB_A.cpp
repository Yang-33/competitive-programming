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

/* -----  2019/04/21  Problem: google_kickstart2019_roundb A / Link: https://codingcompetitions.withgoogle.com/kickstart/round/0000000000050eda/0000000000119866  ----- */

// Palindromes

struct Cumusum {
	vector<LL>csum;
	Cumusum(vector<LL>&a) {
		csum.assign((int)a.size() + 1, 0);
		for (int i = 0; i < (int)a.size(); i++) {
			csum[i + 1] = csum[i] + a[i];
		}
	}
	LL query(int l, int r) {
		return csum[r] - csum[l];
	}
};


void solve(int testcasenum) {
		int N, Q; cin >> N >> Q;
	string s; cin >> s;
	VVL cntalpha(26, VL(N, 0));
	FOR(i, 0, N) {
		cntalpha[s[i] - 'A'][i]++;
	}
	DD(de(N, Q, s))
		vector<Cumusum>sums;
	FOR(i, 0, 26) {
		sums.push_back(Cumusum(cntalpha[i]));
	}

	LL ans = 0;
		FOR(_, 0, Q) {
		int L, R; cin >> L >> R;
		L--;
		int altype_cnt = 0;
		int parity = 0;
		FOR(i, 0, 26) {
			int cnt = sums[i].query(L, R);
			if (cnt) {
				altype_cnt++;
				if (cnt % 2) {
					parity |=  1<<(i);
				}
			}
		}
		if (altype_cnt) {
			{
				ans += (__builtin_popcount(parity) <= 1);
			}
		}
	}

	cout << "Case #" << testcasenum << ": " << ans << endl;
}

int main() {

	LL T; cin >> T;
	FOR(_, 0, T) {
		solve(_ + 1);
	}

	return 0;
}
