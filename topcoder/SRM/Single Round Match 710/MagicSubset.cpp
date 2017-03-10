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
typedef pair<ll,ll> pll;

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
/* -----  xtimex  Problem: SRM710 div2 easy / Link:  ----- */
/* ------���------

You are given n stones labeled from 0 to n-1. Each stone has an integer value: the value of stone i is value[i]. 
Note that some of those values may be negative or zero.
You would like to choose a subset of stones such that the sum of their values is maximized. 
(You are allowed to choose the empty subset. In that case, the sum of the values of the chosen stones is zero.)
This would be an easy problem, but there is a catch: the stone labeled 0 has magical properties.
 If you include this stone into your chosen subset, its entire sum is multiplied by -1. (The value of stone 0 still contributes to the sum. See Example 1.)
You are given the int[] value containing n elements: the values of your stones. 
Find and return the maximum sum of a subset of stones, given that the sum of any subset that contains stone 0 is negated.

-----��肱���܂�----- */
/* -----�����-----

���߂̐΂�������Ɛ��l�̕��������]����̂ł�����l�������ꍇ�������s���A�ő�l���Ƃ�΂悢�B

 ----��������܂�---- */

class MagicSubset 
{
    public:
	
    int findBest(vector<int> values) 
	{
		int ans=0;
		int psum=0;
		int msum=0;
		FOR(i,1,values.size()){
			if(values[i]>0)psum+=values[i];
			else msum+=values[i];
		}
		ans=max(psum,(-1)*(psum+values[0]));
		ans=max(ans,(-1)*(msum+values[0]));
		
        return ans;
    }
};

/*

struct MagicSubset {
  vector<int> values;
  int findBest(vector<int> _values) {
    values = _values;
    return 0;
  }
};

*/

// CUT begin
ifstream data("MagicSubset.sample");

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

bool do_test(vector<int> values, int __expected) {
    time_t startClock = clock();
    MagicSubset *instance = new MagicSubset();
    int __result = instance->findBest(values);
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
        vector<int> values;
        from_stream(values);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(values, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1489111230;
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
        cout << "MagicSubset (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
