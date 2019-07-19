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

/* -----  2019/07/19  Problem: AOJ 0074 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0074  ----- */


stringstream deletecommma(string line) {
	istringstream ss(line);
	string s;
	stringstream input;
	while (getline(ss, s, ',')) {
		input << s; input << " ";
	}
	return input;
}

int main() {
	int H, M, S;
	while (cin >> H >> M >> S) {
		if (H == -1)break;
		int Time = 120 * 60 - H * 60 * 60 - M * 60 - S;
		FOR(i, 0, 2) {
			int leftH = Time / 3600;
			int leftM = (Time - leftH * 3600) / 60;
			int leftS = Time % 60;
			printf("%02d:%02d:%02d\n", leftH, leftM, leftS);
			Time *= 3;
		}
	}

	return 0;
}