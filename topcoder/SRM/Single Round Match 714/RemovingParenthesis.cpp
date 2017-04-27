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
/* -----  xtimex  Problem: SRM714div2 midium / Link:  ----- */
/* ------問題------

正しい括弧列が与えられる。これの一番左端の'('と任意の')'を削除後に正しい括弧列を維持したままにする。
このような選択の組み合わせは全部で何通りあるか。

-----問題ここまで----- */
/* -----解説等-----

最初は((()))=3!,()()()...()=1 であるからdfsの容量で解けば行けそうと思った。.sampleがおかしくなっていたので正しいものを書いたのにもかかわらず
変な実装を深めてしまった。
下記のdfsも正しく動作するが、そんなことをしなくても左かっこの数を数えて、右かっこが現れたときにこれに対応可能な括弧の数、
を知ることができるのでこれの積をとっていけばよい。(div1でもこの解法で通る。)

 ----解説ここまで---- */

class RemovingParenthesis
{
public:
	int factorial(int NUM) {
		if (NUM <= 1)return 1;

		return NUM*factorial(NUM - 1);
	}

	string ka = "()()()()()()()()()()()()()()()()()()";

	int dfs(string S) {
		if (ka.substr(0,S.size()) == S)return 1;
		debug(S.size());
		bool f = true;
		int cnt = 0;
		FOR(i, 0, (int)S.size()/2) {
			if (S[i] == '(' && S[(int)S.size() - 1 - i] == ')') {
				cnt++;
				if (i == ((int)S.size() / 2) - 1 && f == true) {
				//	cout << "reurn" << endl;
					return factorial(cnt);
				}
			}
			else f = false;

		}
		int s = 0;
		int res = 0;
		int a;
		FOR(i, 0, S.size()) {
			if (S[i] == '(')s++;
			else if (S[i] == ')'&&s > 0) {
				//cout << S.substr(1, i-1) << "   " << S.substr(i + 1) << endl;
				//cin >> a;
				res += dfs(S.substr(1, i-1) + S.substr(i + 1));
				s--;
			}
			if (s == 0)break;
		}

		return res;
	}

	int countWays(string s)
	{
		int ans = 0;
		//ans = dfs(s);
		int nu = 0;
		ans = 1;
		FOR(i, 0, s.size()) {
			if (s[i] == '(')nu++;
			else {
				ans *= nu;
				nu--;
			}

		}


		return ans;
	}
};

/*

struct RemovingParenthesis {
  string s;
  int countWays(string _s) {
	s = _s;
	return 0;
  }
};

*/

// CUT begin
ifstream data("RemovingParenthesis.sample");

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

bool do_test(string s, int __expected) {
	time_t startClock = clock();
	RemovingParenthesis *instance = new RemovingParenthesis();
	int __result = instance->countWays(s);
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
		string s;
		from_stream(s);
		next_line();
		int __answer;
		from_stream(__answer);

		cases++;
		if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
			continue;

		cout << "  Testcase #" << cases - 1 << " ... ";
		if (do_test(s, __answer)) {
			passed++;
		}
	}
	if (mainProcess) {
		cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
		int T = time(NULL) - 1494155023;
		double PT = T / 60.0, TT = 75.0;
		cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
		cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
		cout << "RemovingParenthesis (500 Points)" << endl << endl;
	}
	return run_test(mainProcess, cases, argv[0]);
}
// CUT end
