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

/* -----  xtimex  Problem: SRM 608 div1 easy / Link:   ----- */
/* ------問題------

N個の箱の中にキャンディが入っている。今合計でC個あることがわかっているが、それぞれの箱に入っている数がlow[i]~high[i]個であることしか分からない。
箱の部分集合を選択した時、最悪の場合でもキャンディがX個ほしい。この部分集合の選択の仕方のうち、箱の最小数を求めよ。

-----問題ここまで----- */
/* -----解説等-----

全体の集合をSとする。
1. なるべく最低個数が多いものを選択するのが良い。
集合Tを選択した時、残りの箱に最大数キャンディが入っているとしたとき、選択したキャンディの数は、max(C - \sum _S \ _T high ,\sum _T low)である。
これを見ればよく、low,highを組にして降順ソートすれば良い。

2. 上記のS \ Tについて、\sum highが少なければ選択した箱にはキャンディがたくさん入っている。
同様の式について、high,lowを組にして昇順ソートすれば良い。

1,2のどちらかに答えは含まれるので、これを両方見れば良い。
O(NlogN)


----解説ここまで---- */

class MysticAndCandies
{
public:

	int minBoxes(int C, int X, vector<int> low, vector<int> high)
	{
		int N = SZ(low);
		int ans = INF;
		{
			vector<pair<PLL, int>>a;
			FOR(i, 0, N) {
				a.push_back({ PLL(low[i],high[i]), i });
			}
			RSORT(a);
			VL ysum(N + 1, 0);
			FOR(i, 0, N) {
				int idx = a[N - i - 1].second;
				ysum[i + 1] += ysum[i] + high[idx];
			}
			LL xs = 0;
			FOR(i, 0, N) {
				xs += a[i].first.first;
				LL sub = max(C - ysum[N - i - 1], xs);
				if (sub >= X) {
					ans = min(ans, i + 1);
				}
			}
		}
		{
			vector<pair<PLL, int>>b;
			FOR(i, 0, N) {
				b.push_back({ PLL(high[i],low[i]), i });
			}
			SORT(b);
			VL xsum(N + 1, 0);
			FOR(i, 0, N) {
				int idx = b[N - i - 1].second;
				xsum[i + 1] = xsum[i] + low[idx];
			}
			LL ys = 0;
			FOR(i, 0, N) {
				ys += b[i].first.first;
				LL sub = max(C - ys, xsum[N - i - 1]);
				if (sub >= X) {
					ans = min(ans, N - (i + 1));
				}
			}
		}
		return  ans;
	}
};



// CUT begin
ifstream data("MysticAndCandies.sample");

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

bool do_test(int C, int X, vector<int> low, vector<int> high, int __expected) {
	time_t startClock = clock();
	MysticAndCandies *instance = new MysticAndCandies();
	int __result = instance->minBoxes(C, X, low, high);
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
		int C;
		from_stream(C);
		int X;
		from_stream(X);
		vector<int> low;
		from_stream(low);
		vector<int> high;
		from_stream(high);
		next_line();
		int __answer;
		from_stream(__answer);

		cases++;
		if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
			continue;

		cout << "  Testcase #" << cases - 1 << " ... ";
		if (do_test(C, X, low, high, __answer)) {
			passed++;
		}
	}
	if (mainProcess) {
		cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
		int T = time(NULL) - 1545962109;
		double PT = T / 60.0, TT = 75.0;
		cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
		cout << "Score  : " << 300 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
		cout << "MysticAndCandies (300 Points)" << endl << endl;
	}
	return run_test(mainProcess, cases, argv[0]);
}
// CUT end
