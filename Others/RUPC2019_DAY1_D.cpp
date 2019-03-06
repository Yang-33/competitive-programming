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

/* -----  2019/03/05  Problem: rupc2019_day1 D / Link: __CONTEST_URL__  ----- */



int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	enum Enum { YES, NEAR, NO };

	long long  N, K; cin >> N >> K;
	auto ask = [](int num) {
		cout << num << endl;
		string s; cin >> s;
		if (s == "No")return NO;
		else if (s == "Yes")return YES;
		else return NEAR;
	};
	bitset<210>bs;
	VVI G(210);
	// p個おきに作成
	auto make_edge = [&G](int A, int L, int R, int P) {
		for (int i = L; i < R;) {
			FOR(k, 0, P) {
				if (i + k < R)
					G[A].push_back(i + k);
			}
			i += 2 * P;
		}
	};
	auto out = [&]() {
		int cnt = 0;
		FOR(i, 1, N + 1) {
			cnt += SZ(G[i]);
		}
		DD(de(cnt));
		cout << cnt << endl;
		FOR(i, 1, N + 1) {
			for (auto it : G[i]) {
				cout << i << " " << it << endl;
			}
		}
	};
	auto solve = [&make_edge, &ask, &G, &bs, &out](int  N) {
		FOR(i, 1, N + 1)bs[i] = 1;
		// ask
		int altV = min(9, N);
		FOR(i, 1, altV + 1) {
			auto res = ask(i);
			if (res == YES)return;
			else if (res == NO) {
				// G(i)に含まれる頂点を消す
				bs[i] = 0;
				for (auto it : G[i]) {
					bs[it] = 0;
				}
			}
			else { // Near
				   // G(i)にふくまれない頂点を消す
				bs[i] = 0;
				FOR(it, altV + 1, N + 1) {
					bool find = 0;
					for (auto p : G[i]) {
						if (it == p)find = 1;
					}
					if (!find) {
						bs[it] = 0;
					}
				}
			}
		}
		int ans = 0;
		FOR(i, 1, N + 2) {
			if (bs[i]) {
				ans = i;
				ask(ans);
				break;
			}
			if (i == N + 1)assert(0);
		}

	};
	// graph make
	int altV = min(9LL, N);
	FOR(i, 1, altV + 1) {
		make_edge(i, altV + 1, N + 1, pow(2, i - 1));
	}
	out();

	for (int i = 0; i < K; i++) {
		solve(N);
	}

	return 0;
}

