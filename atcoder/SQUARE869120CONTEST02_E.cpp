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

/* -----  2019/07/02  Problem: square869120Contest02 E / Link: https://atcoder.jp/contests/s8pc-2/tasks/  ----- */



struct SuffixArray {
	vector<int> SA;
	string s;

	void Build_SA(const string& str) {
		s = str;
		SA.resize(s.size());
		iota(begin(SA), end(SA), 0);
		sort(begin(SA), end(SA), [&](const int& a, const int& b)
		{
			if (s[a] == s[b]) return(a > b);
			return (s[a] < s[b]);
		});
		vector<int> classes(s.size()), c(s.size()), cnt(s.size());
		for (int i = 0; i < s.size(); i++) {
			c[i] = s[i];
		}
		for (int len = 1; len < s.size(); len <<= 1) {
			for (int i = 0; i < s.size(); i++) {
				if (i > 0 && c[SA[i - 1]] == c[SA[i]] && SA[i - 1] + len < s.size() && c[SA[i - 1] + len / 2] == c[SA[i] + len / 2]) {
					classes[SA[i]] = classes[SA[i - 1]];
				}
				else {
					classes[SA[i]] = i;
				}
			}
			iota(begin(cnt), end(cnt), 0);
			copy(begin(SA), end(SA), begin(c));
			for (int i = 0; i < s.size(); i++) {
				int s1 = c[i] - len;
				if (s1 >= 0) SA[cnt[classes[s1]]++] = s1;
			}
			classes.swap(c);
		}
	}

	vector<int> res_sa() {
		return std::move(SA);
	}
};

VI make_lcp(const string s, const VI &sa, const VI&rank) {
	VI LCP;
	LCP.resize(s.size());
	LCP[0] = 0;
	for (int i = 0, h = 0; i < s.size(); i++) {
		if (rank[i] + 1 < s.size()) {
			for (int j = sa[rank[i] + 1]; max(i, j) + h < s.length() && s[i + h] == s[j + h]; ++h);
			LCP[rank[i] + 1] = h;
			if (h > 0) --h;
		}
	}
	return std::move(LCP);
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string s; cin >> s;
	vector<int>sa; {
		SuffixArray suffixarray;
		suffixarray.Build_SA(s);
		sa = suffixarray.res_sa();
	}
	vector<int>rank = vector<int>((int)s.size());
	for (int i = 0; i < (int)s.size(); ++i) {
		rank[sa[i]] = i;
	}
	vector<int>LCP = make_lcp(s, sa, rank);

	LL ans = 0LL;
	auto f = [](LL n) {return n * (n + 1) / 2; };
	FOR(i, 0, SZ(s)) {
		ans += f(i + 1);
		ans -= f(LCP[i]);	
	}


	cout << (ans) << "\n";

	return 0;
}
