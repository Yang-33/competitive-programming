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
/* -----  xtimex  Problem: SRM 722 div2 hard MulticoreProcessingEasy  / Link:  ----- */
/* ------問題------

job:jobLength
2つ以上のコアをつかうときcorePenalty*num
様々なコンピュータが来る。
各speed, core数があるのでどのように使うかが最適か答えよ。(最小化)

-----問題ここまで----- */
/* -----解説等-----

どう考えても凸関数なので多いときは三分探索。
制約がクソなので全探索が許される。

 ----解説ここまで---- */

class MulticoreProcessingEasy
{
public:

	int fastestTime(int jobLength, int corePenalty, vector<int> speed, vector<int> cores)
	{
		double ans = LINF;

		FOR(i, 0, SZ(speed)) {
			FOR(j, 1, cores[i] + 1) {
				int pena = j - 1;
				double sub = (double)jobLength / (j*speed[i]);
				if (pena >= 1) { sub += corePenalty*pena; }
				ans = min(ans, ceil(sub));
			}
		}

		return (int)ans;
	}
};

/*

struct MulticoreProcessingEasy {
  int jobLength;
  int corePenalty;
  vector<int> speed;
  vector<int> cores;
  int fastestTime(int _jobLength, int _corePenalty, vector<int> _speed, vector<int> _cores) {
	jobLength = _jobLength, corePenalty = _corePenalty, speed = _speed, cores = _cores;
	return 0;
  }
};

*/

// CUT begin
ifstream data("MulticoreProcessingEasy.sample");

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

bool do_test(int jobLength, int corePenalty, vector<int> speed, vector<int> cores, int __expected) {
	time_t startClock = clock();
	MulticoreProcessingEasy *instance = new MulticoreProcessingEasy();
	int __result = instance->fastestTime(jobLength, corePenalty, speed, cores);
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
		int jobLength;
		from_stream(jobLength);
		int corePenalty;
		from_stream(corePenalty);
		vector<int> speed;
		from_stream(speed);
		vector<int> cores;
		from_stream(cores);
		next_line();
		int __answer;
		from_stream(__answer);

		cases++;
		if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
			continue;

		cout << "  Testcase #" << cases - 1 << " ... ";
		if (do_test(jobLength, corePenalty, speed, cores, __answer)) {
			passed++;
		}
	}
	if (mainProcess) {
		cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
		int T = time(NULL) - 1507806631;
		double PT = T / 60.0, TT = 75.0;
		cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
		cout << "Score  : " << 700 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
		cout << "MulticoreProcessingEasy (700 Points)" << endl << endl;
	}
	return run_test(mainProcess, cases, argv[0]);
}
// CUT end
