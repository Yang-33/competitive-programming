#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define FOR(i, s, e) for (ll(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (ll(i) = (s); (i) > (e); (i)--)
#define debug(x) cout << #x << ": " << x << endl
#define mp make_pair
#define pb push_back
const ll MOD = 1000000007;
const int INF = 1e9;
const ll LINF = 1e16;
const double PI = acos(-1.0);
int dx[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2017/06/16  Problem: JAG summer 2013  / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2613  ----- */
/* ------問題------

AOJ2613
Unordered Operators

-----問題ここまで----- */
/* -----解説等-----

構文解析の問題であるが、演算順序が最適なものを探す必要がある。
演算子は３つしかないのでこれを全探索すればよい。演算順位は３つ存在するので３段階の構文解析をすればよい。
(v[1].find(s[i]) != string::npos
とかができるようになった。=> string ::nposは-1で定義されているらしい。

----解説ここまで---- */

ll N;
string S;
char c[3] = { '+','-','*' };
ll ans = LLONG_MIN;

ll expr0(int &i, string &s, vector<string>&v);
ll expr1(int &i, string &s, vector<string>&v);
ll expr2(int &i, string &s, vector<string>&v);
ll expr3(int &i, string &s, vector<string>&v);
ll getnum(int &i, string &s, vector<string>&v) {
	ll num = 0;
	while ('0' <= s[i] && s[i] <= '9') {
		num *= 10;
		num += s[i] - '0';
		i++;
	}
	return num;
}

ll expr0(int &i, string &s, vector<string>&v) {
	ll num = expr1(i, s, v);

	while (i < N && (v[0].find(s[i]) != string::npos)) {
		char op = s[i];
		i++;
		if (op == '+') {
			num += expr1(i, s, v);
		}
		else if (op == '-') {
			num -= expr1(i, s, v);
		}
		else if (op == '*') {
			num *= expr1(i, s, v);
		}
	}
	return num;
}

ll expr1(int &i, string &s, vector<string>&v) {
	ll num = expr2(i, s, v);

	while (i < N && (v[1].find(s[i]) != string::npos)) {
		char op = s[i];
		i++;
		if (op == '+') {
			num += expr2(i, s, v);
		}
		else if (op == '-') {
			num -= expr2(i, s, v);
		}
		else if (op == '*') {
			num *= expr2(i, s, v);
		}
	}
	return num;
}

ll expr2(int &i, string &s, vector<string>&v) {
	ll num = expr3(i, s, v);

	while (i < N && (v[2].find(s[i]) != string::npos)) {
		char op = s[i];
		i++;
		if (op == '+') {
			num += expr3(i, s, v);
		}
		else if (op == '-') {
			num -= expr3(i, s, v);
		}
		else if (op == '*') {
			num *= expr3(i, s, v);
		}
	}
	return num;
}


ll expr3(int &i, string &s, vector<string>&v) {
	ll num = 0;
	if (s[i] == '(') {
		i++;
		num = expr0(i, s, v);
		i++;
	}
	else num = getnum(i, s, v);
	return num;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> S;
	FOR(i, 0, 3)FOR(j, 0, 3)FOR(k, 0, 3) {
		vector<string>v(3);
		v[i].pb(c[0]);
		v[j].pb(c[1]);
		v[k].pb(c[2]);
		N = S.size();
		int x = 0;
		ans = max(ans, expr0(x, S, v));
	}
	cout << ans << endl;

	return 0;
}
