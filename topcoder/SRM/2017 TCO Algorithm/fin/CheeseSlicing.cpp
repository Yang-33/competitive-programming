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
#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
#define debug(x) cout<<#x<<": "<<x<<endl

/* -----  xtimex  Problem: 2017 TCO Algorithm Round A 500pt / Link: �Ȃ� ----- */
/* ------���------

������(A,B,C)���^������̂ł����C�ӂ̐����_�Őؒf���A��ԒZ���ӂ������Ƃ���
��ʂ̖ʐς��ő剻����B
������������S�ȏ�łȂ���΂Ȃ�Ȃ��B���ꖢ���̂��̂͂O�Ƃ݂Ȃ��B

-----��肱���܂�----- */
/* -----�����-----

�𒼂Ɉ�ԑ傫�ȕӂ���S�ŕ�������B
make_pair(Z-S)�݂����Ȃ��Ƃ����Ă��Đh�������B
���ƍő�l�ƍŏ��l��x,y,z����݂���̂Ɏ��s���Ă��Ēʂ�Ȃ������B
�T����ɒʂ��܂����Bdp����葬���B

 ----��������܂�---- */

class CheeseSlicing
{
public:

    int totalArea(int A, int B, int C, int S)
    {
        queue<pair<int, pair<int, int>>>q;
        q.push(make_pair(A, make_pair(B, C)));
        vector<pair<int, pair<int, int>>>v;
        while (!q.empty()) {
            pair<int, pair<int, int>>s = q.front(); q.pop();
            int x = s.first;
            int y = s.second.first;
            int z = s.second.second;
            if (x == S || y == S || z == S)v.push_back(s);
            else if (x < 2 * S&&y < 2 * S&&z < 2 * S) {
                v.push_back(s);
            }
            else {
                int x = s.first;
                int y = s.second.first;
                int z = s.second.second;
                if (y > z)swap(z, y);
                if (x > y)swap(x, y);
                if (y > z)swap(z, y);
                if (z >= 2 * S) {
                    int t = z / S;
                    FOR(j, 0, t - 1) {
                        q.push(make_pair(S, make_pair(y, x)));
                        z -= S;

                    }
                    q.push(make_pair(z, make_pair(y, x)));

                }

            }


        }
        int ans = 0;
        FOR(i, 0, v.size()) {
            pair<int, pair<int, int>>s = v[i];
            int x = s.first;
            int y = s.second.first;
            int z = s.second.second;//x min
            if (y > z)swap(z, y);
            if (x > y)swap(x, y);
            if (x < S)continue;
            ans += y*z;
        }
        return ans;
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
