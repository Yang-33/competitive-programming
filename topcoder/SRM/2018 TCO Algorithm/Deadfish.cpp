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

using VS = vector<string>;    using LL = long long;
using VI = vector<int>;       using VVI = vector<VI>;
using PII = pair<int, int>;   using PLL = pair<LL, LL>;
using VL = vector<LL>;        using VVL = vector<VL>;

#define ALL(a)  begin((a)),end((a))
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define SZ(a) int((a).size())
#define SORT(c) sort(ALL((c)))
#define RSORT(c) sort(RALL((c)))
#define UNIQ(c) (c).erase(unique(ALL((c))), end((c)))
#define FOR(i, s, e) for (LL(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (int(i) = (s); (i) > (e); (i)--)
#define debug(x) cerr << #x << ": " << x << endl
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

#define foreach(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); itr++)

/* -----  2017/10/02  Problem: SRM  / Link:   ----- */
/* ------–â‘è------

-----–â‘è‚±‚±‚Ü‚Å----- */
/* -----‰ðà“™-----

‚¨‚à‚ñ‚È

----‰ðà‚±‚±‚Ü‚Å---- */

class Deadfish
{
public:
	int f(int x) {
		string s;
		while (x) {
			s += string(1, x % 10 + '0');
			x /= 10;
		}
		RSORT(s);
		return stoi(s);
	}
	int shortestCode(int N)
	{
		vector<long long> dp(400005, 1e18);
		dp[0] = 0;
		map<int, int>Map;
		FOR(i, 1, 400005) {
			Map[i] = f(i);
		}
		queue<int>q;
		q.push(0);
		map<int, int>visit;
		while (!q.empty()) {
			LL i = q.front(); q.pop();
			if (visit[i])continue;
			visit[i] = 1;
			if (i+1<=400000&&dp[i + 1] > dp[i] + 1) {
				dp[i + 1] = dp[i] + 1;
				q.push(i + 1);
			}
			if (i>=1&&dp[i - 1] > dp[i] + 1) {
				dp[i - 1] = dp[i] + 1;
				q.push(i - 1);
			}if (i*i<=400000 &&dp[i*i] > dp[i] + 1) {
				dp[i*i] = dp[i] + 1;
				q.push(i*i);
			}if (Map[i]<=400000&&dp[Map[i]] > dp[i] + 1) {
				dp[Map[i]] = dp[i] + 1;
				q.push(Map[i]);
			}

		}
		return dp[N];
	}
};

/*

struct Deadfish {
  int N;
  int shortestCode(int _N) {
	N = _N;
	return 0;
  }
};

*/

// CUT begin
ifstream data("Deadfish.sample");

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

bool do_test(int N, int __expected) {
	time_t startClock = clock();
	Deadfish *instance = new Deadfish();
	int __result = instance->shortestCode(N);
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
		int N;
		from_stream(N);
		next_line();
		int __answer;
		from_stream(__answer);

		cases++;
		if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
			continue;

		cout << "  Testcase #" << cases - 1 << " ... ";
		if (do_test(N, __answer)) {
			passed++;
		}
	}
	if (mainProcess) {
		cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
		int T = time(NULL) - 1524328602;
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
		cout << "Deadfish (1000 Points)" << endl << endl;
	}
	return run_test(mainProcess, cases, argv[0]);
}
// CUT end
