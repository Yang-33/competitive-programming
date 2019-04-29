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

/* -----  2019/04/29  Problem: AOJ 2680 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/2680  ----- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string s; cin >> s;
	// 制約が小さいときは区間の評価をしたくなりたい

	const string invalid = "invalid";
	// [L,R)の最大値
	auto maxstring = [&](const string &L, const string &R) {
		if (R == invalid)return L;
		if (L == invalid)return R;
		// num
		if (SZ(L) != SZ(R)) {
			return (SZ(L) > SZ(R) ? L : R);
		}
		else {
			FOR(i, 0, SZ(L)) {
				if (L[i] != R[i]) {
					return (L[i] > R[i] ? L : R);
				}
			}
		}
		return L;
	};
	auto allnum = [&](int L, int R) {
		bool ok = 1;
		string ret;
		FOR(i, L, R) {
			ok &= isdigit(s[i]) || s[i] == '?';
			ret += string(1, (isdigit(s[i]) ? s[i] : '9'));
		}
		// 0??はダメ
		if (s[L] == '0' && R - L != 1)ok = 0;

		return make_pair(ok, ret);
	};
	vector<vector<string>>memo(SZ(s), vector<string>(SZ(s)+1, "-1"));
	function<string(int, int)> f = [&](int L, int R) {
		if (L >= R)return invalid;
		// 数字でよければ数字で返しちゃう
		if (memo[L][R] != "-1")return memo[L][R];
		if (allnum(L, R).first){
			return memo[L][R] = allnum(L, R).second;
		}
		string ret = invalid;
		if (R - L <= 5)return memo[L][R] = invalid;
		char F = s[L];
		char sF = s[L + 1];
		char tF = s[R - 1];

		if ((F == 'L' || F == 'R' || F == '?')
			&& (sF == '(' || sF == '?')
			&& (tF == ')' || tF == '?')) {
			// [L+2,R-2]で分割
			FOR(i, L + 3, R - 2) {
				if (s[i] == ',' || s[i] == '?') {
					string a = f(L + 2, i);
					string b = f(i + 1, R - 1);
					if (a != invalid && b != invalid) {
						if (F == 'L' || F == '?') {
							ret = maxstring(ret, a);
						}
						if (F == 'R' || F == '?') {
							ret = maxstring(ret, b);
						}
					}
				}
			}
			return memo[L][R] = ret;
		}
		else {
			return memo[L][R] =invalid;
		}
	};

	cout << f(0, SZ(s)) << endl;

	return 0;
}
