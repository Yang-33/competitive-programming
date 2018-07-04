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

/* -----  2018/07/04  Problem: AOJ 1078 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/1078  ----- */
/* ------問題------

OR SATの構文解析?

-----問題ここまで----- */
/* -----解説等-----

やる(BNFをかんたんなので)

----解説ここまで---- */


VS split(string& s, char c) {
	int i = 0;
	int t = 0;
	VS ret;
	while (t + i < SZ(s)) {
		while (s[t + i] != c && t+i<SZ(s))i++;
		ret.push_back(s.substr(t, i));
		t += i + 1;
		i = 0;
	}
	return ret;
}
bool check(string s) {
	s = s.substr(1, SZ(s) - 2);
	VS se = split(s, '&');
	map<char, int>bg;
	map<char, int>sm;
	for (string str : se) {
		if (str[0] == '~') {
			bg[str[1]] = 1;
		}
		else {
			sm[str[0]] = 1;
		}
	}
	FOR(i, 0, SZ(s)) {
		if (isalpha(s[i]))
			if (sm[s[i]] && bg[s[i]])return 0;

	}
	return 1;

}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string in;
	while (cin >> in, in != "#") {
		VS se = split(in, '|');
		int f = 0;
		for (string s : se) {
			f |= check(s);
		}
		cout << (f ? "yes" : "no") << endl;
	}

	return 0;
}
