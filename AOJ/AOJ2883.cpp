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

/* -----  2018/07/07  Problem: AOJ 2883 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/2883  ----- */
/* ------問題------

あなたのパスワード P をハッシュ関数 S に入力した結果を出力せよ．また，ハッシュ値からパスワードを一意に特定可能なハッシュ関数の使用を防ぐため，あなたのパスワードと同じハッシュ値になるパスワードの数も出力せよ．

-----問題ここまで----- */
/* -----解説等-----

構文解析+全探索

----解説ここまで---- */


LL hh(int &i, string &s, map<char, int> &Map) {
	if (s[i] >= 'a' && s[i] <= 'd') {
		LL ret = Map[s[i]];
		i++;
		return ret;
	}
	else {
		i++; // [
		char op = s[i];
		i++;
		LL hash1 = hh(i, s, Map);
		LL hash2 = hh(i, s, Map);
		i++; // ]
		if (op == '^') {
			return hash1 ^ hash2;
		}
		else if (op == '+') {
			return hash1 | hash2;
		}
		else if (op == '*') {
			return hash1 & hash2;
		}
		else {
			debug(i);
			debug(s[i]);
			debug(s);
			assert(0);
		}
	}
}

LL F(string & s, string &num) {
	map<char, int>CtoI;
	FOR(i, 0, 4) {
		CtoI['a' + i] = num[i] - '0';
	}
	int i = 0;

	return hh(i, s, CtoI);
}


int solve() {
	string s; string num;
	while (cin >> s, s != ".") {
		cin >> num;
		LL val = F(s, num);
		map<LL, int>Mapval;
		FOR(i, 0, 10000) {

			string tmp = to_string(i);
			tmp = string(4 - SZ(tmp), '0') + tmp;
			LL ret = F(s, tmp);
			Mapval[ret]++;
		}
		cout << val << " " << Mapval[val] << endl;
	}
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	solve();
	return 0;
}