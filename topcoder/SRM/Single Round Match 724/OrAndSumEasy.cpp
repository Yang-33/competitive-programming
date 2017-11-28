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

/* -----  2017/11/29  Problem: SRM724 div2 mid  / Link:   ----- */
/* ------���------

2�i�� Or, Sum���^������B
������\��������a,b �͑��݂��邩?

-----��肱���܂�----- */
/* -----�����-----

�𒼂�or,sum�̏�񂩂�\�����邱�ƂŌ��o�\�B
�܂��Asum - or = and �ł��邱�Ƃ�m���Ă���Ώu�E

----��������܂�---- */

class OrAndSumEasy
{
public:

	string isPossible(long long pairOr, long long pairSum)
	{
		long long a = 0;
		long long b = 0;

		int carry = 0;
		int ok = 1;
		FOR(i, 0, 64) {
			long long  Or = pairOr & (1LL << i);
			long long  Sum = pairSum & (1LL << i);

			if (carry == 0) {

				if (Or == 0 && Sum == 0) {
					;
				}
				else if (Or == 0 && Sum != 0) {
					ok = 0; // no carry
				}
				else if (Or != 0 && Sum == 0) {
					a |= 1LL << i;
					b |= 1LL << i;
					carry = 1;
				}
				else if (Or != 0 && Sum != 0) {
					a |= 1LL << i;
				}

			}
			else {
				// carry=1
				if (Or == 0 && Sum == 0) {
					ok = 0;
					carry = 0;
				}
				else if (Or == 0 && Sum != 0) {
					carry = 0;
					;
				}
				else if (Or != 0 && Sum == 0) {
					a |= 1LL << i;
					carry = 1;
				}
				else if (Or != 0 && Sum != 0) {
					a |= 1LL << i;
					b |= 1LL << i;
					carry = 1;
				}
			}

		}
		if (((a | b) == pairOr) && (a + b) == pairSum) {
			ok = 1;
		}
		else ok = 0;

		string ans[2] = { "Impossible","Possible" };
		return ans[ok];
	}
};

/*

struct OrAndSumEasy {
  long long pairOr;
  long long pairSum;
  string isPossible(long long _pairOr, long long _pairSum) {
	pairOr = _pairOr, pairSum = _pairSum;
	return "";
  }
};

*/

// CUT begin
ifstream data("OrAndSumEasy.sample");

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

bool do_test(long long pairOr, long long pairSum, string __expected) {
	time_t startClock = clock();
	OrAndSumEasy *instance = new OrAndSumEasy();
	string __result = instance->isPossible(pairOr, pairSum);
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
		long long pairOr;
		from_stream(pairOr);
		long long pairSum;
		from_stream(pairSum);
		next_line();
		string __answer;
		from_stream(__answer);

		cases++;
		if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
			continue;

		cout << "  Testcase #" << cases - 1 << " ... ";
		if (do_test(pairOr, pairSum, __answer)) {
			passed++;
		}
	}
	if (mainProcess) {
		cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
		int T = time(NULL) - 1511885166;
		double PT = T / 60.0, TT = 75.0;
		cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
		cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
		cout << "OrAndSumEasy (500 Points)" << endl << endl;
	}
	return run_test(mainProcess, cases, argv[0]);
}
// CUT end
