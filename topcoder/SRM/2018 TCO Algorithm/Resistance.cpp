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
#include <bitset>
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
#define REP(i, s, e) for (int(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (int(i) = (s); (i) > (e); (i)--)
#define debug(x) cerr << #x << ": " << x << endl
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

#define foreach(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); itr++)

/* -----  2017/10/02  Problem: SRM  / Link:   ----- */
/* ------–â‘è------

-----–â‘è‚±‚±‚Ü‚Å----- */
/* -----‰ðà“™-----

----‰ðà‚±‚±‚Ü‚Å---- */


int popcount2(int x) {
	int ret = 0;
	while (x) {
		x &= x - 1;
		++ret;
	}
	return ret;
}

class Resistance 
{
    public:
	
    vector<double> spyProbability(int P, int S, vector<string> missions) 
	{
		int N = (int)missions.size();
		int okcnt = 0;
		vector<int> ppl(P,0);
		REP(bit, 0, 1 << P) {
			if (popcount2(bit) != S)continue;
			vector<int>a;
			REP(i, 0, P) {
				if (bit&(1 << i)) {
					a.push_back(i);
				}
			}
			int F = 0;
			REP(i, 0, N) {
				if (missions[i][0] == 'F')F++;
			}

			int flag = 0;
			REP(i, 0, N) {
				if (missions[i][0] == 'F') {
					int f = 0;
					REP(j, 0, SZ(a)) {
						if (missions[i][a[j] + 1] == '1')f = 1;
					}
					if (!f)flag = 0;
					else flag++;
				}
			}
			if (flag==F) {
				okcnt++;
				REP(j, 0, SZ(a)) {
					ppl[a[j]]++;
				}
			}
		}
		if (okcnt) {
			vector<double>ret(P,0);
			REP(i, 0, P) {
				ret[i] = 1.0*ppl[i] / okcnt;
			}
			return ret;
		}
		else  return vector<double>();
    }
};

/*

struct Resistance {
  int P;
  int S;
  vector<string> missions;
  vector<double> spyProbability(int _P, int _S, vector<string> _missions) {
    P = _P, S = _S, missions = _missions;
    return vector<double>();
  }
};

*/

// CUT begin
ifstream data("Resistance.sample");

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

bool double_equal(const double &a, const double &b) { return b==b && a==a && fabs(b - a) <= 1e-9 * max(1.0, fabs(a) ); }

bool double_vector_equal (const vector<double> &expected, const vector<double> &received) {
    if (expected.size() != received.size()) return false;
    int n = expected.size();
    for (int i = 0; i < n; ++i)
        if (!double_equal(expected[i], received[i])) return false;
    return true;
}

bool do_test(int P, int S, vector<string> missions, vector<double> __expected) {
    time_t startClock = clock();
    Resistance *instance = new Resistance();
    vector<double> __result = instance->spyProbability(P, S, missions);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (double_vector_equal(__expected, __result)) {
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
        int P;
        from_stream(P);
        int S;
        from_stream(S);
        vector<string> missions;
        from_stream(missions);
        next_line();
        vector<double> __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(P, S, missions, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1524326873;
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
        if ( string(argv[i]) == "-") {
            mainProcess = false;
        } else {
            cases.insert(atoi(argv[i]));
        }
    }
    if (mainProcess) {
        cout << "Resistance (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
