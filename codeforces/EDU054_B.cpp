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

/* -----  2018/11/12  Problem: EDU054 B / Link: __CONTEST_URL__  ----- */
/* ------問題------

何回引くか

-----問題ここまで----- */
/* -----解説等-----

2か奇数+2

----解説ここまで---- */
#define primeN 100000 //78493個
// 78493番目までの素数のリストを返す Ｏ(NloglogN)
bool prime[primeN + 1];
vector<long long > make_prime() {
	vector<long long >a;
	FOR(i, 0, primeN + 1) {
		prime[i] = 1;
	}prime[0] = prime[1] = 0;

	for (int i = 2; i <= primeN; i++) {
		if (prime[i]) {
			a.push_back((long long)i);
			for (int j = i * 2; j <= primeN; j += i)
				prime[j] = 0;
		}
	}
	return a;
}
#undef primeN 
//素数判定
bool is_prime(long long  n) {
	if (n < 2) return false;
	for (long long i = 2; i * i <= n; ++i) {
		if (n % i == 0) return false;
	}
	return true;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	/*for (LL n = 1; n <= 100; n += 1)*/ {
		LL N;
		cin >> N;
		

		VL a = make_prime();
		LL ans = 0;
		while (N != 0) {
			LL subN = N;
			if (N % 2 == 0) {
				ans += N / 2;
				break;
			}
			else {
				FOR(i, 0, SZ(a)) {
					if (N % a[i] == 0) {
						N -= a[i];
						break;
					}
					else if (N < a[i]) {
						break;
					}
				}
				ans++;
				//DD(de(ans, N));
				if (N == subN) {
					N -= subN;
				}
			}
		}
		cout << ans  << endl;
	}
	return 0;
}
