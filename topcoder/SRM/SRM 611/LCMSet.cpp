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

/* -----  xtimex  Problem: SRM  611 div1 easy / Link:   ----- */
/* ------問題------

集合A,Bが与えられる。それぞれの集合の部分集合のLCMで生み出される値は一致するか?

-----問題ここまで----- */
/* -----解説等-----

いやこれ難しくないかN時間かかった
-- しばらく考えた --
結局、LCMで生み出される値は集合の元(げん)が元(もと)になっている。
集合Aを使って、集合Bの要素を表せないとすると、BにはAに含まれない元が存在することになる。
あとは元の確認をすれば良い。
これは、b[i] = p1^k1 * p2^k2 * ... * px^kxとなるような値をAの要素を使って作成可能か?という問いに答えればよく、
Aのうち、b[i]の約数を持つ値のLCMを取っていけば良い。←ここに気づくのにN時間かかった。
これをAからみたときとBからみたときの両方を見ればよい。

----解説ここまで---- */

class LCMSet
{
public:
	long long  gcd(long long  a, long long  b) { return b ? gcd(b, a%b) : a; }
	long long  lcm(long long  a, long long  b) { return a / gcd(a, b) * b; }



	string equal(vector<int> A, vector<int> B)
	{
		const string OK = "Equal";
		const string NG = "Not equal";

		// 元の一致をみたい

		auto f = [&](int x, const VI& a) {
			int val = 1;
			FOR(i, 0, SZ(a)) {
				if (x%a[i] == 0) {
					val = lcm(val, a[i]);
				}
			}
			return val == x;
		};

		int ok = 1;
		FOR(i, 0, SZ(A)) {
			ok &= f(A[i], B);
		}
		FOR(i, 0, SZ(B)) {
			ok &= f(B[i], A);
		}

		return (ok ? OK : NG);
	}
};


// CUT begin
ifstream data("LCMSet.sample");

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

bool do_test(vector<int> A, vector<int> B, string __expected) {
	time_t startClock = clock();
	LCMSet *instance = new LCMSet();
	string __result = instance->equal(A, B);
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
		vector<int> A;
		from_stream(A);
		vector<int> B;
		from_stream(B);
		next_line();
		string __answer;
		from_stream(__answer);

		cases++;
		if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
			continue;

		cout << "  Testcase #" << cases - 1 << " ... ";
		if (do_test(A, B, __answer)) {
			passed++;
		}
	}
	if (mainProcess) {
		cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
		int T = time(NULL) - 1545962146;
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
		cout << "LCMSet (250 Points)" << endl << endl;
	}
	return run_test(mainProcess, cases, argv[0]);
}
// CUT end
