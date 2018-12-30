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

/* -----  xtimex  Problem: SRM 718 div1 easy  / Link:   ----- */
/* ------問題------

ある子どもiの親がp1[i],p2[i]であるという家族関係が与えられる。
このとき、親の性別が2種類としたときにありうる家族関係が存在するかを判定せよ。

-----問題ここまで----- */
/* -----解説等-----

親について、二部グラフである必要があり、これを満たせば存在する。
連結でないものも存在するので注意。
雑ライブラリを貼った。

----解説ここまで---- */

vector<pair<bool, vector<int>>> BipartiteGraphInfo(const std::vector<std::vector<int>>& g) {
	int n = g.size();
	std::vector<int> color(n, -1);
	vector<pair<bool, vector<int>>>infos;
	FOR(i, 0, n) {
		if (color[i] == -1) {
			std::queue<int> que;
			que.push(i);
			color[i] = 0; 
			int ok = 1;
			vector<int>res;
			res.push_back(i);
			while (!que.empty()) {
				int now = que.front(); que.pop();
				for (auto to : g[now]) {
					if (color[to] != -1) {
						if (color[now] == color[to]) {
							ok = 0;
						}
					}
					else {
						color[to] = color[now] ^ 1;
						res.push_back(color[to] ? -to : to);
						que.push(to);
					}
				}
			}
			if (ok) {
				infos.push_back(pair<bool, vector<int>>(true, move(res)));
			}
			else {
				infos.push_back(pair<bool, vector<int>>(false, vector<int>()));
			}
		}
	}
	return infos;
}

class Family 
{
	public:
	
	string isFamily(vector<int> parent1, vector<int> parent2) 
	{
		int N = SZ(parent1);
		VVI G(N);
		FOR(i, 0, N) {
			int p1 = parent1[i];
			int p2 = parent2[i];
			if (p1 != -1 && p2 != -1) {
				G[p1].push_back(p2);
				G[p2].push_back(p1);
			}
		}
		auto infos = BipartiteGraphInfo(G);
		int ok = 1;
		for (auto it : infos) {
			ok &= it.first;
		}

		return (ok?"Possible":"Impossible");
	}
};


// CUT begin
ifstream data("Family.sample");

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

bool do_test(vector<int> parent1, vector<int> parent2, string __expected) {
	time_t startClock = clock();
	Family *instance = new Family();
	string __result = instance->isFamily(parent1, parent2);
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
		vector<int> parent1;
		from_stream(parent1);
		vector<int> parent2;
		from_stream(parent2);
		next_line();
		string __answer;
		from_stream(__answer);

		cases++;
		if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
			continue;

		cout << "  Testcase #" << cases - 1 << " ... ";
		if ( do_test(parent1, parent2, __answer)) {
			passed++;
		}
	}
	if (mainProcess) {
		cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
		int T = time(NULL) - 1545962242;
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
		cout << "Family (250 Points)" << endl << endl;
	}
	return run_test(mainProcess, cases, argv[0]);
}
// CUT end
