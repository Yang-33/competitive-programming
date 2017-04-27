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
typedef pair<ll, ll> pii;
typedef pair<ll, ll> pll;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
#define FORR(i,s,e) for(ll (i)=(s);(i)>(e);(i)--)
#define debug(x) cout<<#x<<": "<<x<<endl
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
const ll MOD = 1000000007;
const ll INF = 1e9;
const ll LINF = 1e16;
const double PI = acos(-1.0);
ll dx[8] = { 0,0,1,-1,1,1,-1,-1 };
ll dy[8] = { 1,-1,0,0,1,-1,1,-1 };

#define foreach(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); itr++)
/* -----  xtimex  Problem: Single Round Match 713 500 PowerEquationEasy / Link:  ----- */
/* ------問題------

1≦a,b,c,d≦N について、a^b=c^dの組み合わせの総数を求める。
N≦10^6

-----問題ここまで----- */
/* -----解説等-----

結局のところ、素数となる指数の底を固定すれば、この問題は
n以下のa,bについて、〇^a = 〇^b を求めることになる。
愚直に計算してしまうと計算量が爆発してしまうので、底をまとめ上げていくと結局同じ数になるものをまとめて計算する。
具体的には、2,4,8,16,...は大きい方の指数に着目すればよい。
これを満たす数は、a<b,に対してN*a/lcm(a,b)となる

 ----解説ここまで---- */

class PowerEquationEasy
{
public:
	ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }

	ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

	bool numbers[10000100];
	ll dp[1000];

	ll cal(ll N, ll num) {
		if (dp[num] != -1)return dp[num];
		dp[num] = 0;
		FOR(i, 1, num + 1) {
			FOR(j, 1, num + 1) {
				ll Lcm = lcm(i, j);
				ll maxi = Lcm / min(i, j);
				dp[num] = (dp[num] + N / maxi) % MOD;
			}
		}
		return dp[num];
	}

	ll count(ll n) {
		memset(dp, -1, sizeof(dp));
		ll ans = (n*n)%MOD;
		FOR(i, 2, n + 1) {
			if (numbers[i] != true) {
				ll temp = 0;
				for (ll j = i; j <= n; j *= i) {
					temp++;
					numbers[j] = true;
				}
				ans = (ans + cal(n, temp)) % MOD;
			}
		}

		return ans%MOD;
	}
};

/*

struct PowerEquationEasy {
  ll n;
  ll count(ll _n) {
	n = _n;
	return 0;
  }
};

*/

// CUT begin
ifstream data("PowerEquationEasy.sample");

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

bool do_test(ll n, ll __expected) {
	time_t startClock = clock();
	PowerEquationEasy *instance = new PowerEquationEasy();
	ll __result = instance->count(n);
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

ll run_test(bool mainProcess, const set<ll> &case_set, const string command) {
	ll cases = 0, passed = 0;
	while (true) {
		if (next_line().find("--") != 0)
			break;
		ll n;
		from_stream(n);
		next_line();
		ll __answer;
		from_stream(__answer);

		cases++;
		if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
			continue;

		cout << "  Testcase #" << cases - 1 << " ... ";
		if (do_test(n, __answer)) {
			passed++;
		}
	}
	if (mainProcess) {
		cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
		ll T = time(NULL) - 1493255502;
		double PT = T / 60.0, TT = 75.0;
		cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
		cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
	}
	return 0;
}

int main(ll argc, char *argv[]) {
	cout.setf(ios::fixed, ios::floatfield);
	cout.precision(2);
	set<ll> cases;
	bool mainProcess = true;
	for (ll i = 1; i < argc; ++i) {
		if (string(argv[i]) == "-") {
			mainProcess = false;
		}
		else {
			cases.insert(atoi(argv[i]));
		}
	}
	if (mainProcess) {
		cout << "PowerEquationEasy (500 Points)" << endl << endl;
	}
	return run_test(mainProcess, cases, argv[0]);
}
// CUT end
