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

/* -----  2018/07/31  Problem: yukicoder 193  / Link: http://yukicoder.me/problems/no/193  ----- */
/* ------問題------

筒の側面に数式が前と後ろが繋がるように書かれている。
筒を好きな文字と文字の間一箇所で切り開き、数式を作る。
この時、数式の最初や最後が演算子になってはいけない。
leading zero(012,003など0が先頭にくる数の表し方)は認める。
切り開いた時の数式の答えの最大値を求めよ。
1+-1のような、演算子が並ぶ表記は与えられない。

-----問題ここまで----- */
/* -----解説等-----

validな式かを確認しながら、全探索する。

----解説ここまで---- */

int flag;
int getnum(const string&s, int &i) {
	int cnt = 0;
	int ret = 0;
	while (isdigit(s[i])) {
		ret *= 10;
		ret += s[i] - '0';
		i++;
		cnt++;
	}
	if (!cnt)flag = 0;
	return ret;
}
int expr(const string& s, int &i) {
	int val = getnum(s, i);

	while (s[i]=='+'||s[i]=='-'){
		int c = s[i];
		if (i + 1 == SZ(s)) {
			flag = 0;
			return val;
		}
		if (c == '+')val += getnum(s, ++i);
		else val -= getnum(s, ++i);
	}
	return val;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string s; cin >> s;
	s += s;
	int ans = -INF;
	FOR(i, 0, SZ(s)/2) {
		// check valid
		flag = 1;
		string t = s.substr(i, SZ(s) / 2);
		int ii = 0;
		int ret = expr(t,ii);
		if (flag) {
			ans = max(ans, ret);
		}
	}
	cout << ans << "\n";

	return 0;
}
