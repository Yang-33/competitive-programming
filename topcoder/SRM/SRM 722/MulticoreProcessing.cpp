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

/* -----  2017/10/02  Problem: SRM 722 div1 MulticoreProcessing / Link:   ----- */
/* ------問題------

div2 hardの,各コアが10^9まであるバージョン。
最小化せよ。

-----問題ここまで----- */
/* -----解説等-----

div2の時点で凸関数が見えていたのでこれをやる
精度が要求されているのでlong doubleでお祈りをする
探索範囲に注意

----解説ここまで---- */

class MulticoreProcessing
{
public:

	LL jl,cP;
	VI sp;
	VI crs;
	long long fastestTime(long long jobLength, int corePenalty, vector<int> speed, vector<int> cores)
	{
		jl = jobLength;
		cP = corePenalty;
		sp = speed;
		crs = cores;
		//
		LL ans = LLONG_MAX;

		int N = SZ(speed);
		FOR(i, 0, N) {
			LL L = 1; LL R = cores[i];
			while (R - L > 10) {
				LL x1 = (2 * L + R) / 3;
				LL x2 = (2*R+L) / 3;
				long double y1 = f(x1,i);
				long double y2 = f(x2,i);
				if (y1 > y2)L = x1;
				else R = x2;
			}
			LL ret = LLONG_MAX;
			FOR(k, max(1LL, L-2), min(R+1, (LL)cores[i] + 1)) {
				ret = min(ret, (LL)ceil(f(k,i)));
			}
			ans = min(ans, ret);
		}

		return ans;
	}

	long double f(LL x,int i) {//i を選択しコアをx個使う
		if (crs[i] < x)return LLONG_MAX;
		long double res = (long double)jl/((long double)x*sp[i])+(x-1)*cP;
		return res;
	}
};

/*

struct MulticoreProcessing {
  long long jobLength;
  int corePenalty;
  vector<int> speed;
  vector<int> cores;
  long long fastestTime(long long _jobLength, int _corePenalty, vector<int> _speed, vector<int> _cores) {
	jobLength = _jobLength, corePenalty = _corePenalty, speed = _speed, cores = _cores;
	return 0;
  }
};

*/

// CUT begin
ifstream data("MulticoreProcessing.sample");

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

bool do_test(long long jobLength, int corePenalty, vector<int> speed, vector<int> cores, long long __expected) {
	time_t startClock = clock();
	MulticoreProcessing *instance = new MulticoreProcessing();
	long long __result = instance->fastestTime(jobLength, corePenalty, speed, cores);
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
		long long jobLength;
		from_stream(jobLength);
		int corePenalty;
		from_stream(corePenalty);
		vector<int> speed;
		from_stream(speed);
		vector<int> cores;
		from_stream(cores);
		next_line();
		long long __answer;
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
		int T = time(NULL) - 1507815813;
		double PT = T / 60.0, TT = 75.0;
		cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
		cout << "Score  : " << 350 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
		cout << "MulticoreProcessing (350 Points)" << endl << endl;
	}
	return run_test(mainProcess, cases, argv[0]);
}
// CUT end
