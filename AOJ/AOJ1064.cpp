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

/* -----  2019/07/07  Problem: AOJ 1064 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/1064  ----- */


int main() {
	int N;
	int p = 0;
	while (cin >> N, N) {
		if (p) cout << endl;
		p++;
		vector<int>sx, sy, tx, ty; {
			FOR(i, 0, N) {
				int a, b, c, d; cin >> a >> b >> c >> d;
				sx.push_back(a), sy.push_back(b), tx.push_back(c), ty.push_back(d);
			}
		}
		vector<int>idx(N, 0); {
			iota(idx.begin(), idx.end(), 0);
		}
		vector<int>order(N, -1);// !!
		int anscnt = 0;

		// [hei]
		auto sq_in = [&](int i, int LX, int RX, int DONWY, int UPY) {
			bool ok = 1;
			if (RX >= tx[i] && sx[i] >= LX) {}
			else ok = 0;
			if (UPY >= ty[i] && sy[i] >= DONWY) {}
			else ok = 0;
			return ok;
		};

		function<void(vector<int>)> f = [&](vector<int>leftid) {
			if (leftid.size() == 0) return;
			if (leftid.size() == 1) {
				order[leftid[0]] = anscnt++;
				return;
			}
			// right up decision
			using pii = pair<int, int>;
			int i;
			pii T = { 100000, 100000 }; {
				for (auto id : leftid) {
					if (T > pii(sx[id], ty[id])) {
						T = pii(sx[id], ty[id]);
						i = id;
					}
				}
			}

			// use
			order[i] = anscnt;
			anscnt++;


			int LX = sx[i], RX = 0;
			int SITAY = ty[i];
			// <- nobasu!
			{
				RX = 10000;
				for (auto id : leftid) {
					if (SITAY > sy[id] && SITAY < ty[id]) {
						RX = min(RX, sx[id]);
					}
				}
			}

			vector<int> nextid;
			vector<int>nxnxid;
			for (auto it : leftid) {
				if (it == i) continue;
				// if [LX..RX] SITAY ni hukumareru
				if (sq_in(it, LX, RX, -10000, SITAY)) {
					nextid.push_back(it);
				}
				else {
					nxnxid.push_back(it);
				}
			}

			f(nextid);
			f(nxnxid);

		};

		f(idx);

		for (auto v : order) {
			cout << v + 1 << endl;
		}
	}
}
