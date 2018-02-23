#include <bits/stdc++.h>
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

/* -----  2018/02/23  Problem: 084_abc_d / Link: https://abc084.contest.atcoder.jp/tasks/abc084_d?lang=en  ----- */
/* ------問題------

「N も (N+1)÷2 も素数」を満たす奇数 N を 2017に似た数 とします。
Q 個のクエリが与えられます。
クエリ i(1≦i≦Q) では奇数 li,ri が与えられるので、li≦x≦ri かつ 2017に似た数 となる奇数 x の個数を求めてください。

-----問題ここまで----- */
/* -----解説等-----

素数表ができれば後は適当に2017っぽい数がわかるので累積和をとれば十分高速。

----解説ここまで---- */

LL N;

LL ans = 0LL;
#define primeN 100000
bool prime[primeN + 1];// 外部だとハッシュ表みたいになる
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
#undef primeN 

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	make_prime();

	VI like2017(100001, 0);
	FOR(i, 1, 100001) {
		if (i % 2 == 1 && prime[i] && prime[(i + 1) / 2]) {
			like2017[i] = 1;
		}
	}
	VI sum(100002, 0);
	FOR(i, 0, 100001) {
		sum[i + 1] += sum[i]+ like2017[i];
	}

	cin >> N;
	FOR(i, 0, N) {
		int L, R;
		cin >> L >> R;
		cout << sum[R+1] - sum[L] << endl;
	}

	return 0;
}
