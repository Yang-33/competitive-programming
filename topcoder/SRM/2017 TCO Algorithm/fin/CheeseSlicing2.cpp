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
#define debug(x) cout<<#x<<": "<<x<<endl
/* -----  xtimex  Problem: 2017 TCO Algorithm Round A 500pt / Link: ‚È‚µ ----- */
/* ------–â‘è------

’¼•û‘Ì(A,B,C)‚ª—^‚¦‚ç‚ê‚é‚Ì‚Å‚±‚ê‚ð”CˆÓ‚Ì®”“_‚ÅØ’f‚µAˆê”Ô’Z‚¢•Ó‚ð‚‚³‚Æ‚µ‚Ä
’ê–Ê‚Ì–ÊÏ‚ðÅ‘å‰»‚·‚éB
‚½‚¾‚µ‚‚³‚ÍSˆÈã‚Å‚È‚¯‚ê‚Î‚È‚ç‚È‚¢B‚»‚ê–¢–ž‚Ì‚à‚Ì‚Í‚O‚Æ‚Ý‚È‚·B

-----–â‘è‚±‚±‚Ü‚Å----- */
/* -----‰ðà“™-----

DP‰ðBƒƒ‚‰»Ä‹AB
Å“K‚ÈØ‚è•û‚ª‚í‚©‚ç‚È‚¢‚Æ‚«‚É‚Í‘S’Tõ‚·‚éB
dp[x][y][z] :=‚±‚Ì’¼•û‘Ì‚Å“¾‚ç‚ê‚éÅ‘å’l

 ----‰ðà‚±‚±‚Ü‚Å---- */

class CheeseSlicing
{
public:
#define N 110
    int f[N][N][N];
    int w;
    int ff(int x, int y, int z) {
        if (x < y)swap(x, y);
        if (x < z)swap(x, z);
        if (y < z)swap(z, y);

        if (f[x][y][z] != -1)return f[x][y][z];
        if (z < w)return 0;
        int s = x*y;
        for (int i = w; i <= x - i; i++)
            s = max(s, ff(i, y, z) + ff(x - i, y, z));
        for (int i = w; i <= y - i; i++)
            s = max(s, ff(x, i, z) + ff(x, y - i, z));
        for (int i = w; i <= z - i; i++)
            s = max(s, ff(x, y, i) + ff(x, y, z - i));
        return f[x][y][z] = s;
    }
    int totalArea(int A, int B, int C, int S)
    {
        w = S;
        memset(f, -1, sizeof(f));
        return ff(A, B, C);

    }
};

/*

struct CheeseSlicing {
  int A;
  int B;
  int C;
  int S;
  int totalArea(int _A, int _B, int _C, int _S) {
    A = _A, B = _B, C = _C, S = _S;
    return 0;
  }
};

*/

// CUT begin
ifstream data("CheeseSlicing.sample");

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

bool do_test(int A, int B, int C, int S, int __expected) {
    time_t startClock = clock();
    CheeseSlicing *instance = new CheeseSlicing();
    int __result = instance->totalArea(A, B, C, S);
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
        int A;
        from_stream(A);
        int B;
        from_stream(B);
        int C;
        from_stream(C);
        int S;
        from_stream(S);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if (do_test(A, B, C, S, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1491063828;
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
        cout << "CheeseSlicing (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
