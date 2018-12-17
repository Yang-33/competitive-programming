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

/* -----  2018/12/16  Problem: avitoCoolChallenge2018 B / Link: __CONTEST_URL__  ----- */
/* ------問題------

N人が帽子をかぶっている。それぞれの人iは、自分と異なる帽子をa[i]人かぶっていたと報告した。
これが存在するか判定し、存在すれば一例を示せ。

-----問題ここまで----- */
/* -----解説等-----

N-a[i]人は同じ色の帽子をかぶっている。
これらに割り振っていけば良い。
multiset<int>をa[i]をキーにして判定していくと楽。

全然解法が振ってこなかった。ビビった。

----解説ここまで---- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N; cin >> N;
	VL a(N);
	vector<set<int>>vecset(N);
	FOR(i, 0, N) {
		cin >> a[i];
		vecset[a[i]].insert(i);
	}

	VI ans(N);
	int num = 0;
	int ok = 1;
	FOR(i, 0, N) {
		if (vecset[a[i]].find(i) == vecset[a[i]].end())continue;
		LL s = N - a[i];
		// a[i]をs個除去
		if (SZ(vecset[a[i]]) < s) {
			ok = 0;
			break;
		}
		else {
			//cnt[a[i]] -= s;
			num++;
			FOR(_, 0, s) {
				auto it = vecset[a[i]].begin();
				ans[*it] = num;
				vecset[a[i]].erase(it);
			}
		}
	}
	if (num > N)ok = 0;
	if (ok) {
		cout << "Possible" << endl;
		FOR(i, 0, N) {
			cout << ans[i] << " \n"[i==N-1];
		}
	}
	else {
		cout << "Impossible" << endl;
	}

	return 0;
}
