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

/* -----  2019/07/21  Problem: AOJ 0146 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0146  ----- */


// bitdpの復元
int main() {
	int N; cin >> N;
	VI id(N);
	VL d(N), w(N);
	FOR(i, 0, N) {
		cin >> id[i] >> d[i] >> w[i];
	}
	VL wsum(1 << N, 0); {
		FOR(state, 0, 1 << N) {
			LL s = 0;
			FOR(i, 0, N) {
				if (state & 1 << i)s += w[i];
			}
			wsum[state] = s;
		}
	}
	auto speed = [&](LL w) {return 2000.0 / (70 + 20 * w); };
	auto dist = [&](int i, int j) {return abs(d[i] - d[j]); };
	vector<vector<double>> dp(1 << N, vector<double>(N, LINF));
	FOR(i, 0, N) {
		dp[1 << i][i] = 0;
	}
	VVI rev(1 << N, VI(N, -1));// 戻れるようにする
	FOR(state, 0, 1 << N) {
		FOR(from, 0, N) {
			if (!(state & 1 << from))continue;
			FOR(to, 0, N) {
				if (state & 1 << to)continue;
				double nd = dp[state][from] + dist(from, to) / speed(wsum[state]);
				int ns = state | (1 << to);
				if (dp[ns][to] > nd) {
					dp[ns][to] = nd;
					rev[ns][to] = from;
				}
			}
		}
	}
	int t = -1;
	{
		double mn = LINF;
		FOR(i, 0, N) {
			if (dp[(1 << N) - 1][i] < mn) {
				mn = dp[(1 << N) - 1][i];
				t = i;
			}
		}
	}
	DD(de(t));
	// t->s
	VI path = { t }; {
		int state = (1 << N) - 1;
		for (;;) {
			bitset<10> bs = state;
			DD(de(bs, t));
			int pre = t;
			t = rev[state][t];
			if (t == -1)break;
			path.push_back(t);
			state ^= 1 << pre;
			bitset<10> ns = state;
			DD(de(ns, t));
		}
	}

	reverse(ALL(path));
	FOR(i, 0, SZ(path)) {
		cout << id[path[i]] << " \n"[i + 1 == SZ(path)];
	}
}