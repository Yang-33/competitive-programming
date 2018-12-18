#include <bits/stdc++.h>
using namespace std;

using VS = vector<string>;    using LL = long long;
using VI = vector<int>;       using VVI = vector<VI>;
using PII = pair<int, int>;   using PLL = pair<LL, LL>;
using VL = vector<LL>;        using VVL = vector<VL>;

#define ALL(a)  begin((a)),end((a))
#define RALL(a) (a).rbegin(), (a).rend()
#define SZ(a) int((a).size())
#define SORT(c) sort(ALL((c)))
#define RSORT(c) sort(RALL((c)))
#define UNIQ(c) (c).erase(unique(ALL((c))), end((c)))
#define FOR(i, s, e) for (int(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (int(i) = (s); (i) > (e); (i)--)
//#pragma GCC optimize ("-O3") 
#ifdef YANG33
#include "mydebug.hpp"
#else
#define DD(x) 
#endif
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/10/25  Problem: EDU053 A / Link: __CONTEST_URL__  ----- */
/* ------問題------

sからなる連続部分列について、どのアルファベットも過半数をこえないようなものをつくることができるか判定し、
存在するならその一例を示せ。

-----問題ここまで----- */
/* -----解説等-----

となりあう2個をとって一致しなければOK.

----解説ここまで---- */

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N; 
	
	cin >> N;
	string s; cin >> s;
	if (N == 1) {
		cout << "NO" << endl;
	}else{
		bool f = 0;
		string t = "";
		FOR(i, 0, SZ(s)-1) {
			if (s[i] != s[i + 1]) {
				t = string(1, s[i]) + string(1, s[i + 1]);
				f = 1;
			}
		}

		if (f) {
			cout << "YES" << endl;
			cout << t << endl;
		}
		else {
			cout << "NO" << endl;
		}

	}




	
	return 0;
}
