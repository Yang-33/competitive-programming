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

/* -----  xtimex  Problem: SRM 604 div1 easy  / Link:   ----- */
/* ------問題------

3^kの移動のみで (k=0,1,2,...)
(0,0)から(x,y)に移動できるか?

-----問題ここまで----- */
/* -----解説等-----

まず対称性から絶対値のみを考えても問題ない。
どちらかに+-1が加算され、どちらかに+-3が加算され...を考えると、
値の下から行動を決めていけば良いことになる。
これは3の倍数で下の値が(0,[1or2])or([1or2],0)のとき正しい動きが可能と言える。
1のときは加算、2のときは減算に対応する。
マイナス3^kの加算は、3^(k+1)-3^kみたいに見れば良い。
値を1/3すると問題のサイズも1/3になる。この繰り返しで矛盾を見れば判定ができる。
O(log Max(x,y))

----解説ここまで---- */

class PowerOfThree
{
public:

	string ableToGet(int x, int y)
	{
		x = abs(x);
		y = abs(y);
		const string OK = "Possible";
		const string NO = "Impossible";
		while (x != 0 || y != 0) {
			if (x % 3 == 0 && y % 3 == 0) {
				return NO;
			}
			if (x % 3 == 0) {// (0,[1,2])
				x = x / 3;
				y = (y + 1) / 3;
			}
			else if (y % 3 == 0) { // ([1,2],0)
				x = (x + 1) / 3;
				y = y / 3;
			}
			else {// ([1,2],[1,2])
				return NO;
			}
		}



		return OK;
	}
};

/*

struct PowerOfThree {
  int x;
  int y;
  string ableToGet(int _x, int _y) {
	x = _x, y = _y;
	return "";
  }
};

*/

// CUT begin
ifstream data("PowerOfThree.sample");

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

bool do_test(int x, int y, string __expected) {
	time_t startClock = clock();
	PowerOfThree *instance = new PowerOfThree();
	string __result = instance->ableToGet(x, y);
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
		int x;
		from_stream(x);
		int y;
		from_stream(y);
		next_line();
		string __answer;
		from_stream(__answer);

		cases++;
		if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
			continue;

		cout << "  Testcase #" << cases - 1 << " ... ";
		if (do_test(x, y, __answer)) {
			passed++;
		}
	}
	if (mainProcess) {
		cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
		int T = time(NULL) - 1545962061;
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
		cout << "PowerOfThree (250 Points)" << endl << endl;
	}
	return run_test(mainProcess, cases, argv[0]);
}
// CUT end
