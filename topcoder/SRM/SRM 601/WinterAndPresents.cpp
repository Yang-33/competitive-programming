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

/* -----  xtimex  Problem: SRM 601 div1 easy / Link:   ----- */
/* ------問題------

箱iにリンゴとミカンがapple[i],orange[i]個づつ入っている。
すべての箱からX個づつ取り出した時、この果物の組(リンゴ、ミカン)の組合せは何通りあるか?

-----問題ここまで----- */
/* -----解説等-----

X個それぞれで組は独立して見ることができる。
どのような組合せでもよいがX個必ず取り出せるとして、各箱からX個取り出す。
このときリンゴの取る数を最大化したときと、最小化した時までの組の値は(5,1),(4,2),(3,3),(2,4)のように連続している。
したがって最大化したときと最小化したときの値がわかればよく、これはO(箱の中身の最小値*N)時間で解くことができる。

----解説ここまで---- */

class WinterAndPresents {
public:
	long long getNumber(VI apple, VI orange) {
		int N = SZ(apple);
		int Max = apple.front() + orange.front();
		FOR(i, 0, N) {
			Max = min(Max, apple[i] + orange[i]);
		}
		LL ans = 0;
		// 連続に取れる
		FOR(c, 1, Max + 1) {
			int appleMax = 0;
			int appleMin = 0;
			FOR(i, 0, N) {
				appleMax += min(c, apple[i]);
				appleMin += max(c - orange[i], 0);
			}
			ans += appleMax - appleMin + 1;
		}
		return ans;
	}

};
/*

struct WinterAndPresents {
  vector<int> apple;
  vector<int> orange;
  long long getNumber(vector<int> _apple, vector<int> _orange) {
	apple = _apple, orange = _orange;
	return 0;
  }
};

*/

// CUT begin
ifstream data("WinterAndPresents.sample");

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

bool do_test(vector<int> apple, vector<int> orange, long long __expected) {
	time_t startClock = clock();
	WinterAndPresents *instance = new WinterAndPresents();
	long long __result = instance->getNumber(apple, orange);
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
		vector<int> apple;
		from_stream(apple);
		vector<int> orange;
		from_stream(orange);
		next_line();
		long long __answer;
		from_stream(__answer);

		cases++;
		if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
			continue;

		cout << "  Testcase #" << cases - 1 << " ... ";
		if ( do_test(apple, orange, __answer)) {
			passed++;
		}
	}
	if (mainProcess) {
		cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
		int T = time(NULL) - 1545803138;
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
		if ( string(argv[i]) == "-") {
			mainProcess = false;
		} else {
			cases.insert(atoi(argv[i]));
		}
	}
	if (mainProcess) {
		cout << "WinterAndPresents (250 Points)" << endl << endl;
	}
	return run_test(mainProcess, cases, argv[0]);
}
// CUT end
