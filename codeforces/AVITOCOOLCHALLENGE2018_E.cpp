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

/* -----  2018/12/16  Problem: avitoCoolChallenge2018 E / Link: __CONTEST_URL__  ----- */
/* ------問題------

数列Xについて、\sum x_iを、どのprefixをとっても二乗和になるようにしたい。
Xの偶数番目のみが与えられるので、これが存在するかを判定し、存在するならその一例を示せ。

-----問題ここまで----- */
/* -----解説等-----

// sum+bi+ai = (x+k)^2
// sum+bi    = (x  )^2
// ai        = k(k+2x)
// k>0,x>0
// minimize x+k
を解けば良い。
O(Nsqrt(a))

----解説ここまで---- */

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N; cin >> N;
	int n = N / 2;
	VL a(n);
	FOR(i, 0, n) {
		cin >> a[i];
	}
	VL b(n);
	const LL LIMIT = 1000'00000'00000LL;
	static int ok = 1;

	// sum+bi+ai = (x+k)^2
	// sum+bi    = (x  )^2
	// ai        = k(k+2x)
	// k>0,x>0,x^2-sum>0
	// minimize x+k

	LL presum = 0;
	FOR(i, 0, n) {
		if (ok) {
			int dd = 0;
			PLL kx = PLL(-1, -1);
			LL tar = LINF;
			for (LL k = 1; k*k <= a[i]; k++) {
				if (a[i] % k == 0) {
					LL div = a[i] / k;
					if (div - k > 0 && (div - k) % 2 == 0) {
						LL x = (div - k) / 2;
						if (x*x > presum) {
							LL tn = x + k;
							if (tar > tn) {
								tar = tn;
								kx = PLL(k, x);
							}
							dd = 1;
						}
					}
				}
			}
			if (!dd) ok = 0;
			else {
				LL k = kx.first;
				LL x = kx.second;
				b[i] = x * x- presum;
				if (b[i] > LIMIT)ok = 0;
				presum += a[i] + b[i];
			}
		}
	}
	if (ok) {
		cout << "Yes" << endl;
		FOR(i, 0, n) {
			cout << b[i] << " " << a[i] << " \n"[i == n - 1];
		}
	}
	else {
		cout << "No" << endl;
	}


	return 0;
}
