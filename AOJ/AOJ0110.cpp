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

/* -----  2017/05/12  Problem:  / Link:   ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----



----解説ここまで---- */


ll getnum(int &i, string &s, int x) {
	ll num = 0;
	int ii = i;
	while (isdigit(s[i])||s[i]=='X') {
		if (ii-i == 0 && s[i] == 'X'&&x==0)return LINF;
		char c = s[i];
		if (s[i] == 'X')c = '0' + x;
		num *= 10;
		num += c - '0';
		i++;
	}

	return num;
}


string f(string &s) {
	string ans = "";
	int p = 0;
	FOR(i, 0, 10) {
		p = 0;
		ll x1 = getnum(p, s, i);
		p++;
		ll x2 = getnum(p, s, i);
		p++;
		ll x3 = getnum(p, s, i);
		if (x1 + x2 == x3) {
			ans = to_string(i);
			break;
		}
	}

	if (ans == "")ans = "NA";

	return ans;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string s;

	while (cin >> s) {
		cout << f(s) << endl;
	}
	return 0;
}
