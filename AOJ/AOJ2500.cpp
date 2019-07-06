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

/* -----  2019/07/07  Problem: AOJ 2500 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/2500  ----- */

inline int readint() { int in; scanf("%d", &in); return in; }
inline void outint(int out, bool endl = 1) { printf("%d%c", out, " \n"[endl]); }

int main() {
	int N = readint(), M = readint();
	VVI G(N);
	vector<PII>edge(M);
	FOR(i, 0, M) {
		int a = readint() - 1, b = readint() - 1;
		G[a].push_back(b), G[b].push_back(a);
		edge[i] = { a,b };
	}
	int D = 0;
	VI topdist(N); {
		FOR(i, 0, N) {
			D = max(D, topdist[i]);
			for (auto nx : G[i]) {
				if (i < nx) {
					topdist[nx] = max(topdist[nx], topdist[i] + 1);
				}
			}
		}
	}
	VI bottomdist(N); {
		FORR(i, N - 1, 0 - 1) {
			for (auto nx : G[i]) {
				if (i > nx) {
					bottomdist[nx] = max(bottomdist[nx], bottomdist[i] + 1);
				}
			}
		}
	}
	VVI depthset(N); {
		int cnt = 0;
		for (auto e : edge) {
			int a = e.first, b = e.second;
			if (topdist[a] + 1 + bottomdist[b] == D) {
				depthset[topdist[a]].push_back(cnt);
			}
			cnt++;
		}
	}
	VI ans; {
		FOR(i, 0, N) {
			if (SZ(depthset[i]) == 1) {
				ans.push_back(depthset[i].front());
			}
		}
	}
	if (SZ(ans)) {
		SORT(ans);
		for (auto it : ans) {
			outint(it+1);
		}
	}
	else {
		outint(-1);
	}
	return 0;
}
