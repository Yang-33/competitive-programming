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
#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
/* -----  xtimex  Problem: 2017 TCO Algorithm Round A 250pt / Link: なし ----- */
/* ------問題------

強さを並べたskillsが与えられる。
負けた人は待ち行列の後ろから並ぶ。
ただしN回勝ったらその人も後ろに並ぶ。
K回目の勝者と敗者を返り値(Loser,Winer)にせよ。

-----問題ここまで----- */
/* -----解説等-----

シュミレーションをする。
ほかの回答者にはpositionをとって列を右に移動していく（勝者を右にずらす）解法があった。
Challenge Phase 用の撃墜ケースを見つけたのに取られてしまったので
休憩Phaseでその準備をしたい。

 ----解説ここまで---- */

class PingPongQueue
{
public:

    vector<int> whoPlaysNext(vector<int> skills, int N, int K)
    {
        queue<int>q;
        vector<int >ans;
        FOR(i, 0, skills.size()) {
            q.push(skills[i]);
        }
        int k = 0;
        int a = q.front(); q.pop();
        int b = q.front(); q.pop();
        if (b > a)swap(a, b);
        int cnt = 0;
        for (;;) {
            if (a > b) {
                q.push(b);
                cnt++;
            }
            else {
                swap(a, b);
                q.push(b);
                cnt=1;
            }

            k++;
            if (k == K)break;

            if (cnt == N) {
                q.push(a);
                a = q.front();
                q.pop();
                cnt = 0;
            }

            b = q.front(); q.pop();

        }
        if (a < b)swap(a, b);
        ans.push_back(b);
        ans.push_back(a);
        return ans;
    }
};

/*

struct PingPongQueue {
  vector<int> skills;
  int N;
  int K;
  vector<int> whoPlaysNext(vector<int> _skills, int _N, int _K) {
    skills = _skills, N = _N, K = _K;
    return vector<int>();
  }
};

*/

// CUT begin
ifstream data("PingPongQueue.sample");

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

bool do_test(vector<int> skills, int N, int K, vector<int> __expected) {
    time_t startClock = clock();
    PingPongQueue *instance = new PingPongQueue();
    vector<int> __result = instance->whoPlaysNext(skills, N, K);
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
        vector<int> skills;
        from_stream(skills);
        int N;
        from_stream(N);
        int K;
        from_stream(K);
        next_line();
        vector<int> __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if (do_test(skills, N, K, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1491062427;
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
        cout << "PingPongQueue (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
