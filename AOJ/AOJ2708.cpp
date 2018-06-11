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

/* -----  2018/06/10  Problem: AOJ 2708 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2708  ----- */
/* ------問題------

文字列 ABC で表される遺伝子配列がある。あなたは次の操作を何回か行い、この遺伝子配列を書き換えていくことができる。
文字 A，B，C のうち 1 つを選ぶ。これを x とおく。遺伝子配列に含まれるすべての x をそれぞれ ABC へ同時に置き換える。
A，B，C だけからなる文字列 S が与えられる。遺伝子配列を S に一致させられるか判定せよ。

-----問題ここまで----- */
/* -----解説等-----

これ苦手じゃん
逆をするときは反例がないか注意

----解説ここまで---- */

int ans = 0;
string replace(string S, string from, string to) {
	auto pos = S.find(from);
	while (pos != string::npos) {
		S.replace(pos, from.size(), to);
		pos = S.find(from, pos + to.size());
	}
	return S;
}
// 前やった気がする
// 前も同じミスをした気がする
void f(string s) {
	if (s == "ABC")ans = 1;

	string toS = replace(s, "ABC", "#");
	string ABC = "ABC";
	FOR(i, 0, 3)
		if (!count(toS.begin(), toS.end(), ABC[i])) {
			string toABC = replace(s, "ABC", string(1, ABC[i]));
			if (s != toABC)f(toABC);
		}
}

void solve() {
	string s;
	cin >> s;
	// ABCへ還元する
	f(s);

	cout << (ans ? "Yes" : "No") << endl;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	solve();

	return 0;
}