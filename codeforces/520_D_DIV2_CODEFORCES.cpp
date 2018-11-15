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

/* -----  2018/11/15  Problem: CodeForces520 D div2 / Link: http://codeforces.com/contest/1062/problem/D  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

順番にi,-iを足していくと、偶数本しか追加されないので、全部到達可能。
よって1,i以外の約数には到達可能であるから、約数列挙して4倍が答え。

----解説ここまで---- */
vector<LL> getdivisor(int n) {
	vector<LL> res;
	for (LL i = 1; i*i <= n; i++) {
		if (n%i == 0) {
			res.push_back(i);
			if (n / i != i)res.push_back(n / i);
		}
	}
	sort(res.begin(), res.end());
	return res;
}

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N; 
	cin >> N;
	FOR(i, 4, N + 1) {
		VL res = getdivisor(i);
		LL val = 0;
		for (auto it : res) {
			if (it == 1 || it == i)continue;
			val += it;
		}
		val *= 4;
		//DD(de(i, val));
		ans += val;
	}
	
	cout << ans << "\n";

	return 0;
}
