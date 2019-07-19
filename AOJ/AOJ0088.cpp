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

/* -----  2019/07/19  Problem: AOJ 0088 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0088  ----- */


int main(){
	map<char, string>A;
	map<string, char>B;

	A[' '] = "101";
	A['\''] = "000000";
	A[','] = "000011";
	A['-'] = "10010001";
	A['.'] = "010001";
	A['?'] = "000001";
	A['A'] = "100101";
	A['B'] = "10011010";
	A['C'] = "0101";
	A['D'] = "0001";
	A['E'] = "110";
	A['F'] = "01001";
	A['G'] = "10011011";
	A['H'] = "010000";
	A['I'] = "0111";
	A['J'] = "10011000";
	A['K'] = "0110";
	A['L'] = "00100";
	A['M'] = "10011001";
	A['N'] = "10011110";
	A['O'] = "00101";
	A['P'] = "111";
	A['Q'] = "10011111";
	A['R'] = "1000";
	A['S'] = "00110";
	A['T'] = "00111";
	A['U'] = "10011100";
	A['V'] = "10011101";
	A['W'] = "000010";
	A['X'] = "10010010";
	A['Y'] = "10010011";
	A['Z'] = "10010000";
	B["00000"] = 'A';
	B["00001"] = 'B';
	B["00010"] = 'C';
	B["00011"] = 'D';
	B["00100"] = 'E';
	B["00101"] = 'F';
	B["00110"] = 'G';
	B["00111"] = 'H';
	B["01000"] = 'I';
	B["01001"] = 'J';
	B["01010"] = 'K';
	B["01011"] = 'L';
	B["01100"] = 'M';
	B["01101"] = 'N';
	B["01110"] = 'O';
	B["01111"] = 'P';
	B["10000"] = 'Q';
	B["10001"] = 'R';
	B["10010"] = 'S';
	B["10011"] = 'T';
	B["10100"] = 'U';
	B["10101"] = 'V';
	B["10110"] = 'W';
	B["10111"] = 'X';
	B["11000"] = 'Y';
	B["11001"] = 'Z';
	B["11010"] = ' ';
	B["11011"] = '.';
	B["11100"] = ',';
	B["11101"] = '-';
	B["11110"] = '\'';
	B["11111"] = '?';
	string s;

	while (getline(cin, s)) {
		string t = "";
		for (int i = 0; i < s.size(); i++)t += A[s[i]];
		if (t.size() % 5)t += string(5 - t.size() % 5, '0');
		for (int i = 0; i < t.size(); i += 5)cout << B[t.substr(i, 5)];
		cout << endl;
	}
}