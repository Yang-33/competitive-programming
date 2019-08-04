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

/* -----  2019/07/28  Problem: GOOGLE_KICKSTART2019_ROUNDD A / Link: https://codingcompetitions.withgoogle.com/kickstart/round/0000000000051061  ----- */

// 1024 !! -> 2^10 
// 10 times solve (?)

// X or What?
void solve(int testcasenum) {

	int N, Q; cin >> N >> Q;
	vector<int> a(N);
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
	}
	VI result;
	FOR(_, 0, Q) {
		int p, v; cin >> p >> v;
		a[p] = v;
		VI b(N + 1); {
			FOR(i, 0, N) {
				b[i + 1] = b[i] ^ a[i];
			}
		}
		auto query = [&](int L, int R) {
			return b[R] ^ b[L];
		};
		int ans = 0;
		FOR(i, 0, N) {
			FOR(j, i + 1, N + 1) {
				int res = query(i, j);
				int interval = __builtin_popcount(res);
				DD(de(i, j, res, interval));
				if (interval % 2 == 0) {
					ans = max(ans, j - i);
				}
			}
		}
		result.push_back(ans);
	}

	cout << "Case #" << testcasenum << ": ";
	FOR(i, 0, SZ(result)) {
		cout << result[i] << " \n"[i + 1 == SZ(result)];
	}
}

// 各桁のxorはなんか和にしてもmod2は変わらない
// 偶奇列の管理になる．
// 和が偶数というのは全体の和が奇数のとき，最左右を除いた部分の長さ
// 全体の和が偶数のときはN

void solve2(int testcasenum) {

	int N, Q; cin >> N >> Q;
	vector<int> a(N);
	set<int>se;
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
		int b = __builtin_popcount(a[i]) % 2;
		if (b)se.insert(i);
		a[i] = b;
	}
	VI result;
	int sum = accumulate(ALL(a), 0);
	FOR(_, 0, Q) {
		int p, v; cin >> p >> v;
		v = __builtin_popcount(v) % 2;
		if (v != a[p]) {
			if (v) {
				se.insert(p);
				sum++;
			}
			else {
				se.erase(p);
				sum--;
			}
		}
		a[p] = v;

		int ans = (sum % 2 ? 0 : N);
		if (SZ(se)) {
			auto it = se.begin();
			ans = max({ ans, *it,N - 1 - *it });
			it = prev(se.end());
			ans = max({ ans, *it,N - 1 - *it });
		}
		result.push_back(ans);
	}

	cout << "Case #" << testcasenum << ": ";
	FOR(i, 0, SZ(result)) {
		cout << result[i] << " \n"[i + 1 == SZ(result)];
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int T; cin >> T;
	FOR(t, 0, T) {
		//solve(t + 1);
		solve2(t + 1);
	}

	return 0;
}

/*
[1 input]:
2
4 3
10 21 3 7
1 13
0 32
2 22
5 1
14 1 15 20 26
4 26
[1 output]:
Case #1: 4 3 4
Case #2: 4
*/