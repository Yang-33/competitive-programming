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

/* -----  2019/04/06  Problem: GCJ2019_qual A / Link: __CONTEST_URL__  ----- */
string minusone(string s) {
	for (int i = (int)s.size() - 1; i >= 0; --i) {
		if (s[i] == '0') { s[i] = '9'; }
		else { s[i]--; break; }
	}
	if (s[0] == '0')s = s.substr(1);
	return s;
}
string remove_leadingzero(string s) {
	string t;
	bool lz = 1;
	for (auto c : s) {
		if (lz&&c == '0')continue;
		t += string(1, c);
		lz = 0;
	}
	return t;
}
void solve(int testcaseid) {


	string N; cin >> N;
	string a = string(SZ(N), '0');
	a.back() = '1';
	// dec 1
	N = minusone(N);
	for (int i = SZ(N) - 1; i >= 0; i--) {
		if (N[i] == '4') {
			N[i] = '3';
			a[i]++;
		}

	}


	cout << "Case #" << testcaseid << ": " << remove_leadingzero(a) << " " << N << endl;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int T; cin >> T;
	FOR(_, 0, T) {
		solve(_ + 1);
	}

	return 0;
}
