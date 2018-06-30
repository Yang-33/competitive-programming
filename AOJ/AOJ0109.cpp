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

/* -----  2018/06/30  Problem: AOJ 0109 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0109  ----- */
/* ------問題------

四則演算の構文解析

-----問題ここまで----- */
/* -----解説等-----

BNFをみて練習
演算の読み込みに注意して、読み込んでi++的なことをする。or 保存

----解説ここまで---- */


LL expr1(int&, string&);
LL expr2(int&, string&);
LL expr3(int&, string&);
LL getnum(int&, string&);

// + - 
LL expr1(int & i, string &s) {
	LL ret = expr2(i, s);
	while (s[i] == '+' || s[i] == '-') {
		if (s[i] == '+')ret += expr2(++i, s);
		if (s[i] == '-')ret -= expr2(++i, s);
	}
	return ret;
}
// * / 
LL expr2(int & i, string &s) {
	LL ret = expr3(i, s);
	while (s[i] == '*' || s[i] == '/') {
		if (s[i] == '*')ret *= expr3(++i, s);
		if (s[i] == '/')ret /= expr3(++i, s);
	}
	return ret;

}
// (re expr) or num
LL expr3(int & i, string &s) {
	if (s[i] == '(') {
		i++;
		LL ret = expr1(i, s);
		i++;// ')'
		return ret;
	}
	else {
		return getnum(i, s);
	}
}
LL getnum(int& i, string &s) {
	LL ret = 0;
	while (isdigit(s[i])){
		ret *= 10; 
		ret += s[i] - '0';
		i++;
	}
	return ret;
}



int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N; cin >> N;
	FOR(shuri, 0, N) {
		string s; cin >> s;
		int i = 0;
		cout << expr1(i, s) << endl;
	}

	return 0;
}
