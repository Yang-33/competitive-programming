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
#define FOR(i, s, e) for (int(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (int(i) = (s); (i) > (e); (i)--)
#define debug(x) cerr << #x << ": " << x << endl
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

#define foreach(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); itr++)

/* -----  xtimex  Problem: SRM 620 div1 easy / Link:   ----- */
/* ------問題------

数(x,y)があるとき、(x+y,y)or(x,y+x)へ進めることができる。
最終的に(a,b)と(c,d)に到達可能な(x,y)のうち、x+yの値が最大になるものは?

-----問題ここまで----- */
/* -----解説等-----

(a,b)と(c,d)がどのように構成されてきたかは一意に定まる。
これらの経路のうち、一致するものの最大値を直接見れば良い。

----解説ここまで---- */

class PairGame
{
public:
	long long  gcd(long long  a, long long  b) { return b ? gcd(b, a%b) : a; }

	int maxSum(int a, int b, int c, int d)
	{
		auto f = [](set<PII>&se, int x, int y) {
			while (1) {
				se.insert(PII(x, y));
				if (x > y)x -= y;
				else y -= x;
				if (!x || !y)break;
			}
		};

		set<PII>se1, se2;
		f(se1, a, b);
		f(se2, c, d);
		int ans = -1;
		for (auto it : se1) {
			PII val = it;
			if (se2.find(val) != se2.end()) {
				ans = max(ans, val.first + val.second);
			}
		}

		return ans;
	}
};

/*

struct PairGame {
  int a;
  int b;
  int c;
  int d;
  int maxSum(int _a, int _b, int _c, int _d) {
	a = _a, b = _b, c = _c, d = _d;
	return 0;
  }
};

*/

// CUT begin
ifstream data("PairGame.sample");

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

bool do_test(int a, int b, int c, int d, int __expected) {
	time_t startClock = clock();
	PairGame *instance = new PairGame();
	int __result = instance->maxSum(a, b, c, d);
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
		int a;
		from_stream(a);
		int b;
		from_stream(b);
		int c;
		from_stream(c);
		int d;
		from_stream(d);
		next_line();
		int __answer;
		from_stream(__answer);

		cases++;
		if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
			continue;

		cout << "  Testcase #" << cases - 1 << " ... ";
		if (do_test(a, b, c, d, __answer)) {
			passed++;
		}
	}
	if (mainProcess) {
		cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
		int T = time(NULL) - 1545962262;
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
		cout << "PairGame (250 Points)" << endl << endl;
	}
	return run_test(mainProcess, cases, argv[0]);
}
// CUT end
