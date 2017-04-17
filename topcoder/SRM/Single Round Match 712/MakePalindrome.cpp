#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <fstream>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define FOR(i,s,e) for(int (i)=(s);(i)<(e);(i)++)
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

string str = "abcdefghijklmnopqrstuvwxyz";

class MakePalindrome {
public:
	vector<string> constructMinimal(string card) {
		vector<string>ans(30);
		int a[30];
		FOR(i, 0, 30) {
			a[i] = 0;
		}

		FOR(i, 0, (int)card.size()) {
			char c = card[i];
			a[c - 'a']++;
		}
		string s;
		string ss;
		FOR(i, 0, 26) {
			if (a[i] != 0) {
				if (a[i] % 2 == 0) {
					FOR(j, 0, a[i] / 2) {
						s += str.substr(i, 1);
					}
				}
				else {
					a[i]--;
					ss += str.substr(i, 1);
					FOR(j, 0, a[i] / 2) {
						s += str.substr(i, 1);
					}
				}
			}
		}
		int cnt = 0;
		if (ss.size() > 0) {//ŠjƒAƒŠ
			FOR(i, 0, s.size()) {
				ans[0] += s[i];
			}
			ans[0] += ss[0];
			FOR(i, 0, s.size()) {
				ans[0] += s[(int)s.size() - 1 - i];
			}
			FOR(j, 1, ss.size()) {
				ans[j] = ss[j];
			}
			cnt = ss.size();
		}
		else {//Šj‚È‚µ
			FOR(i, 0, s.size()) {
				ans[0] += s[i];
			}
			FOR(i, 0, s.size()) {
				ans[0] += s[(int)s.size() - 1 - i];
			}
			cnt = 1;
		}
		
		ans.resize(cnt);
		return ans;
	}
};

// CUT begin
ifstream data("MakePalindrome.sample");

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

bool do_test(string card, vector<string> __expected) {
	time_t startClock = clock();
	MakePalindrome *instance = new MakePalindrome();
	vector<string> __result = instance->constructMinimal(card);
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
		string card;
		from_stream(card);
		next_line();
		vector<string> __answer;
		from_stream(__answer);

		cases++;
		if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
			continue;

		cout << "  Testcase #" << cases - 1 << " ... ";
		if (do_test(card, __answer)) {
			passed++;
		}
	}
	if (mainProcess) {
		cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
		int T = time(NULL) - 1492514038;
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
		cout << "MakePalindrome (500 Points)" << endl << endl;
	}
	return run_test(mainProcess, cases, argv[0]);
}
// CUT end
