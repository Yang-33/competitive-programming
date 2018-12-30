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

/* -----  xtimex  Problem: SRM 610 div1 easy  / Link:   ----- */
/* ------問題------

白黒の盤面が与えられる。任意の長方形を選択した時、市松模様なら良い盤面であるとする。
良い盤面の最大面積を答えよ。

-----問題ここまで----- */
/* -----解説等-----

これは最近知ったテクニックで解いた。
幅Wを全探索する。
この際1stepでWを増加させる際、Hの情報を1次元の配列に落とし込む。
するとWにO(N^2)時間、HにO(N)時間で検査できるので全体O(N^3)で解ける。
1次元の配列は以下。
color[i]:= i行目は0/1から始まる配列であれば0/1、そうでないなら-1
これはWを変化させた時、正しいかをO(1)で更新可能。
更にcolorを見たときに、0/1の連続部分列の最大長を見れば市松模様の最大高さ(H)が求められる。

----解説ここまで---- */

class TheMatrix
{
public:

	int MaxArea(vector<string> board)
	{
		// O(N^3)で
		// O(N^4)は間に合うのかな?
		int W = SZ(board[0]);
		int H = SZ(board);
		int ans = 0;

		auto f = [](const VI & a) {// 0/1列の最大長
			int ret = 0;
			int pre = -1;
			// 0,1,-1
			int sub = 0;
			FOR(i, 0, SZ(a)) {
				if (pre == 0 && a[i] == 1) {
					sub++;
				}
				else if (pre == 1 && a[i] == 0) {
					sub++;
				}
				else if (a[i] == 0 || a[i] == 1) {
					sub = 1;
				}
				pre = a[i];
				ret = max(ret, sub);
			}
			return ret;
		};
		
		FOR(L, 0, W) {
			VI color(H, 1);
			FOR(i, 0, H) {
				color[i] = board[i][L] - '0';
			}
			ans = max(ans, 1 * f(color));
			FOR(R, L + 1, W) {
				FOR(i, 0, H) {
					if (board[i][R - 1] == board[i][R]) {
						color[i] = -1;
					}
				}
				ans = max(ans, (R - L + 1)*f(color));
			}
		}

		return ans;
	}
};



// CUT begin
ifstream data("TheMatrix.sample");

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

bool do_test(vector<string> board, int __expected) {
	time_t startClock = clock();
	TheMatrix *instance = new TheMatrix();
	int __result = instance->MaxArea(board);
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
		vector<string> board;
		from_stream(board);
		next_line();
		int __answer;
		from_stream(__answer);

		cases++;
		if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
			continue;

		cout << "  Testcase #" << cases - 1 << " ... ";
		if (do_test(board, __answer)) {
			passed++;
		}
	}
	if (mainProcess) {
		cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
		int T = time(NULL) - 1545962135;
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
		cout << "TheMatrix (250 Points)" << endl << endl;
	}
	return run_test(mainProcess, cases, argv[0]);
}
// CUT end
