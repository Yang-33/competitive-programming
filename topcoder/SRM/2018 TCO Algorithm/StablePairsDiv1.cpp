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

/* -----  2017/10/02  Problem: SRM  / Link:   ----- */
/* ------問題------
数列を真に単調増加に構成する。ただし、
(i+3)+(i+2) - {(i+1)+(i)} = c, 
(2*k) <=N , 1<=(1)を満たす。

-----問題ここまで----- */
/* -----解説等-----


よしなにやる(c < 4 && k>1で落とした…)

----解説ここまで---- */

class StablePairsDiv1
{
public:

	vector<int> findMaxStablePairs(int n, int c, int k)
	{

		int f = 1;
		VI res;
		int mode = (1 + c) % 2;
		res.push_back(n);
		res.push_back(n - 1);
		int a = (c+1) / 2;
		int b = c - a;
		FOR(i, 1, k) {
			if (mode == 0) {
				res.push_back(res[2 * (i - 1)]-b);
				res.push_back(res[2 * (i - 1)+1 ]-a);
				swap(a, b);
				/*res.push_back(n - i*(c / 2));
				res.push_back(n - 1 - i*((c + 1) / 2));*/
			}
			else {
				res.push_back(n - i*((c) / 2));
				res.push_back(n - 1 - i*((c) / 2));
			}
		}
		for (int i = 3; i < 2 * k; i += 2) {// 下を上げたい
			int high = res[i - 2];
			int h = res[i - 1], l = res[i];
			while (h - 1 < high && h - 1 > l + 1) {
				h--, l++;
			}
			res[i] = l;
			res[i - 1] = h;

		}		
		FOR(i, 0, SZ(res)) {
			if (res[i] <= 0)f = 0;
		}
		FOR(i, 1, SZ(res)) {
			if (res[i] >= res[i - 1])f = 0;
		}

		if (c < 4 && k>1)f = 0;
		if (f) {
			reverse(ALL(res));
			return res;
		}
		else return vector<int>();
	}
};

/*

struct StablePairsDiv1 {
  int n;
  int c;
  int k;
  vector<int> findMaxStablePairs(int _n, int _c, int _k) {
	n = _n, c = _c, k = _k;
	return vector<int>();
  }
};

*/

// CUT begin
ifstream data("StablePairsDiv1.sample");

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

template <typename T> string to_string(vector<T> ts) {
	stringstream s;
	s << "[ ";
	for (int i = 0; i < ts.size(); ++i) {
		if (i > 0) s << ", ";
		s << to_string(ts[i]);
	}
	s << " ]";
	return s.str();
}

bool do_test(int n, int c, int k, vector<int> __expected) {
	time_t startClock = clock();
	StablePairsDiv1 *instance = new StablePairsDiv1();
	vector<int> __result = instance->findMaxStablePairs(n, c, k);
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
		int n;
		from_stream(n);
		int c;
		from_stream(c);
		int k;
		from_stream(k);
		next_line();
		vector<int> __answer;
		from_stream(__answer);

		cases++;
		if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
			continue;

		cout << "  Testcase #" << cases - 1 << " ... ";
		if (do_test(n, c, k, __answer)) {
			passed++;
		}
	}
	if (mainProcess) {
		cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
		int T = time(NULL) - 1525345801;
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
		cout << "StablePairsDiv1 (600 Points)" << endl << endl;
	}
	return run_test(mainProcess, cases, argv[0]);
}
// CUT end
