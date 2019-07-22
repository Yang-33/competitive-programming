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

/* -----  2019/07/21  Problem: AOJ 0135 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0135  ----- */

stringstream deletecommma(string line) {
	istringstream ss(line);
	string s;
	stringstream input;
	while (getline(ss, s, ':')) {
		input << s; input << " ";
	}
	return input;
}
int main() {
	LL N; cin >> N;
	FOR(_, 0, N) {
		string in; cin >> in;
		auto input = deletecommma(in);
		int H, M; input >> H >> M;
		double hdeg = H * 30 + M * 0.5;
		double mdeg = M * 6.0;
		double mn = abs(hdeg - mdeg);
		if (hdeg < mdeg)hdeg += 360;
		else mdeg += 360;
		mn = min(mn, abs(hdeg - mdeg));

		if (mn < 30) cout << "alert" << "\n";
		else if (mn >= 90) cout << "safe" << "\n";
		else cout << "warning" << "\n";
	}

	return 0;
}
