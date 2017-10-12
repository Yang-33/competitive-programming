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

/* -----  2017/10/02  Problem: SRM 722 div1 hard DominoTiling / Link:   ----- */
/* ------問題------

ドミノ敷き詰め
ただし埋めてはいけない場所が複数点指定されている

-----問題ここまで----- */
/* -----解説等-----

は？となりこれは普通にbitDPをやっておわり。(しかも既出)
既出の問題を出すのはどうなんだろうね

----解説ここまで---- */

class DominoTiling
{
public:

	LL dp[2][1 << 14];
	long long count(vector<string> grid) {


		LL H = SZ(grid); LL W = SZ(grid[0]);
		dp[0][0] = 1LL;
		for (int i = H - 1; i >= 0; i--) {
			for (int j = W - 1; j >= 0; j--) {
				FOR(used, 0, 1 << W) {
					if (((used >> j) & 1) || grid[i][j] == 'X') {
						dp[1][used] = dp[0][used & (~(1 << j))];
					}
					else {
						LL res = 0;
						if (j + 1 < W && !(used >> (j + 1) & 1) && (grid[i][j + 1] != 'X')) {
							res += dp[0][used | 1 << (j + 1)];
						}
						if (i + 1 < H && (grid[i + 1][j] != 'X')) {
							res += dp[0][used | 1 << j];
						}
						dp[1][used] = res;
					}
				}
				FOR(i, 0, 1LL << W) {//swap
					dp[0][i] = dp[1][i];
					dp[1][i] = 0;
				}
			}
		}

		return dp[0][0];
	}
};

/*

struct DominoTiling {
  vector<string> grid;
  long long count(vector<string> _grid) {
	grid = _grid;
	return 0;
  }
};

*/

// CUT begin
ifstream data("DominoTiling.sample");

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

template <typename T> void from_stream(vector<T> &ts) {
	int len;
	from_stream(len);
	ts.clear();
	for (int i = 0; i < len; ++i) {
		T t;
		from_stream(t);
		ts.push_back(t);
	}
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

bool do_test(vector<string> grid, long long __expected) {
	time_t startClock = clock();
	DominoTiling *instance = new DominoTiling();
	long long __result = instance->count(grid);
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
		vector<string> grid;
		from_stream(grid);
		next_line();
		long long __answer;
		from_stream(__answer);

		cases++;
		if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
			continue;

		cout << "  Testcase #" << cases - 1 << " ... ";
		if (do_test(grid, __answer)) {
			passed++;
		}
	}
	if (mainProcess) {
		cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
		int T = time(NULL) - 1507816867;
		double PT = T / 60.0, TT = 75.0;
		cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
		cout << "Score  : " << 600 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
		cout << "DominoTiling (600 Points)" << endl << endl;
	}
	return run_test(mainProcess, cases, argv[0]);
}
// CUT end
