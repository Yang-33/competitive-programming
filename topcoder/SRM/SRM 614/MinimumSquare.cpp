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

/* -----  xtimex  Problem: SRM 614 div1 easy  / Link:   ----- */
/* ------問題------

二次元座標上に点がN点ある。
境界より真に内側にK点以上含まれるような長方形の選択のうち、最小の長方形面積は?

-----問題ここまで----- */
/* -----解説等-----

幅を二分探索する。
幅Wに対して、適当な座標を決めた時、この内側の点を数えればよく、これはO(N^3)でできる。
全体でO(N^3logMax)で解ける。

----解説ここまで---- */

class MinimumSquare 
{
	public:
	
	long long minArea(vector<int> x, vector<int> y, int K) 
	{

		// 内部の累積和+座標圧縮でO(N^2)
		int N = SZ(x);
		auto f = [&](LL ran) {
			FOR(i, 0, N) {
				FOR(j, 0, N) {
					LL x1 = x[i] - 1, x2 = x[i] - 1 + ran;
					LL y1 = y[j] - 1, y2 = y[j] - 1 + ran;
					int cnt = 0;
					FOR(k, 0, N) {
						if (x1 < x[k] && x[k] < x2&&y1 < y[k] && y[k] < y2)cnt++;
					}
					if (cnt >= K)return true;
				}
			}

			return false;
		};
		LL L = 0, R = LINF;
		while (R - L > 1) {
			LL mid = (L + R) / 2;
			if (f(mid)) {
				R = mid;
			}
			else {
				L = mid;
			}
		}

		return R*R;
	}
};



// CUT begin
ifstream data("MinimumSquare.sample");

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

bool do_test(vector<int> x, vector<int> y, int K, long long __expected) {
	time_t startClock = clock();
	MinimumSquare *instance = new MinimumSquare();
	long long __result = instance->minArea(x, y, K);
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
		vector<int> x;
		from_stream(x);
		vector<int> y;
		from_stream(y);
		int K;
		from_stream(K);
		next_line();
		long long __answer;
		from_stream(__answer);

		cases++;
		if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
			continue;

		cout << "  Testcase #" << cases - 1 << " ... ";
		if ( do_test(x, y, K, __answer)) {
			passed++;
		}
	}
	if (mainProcess) {
		cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
		int T = time(NULL) - 1545962191;
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
		cout << "MinimumSquare (250 Points)" << endl << endl;
	}
	return run_test(mainProcess, cases, argv[0]);
}
// CUT end
