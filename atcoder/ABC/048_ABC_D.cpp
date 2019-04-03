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

/* -----  2019/04/03  Problem: ABC 048 D / Link: http://abc048.contest.atcoder.jp/tasks/abc048_d  ----- */

const int sz = 1000;
const int WIN = 1, LOSE = 2;
map<string, int>gamedp;
int f(string s) {
	if (SZ(s) <= 2) {
		return LOSE;
	}
	if (gamedp[s])return gamedp[s];

	bool gotolose = 0;
	FOR(i, 1, SZ(s) - 1) {
		string t = "";
		FOR(k, 0, SZ(s)) {
			if (k == i)continue;
			t += string(1, s[k]);
		}
		bool ok = 1;
		FOR(k, 0, SZ(t) - 1) {
			if (t[k] == t[k + 1])ok = 0;
		}
		if (ok)
			gotolose |= f(t) == LOSE;
	}
	return gamedp[s] = (gotolose ? WIN : LOSE);
}


#include<chrono>
#include<random>
struct randgen {
	mt19937_64 rng;
	randgen() :rng((int)std::chrono::steady_clock::now().time_since_epoch().count()) {}
	LL getrand(LL s, LL t) {
		return rng() % (t - s) + s;
	}
};


void test(int n) {
	string s; {
		randgen rnd;
		FOR(i, 0, n) {
			while (true) {
				string t = string(1, 'a' + rnd.getrand(0, 4));
				if (SZ(s) && s.back() == t.front())continue;
				else {
					s += t;
					break;
				}
			}
		}
	}
	DD(de(s, SZ(s), s.front() == s.back(), "WL"[f(s) == LOSE]))
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	//FOR(i, 0, 10) {
	//	test(10);
	//}
	//FOR(i, 0, 10) {
	//	test(11);
	//}
	//cout << "WL"[f("aba") == LOSE] << endl;
	//cout << "WL"[f("abc") == LOSE] << endl;
	//cout << "WL"[f("abcab") == LOSE] << endl;

	string s; cin >> s;

	cout << ((s.front()==s.back())^(SZ(s)%2)? "First" : "Second") << endl;


	return 0;
}
