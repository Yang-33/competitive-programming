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
/*const LL MOD = 1000000007;*/                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

#define foreach(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); itr++)

/* -----  2017/10/02  Problem: SRM  / Link:   ----- */
/* ------問題------

N要素のL,Rが与えられる。
すべてのiについてL [i]≦A [i]≦ R [i]となるように 、厳密に増加する整数列A [0] <A [1] <... <A [n-1]の数を求めよ。
mod = 998244353とする。

-----問題ここまで----- */
/* -----解説等-----

dp(i,j):= i番目の値をjとする場合の組み合わせ数
とする。
DPの適用範囲は、dp(i,j)-> dp(i+1,j+k) (k>=0)
なので、これはTLEっぽいが、増加する値が一定でかつ無限方向であることをかんがえると、
iについて一つだけ遷移をした後、まとめて更新してもよい。
これでO(N*VAL)時間で解けた。

すぐわかったんだけど、テストに時間を裂きすぎたのでいい感じにできるようにしておきたい

----解説ここまで---- */

class IncreasingSequencesEasy 
{
    public:
	
    int count(vector<int> L, vector<int> R) 
	{
		const LL mod = 998244353;
		int N = SZ(L);

		VVL dp(N + 1, VL(10004, 0));
		FOR(i, L[0], R[0] + 1)dp[0][i] = 1;

		FOR(i, 0, N) {

			FOR(val, L[i], R[i] + 1) {

				if (dp[i][val]) {
					dp[i + 1][val + 1] += dp[i][val];
					dp[i + 1][val + 1] %= mod;
				}
			}
			FOR(val, 0, 10003) {
				dp[i + 1][val + 1] += dp[i + 1][val];
				dp[i + 1][val + 1] %= mod;
			}
		}


		//FOR(i, 0, N) {
		//	FOR(j, 0, 10) {
		//		cout << "dp(" << i << "," << j << "):" << dp[i][j] << " ";
		//	}cout << endl;
		//}
		LL ans = 0;
		FOR(i, L[N-1], R[N-1]+1) {
			ans += dp[N-1][i];
			ans %= mod;
		}

		debug(ans);
		return ans;
    }


};

/*

struct IncreasingSequencesEasy {
  vector<int> L;
  vector<int> R;
  int count(vector<int> _L, vector<int> _R) {
    L = _L, R = _R;
    return 0;
  }
};

*/

// CUT begin
ifstream data("IncreasingSequencesEasy.sample");

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

bool do_test(vector<int> L, vector<int> R, int __expected) {
    time_t startClock = clock();
    IncreasingSequencesEasy *instance = new IncreasingSequencesEasy();
    int __result = instance->count(L, R);
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
        vector<int> L;
        from_stream(L);
        vector<int> R;
        from_stream(R);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(L, R, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1516896234;
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
        cout << "IncreasingSequencesEasy (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
