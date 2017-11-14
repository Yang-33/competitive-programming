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

/* -----  2017/10/20  Problem: uva 00727  / Link:   ----- */
/* ------問題------

通常の？計算式が一文字ずつ分けられて与えられる。
これを逆ポーランド記法で出力せよ。

-----問題ここまで----- */
/* -----解説等-----

特になしだが、もうこれだけでもつらい
LL(1)なので、、とか言いたいので勉強します

----解説ここまで---- */

LL N;

LL ans = 0LL;

void solve(string &s) {
	stack<char>st;
	FOR(i, 0, SZ(s)) {
		if (s[i] == '(')st.push(s[i]);
		else if (isdigit(s[i]))cout << s[i];
		else if (s[i] == ')') {
			while (st.top() != '(') {
				cout << st.top(); st.pop();
			}
			st.pop();
		}
		else if (s[i] == '*' || s[i] == '/') {
			while (!st.empty() && (st.top() == '*' || st.top() == '/')) {
				cout << st.top(); st.pop();
			}
			st.push(s[i]);
		}
		else if (s[i] == '+' || s[i] == '-') {
			while (!st.empty() && !isdigit(st.top())&&st.top()!='(') {
				cout << st.top(); st.pop();
			}
			st.push(s[i]);
		}
	}
	while (!st.empty()) {
		cout << st.top(); st.pop();
	}
	cout << endl;

}
int main() {
	string line;

	getline(cin, line);
	N = atoi(line.c_str());
	getline(cin, line);
	FOR(_i, 0, N) {
		string s;
		while (getline(cin, line)) {
			if (line.empty())break;
			s += line[0];
		}

		if (_i)cout << endl;
		solve(s);

	}
	return 0;
}