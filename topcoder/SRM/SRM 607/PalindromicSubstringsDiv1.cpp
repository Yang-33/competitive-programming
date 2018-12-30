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

/* -----  xtimex  Problem: SRM 607 div1 easy  / Link:   ----- */
/* ------問題------

文字列が与えられる。これを与えられた順番で連結した際に得られる文字列をSとする。
Sにふくまれる'?'にそれぞれ等確率で'a'~'z'が割り振られる時、文字列Sの連続部分列が回文になる期待値を求めよ。

-----問題ここまで----- */
/* -----解説等-----

これ速く解けないの絶対にダメそう
回文の中央を決定し、そこから伸ばしていくとする。
この際、文字列が固定ならば回文の判定が可能。片側が'?'のときは1/26で一致し回文に、両側が'?'のとき回文にするためには片側に合わせればよく、26/26 * 1/26 = 1/26である。
あとはあり得る連続部分列についてこれらの確率を足せば求める期待値になる。

----解説ここまで---- */

class PalindromicSubstringsDiv1 
{
	public:
	
	double expectedPalindromes(vector<string> S1, vector<string> S2) 
	{
		string S = "";
		FOR(i, 0, SZ(S1)) {
			S += S1[i];
		}
		FOR(i, 0, SZ(S2)) {
			S += S2[i];
		}
		// S<=10^4
		// ?に埋めたときの期待値

		double ans = 0;
		// odd
		auto match = [](char a,char b) {
			if (a == '?' || b == '?')return 1 / 26.0; // 1だと思った(は?)
			else if (a == b)return 1.0;
			else return 0.0;
		};
		int N = SZ(S);

		FOR(i, 0, N) {
			double ret = 1.0;
			ans += ret;
			FOR(w, 1, N) {
				int L = i - w;
				int R = i + w;
#define IN(x) (0<=x)&&(x<N)
				if (IN(L) && IN(R)) {
					ret *= match(S[L],S[R]);
					ans += ret;
				}
			}
		}
		// even
		FOR(i, 0, N-1) {
			double ret = match(S[i], S[i + 1]);
			ans += ret;
			FOR(w, 1, N) {
				int L = i - w;
				int R = i + 1 + w;
				if (IN(L) && IN(R)) {
					ret *= match(S[L], S[R]);
					ans += ret;
				}
			}
		}

		return ans;
	}
};
// CUT begin
ifstream data("PalindromicSubstringsDiv1.sample");

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

bool double_equal(const double &a, const double &b) { return b==b && a==a && fabs(b - a) <= 1e-9 * max(1.0, fabs(a) ); }

bool do_test(vector<string> S1, vector<string> S2, double __expected) {
	time_t startClock = clock();
	PalindromicSubstringsDiv1 *instance = new PalindromicSubstringsDiv1();
	double __result = instance->expectedPalindromes(S1, S2);
	double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
	delete instance;

	if (double_equal(__expected, __result)) {
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
		vector<string> S1;
		from_stream(S1);
		vector<string> S2;
		from_stream(S2);
		next_line();
		double __answer;
		from_stream(__answer);

		cases++;
		if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
			continue;

		cout << "  Testcase #" << cases - 1 << " ... ";
		if ( do_test(S1, S2, __answer)) {
			passed++;
		}
	}
	if (mainProcess) {
		cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
		int T = time(NULL) - 1545962099;
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
		cout << "PalindromicSubstringsDiv1 (250 Points)" << endl << endl;
	}
	return run_test(mainProcess, cases, argv[0]);
}
// CUT end
