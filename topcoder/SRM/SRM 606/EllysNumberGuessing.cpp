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

/* -----  xtimex  Problem: SRM 606 div1 easy / Link:   ----- */
/* ------問題------

数当てゲームを行う。元の数字Xに対して、予想した値と、その差の絶対値が与えられる。
絶対値の値は大小どちらかはわからない。
元の数字が1つに決まるならその値を、2つに決まるなら-2を、決まらないなら-1を出力せよ。

-----問題ここまで----- */
/* -----解説等-----

最初の回答から答えは2つ以下に絞り込むことができる。
以降は正しい答えの積集合のみを残していけばよく、そのサイズが0→無理、1→その値、2→特定不能、となる。
値は制約を守るものを取るとは限らないので注意。

----解説ここまで---- */

class EllysNumberGuessing
{
public:

	int getNumber(vector<int> guesses, vector<int> answers)
	{
		set<int>ans; {
			int v1 = guesses[0] + answers[0];
			if (0<v1&&v1<=1000000000)ans.insert(v1);
			int v2 = guesses[0] - answers[0];
			if (0<v2&&v2<=1000000000)ans.insert(v2);
		}
		// answer[0] != 0
		FOR(i, 1, SZ(guesses)) {
			int v1 = guesses[i] + answers[i];
			int v2 = guesses[i] - answers[i];
			if (SZ(ans) == 2) {
				if (ans.find(v1) != ans.end() && ans.find(v2) != ans.end()) {
					continue;
				}
				else if (ans.find(v1) != ans.end()) {
					int val;
					for (auto it : ans) {
						if (it != v1)val = it;
					}
					ans.erase(val);
				}
				else if (ans.find(v2) != ans.end()) {
					int val;
					for (auto it : ans) {
						if (it != v2)val = it;
					}
					ans.erase(val);
				}
				else return -2;
			}
			else {
				if (ans.find(v1) != ans.end() || ans.find(v2) != ans.end()) {
					continue;
				}
				else {
					return -2;
				}
			}
		}
		int res = -1;
		if (SZ(ans) == 1)res = *ans.begin();
		if (SZ(ans) == 0)res = -2; // これで落ちた
		return res;
	}
};

/*

struct EllysNumberGuessing {
  vector<int> guesses;
  vector<int> answers;
  int getNumber(vector<int> _guesses, vector<int> _answers) {
	guesses = _guesses, answers = _answers;
	return 0;
  }
};

*/

// CUT begin
ifstream data("EllysNumberGuessing.sample");

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

bool do_test(vector<int> guesses, vector<int> answers, int __expected) {
	time_t startClock = clock();
	EllysNumberGuessing *instance = new EllysNumberGuessing();
	int __result = instance->getNumber(guesses, answers);
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
		vector<int> guesses;
		from_stream(guesses);
		vector<int> answers;
		from_stream(answers);
		next_line();
		int __answer;
		from_stream(__answer);

		cases++;
		if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
			continue;

		cout << "  Testcase #" << cases - 1 << " ... ";
		if (do_test(guesses, answers, __answer)) {
			passed++;
		}
	}
	if (mainProcess) {
		cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
		int T = time(NULL) - 1545962088;
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
		cout << "EllysNumberGuessing (250 Points)" << endl << endl;
	}
	return run_test(mainProcess, cases, argv[0]);
}
// CUT end
