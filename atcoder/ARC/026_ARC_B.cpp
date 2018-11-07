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

/* -----  2018/11/07  Problem: ARC 026 B / Link: http://arc026.contest.atcoder.jp/tasks/arc026_b  ----- */
/* ------問題------

高橋君は完全なものが大好きです。
自然数には、完全数というものがあります。 完全数というのは、自分以外の約数の総和が自分と等しくなる自然数のことです。 例えば 6 の場合 1+2+3=6となるので完全数です。 それに対して、自分以外の約数の総和が自分より小さくなる場合は不足数と言い、大きくなる場合は過剰数と言います。
高橋君には今気になっている自然数があります。高橋君のために、それが完全数なのか不足数なのか過剰数なのか判定してください。

-----問題ここまで----- */
/* -----解説等-----

N＜10^10なので何をしても許される
素因数分解して約数総和を求める。

----解説ここまで---- */

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N;

	cin >> N;
	LL ttN = N;
	map<LL, LL>cnt;
	for (LL i = 2; i*i <= N; i++) {
		while (N%i == 0) {
			cnt[i]++;
			N /= i;
		}
	}
	if (N != 1)cnt[N]++;
	ans = 1;
	for (auto it : cnt) {
		ans *= (pow(it.first, it.second + 1) - 1) / (it.first - 1);
	}
	ans -= ttN;
	if (ans == ttN) {
		cout << "Perfect" << endl;
	}
	else if (ans > ttN) {
		cout << "Abundant" << endl;
	}
	else {
		cout << "Deficient" << endl;
	}

	return 0;
}