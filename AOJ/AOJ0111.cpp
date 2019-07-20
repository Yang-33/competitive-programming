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

/* -----  2019/07/20  Problem: AOJ 0111 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0111  ----- */

int main() {
	string e = "ABCDEFGHIJKLMNOPQRSTUVWXYZ .,-'?";
	vector<string> s1 = {
		"100101", "10011010", "0101", "0001", "110",
		"01001", "10011011", "010000", "0111", "10011000",
		"0110", "00100", "10011001", "10011110", "00101",
		"111", "10011111", "1000", "00110", "00111",
		"10011100", "10011101", "000010", "10010010", "10010011",
		"10010000", "101", "010001", "000011", "10010001",
		"000000", "000001"
	};
	vector<string> s2 = {
		"00000", "00001", "00010", "00011", "00100", "00101", "00110", "00111", "01000", "01001",
		"01010", "01011", "01100", "01101", "01110", "01111", "10000", "10001", "10010", "10011",
		"10100", "10101", "10110", "10111", "11000", "11001", "11010", "11011", "11100", "11101",
		"11110", "11111"
	};



	string s;
	while (s = "", getline(cin, s)) {
		string t;
		for (int i = 0; i < s.size(); i++) {
			for (int j = 0; j < e.size(); j++) {
				if (s[i] == e[j]) t += s2[j];
			}
		}
		string ret = "";
		for (int i = 0; i < t.size();) {
			bool flag = false;
			for (int j = 0; j < e.size(); j++) {
				if (t.substr(i, s1[j].size()) == s1[j]) {
					ret += e[j]; i += s1[j].size(); flag = true;
					break;
				}
			}
			if (!flag) break;
		}
		cout << ret << endl;
	}
	return 0;
}