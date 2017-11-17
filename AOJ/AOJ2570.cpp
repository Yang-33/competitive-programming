#include "bits/stdc++.h"
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

/* -----  2017/11/15  Problem: AOJ 2570 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2570  ----- */
/* ------問題------

expr   ::= term | expr sp ">>" sp term
term   ::= number | "S" sp "<" sp expr sp ">"
sp     ::= "" | sp " "
number ::= digit | number digit
digit  ::= "0" | "1" | "2" | "3" | "4" | "5" | "6" | "7" | "8" | "9"

計算せよ。

-----問題ここまで----- */
/* -----解説等-----

>>>があったときとかにバックトラックすると指数時間になってしまうが、
シフトは必ず数字かSの手前に来ることを考えると後ろから見たときに区別できることが分かる。
これによってめっちゃ簡単な構文解析になる。
嬉しい。
知見としてSHIFT演算は1000シフトとかをしたときに周期で値が返ってくることがあるらしく、64bit以上やるのはまずそう。

----解説ここまで---- */

LL N;

LL ans = 0LL;
LL expr0(int &i, string &s);

LL getnum(int &i, string &s) {
	LL res = 0;
	while (isdigit(s[i])) {
		res *= 10LL;
		res += s[i] - '0';
		i++;
	}
	return res;
}
LL term(int &i, string &s) {
	LL num;
	if (s[i] == 'S') {
		i += 2;// S<
		num = expr0(i, s) % MOD;
		num = (num*num) % MOD;
		i++;// > 
	}
	else num = getnum(i, s);
	return num;
}
// PP, S<expr>
LL expr0(int &i, string &s) {
	LL ret = term(i, s);
	int id = i;
	while (id < SZ(s)) {
		if (s[i] == 'P'&&s[i + 1] == 'P') {
			i += 2;
			ret >>= (min(50LL, term(i, s)));
		}
		else break;
	}
	return ret;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string s;
	while (getline(cin, s)) {
		if (s[0] == '#')break;
		string t;
		FOR(i, 0, SZ(s)) {
			if (s[i] != ' ') {
				t += s[i];
			}
		}// tでやるぞ
		FORR(i, SZ(t) - 3, -1) {
			if (t[i] == '>'&&t[i + 1] == '>' && (t[i + 2] == 'S' || isdigit(t[i + 2]))) {
				t[i] = 'P'; t[i + 1] = 'P';
				int id = i - 1;
				while (0 <= id) {
					if (t[id] == '<')id--;
					else break;
				}
				i = id + 1;
			}
		}
		//cout <<"!!! "<< t << endl;
		int id = 0;
		cout << expr0(id, t) << endl;
	}

	return 0;
}
