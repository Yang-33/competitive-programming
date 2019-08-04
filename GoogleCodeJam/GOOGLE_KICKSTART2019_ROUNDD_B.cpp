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

/* -----  2019/07/28  Problem: GOOGLE_KICKSTART2019_ROUNDD B / Link: https://codingcompetitions.withgoogle.com/kickstart/round/0000000000051061  ----- */


// Latest Guests
void solve(int testcasenum) {
	int N, G, M; cin >> N >> G >> M;
	vector<pair<int, VI>>Hs(N); {
		FOR(i, 0, N)Hs[i] = { -1,VI({-1}) };
	};
	auto update = [&](int h, int t, int who) {
		if (Hs[h].first < t) {
			Hs[h] = { t,VI({who}) };
		}
		else if (Hs[h].first == t) {
			Hs[h].second.emplace_back(who);
		}
	};
	FOR(g, 0, G) {
		int pos; char C;
		cin >> pos >> C;
		pos--;
		int add = (C == 'C' ? 1 : -1);
		// Mstep
		FOR(step, 0, M+1) {
			update(pos, step, g);
			pos += add;
			pos += N; pos %= N;
		}
		//FOR(i, 0, N) {
		//	DD(de(i, Hs[i].first); De(Hs[i].second));
		//}
	}
	//exit(0);
	VI ans(G); {
		FOR(i, 0, N) {
			auto it = Hs[i];
			for (auto who : it.second) {
			//	DD(de(i); De(who));
				if (who != -1) {
					ans[who]++;
				}
			}
		}
	}


	cout << "Case #" << testcasenum << ": ";
	FOR(i, 0, G) {
		cout << ans[i] << " \n"[i + 1 == G];
	}
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
4
5 3 2
5 C
2 A
1 A
2 4 0
1 A
1 C
1 A
1 C
3 2 10
3 C
2 A
6 1 6
4 A
[1 output]:
Case #1: 2 2 1
Case #2: 1 1 1 1
Case #3: 2 2
Case #4: 6
*/