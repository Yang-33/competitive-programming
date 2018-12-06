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

/* -----  2018/12/06  Problem: ARC 009 B / Link: http://arc009.contest.atcoder.jp/tasks/arc009_b  ----- */
/* ------問題------

高橋君の住むAtCoder国では、私達が普段使用する数字と同様に 10 個のアラビア数字 (0−9) の 10 進数が使われています。
しかし、私達が普段使用する数字は大小関係が 0<1<2<3<4<5<6<7<8<9 の順になっているのに対して、 AtCoder国の数字ではその大小関係が異なっています。
例えば、AtCoder国の数字では 0<9<8<7<6<5<4<3<2<1 の順になっている場合、AtCoder国では 9 よりも 8 の方が大きいことになります。また、97 よりも 72 の方が大きいことになります。

AtCoder国の数字の大小関係といくつかの数が与えられるので、AtCoder国の数字の大小関係で昇順に並び替えてください。
なお、私達が普段使用する数字同様、AtCoder国で最も小さい数字は 0 であることは決まっています。


-----問題ここまで----- */
/* -----解説等-----

sort関数を作れば良い。

----解説ここまで---- */



int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	VI order(10);
	FOR(i, 0, 10) {
		cin >> order[i];
	}
	VI rev(10);
	FOR(i, 0, 10) {
		rev[order[i]] = i;
	}
	DD(De(rev));
	int N; cin >> N;
	VS vs(N);
	FOR(i, 0, N) {
		cin >> vs[i];
	}
	sort(ALL(vs), [&](const string &L, const string &R) {
		if (SZ(L) != SZ(R)) {
			return SZ(L) < SZ(R);
		}
		else {
			FOR(i, 0, SZ(L)) {
				if (L[i] == R[i])continue;
				else {
					return rev[L[i] - '0'] < rev[R[i] - '0'];
				}
			}
			return false;
		}
	});


	FOR(i, 0, N) {
		cout << vs[i] << endl;
	}

	return 0;
}
