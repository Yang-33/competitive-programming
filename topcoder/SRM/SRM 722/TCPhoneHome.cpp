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

/* -----  2017/10/02  Problem: SRM div1 easy TCPhoneHome / Link:   ----- */
/* ------問題------

digit桁の電話番号のうち、prefixが指定されたものは使ってはいけない。
有効な電話番号は何個存在するか。
prefixは重複するものも数えられる。

-----問題ここまで----- */
/* -----解説等-----

例えば、123,14,12,19,1923289はprefixが1のものにすべて含まれる。
これは全て1に属していると見れるので、なんかtrieみたいな構造をもてばいいことになる。
更に少し考えると、s[i].len() ≧ s[j].len() な(i,j)に対して、s[i].substr(0,s[j].len())とs[j]が
同じならばs[i]はs[j]に含まれていることになるので、これをやればサクッと実装できる。

----解説ここまで---- */

class TCPhoneHome 
{
    public:
	
    long long validNumbers(int digits, vector<string> specialPrefixes) 
	{
		int N = SZ(specialPrefixes);
		LL sum = pow(10,digits);
		int ok[51];
		FOR(i, 0, 51)ok[i] = 1;

		FOR(i, 0, N) {
			FOR(j, 0, N) {
				int js = specialPrefixes[j].length();
				int is = specialPrefixes[i].length();
				if (i == j)continue;
				if (is<js)continue;
				if (specialPrefixes[i].substr(0, js) == specialPrefixes[j])ok[i] = 0;
			}
		}

		FOR(i, 0, N) {
			if (ok[i]) {
				int is = specialPrefixes[i].length();
				sum -= (LL)pow(10, digits - is);
			}
		}

        return sum;
    }
};

/*

struct TCPhoneHome {
  int digits;
  vector<string> specialPrefixes;
  long long validNumbers(int _digits, vector<string> _specialPrefixes) {
    digits = _digits, specialPrefixes = _specialPrefixes;
    return 0;
  }
};

*/

// CUT begin
ifstream data("TCPhoneHome.sample");

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

bool do_test(int digits, vector<string> specialPrefixes, long long __expected) {
    time_t startClock = clock();
    TCPhoneHome *instance = new TCPhoneHome();
    long long __result = instance->validNumbers(digits, specialPrefixes);
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
        int digits;
        from_stream(digits);
        vector<string> specialPrefixes;
        from_stream(specialPrefixes);
        next_line();
        long long __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(digits, specialPrefixes, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1507815201;
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
        cout << "TCPhoneHome (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
