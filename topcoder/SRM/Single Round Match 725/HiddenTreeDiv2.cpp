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

/* -----  2017/12/10  Problem: SRM 725 div2 hard / Link:   ----- */
/* ------問題------

有向グラフ上に点がある。各点の重みはa(i)である。
点iから到達可能な重みの和がb(i)となるようなグラフを構成することができるか。

-----問題ここまで----- */
/* -----解説等-----

重み付きUF？とおもったけど、そんなことはなくて、最小の点に対してそうでない点をくっつけていけばよい。
工夫なしだとTLEしそうなので、昇順に並べておくことで、効率の良い枝刈りができる。
div2全完だと思ったけどresubmitできなくて、しかもunratedになって悲しみ

が、まちがっていた！
上位集合が下位集合を複数持つパターンが書けていなかった。
これはbitDPをしなくちゃいけないので、この解法はだめ。

----解説ここまで---- */



class HiddenTreeDiv2
{
public:

	string isPossible(vector<int> a, vector<int> b)
	{
		// 小さい方から探索していけばOK


		int N = SZ(a);
		vector<PII>v;
		FOR(i, 0, N) {
			v.push_back(PII(b[i], a[i]));
		}
		SORT(v);
		VL A(N), B(N);
		cout << endl;
		FOR(i, 0, N) {
			B[i] = v[i].first;
			A[i] = v[i].second;
			cout << A[i] << " " << B[i] <<" "<<B[i]-A[i]<< endl;
		}
		map<LL, int>mp;
		int nodesize = 0;
		vector<PLL> root;
		VI used(N, 0);
		FOR(i, 0, N) {
			if (A[i] == B[i]) {
				used[i] = 1;
				if (mp[A[i]] == 0)root.push_back(PLL(A[i], i)), mp[A[i]] = 1, nodesize++;
			}
		}
		FOR(i, 0, N) { cout << used[i] << " "; }cout << endl;
		int ok = 0; 
		while (1) {
			int br = 1; FOR(i, 0, N) { if (used[i] == 0)br = 0; }
			if (br) {
				ok = 1;
				break;
			}
			int koshin = 0;
			for (int i = 0; i < nodesize; i++) {
				LL val = root[i].first;
				FOR(j, 0, N) {
					if (used[j] == 0 && B[j] == A[j] + val) {
						used[j] = 1;
						if (mp[B[j]] == 0)root.push_back(PLL(B[j], j)), mp[B[j]] = 1,nodesize++;
						koshin = 1;
					}
					else if (used[j] == 0 && B[j] > A[j] + val) {
						break;
					}
				}
			}
			if (koshin == 0)break;
		}

		FOR(i, 0, SZ(root))cout << root[i].first << " ";
		FOR(i, 0, N)if (used[i] == 0)cout << i << " " << B[i] << endl;
		string ans[2] = { "Impossible","Possible" };
		return ans[ok];
	}
};

/*

struct HiddenTreeDiv2 {
  vector<int> a;
  vector<int> b;
  string isPossible(vector<int> _a, vector<int> _b) {
	a = _a, b = _b;
	return "";
  }
};

*/

// CUT begin
ifstream data("HiddenTreeDiv2.sample");

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

bool do_test(vector<int> a, vector<int> b, string __expected) {
	time_t startClock = clock();
	HiddenTreeDiv2 *instance = new HiddenTreeDiv2();
	string __result = instance->isPossible(a, b);
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
		vector<int> a;
		from_stream(a);
		vector<int> b;
		from_stream(b);
		next_line();
		string __answer;
		from_stream(__answer);

		cases++;
		if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
			continue;

		cout << "  Testcase #" << cases - 1 << " ... ";
		if (do_test(a, b, __answer)) {
			passed++;
		}
	}
	if (mainProcess) {
		cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
		int T = time(NULL) - 1512841100;
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
		if (string(argv[i]) == "-") {
			mainProcess = false;
		}
		else {
			cases.insert(atoi(argv[i]));
		}
	}
	if (mainProcess) {
		cout << "HiddenTreeDiv2 (1000 Points)" << endl << endl;
	}
	return run_test(mainProcess, cases, argv[0]);
}
// CUT end
