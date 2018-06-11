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
#define debug(x) cerr << #x << ": " << x << endl
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/06/11  Problem: AOJ 1155 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1155  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

構文解析

----解説ここまで---- */

void change(string&s, int a, int b, int c) {
	FOR(i, 0, SZ(s)) {
		if (s[i] == 'P') {
			s[i] = a + '0';
		}
		if (s[i] == 'Q') {
			s[i] = b + '0';
		}
		if (s[i] == 'R') {
			s[i] = c + '0';
		}
	}
}
string expr1(string&, int&);
string expr2(string&, int&);

// (だったらFを再度評価
// -だったらFを再度評価
// numだったらおちまい
// ()内でしか*,+をやらない

string expr2(string &s, int &i) { // とるとこ,(だったらexpr1へ
	if (isdigit(s[i])) {
		string num = string(1, s[i]);
		i++;
		return num;
	}
	if (s[i] == '-') {
		i++;
		string num = expr2(s, i);
		if ("2" == num)return "0";
		if ("0" == num)return "2";
		assert(num == "1");
		return num;
	}
	if (s[i] == '(') {
		i++;
		string num = expr1(s, i);
		// とってきたので、今見てるのは)
		assert(s[i] == ')');
		i++;
		return num;
	}
	// -

	return "";
}


string expr1(string &s, int &i) {
	string A = expr2(s, i);
	string B = "";
	// いっことった
	int mode = 0;
	while (i < SZ(s) && (s[i] == '+' || s[i] == '*')) {
		char op = s[i];
		i++;
		if (op == '+') {
			B = expr1(s, i);
			mode = 1;
		}
		else if (op == '*') {
			B = expr1(s, i);
			mode = 2;
		}
	}
	string OP = " +*";

	//cout << "A:" << A << ", "<<OP[mode] <<" B:" << B << endl;
	if (mode == 1) {
		if (A == "2" || B == "2")return "2";
		if (A == "1" || B == "1")return "1";
		return "0";
	}
	else if (mode == 2) {
		if (A == "0" || B == "0")return "0";
		if (A == "1" || B == "1")return "1";
		return "2";
	}

	return A;
}


void solve() {
	string s;
	while (cin >> s, s != ".") {
		// p,q,r:0,1,2
		int ans = 0;
		FOR(a, 0, 2 + 1) {
			FOR(b, 0, 2 + 1) {
				FOR(c, 0, 2 + 1) {
					string t = s;
					change(t, a, b, c);
					int i = 0;
					string res = expr1(t, i);
					//ut << "res:" << res << endl;
					if ("2" == res) {
						ans++;
					}
				}
			}
		}
		cout << ans << endl;
	}
}
// aa/a/a/a/a/

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	solve();
	return 0;
}
