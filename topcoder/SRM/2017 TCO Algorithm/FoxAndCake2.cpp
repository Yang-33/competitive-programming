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
/* ------–â‘è------

-----–â‘è‚±‚±‚Ü‚Å----- */
/* -----‰ðà“™-----

‰R‰ð–@z

 ----‰ðà‚±‚±‚Ü‚Å---- */
#define N 100010


class FoxAndCake2
{
public:

	int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }

	int lcm(int a, int b) { return a / gcd(a, b) * b; }


	bool prime[N + 100]; 
	vector<int>pr;
	void primes() {
		for (int i = 2; i <= N; i++)
			prime[i] = true;//‡‚Éƒtƒ‰ƒO‚ð—§‚Ä‚é
		for (int i = 2; i * i <= N; i++)
			if (prime[i]) {
				pr.pb(i);
				for (int j = i * 2; j <= N; j += i)
					prime[j] = false;
			}//i‚Ì”{”‚Í‘f”‚Å‚È‚¢
	}
	string isPossible(int c, int s)
	{
		bool f = 0;
		primes();
		if (c > s)swap(c, s);
		if (gcd(c, s) != 1)f = 1;
		FOR(i, 0, pr.size()) {
			if (c-1<= pr[i])break;

			if (gcd(pr[i],s-c+pr[i]) != 1) {
				f = 1;
			}
		}
		if (f) return "Possible";
		else return "Impossible";
	}
};

/*

struct FoxAndCake2 {
  int c;
  int s;
  string isPossible(int _c, int _s) {
	c = _c, s = _s;
	return "";
  }
};

*/

// CUT begin
ifstream data("FoxAndCake2.sample");

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

bool do_test(int c, int s, string __expected) {
	time_t startClock = clock();
	FoxAndCake2 *instance = new FoxAndCake2();
	string __result = instance->isPossible(c, s);
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
		int c;
		from_stream(c);
		int s;
		from_stream(s);
		next_line();
		string __answer;
		from_stream(__answer);

		cases++;
		if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
			continue;

		cout << "  Testcase #" << cases - 1 << " ... ";
		if (do_test(c, s, __answer)) {
			passed++;
		}
	}
	if (mainProcess) {
		cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
		int T = time(NULL) - 1495296006;
		double PT = T / 60.0, TT = 75.0;
		cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
		cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
		cout << "FoxAndCake2 (250 Points)" << endl << endl;
	}
	return run_test(mainProcess, cases, argv[0]);
}
// CUT end
