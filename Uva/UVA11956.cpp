#include "bits/stdc++.h"
#include <iomanip>
using namespace std;

using VS = vector<string>;    using LL = long long;
using VI = vector<int>;       using VVI = vector<VI>;
using PII = pair<int, int>;   using PLL = pair<LL, LL>;
using VL = vector<LL>;        using VVL = vector<VL>;

#define ALL(a)  begin((a)),end((a))
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define SZ(a) int((a).size())
#define SORT(c) sort(ALL((c)))
#define RSORT(c) sort(RALL((c)))
#define UNIQ(c) (c).erase(unique(ALL((c))), end((c)))
#define FOR(i, s, e) for (int(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (int(i) = (s); (i) > (e); (i)--)
#define debug(x) cerr << #x << ": " << x << endl
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2017/10/18  Problem: uva11956  / Link: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=229&page=show_problem&problem=3107  ----- */
/* ------問題------

brainfuck

-----問題ここまで----- */
/* -----解説等-----

c++でいろいろ形式を変えて出力するのつらい…勉強になった！

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {

	cin >> N;
	cin.ignore();
	FOR(t, 0, N) {
		string s;
		getline(cin, s);
		cout <<dec<< "Case " << t + 1 << ":";
		VI a(100, 0); int pos = 0;
		FOR(i, 0, SZ(s)) {
			if (s[i] == '>') { pos++; }
			else if (s[i] == '<') { pos--; }
			else if (s[i] == '+') { a[pos]++; }
			else if (s[i] == '-') { a[pos]--; }
			if (a[pos] == -1)a[pos] = 255;
			if (a[pos] == 256)a[pos] = 0;
			if (pos == 100)pos = 0;
			if (pos == -1)pos = 99;
		}
		FOR(i, 0, 100) {
			cout <<" "<< hex << setw(2) << setfill('0') <<uppercase<< a[i];
		}cout << endl;
		//FOR(i, 0, 100) {
		//	printf(" %02X", a[i]);
		//}printf("\n");
	}

	return 0;
}
