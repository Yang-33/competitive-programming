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

/* -----  2019/07/19  Problem: AOJ 0071 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0071  ----- */



int main() {
	int T; cin >> T;
	FOR(_, 0, T) {
		const int N = 8;
		VS s(N); {
			FOR(i, 0, N) {
				cin >> s[i];
			}
		}
		int X, Y; cin >> X >> Y;
		X--, Y--;
		// (y,x)
		VVI checked(N, VI(N, 0));
		queue<PII>q;
		auto IFPUSH = [&](int y, int x) {
			if (checked[y][x] == 0 && s[y][x] == '1') {
				checked[y][x] = 1;
				s[y][x] = '0';
				q.push(PII(y, x));
			}
		};
		IFPUSH(Y, X);
		while (!q.empty()) {
			auto p = q.front(); q.pop();
			FOR(dy, -3, 3 + 1) {
				int ny = p.first + dy, nx = p.second + 0;
				if (0 <= ny && ny < N && 0 <= nx && nx < N) {
					IFPUSH(ny, nx);
				}
			}
			FOR(dx, -3, 3 + 1) {
				int ny = p.first, nx = p.second + dx;
				if (0 <= ny && ny < N && 0 <= nx && nx < N) {
					IFPUSH(ny, nx);
				}
			}

		}
		static int ca = 1;
		cout << "Data " << ca++ << ":\n";
		FOR(i, 0, N) {
			cout << s[i] << "\n";
		}
	}

	return 0;
}