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

/* -----  2017/07/08  Problem: AOJ 1155  / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1155  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

構文解析
BNFにしたがって書く。

----解説ここまで---- */

ll N;

ll ans = 0LL;
char c[3] = { '0','1','2' };
string ch(string &s,int i,int j,int k) {
	string ss=s;
	FOR(a, 0, s.size()) {
		if (s[a] == 'P') { ss[a] = c[i]; }
		if (s[a] == 'Q') { ss[a] = c[j]; }
		if (s[a] == 'R') { ss[a] = c[k]; }
	}
	return ss;
}

int factor(string &s, int &i) {
	int ret = 0;
	if (isdigit(s[i])) {
		ret = s[i] - '0';
	}
	i++;
	return ret;
}

int expr0(string &s, int &i) {
	if (s[i] == '-') {
		i++;
		return 2 - expr0(s, i);
	}
	if (s[i] == '(') {
		i++;
		int ret = expr0(s, i);
		if (s[i] == '*') {
			i++;
			ret = min(ret, expr0(s, i));
		}
		else if (s[i] == '+') {
			i++;
			ret = max(ret, expr0(s, i));
		}
		i++;
		return ret;
	}
	else {
		return factor(s, i);
	}

}



int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	while (1) {
		string s;
		cin >> s;
		if (s[0] == '.')break;
		ans = 0;
		FOR(p, 0, 3) {
			FOR(q, 0, 3) {
				FOR(r, 0, 3) {
					string ss = ch(s,p,q,r);
					int id = 0;
					if (expr0(ss, id) == 2)ans++;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
