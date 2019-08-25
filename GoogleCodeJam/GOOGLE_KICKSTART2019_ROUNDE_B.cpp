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

/* -----  2019/08/25  Problem: GOOGLE_KICKSTART2019_ROUNDE B / Link: https://codingcompetitions.withgoogle.com/kickstart  ----- */


// Code - Eat Switcher(11pts, 25pts)

// LPなんだけどなんかWA(smallは解けてほしいのに…)
// 2つしかないのでソートしてやるとできる
// それはそうで，大きいやつで片側固定して，残りは反対側に全振りが最適．
// 頭ついてない…
void solve(int testcasenum) {
	cout << "Case #" << testcasenum << ": ";

	int Q, N; cin >> Q >> N;

	VL SC(N), SE(N);

	FOR(i, 0, N) {
		cin >> SC[i] >> SE[i];
	}
	LL CSum = accumulate(ALL(SC),0LL);
	LL ESum = accumulate(ALL(SE), 0LL);
	VI idx(N); iota(ALL(idx), 0);
	sort(ALL(idx), [&](const int a, const int b) {
		return SC[a] * SE[b] > SC[b] * SE[a];
	});
	vector<LL> csum(N + 1), esum(N + 1); {
		FOR(i, 0, N) {
			csum[i + 1] = csum[i] + SC[idx[i]];
			esum[i + 1] = esum[i] + SE[idx[i]];
		}
	}

	FOR(i, 0, Q) {
		LL QC, QE; cin >> QC >> QE;
		if (QC > CSum || QE > ESum) {
			cout << "N";
			continue;
		}

		int p = upper_bound(csum.begin(), csum.begin() + N, QC) - csum.begin() - 1;
		LL cur_E = ESum - esum[p];
		QC -= csum[p];
		int id = idx[p];
		if (cur_E*SC[id] - QC * SE[id] >= QE * SC[id]) {
			cout << "Y";
		}
		else {
			cout << "N";
		}
	}
	cout << "\n";
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int T; cin >> T;
	FOR(t, 0, T) {
		solve(t + 1);
	}

	return 0;
}


/*
[1 input]:
2
4 2
3 8
6 10
0 18
3 13
10 0
7 3
1 2
4 4
4 4
0 0
[1 output]:
Case #1: YYNY
Case #2: Y
[2 input]:
1
2 1
3 8
10 0
1 4
[2 output]:
Case #1: NY

*/
