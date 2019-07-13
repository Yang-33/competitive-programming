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

/* -----  2019/07/13  Problem: AOJ 0038 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0038  ----- */

stringstream deletecommma(string line) {
	istringstream ss(line);
	string s;
	stringstream input;
	while (getline(ss, s, ',')) {
		input << s; input << " ";
	}
	return input;
}

string fivepoker(const VI& cards) { // [1,13] 
	// no joker
	int N = 14;
	VI cnt(14); {
		for (auto it : cards) {
			cnt[it]++;
		}
	}
	int two = 0, three = 0, four = 0;
	bool straight = 0; {
		int c = 0;
		FOR(i, 1, N) {
			two += cnt[i] == 2;
			three += cnt[i] == 3;
			four += cnt[i] == 4;
			if (cnt[i]) {
				c++;
				straight |= c == 5;
			}
			else {
				c = 0;
			}
		}
		if (c == 4 && cnt[1])straight = 1;
	}
	if (four)return "four card";
	if (three&&two)return "full house";
	if (straight)return "straight";
	if (three)return "three card";
	if (two == 2)return "two pair";
	if (two)return "one pair";
	return "null";
}

int main() {
	string in;
	while (getline(cin, in)) {
		auto input = deletecommma(in);
		int N = 5;
		vector<int> a(N);
		for (int i = 0; i < N; ++i) {
			input >> a[i];
		}
		cout << fivepoker(a) << "\n";
	}


	return 0;
}
