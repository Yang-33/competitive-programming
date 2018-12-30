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

/* -----  xtimex Problem: SRM 612 div1 easy / Link:   ----- */
/* ------問題------

文字列を今smiles個画面に表示したい。
今画面に1つだけ表示されているとして、行える動作を
1. clipboardから貼り付ける
2. 表示されている文字列を全部clipboardにコピーする
3. 表示されている文字列を1つ消す
とし、それぞれのコストを1とする。
smiles個表示するときの最小コストは?

-----問題ここまで----- */
/* -----解説等-----

ダイクストラ法をしたい気持ちになる。
区別するのはclipboardの状態。
dist[x][y]:= 文字列がx個書かれており、いまclipboradに長さyの文字列がかかれている際の行動の最小値
とすればよい。


----解説ここまで---- */

class EmoticonsDiv1
{
public:

	int printSmiles(int smiles)
	{
		const int sz = 3000;
		VVI dist(sz, VI(sz, INF));
		dist[1][0] = 0;
		using tp = tuple<int, int, int>;
		priority_queue<tp, vector<tp>, greater<tp>>q;
		q.push(tp(0, 1, 0));
		while (!q.empty()) {
			int d, pos, clip;
			tie(d, pos, clip) = q.top(); q.pop();
			if (pos == smiles)break;
			// -
			if (pos - 1 >= 0 && d < sz && clip<sz
				&& dist[pos - 1][clip] > dist[pos][clip] + 1) {
				dist[pos - 1][clip] = dist[pos][clip] + 1;
				q.push(tp(dist[pos - 1][clip], pos - 1, clip));
			}

			// paste
			if (pos + clip < sz && d < sz && clip<sz
				&& dist[pos + clip][clip] > dist[pos][clip] + 1) {
				dist[pos + clip][clip] = dist[pos][clip] + 1;
				q.push(tp(dist[pos + clip][clip], pos + clip, clip));
			}

			// copy all
			if (pos < sz && d < sz && clip<sz
				&& dist[pos][pos] > dist[pos][clip] + 1) {
				dist[pos][pos] = dist[pos][clip] + 1;
				q.push(tp(dist[pos][pos], pos, pos));
			}
		}

		int ans = INF;
		FOR(i, 0, sz) {
			ans = min(ans, dist[smiles][i]);
		}
		return ans;
	}
};

/*

struct EmoticonsDiv1 {
  int smiles;
  int printSmiles(int _smiles) {
	smiles = _smiles;
	return 0;
  }
};

*/

// CUT begin
ifstream data("EmoticonsDiv1.sample");

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

bool do_test(int smiles, int __expected) {
	time_t startClock = clock();
	EmoticonsDiv1 *instance = new EmoticonsDiv1();
	int __result = instance->printSmiles(smiles);
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
		int smiles;
		from_stream(smiles);
		next_line();
		int __answer;
		from_stream(__answer);

		cases++;
		if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
			continue;

		cout << "  Testcase #" << cases - 1 << " ... ";
		if (do_test(smiles, __answer)) {
			passed++;
		}
	}
	if (mainProcess) {
		cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
		int T = time(NULL) - 1545962156;
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
		cout << "EmoticonsDiv1 (250 Points)" << endl << endl;
	}
	return run_test(mainProcess, cases, argv[0]);
}
// CUT end
