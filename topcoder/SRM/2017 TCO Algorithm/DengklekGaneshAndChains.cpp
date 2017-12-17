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
/* -----  xtimex  Problem:  / Link:  ----- */
/* ------–â‘è------

-----–â‘è‚±‚±‚Ü‚Å----- */
/* -----‰ðà“™-----

 ----‰ðà‚±‚±‚Ü‚Å---- */

class DengklekGaneshAndChains 
{
    public:
	
    string getBestChains(vector<string> chains, vector<int> lengths) 
	{
		string ans = "";
		set<int>s;
		FOR(j, 0, chains.size()) {
			chains[j] = chains[j] + chains[j];
		}

		FOR(i, 0, lengths.size()) {
			int num = lengths[i];
			vector<pair<string, int>>v;
			FOR(j, 0, chains.size()) {
				if (s.count(j) == 1)continue;
				FOR(k, 0, chains[j].size() - (num - 1))
					v.push_back(mp(chains[j].substr(k,num),j));
			}
			sort(v.begin(), v.end());
			reverse(v.begin(), v.end());
			vector<int>p; p.push_back(v[0].second);
			int id = 0;
			while (v[id].first == v[id+1].first) {
				p.push_back(v[id + 1].second);
				id++;
			}
			sort(p.begin(), p.end());
			p.erase(unique(p.begin(), p.end()), p.end());
			FOR(j, 0, p.size()) {



			}

		}


        return ans;
    }
};

/*

struct DengklekGaneshAndChains {
  vector<string> chains;
  vector<int> lengths;
  string getBestChains(vector<string> _chains, vector<int> _lengths) {
    chains = _chains, lengths = _lengths;
    return "";
  }
};

*/

// CUT begin
ifstream data("DengklekGaneshAndChains.sample");

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

bool do_test(vector<string> chains, vector<int> lengths, string __expected) {
    time_t startClock = clock();
    DengklekGaneshAndChains *instance = new DengklekGaneshAndChains();
    string __result = instance->getBestChains(chains, lengths);
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
        vector<string> chains;
        from_stream(chains);
        vector<int> lengths;
        from_stream(lengths);
        next_line();
        string __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(chains, lengths, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1499529613;
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
        if ( string(argv[i]) == "-") {
            mainProcess = false;
        } else {
            cases.insert(atoi(argv[i]));
        }
    }
    if (mainProcess) {
        cout << "DengklekGaneshAndChains (300 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
