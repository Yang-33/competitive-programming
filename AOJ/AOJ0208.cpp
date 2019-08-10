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

/* -----  2019/08/04  Problem: AOJ 0208 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0208  ----- */

string to_any_base_String(int base, unsigned int val) //base進数表示
{
	string str;
	while (val != 0) {
		str += string(1, '0' + val % base);
		val /= base;
	}
	reverse(ALL(str));
	return str;
}

// 置換 S の fromをtoに置換 ex:  string U = replace(S, "ABC", "X");
string replace(string S, string from, string to) {
	auto pos = S.find(from);
	while (pos != string::npos) {
		S.replace(pos, from.size(), to);
		pos = S.find(from, pos + to.size());
	}
	return S;
}

int main() {

	LL N;
	while (cin >> N, N) {
		string n8 = to_any_base_String(8, N);
		string ans = replace(n8, "7", "9");
		ans = replace(ans, "6", "8");
		ans = replace(ans, "5", "7");
		ans = replace(ans, "4", "5");
		cout << ans << "\n";
	}

	return 0;
}
