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

/* -----  2018/10/27  Problem: ARC 034 B / Link: http://arc034.contest.atcoder.jp/tasks/arc034_b  ----- */
/* ------問題------

正整数 n に対し、n の十進表記における各桁の数の和を f(n) で表す。例えば、 f(123)=1+2+3=6, f(4)=4 となる。
正整数 N が与えられる。等式 x+f(x)=N を満たす正整数 x を全て求めよ。

-----問題ここまで----- */
/* -----解説等-----

クソでかNに対して、f(N)は結構小さいので、xもそれなりに大きくないとダメ。
f(10^18)だと9*19なのでNから200以下で十分。

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N; cin >> N;
	auto f = [](LL x) {
		string s = to_string(x);
		int sum = 0;
		for (char c : s) {
			sum += c - '0';
		}
		return sum;
	};
	VL ans;
	FORR(i, 200, 0 - 1) {
		LL x = N - i;
		if (x <= 0)continue;
		if (x + f(x) == N)ans.push_back(x);
	}

	cout << SZ(ans) << endl;
	for (auto i : ans) {
		cout << i << endl;
	}

	return 0;
}
