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

/* -----  2019/09/30  Problem: GOOGLE_KICKSTART2019_ROUNDF C / Link: https://codingcompetitions.withgoogle.com/kickstart/about  ----- */


// Spectating Villages(13pts, 29pts)
void solve(int testcasenum) {
	int N; cin >> N;
	DD(de(N));
	vector<LL> a(N);
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
	}
	DD(De(a));
	VVI G(N); {
		FOR(i, 0, N - 1) {
			int x, y; cin >> x >> y;
			x--, y--;
			G[x].push_back(y);
			G[y].push_back(x);
		}
	}
	LL ans = 0;
	VL visit(N, 0);
	FOR(state, 0, 1 << N) {
		{ // reset
			FOR(i, 0, N)visit[i] = 0;
		}

		FOR(i, 0, N) {
			if (state & 1 << i) {
				visit[i] = 1;
				for (auto v : G[i]) {
					visit[v] = 1;
				}
			}
		}
		LL sum = 0;
		FOR(i, 0, N) {
			if (visit[i])sum += a[i];
		}
		ans = max(ans, sum);
	}


	cout << "Case #" << testcasenum << ": ";
	cout << ans << "\n";
}

template<typename F>
struct FixPoint : F {
	FixPoint(F&& f) noexcept :F(forward<F>(f)) {}
	template<typename... Args>
	constexpr decltype(auto) operator()(Args&&... args) const noexcept {
		return F::operator()(*this, forward<Args>(args)...);
	}
};

template<typename F>
static inline constexpr decltype(auto) FUNC(F&& f) noexcept {
	return FixPoint<F>{forward<F>(f)};
}



void solve2(int testcasenum) {
	int N; cin >> N;
	DD(de(N));
	vector<LL> a(N);
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
	}
	VVI G(N); {
		FOR(i, 0, N - 1) {
			int x, y; cin >> x >> y;
			x--, y--;
			G[x].push_back(y);
			G[y].push_back(x);
		}
	}

	VVL dp(N, VL(3, -LINF));
	enum State {
		Direct,
		InDirect,
		No
	};
	auto func = FUNC([&](auto f, int v, int p) ->void {
		for (auto nx : G[v]) {
			if (nx == p)continue;
			f(nx, v);
		}
		dp[v][Direct] = a[v];
		dp[v][No] = 0;
		for (auto nx : G[v]) {
			if (nx == p)continue;
			// Direct 
			dp[v][Direct] += max({
				dp[nx][Direct],
				dp[nx][InDirect],
				dp[nx][No] + a[nx] });

			// No
			dp[v][No] += max({
				dp[nx][InDirect],
				dp[nx][No] });
		}

		// InDirect
		int cmaxid = -1;
		LL valmax = -LINF;
		for (auto nx : G[v]) {
			if (nx == p)continue;
			LL val = dp[nx][Direct]
				- max({
				dp[nx][Direct],
				dp[nx][InDirect],
				dp[nx][No] });
			if (valmax <= val) {
				valmax = val;
				cmaxid = nx;
			}
		}
		if (cmaxid == -1)return;

		dp[v][InDirect] = a[v] + dp[cmaxid][Direct];
		//DD(de(v, cmaxid));
		for (auto nx : G[v]) {
			if (nx == p)continue;
			if (cmaxid == nx)continue;

			dp[v][InDirect] += max({
				dp[nx][Direct],
				dp[nx][InDirect],
				dp[nx][No]});
		}

	});

	func(0, -1);
	//FOR(i, 0, N) {
	//	DD(de(i+1,dp[i][Direct],dp[i][InDirect],dp[i][No]))
	//}
	LL ans = max({ dp[0][Direct],dp[0][InDirect],dp[0][No] });
	std::cout << "Case #" << testcasenum << ": ";
	std::cout << ans << "\n";
}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int T; cin >> T;
	FOR(t, 0, T) {
		solve2(t + 1);
	}

	return 0;
}

/*
[1 input]:
3
9
-10 4 -10 8 20 30 -2 -3 7
1 4
2 4
4 3
9 4
9 8
7 5
6 7
7 9
4
-2 20 20 20
1 2
1 3
1 4
5
-5 -10 8 -7 -2
5 4
4 3
3 2
2 1
[1 output]:
Case #1: 67
Case #2: 58
Case #3: 0

*/
