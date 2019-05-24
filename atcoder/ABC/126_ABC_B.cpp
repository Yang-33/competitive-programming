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

/* -----  2019/05/19  Problem: ABC 126 B / Link: http://abc126.contest.atcoder.jp/tasks/abc126_b  ----- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string s; cin >> s;

	int A = stoi(s.substr(0, 2));
	int B = stoi(s.substr(2));
	DD(de(A, B));
	int st = 0;
	if (0 < B&& B <= 12)st = 1;
	if (0 < A&&A <= 12)st |= 2;
	if (st == 3) {
		cout << "AMBIGUOUS" << endl;
	}
	else if (st == 2) {
		cout << "MMYY" << endl;
	}
	else if (st == 1) {
		cout << "YYMM" << endl;
	}
	else {
		cout << "NA" << endl;
	}

	return 0;
}
