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

/* -----  xtimex  Problem: SRM 616 div1 easy  / Link:   ----- */
/* ------問題------

アラームが設定されている。
時刻start[i]から周期period[i]で強さvolume[i]の音量がなる。
今の睡眠度をSとして、1秒経過すると睡眠度がD増加し、アラームの音量の総和だけ減少する。
S<=0となると起床する。
いつか起床できるような最大のSを求めよ。
もしどのような値でも起床可能なら、-1を出力せよ。

-----問題ここまで----- */
/* -----解説等-----

周期が2530なのでこれでシミュレーションする。
2周期みたとき、最小値が減少しているならば必ず起きれる。
もしそうでないなら、最小値の値が最大のSに対応する。

----解説ここまで---- */

class WakingUp
{
public:

	int maxSleepiness(vector<int> period,
		vector<int> start, vector<int> volume,
		int D)
	{
		int N = SZ(period);
		VL alerm(2521, 0);
		FOR(i, 0, N) {
			int t = start[i];
			while (t < 2521) {
				alerm[t] += volume[i];
				t += period[i];
			}
		}
		auto f = [&](int s, int t,int &S) {
			int Min = 0;
			FOR(i, s, t) {
				S += D;
				S -= alerm[(i <= 2520 ? i : i - 2520)];
				Min = min(Min, S);
			}

			return  Min;
		};

		int S = 0;
		int lowestpre = f(1, 2520 + 1,S);
		int lowestsuf = f(2520 + 1, 2520 * 2 + 1,S);
		if (lowestpre > lowestsuf) {
			return -1;
		}
		else {
			return -lowestpre;
		}
	}
};

// CUT begin
ifstream data("WakingUp.sample");

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

bool do_test(vector<int> period, vector<int> start, vector<int> volume, int D, int __expected) {
	time_t startClock = clock();
	WakingUp *instance = new WakingUp();
	int __result = instance->maxSleepiness(period, start, volume, D);
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
		vector<int> period;
		from_stream(period);
		vector<int> start;
		from_stream(start);
		vector<int> volume;
		from_stream(volume);
		int D;
		from_stream(D);
		next_line();
		int __answer;
		from_stream(__answer);

		cases++;
		if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
			continue;

		cout << "  Testcase #" << cases - 1 << " ... ";
		if (do_test(period, start, volume, D, __answer)) {
			passed++;
		}
	}
	if (mainProcess) {
		cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
		int T = time(NULL) - 1545962221;
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
		cout << "WakingUp (250 Points)" << endl << endl;
	}
	return run_test(mainProcess, cases, argv[0]);
}
// CUT end
