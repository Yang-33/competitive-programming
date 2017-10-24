#include "bits/stdc++.h"
using namespace std;

using VS = vector<string>;    using LL = long long;
using VI = vector<int>;       using VVI = vector<VI>;
using PII = pair<int, int>;   using PLL = pair<LL, LL>;
using VL = vector<LL>;        using VVL = vector<VL>;

#define ALL(a)  begin((a)),end((a))
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define SZ(a) int((a).size())
#define SORT(c) sort(ALL((c)))
#define RSORT(c) sort(RALL((c)))
#define UNIQ(c) (c).erase(unique(ALL((c))), end((c)))
#define FOR(i, s, e) for (int(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (int(i) = (s); (i) > (e); (i)--)
#define debug(x) cerr << #x << ": " << x << endl
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2017/10/20  Problem: Uva 11536  / Link:   ----- */
/* ------問題------

数列aにおいて、[1,K]が一つ以上含まれる区間の最小幅

-----問題ここまで----- */
/* -----解説等-----

尺取りをする。
基本的なやつでとてもバグりにくくてうれしい

----解説ここまで---- */

LL N, M, K;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL T; cin >> T;
	FOR(_i, 0, T) {
		cin >> N >> M >> K;
		VI a(N + 3, 0); a[0] = 1; a[1] = 2; a[2] = 3;
		FOR(i, 3, N) {
			a[i] = (a[i - 1] + a[i - 2] + a[i - 3]) % M + 1;
		}
		VI cnt(K + 1, 0);
		ans = INF;
		int kk = 0;
		for (int i = 1, j = 1; i < N; i++) {//K
			if (a[i] <= K) {
				cnt[a[i]]++;
				if (cnt[a[i]] == 1)kk++;
			}
			while (j <= i&&kk == K) {
				ans = min(ans, (LL)i - j + 1);
				if (a[j] <= K) {
					cnt[a[j]]--;
					if (cnt[a[j]] == 0) {
						kk--;
					}
				}
				j++;
			}
		}
		cout << "Case " << _i + 1 << ": ";
		if (ans >= INF) {
			cout << "sequence nai" << endl;
		}
		else {
			cout << ans << endl;
		}
	}


	return 0;
}