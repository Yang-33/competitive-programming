#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <typeinfo>
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
class AverageVarianceSubset {
	double bunsan(vector<int>v, int l, int r) {
		cout << l << " " << r << endl;
		if (r >= (int)v.size() - 1)r = (int)v.size() - 1;
		if (l >= r)return 0;
		double sum = 0;
		FOR(i, l, r+1 ) {
			sum += v[i];
		}
		sum /= (r - l+1);
		double d = 0;
		FOR(i, l, r +1) {
			d += v[i] * v[i];
		}
		d /= (r - l +1);
		cout << d - sum*sum << endl;
		return d - sum*sum;
	}

    public:
    double average(vector<int> s, int R) {
		double ans = 0;
		int l = 0, r = 0;
		int cnt = 0;

		while (l != (int)s.size()) {
			if (r >= (int)s.size()-1) {
				cout << "e" << endl;
				r = s.size() - 1;
				int d = 0;
				d = s[r] - s[l];
				if (d <= R) {

					FOR(i, l, r )ans += bunsan(s, l, i + 1), cnt++;
					l++;
				}
				else {
					FOR(i, l, r -1)ans += bunsan(s, l, i + 1), cnt++;

					l++;
				}
				continue;
			}
			int d = 0;
			d = s[r] - s[l];
			if (d <= R) {
				r++; continue;
			}
			else {
				cout << "plus" << endl;
				FOR(i, l, r-1)ans += bunsan(s, l, i+1),cnt++;
				l++;
			}
		}

        return ans/(cnt+s.size());
    }
};

// CUT begin
ifstream data("AverageVarianceSubset.sample");

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

bool do_test(vector<int> s, int R, double __expected) {
    time_t startClock = clock();
    AverageVarianceSubset *instance = new AverageVarianceSubset();
    double __result = instance->average(s, R);
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
        vector<int> s;
        from_stream(s);
        int R;
        from_stream(R);
        next_line();
        double __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(s, R, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1492516354;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 1000 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "AverageVarianceSubset (1000 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
