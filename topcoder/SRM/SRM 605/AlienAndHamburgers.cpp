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

/* -----  xtimex  Problem: SRM 605 div1 easy / Link:   ----- */
/* ------問題------

N個のハンバーガーにtype[i],taste[i]が割り振られている。
部分集合Sにおけるハンバーガーの嬉しさを(Sのtypeの種類数)*(\sum _S taste)とする。
嬉しさの最大値は?

-----問題ここまで----- */
/* -----解説等-----

tasteで降順ソートする。
1つづつハンバーガーを集合に加えていった時、taste>=0のときは常に正。
また、taste<0であっても種類数が増えたときは、多少\sum tasteが減少するが種類数の増加によって最大値を更新できる可能性がある。
降順で無い順番で最大値を得ることができたとして、降順に並べ替えた方が\sum stateは大きいはずなのでこれで正しい。

----解説ここまで---- */

class AlienAndHamburgers
{
public:

	int getNumber(vector<int> type, vector<int> taste)
	{
		int N = SZ(type);
		vector<PLL>a;
		FOR(i, 0, N) {
			a.push_back(PLL(taste[i], type[i]));
		}
		RSORT(a);
		LL ans = 0;
		VI used(102);
		LL cnt = 0;
		LL sum = 0;
		FOR(i, 0, N) {
			LL v = a[i].first, t = a[i].second;
			if (v >= 0) {
				if (!used[t])used[t] = 1, cnt++;
				sum += v;
				ans = max(ans, sum*cnt);
			}
			else {
				if (!used[t]) {
					used[t] = 1;
					cnt++;
					sum += v;
					ans = max(ans, sum*cnt);
				}
			}
		}
		return ans;
	}
};

/*

struct AlienAndHamburgers {
  vector<int> type;
  vector<int> taste;
  int getNumber(vector<int> _type, vector<int> _taste) {
	type = _type, taste = _taste;
	return 0;
  }
};

*/

// CUT begin
ifstream data("AlienAndHamburgers.sample");

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

bool do_test(vector<int> type, vector<int> taste, int __expected) {
	time_t startClock = clock();
	AlienAndHamburgers *instance = new AlienAndHamburgers();
	int __result = instance->getNumber(type, taste);
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
		vector<int> type;
		from_stream(type);
		vector<int> taste;
		from_stream(taste);
		next_line();
		int __answer;
		from_stream(__answer);

		cases++;
		if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
			continue;

		cout << "  Testcase #" << cases - 1 << " ... ";
		if (do_test(type, taste, __answer)) {
			passed++;
		}
	}
	if (mainProcess) {
		cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
		int T = time(NULL) - 1545962076;
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
		cout << "AlienAndHamburgers (250 Points)" << endl << endl;
	}
	return run_test(mainProcess, cases, argv[0]);
}
// CUT end
