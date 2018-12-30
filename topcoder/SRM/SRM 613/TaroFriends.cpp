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

/* -----  xtimex  Problem: SRM 613 div1 easy / Link:   ----- */
/* ------問題------

位置coordinates[i]に猫がいる。
今合図をすると、全員が独立して+-Xだけ移動する。
一番端の猫の距離差が最小となるときの距離は?

-----問題ここまで----- */
/* -----解説等-----

ある軸を決めてあげて、そのときの移動をシミュレーションすれば良い。
軸を決めるとその左右は軸に移動するのが良い。(そうで無いとすると距離を最小化できないので)
O(N^2)だが工夫するとO(N)でできそう。

----解説ここまで---- */

class TaroFriends
{
public:

	int getNumber(vector<int> coordinates, int X)
	{
		SORT(coordinates);
		// 本当はO(N)でできる
		int ans = INF;
		int N = SZ(coordinates);
		FOR(i, 0, N) {// i]:iは右へ
			int L = INF, R = -INF;
			FOR(j, 0, i) {
				L = min(L, coordinates[j] + X);
				R = max(R, coordinates[j] + X);
			}
			FOR(j, i, N) {
				L = min(L, coordinates[j] - X);
				R = max(R, coordinates[j] - X);
			}
			ans = min(ans, R - L);
		}
		return ans;
	}
};

/*

struct TaroFriends {
  vector<int> coordinates;
  int X;
  int getNumber(vector<int> _coordinates, int _X) {
	coordinates = _coordinates, X = _X;
	return 0;
  }
};

*/

// CUT begin
ifstream data("TaroFriends.sample");

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

bool do_test(vector<int> coordinates, int X, int __expected) {
	time_t startClock = clock();
	TaroFriends *instance = new TaroFriends();
	int __result = instance->getNumber(coordinates, X);
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
		vector<int> coordinates;
		from_stream(coordinates);
		int X;
		from_stream(X);
		next_line();
		int __answer;
		from_stream(__answer);

		cases++;
		if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
			continue;

		cout << "  Testcase #" << cases - 1 << " ... ";
		if (do_test(coordinates, X, __answer)) {
			passed++;
		}
	}
	if (mainProcess) {
		cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
		int T = time(NULL) - 1545962167;
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
		cout << "TaroFriends (250 Points)" << endl << endl;
	}
	return run_test(mainProcess, cases, argv[0]);
}
// CUT end
