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
/* -----  xtimex  Problem: SRM714div2 hard / Link:  ----- */
/* ------問題------

キャリアウーマンが地点0にいます。彼女は地点posにいる人のもつdeltaをすべて回収しまいといけません。
彼女の持つdeltaは現在０です。回収の際に彼女の持つdeltaが府にならないように回収するときの最短距離を求めよ。

-----問題ここまで----- */
/* -----解説等-----

deltaが負となる回収地点を記録する。正となる点については素通りしていけばよいが、負となる地点には値が正のときにしか向かうことができない。
正になったときに戻れば最適となる。

 ----解説ここまで---- */

class Saleswoman
{
public:

	int minMoves(vector<int> pos, vector<int> delta)
	{
		int ans = pos[0];
		int uni = 0;
		int left = 0;
		int startpos = 0;
		FOR(i, 0, pos.size()) {
			if (i > 0) {
				ans += pos[i] - pos[i - 1];
			}
			if (delta[i] >= 0)uni += delta[i];
			else {
				if (left == 0)startpos = pos[i];
				left += delta[i];
			}
			if (uni + left >= 0 && left < 0) {
				ans += (2 * (pos[i] - startpos));
				uni += left;
				left = 0;
			}

		}

		return ans;
	}
};

/*

struct Saleswoman {
  vector<int> pos;
  vector<int> delta;
  int minMoves(vector<int> _pos, vector<int> _delta) {
	pos = _pos, delta = _delta;
	return 0;
  }
};

*/

// CUT begin
ifstream data("Saleswoman.sample");

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

bool do_test(vector<int> pos, vector<int> delta, int __expected) {
	time_t startClock = clock();
	Saleswoman *instance = new Saleswoman();
	int __result = instance->minMoves(pos, delta);
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
		vector<int> pos;
		from_stream(pos);
		vector<int> delta;
		from_stream(delta);
		next_line();
		int __answer;
		from_stream(__answer);

		cases++;
		if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
			continue;

		cout << "  Testcase #" << cases - 1 << " ... ";
		if (do_test(pos, delta, __answer)) {
			passed++;
		}
	}
	if (mainProcess) {
		cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
		int T = time(NULL) - 1494158468;
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
		cout << "Saleswoman (1000 Points)" << endl << endl;
	}
	return run_test(mainProcess, cases, argv[0]);
}
// CUT end
