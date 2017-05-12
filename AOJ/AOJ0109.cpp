#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;
typedef pair<ll, ll> pll;

#define FOR(i, s, e) for (ll(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (ll(i) = (s); (i) > (e); (i)--)
#define debug(x) cout << #x << ": " << x << endl
#define mp make_pair
#define pb push_back
const ll MOD = 1000000007;
const ll INF = 1e9;
const ll LINF = 1e16;
const double PI = acos(-1.0);
ll dx[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };
ll dy[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2017/05/12  Problem:  / Link:   ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

かっこがある
* / は計算順序の優先度が
カッコから出るときに次の要素を見ないといけない


----解説ここまで---- */

ll N;

ll ans = 0LL;

ll parsenum(ll &i, string &s);
ll expr1(ll &i, string &s);
ll expr2(ll &i, string &s);
ll expr3(ll &i, string &s);


ll parsenum(ll &i, string &s) {
	ll res = 0;
	while (isdigit(s[i])) {
		res *= 10;
		res += s[i] - '0';
		i++;
	}
	return res;
}

/*評価開始優先度０*/
ll expr1(ll &i, string &s) {
	ll ret = expr2(i, s);
	while (1) {
		if (s[i] == '+') {
			i++;
			ret += expr2(i, s);
		}
		else if (s[i] == '-') {
			i++;
			ret -= expr2(i, s);
		}
		else break;
	}
	return ret;
}

/*評価開始優先度１*/
ll expr2(ll &i, string &s) {
	ll ret = expr3(i, s);
	while (1) {
		if (s[i] == '*') {
			i++;
			ret *= expr3(i, s);
		}
		else if (s[i] == '/') {
			i++;
			ret /= expr3(i, s);
		}
		else break;
	}
	return ret;
}

/*評価開始優先度２*/
ll expr3(ll &i, string &s) {
	int ret;
	if (s[i] == '(') {
		i++;
		ret = expr1(i, s);
		i++; // !!!!
	}
	else ret = parsenum(i, s);
	
	return ret;
}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	string S[55];
	FOR(i, 0, N) {
		cin >> S[i];
		ll p = 0;
		cout << expr1(p, S[i]) << endl;

	}
	return 0;
}
