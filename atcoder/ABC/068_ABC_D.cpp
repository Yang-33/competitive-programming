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

/* -----  2019/03/19  Problem: ABC 068 D / Link: http://abc068.contest.atcoder.jp/tasks/abc068_d  ----- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL K; cin >> K;
	LL N = 50;
	VL a(N, 49);
	FOR(i, 0, N) {
		a[i] += K / N;
	}
	FOR(i, 0, N) {
		if (i < K%N)a[i]++;
		else a[i] -= K % N;
	}

	DD(De(a));

	if (0) {
		LL cnt = 0;
		while (1) {
			int id = max_element(ALL(a)) - a.begin();
			if (a[id] < 50)break;
			FOR(i, 0, N) {
				if (i == id)a[id] -= 50;
				else a[i]++;
			}
			cnt++;

		}
		DD(de(cnt));
	}
	cout << N << endl;
	FOR(i, 0, N) {
		cout << a[i] << " \n"[i == N - 1];
	}

	return 0;
}
