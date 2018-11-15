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

/* -----  2018/11/15  Problem: CodeForces520 B div2 / Link: http://codeforces.com/contest/1062/problem/B  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

mulを行うかどうか/各素因数の2べきの最大値が答え。

----解説ここまで---- */

vector<long long >make_factor(long long  n) {
	vector<long long >ans;
	for (long long i = 2; i * i <= n; i++) {
		while (n%i == 0) {
			ans.push_back(i);
			n /= i;
		}
	}
	if (n != 1)ans.push_back(n);
	return ans;
}
LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N; 
	
	cin >> N;
	VL facts = make_factor(N);
	DD(De(facts));
	map<LL, LL>Map;
	for (auto it : facts) {
		Map[it]++;
	}
	ans = 1;
	LL t = 0;
	auto div2 = [](LL x) {
		while (x % 2 == 0) {
			x /= 2;
		}
		return (x == 1);
	};
	auto time2 = [](LL x) {
		LL cnt = 0;
		LL val = 1;
		while (val<x){
			cnt++;
			val *= 2;
		}
		return cnt;
	};

	// F:=all div2 or all 1



	for (auto it : Map) {
		ans *= it.first;
		t = max(t, time2(it.second));
		//cout << it.first << "," << it.second << endl;
	}
	if (SZ(facts)) {
		int f = 1;// need mul?
		int val = Map.begin()->second;
		for (auto it : Map) {
			f &= val==it.second;
		}
		DD(de(val,f));
		if (f) {
			if (div2(val) || val == 1) {

			}
			else {
				t++;
			}
		}
		else {
			t++;
		}
	}


	cout << ans << " " << t << endl;

	return 0;
}
