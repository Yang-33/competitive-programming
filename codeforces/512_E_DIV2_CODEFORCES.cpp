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
#define debug(x) cerr << #x << ": " << x << endl
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/09/23  Problem: CodeForces512 E div2 / Link: http://codeforces.com/contest/1058/problem/E  ----- */
/* ------問題------

2進数で任意のbitをswapできる。
区間[l..r]のxorをとったとき、0になるものを良い数列とする。
この数列の(l,r)の個数は？

-----問題ここまで----- */
/* -----解説等-----

bsum[r-1] - bsum[l] ≧ b[r]なlを数えれば良いが、偶奇も考える。

値は小さいので、累積和を持って適当に取り除けばよい。
取り除く条件は、総和に占める最大の要素が半分よりも大きいとき。
一般に厳しそうだが、値は60よりも小さいので適当回やればよい。
O(N*K) K:=60ぐらい
としてできる。

これも解けないとダメだなあ


----解説ここまで---- */




LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	VL a(N);
	VI b(N, 0);
	FOR(i, 0, N) {
		cin >> a[i];
		b[i] = __builtin_popcountll(a[i]);
	}


	LL allsum = 0;
	VVL cnt(N+1, VL(2, 0));
	cnt[N][0] = 1;
	FORR(i, N - 1, 0 - 1) {
		LL sum = 0;
		LL add = 0;
		int mx = 0;
		FOR(j, i, min(N, i + 70LL)) {
			sum += b[j];
			mx = max(mx, b[j]);
			if (mx > sum - mx && sum % 2 == 0) {
				add--;
			}
		}

		allsum += b[i];
		add += cnt[i+1][allsum%2];
		ans += add;

		cnt[i][0] = cnt[i + 1][0];
		cnt[i][1] = cnt[i + 1][1];
		cnt[i][allsum % 2]++;
	}

	cout << ans << "\n";

	return 0;
}
