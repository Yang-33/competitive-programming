#include <bits/stdc++.h>
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

/* -----  2018/01/20  Problem: colcon_final_2017 B / Link: __CONTEST_URL__  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

適当にやりすぎたのでデバッグ駆動してた

----解説ここまで---- */

LL N;

LL ans = 0LL;

string op = "/*+-";
void f(string &s, int &i, int hop) {
	stack<int>st;
	int L, R;
	VI v;
	int wop = 0;
	VI dots;
	while (i < SZ(s)) {
		if (op.find(s[i]) != -1) {
			//cout << "OP pos " << i << endl;
			wop = op.find(s[i]);
			//debug(op[wop]);
			s[i] = '@';
			i++;
			//cout << "!!!! (start: pos is " <<i << endl;
			v.push_back(i); //(
			i++;
			f(s, i, wop);
			v.push_back(i);
			/*cout << "at i: " << i << endl;
			cout << "!!!! end: )" << s[i] << endl;
*/
		}
		else if (s[i] == ',') {
			if (st.size() == 0)dots.push_back(i);
		}
		else if (s[i] == '(') {
			if (st.size() == 0)L = i;
			st.push(1);
			v.push_back(i);
		}
		else if (s[i] == ')') {
			v.push_back(i);
			if (st.size() > 0)st.pop();
			else {
				R = i;
				break;
			}
		}
		i++;
	}
	//cout << "replece" << endl;
	FOR(i, 0, SZ(dots)) {
		s[dots[i]] = op[hop];
		//debug(dots[i]);
	}
//	cout << "replace end." << endl;
	//if (v.size() >= 2 && hop != -1) {
	//	debug(SZ(v));
	//	debug(i);
	//	debug(v[0]);
	//	debug(v[1]);
	//	debug(v[SZ(v) - 2]);
	//	debug(v[SZ(v) - 1]);
	//	FOR(j, v[0], v[1]) {
	//		if (s[j] == ',')s[j] = op[hop];
	//	}
	//	FOR(j, v[SZ(v) - 2], v[SZ(v) - 1]) {
	//		if (s[j] == ',')s[j] = op[hop];
	//	}
	//}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);


	string S;
	cin >> S;
	int i = 0;
	f(S, i, -1);
	FOR(i, 0, SZ(S)) {
		if (S[i] != '@') {
			cout << S[i];
		}
	}
	cout << endl;
	//	cout << ans << "\n";

	return 0;
}
