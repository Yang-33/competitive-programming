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

/* -----  2018/07/01  Problem: AOJ 0264 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0264  ----- */
/* ------問題------

0以外のすべての実数の逆数は実数になりますが、整数の逆数が整数になるとは限りません。Ｃ言語などで 3.0/2.0*2.0 = 3.0 なのに 3/2*2 = 2 になってしまうのはこのためです。ですが、素数で割った余りが等しい整数を同じものとみなすと、0以外のすべての整数が逆数をもつようにできます。
整数 x と y を p で割った余りが等しいとき、x ≡ y (mod p) と書きます。p が素数のとき、このような x と y を同じものとみなすなら、すべての整数 n は0から p−1 までのどれかの整数 x に対して x ≡ n (mod p) となるので、けっきょく { 0, 1, 2, ..., p−1 } という集合だけからなる世界を考えればよいことがわかります。
この世界での加減乗除は以下のようになります。
加算 x+y の値は、x+y ≡ z (mod p) となる 0 から p−1 までの数 z になります。
減算 x−yの値は、y+m ≡ 0 (mod p) となる 0 から p−1 までの数 m（これが y に相当します）について、x−y ≡ x + m (mod p) となることから得られます。たとえば、p = 5のとき、4+1 ≡ 0 (mod 5) となります。このとき、2−4 ≡ 2+1 ≡ 3 (mod 5) より、2−4の値は3になります。
乗算 x*y の値は、x*y ≡ z (mod p) となる 0 から p−1 までの数 z になります。
除算 x/y の値は、y*d ≡ 1 (mod p)となる 0 から p−1 までの数 d （これがyの逆数になります）について、x/y ≡ x*d (mod p) となることから得られます。たとえば、p = 5 のとき、2*3 ≡ 1 (mod 5) より 3 は 2 の逆数になります。このとき、1/2 ≡ 1*3 ≡ 3 (mod 5) より、1/2 の値は 3 になります。
このようにして加減乗除の四則演算がすべて0からp−1の範囲に収まります。このとき、集合 { 0,1,...,p−1 } を p の有限体といいます。この有限体の中で、加減乗除、0 から p−1 までの数、カッコを使って 算術式を構成することができます。
p の有限体の 0 以外のすべての要素が逆数をもつことは、フェルマーの小定理と呼ばれる有名な定理 ap−1 ≡ 1 (mod p) からわかります（ただし、p は素数、a と p は互いに素）。p の有限体のすべての要素 x は p と互いに素なので、この定理から x*xp-2 ≡ 1 (mod p) となり xp-2 が x の逆数になるからです。
では、素数と式が与えられたときに、その素数の有限体で式を計算する電卓プログラムを作成してください。

-----問題ここまで----- */
/* -----解説等-----

やるだけ構文解析を感じられるようになってきた。
いつものparseにちょっと割り算を書き加えるだけ。

----解説ここまで---- */


string parse(string& s) {
	string ret = "";
	FOR(i, 0, SZ(s)) {
		if (s[i] != ' ') {
			ret += string(1, s[i]);
		}
	}
	return ret;
}

LL powmod(LL x, LL n, LL mod) {
	LL ret = 1;
	while (n > 0) {
		if (n & 1) {
			ret = (ret*x) % mod;
		}
		x = (x*x) % mod;
		n >>= 1;
	}

	return ret;
}

bool flag;

LL getnum(int& i, const string& s) {
	LL ret = 0;
	while (isdigit(s[i])) {
		ret *= 10;
		ret += s[i] - '0';
		i++;
	}
	return ret;
}
LL expr1(int &i, const string &s, int mod);
LL expr2(int &i, const string &s, int mod);
LL expr3(int &i, const string &s, int mod);

// + - 
LL expr1(int &i, const string &s, int mod) {
	LL ret = expr2(i, s, mod);
	while (s[i] == '+' || s[i] == '-') {
		char op = s[i];
		i++;
		if (op == '+')ret += expr2(i, s, mod);
		if (op == '-')ret -= expr2(i, s, mod);
		ret += mod;
		ret %= mod;
	}
	return ret;
}
// * / 
LL expr2(int &i, const string &s, int mod) {
	LL ret = expr3(i, s, mod);
	while (s[i] == '*' || s[i] == '/') {
		char op = s[i];
		i++;
		if (op == '*')ret *= expr3(i, s, mod);
		if (op == '/') { // powmod
			LL val = expr3(i, s, mod);
			if (val == 0)flag = 1;
			LL divnum = powmod(val, mod - 2, mod);
			if (divnum == 0)flag = 1;
			ret *= divnum;
		}
		ret += mod;
		ret %= mod;
	}
	return ret;

}
// ( num
LL expr3(int &i, const string &s, int mod) {
	if (s[i] == '(') {
		i++;
		LL ret = expr1(i, s, mod);
		i++;
		return ret;
	}
	else {
		return ((getnum(i, s) % mod) + mod) % mod;
	}
}


void solve() {
	string s;
	while (getline(cin, s), s[0] != '0') {
		s = parse(s);
		int i = 0;
		int mod = getnum(i, s);
		string t = s.substr(i + 1);
		i = 0;
		flag = 0;
		LL val = expr1(i, t, mod);
		if (flag) {
			cout << "NG" << endl;
		}
		else {
			cout << t << " = " << val << " (mod " << mod << ")" << endl;
		}
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	solve();

	return 0;
}