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

/* -----  2017/10/03  Problem: AOJ 0009  / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0009&lang=jp ----- */
/* ------問題------

与えられたN以下の素数

-----問題ここまで----- */
/* -----解説等-----

素数表は簡単に作ることができるのでこれを累積和みたいにすればよい。
c[i]:=i以下の素数の個数

----解説ここまで---- */

LL N;

LL ans = 0LL;

#define primeN 1000006 //78493個
bool prime[primeN + 1];

void make_prime() {
	FOR(i, 0, primeN + 1) {
		prime[i] = 1;
	}prime[0] = prime[1] = 0;

	for (int i = 2; i <= primeN; i++) {
		if (prime[i]) {
			for (int j = i * 2; j <= primeN; j += i)
				prime[j] = 0;
		}
	}
}

int C[primeN];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	make_prime();
	FOR(i, 1, primeN) {
		if (prime[i]) {
			C[i] = C[i - 1] + 1;
		}
		else
			C[i] = C[i - 1];
	}
	while (cin >> N) {
		cout << C[N] << endl;
	}
	
	return 0;
}
