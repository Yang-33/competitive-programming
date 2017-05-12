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

初stringsteram
modやめちくり～

----解説ここまで---- */

bool flag;

ll pow_mod(ll x, ll y, ll mod) {
	ll num = 1;
	while (y > 0) {
		if (y & 1) {
			num =(num* x) % mod;
		}
		x =(x* x) % mod;;
		y >>= 1;
	}
	return num%mod;
}

ll mod_inverse(ll x, ll mod) {
	//debug(pow_mod(x, mod - 2, mod));
	return pow_mod(x, mod - 2, mod);
}

ll getnum(string &s, int &i, ll mod);
ll expr1(string &s, int &i, ll mod);
ll expr2(string &s, int &i, ll mod);
ll expr3(string &s, int &i, ll mod);
ll expr4(string &s, int &i, ll mod);

ll expr1(string &s, int &i, ll mod) {
	if (flag)return -1;
	ll ret = expr2(s, i, mod);
	while (1) {
		if (s[i] == '+') {
			i++;
			ll x2 = expr2(s, i, mod);
			ret =(ret+ x2)%mod;
		}
		else if (s[i] == '-') {
			i++;
			ll x2 = expr2(s, i, mod);
			ret =(ret+ mod - x2)%mod;
		}
		else break;
	}
	return ret%mod;
}

ll expr2(string &s, int &i, ll mod) {
	if (flag)return -1;

	ll ret = expr3(s, i, mod);
	while (1) {
		if (s[i] == '*') {
			i++;
			ret=(ret* expr3(s, i, mod))%mod;
		}
		else break;
	}
	return ret%mod;
}


ll expr3(string &s, int &i, ll mod) {
	if (flag)return -1;

	ll ret = expr4(s, i, mod);
	while (1) {
		if (s[i] == '/') {
			i++; ll d = expr4(s, i, mod);
//			debug(d);
			if ((d%mod) != 0)ret =(ret*mod_inverse(d,mod))%mod;
			else {
				flag = true;
				return -1;
			}
		}
		else break;
	}
	return ret%mod;
}


ll expr4(string &s, int &i, ll mod) {
	if (flag)return -1;

	ll ret;
	if (s[i] == '(') {
		i++, ret = expr1(s, i, mod); i++;
	}
	else ret = getnum(s, i, mod);
	return ret;
}

ll getnum(string &s, int &i, ll mod) {
	if (flag)return -1;

	ll ret = 0;;
	
	while (isdigit(s[i])) {
		ret *= 10;
		ret += s[i] - '0';
		i++;
	}
//	cout << "getnum " << ret << endl;
	return ret;
}

int main() {
	//  cin.tie(0);
	//  ios_base::sync_with_stdio(false);

	while (1) {
		string  ss, str;
		ll Mod;
		scanf("%lld:", &Mod);
		if (Mod == 0)break;
		
		getline(cin, str);
		stringstream s(str);
		while (!s.eof()) {
			string S;
			s >> S;
			ss += S;
		}
		
		//	  cout << ss << endl;
		//	  break;
		//debug(Mod);
		int i = 0;
		flag = false;
		ll x = expr1(ss, i, Mod);
		if (flag) {
			cout << "NG" << endl;
		}
		else {
			cout << ss << " = " << (x + 10 * Mod) % Mod << " (mod " << Mod << ")" << endl;
		}
	}

	return 0;
}
