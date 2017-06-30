#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <set>
#include <sstream>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <climits>
#include <list>
#include <fstream>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
#define FORR(i,s,e) for(ll (i)=(s);(i)>(e);(i)--)
#define debug(x) cout<<#x<<": "<<x<<endl
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
const ll MOD = 1000000007;
const int INF = 1e9;
const ll LINF = 1e16;
const double PI = acos(-1.0);
int dx[8] = { 0,0,1,-1,1,1,-1,-1 };
int dy[8] = { 1,-1,0,0,1,-1,1,-1 };

#define foreach(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); itr++)
/* -----  xtimex  Problem:  / Link:  ----- */
/* ------問題------

-----問題ここまで----- */
/* -----解説等-----
＞n≦mとする。
＞写像f:{1,2,…,n}→{1,2,…,m}ただし、単射かつ∀i∈{1,2,…,n},f(i)≠i
＞の総数

求める写像の総数を S(n,m) とする。包除原理より、

S(n,m)
=Σ[k=0,n]{comb(n,k)*((-1)^k)*comb(m-k,n-k)*(n-k)!}
=(n!)*Σ[k=0,n]{((-1)^k)*(m-k)!/((m-n)!*(n-k)!*k!)}. (答)

----解説ここまで---- */

class DerangementsDiv2
{
public:
	ll fact[100];
	ll inv[100];
	ll factinv[100];
	void make_fact(ll n, ll mod) {
		fact[0] = 1;
		FOR(i, 1, n + 1) {
			fact[i] = fact[i - 1] * i%mod;
		}
	}

	void make_inv(ll n, ll mod) {
		inv[1] = 1;
		FOR(i, 2, n+1) {
			inv[i] = inv[mod%i] * (mod - mod / i) % mod;
		}
	}

	void make_factinv(ll n, ll  mod) {
		factinv[0] = 1;
		FOR(i, 1, n + 1) {
			factinv[i] = (factinv[i-1]*inv[i]) % mod;
		}
	}
	int count(int n, int m)
	{
		int N = m;
		int M = n + m;
		ll ans = 0;
		make_fact(100, MOD);
		make_inv(100, MOD);
		make_factinv(100, MOD);
		FOR(k, 0, N + 1) {
			int s = 1;
			if (k % 2 == 1)s = -1;
			ans = ans +(MOD+ s*(fact[M- k] * factinv[M - N] %MOD)* (factinv[N - k] * factinv[k]%MOD))%MOD;
			//ans +=(s*( (( ( (  (fact[m - k] % MOD)*(inv[m - n] % MOD) ) % MOD)*((inv[n - k] % MOD)) % MOD)*(inv[k]) % MOD)%MOD));
			ans =(ans+MOD)% MOD;
		}
		ans *= fact[N];
		return ans%MOD;
	}
};

/*

struct DerangementsDiv2 {
  int n;
  int m;
  int count(int _n, int _m) {
	n = _n, m = _m;
	return 0;
  }
};

*/

// CUT begin
ifstream data("DerangementsDiv2.sample");

string next_line() {
	string s;
	getline(data, s);
	return s;
}

template <typename T> void from_stream(T &t) {
	stringstream ss(next_line());
	ss >> t;
}

void from_stream(string &s) {
	s = next_line();
}

template <typename T>
string to_string(T t) {
	stringstream s;
	s << t;
	return s.str();
}

string to_string(string t) {
	return "\"" + t + "\"";
}

bool do_test(int n, int m, int __expected) {
	time_t startClock = clock();
	DerangementsDiv2 *instance = new DerangementsDiv2();
	int __result = instance->count(n, m);
	double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
	delete instance;

	if (__result == __expected) {
		cout << "PASSED!" << " (" << elapsed << " seconds)" << endl;
		return true;
	}
	else {
		cout << "FAILED!" << " (" << elapsed << " seconds)" << endl;
		cout << "           Expected: " << to_string(__expected) << endl;
		cout << "           Received: " << to_string(__result) << endl;
		return false;
	}
}

int run_test(bool mainProcess, const set<int> &case_set, const string command) {
	int cases = 0, passed = 0;
	while (true) {
		if (next_line().find("--") != 0)
			break;
		int n;
		from_stream(n);
		int m;
		from_stream(m);
		next_line();
		int __answer;
		from_stream(__answer);

		cases++;
		if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
			continue;

		cout << "  Testcase #" << cases - 1 << " ... ";
		if (do_test(n, m, __answer)) {
			passed++;
		}
	}
	if (mainProcess) {
		cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
		int T = time(NULL) - 1498821423;
		double PT = T / 60.0, TT = 75.0;
		cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
		cout << "Score  : " << 1000 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
	}
	return 0;
}

int main(int argc, char *argv[]) {
	cout.setf(ios::fixed, ios::floatfield);
	cout.precision(2);
	set<int> cases;
	bool mainProcess = true;
	for (int i = 1; i < argc; ++i) {
		if (string(argv[i]) == "-") {
			mainProcess = false;
		}
		else {
			cases.insert(atoi(argv[i]));
		}
	}
	if (mainProcess) {
		cout << "DerangementsDiv2 (1000 Points)" << endl << endl;
	}
	return run_test(mainProcess, cases, argv[0]);
}
// CUT end
