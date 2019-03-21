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

/* -----  2019/03/21  Problem: ABC 057 D / Link: http://abc057.contest.atcoder.jp/tasks/abc057_d  ----- */

const int nCk_MAX = 100;
long long  comb[nCk_MAX + 1][nCk_MAX + 1];
void calcomb() {
	int  i, j;
	for (i = 0; i <= nCk_MAX; i++) {
		for (j = 0; j <= i; j++) {
			if (j == 0 || j == i)
				comb[i][j] = 1;
			else
				comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
		}
	}
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	calcomb();
	LL N, A, B; cin >> N >> A >> B;
	vector<LL> a(N);
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
	}
	map<LL, LL>cnt;
	FOR(i, 0, N) {
		cnt[a[i]]++;
	}
	LL ans = 0;
	double ansv = 0;
	LL mx = *max_element(ALL(a));
	// maxがA個以上ある場合
	if (cnt[mx] >= A) {
		FOR(i, A, B + 1) {
			ans += comb[cnt[mx]][i];
		}
		ansv = mx;
	}
	else {
		// maxがA個以上ないので,なんとかする場合->A個のみ
		LL sum = 1; LL selectable_val = 0;
		RSORT(a);
		ansv = a.front();

		FOR(i, 1, N) {
			if (sum + 1 <= A) {
				ansv += a[i];
				selectable_val = a[i];
			}
			else if (a[i - 1] == a[i]) {
				selectable_val = a[i];
			}
			else if (sum > A) {
				break;
			}
			sum++;

		}
		map<LL, LL>cnt2;
		FOR(i, 0, A) {
			cnt2[a[i]]++;
		}
		ans = comb[cnt[selectable_val]][cnt2[selectable_val]];
		ansv /= A;

	}




	cout << fixed << setprecision(10) << ansv << endl;
	cout << (ans) << "\n";

	return 0;
}
