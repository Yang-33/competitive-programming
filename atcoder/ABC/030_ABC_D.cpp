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

/* -----  2019/04/07  Problem: ABC 030 D / Link: http://abc030.contest.atcoder.jp/tasks/abc030_d  ----- */

LL str_mod(const string &s, int mod) {
	LL res = 0;
	for (auto c : s) {
		res *= 10;
		res += (c - '0');
		res %= mod;
	}
	return res;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, a; cin >> N >> a;
	a--;
	string k; cin >> k;
	VI nextto(N);
	FOR(i, 0, N) {
		int to; cin >> to;
		to--;
		nextto[i] = to;
	}
	auto simulation = [&nextto](LL leftk, int pos) {
		FOR(t, 0, leftk) {
			pos = nextto[pos];
		}
		return pos;
	};
	if (SZ(k) < 7) {
		int leftk = stoi(k);
		cout << simulation(leftk, a) + 1 << endl;
		return 0;
	}

	VI visittime(N);
	int pos = a;
	int now_t = 1;
	int loopsize = 0;
	{
		while (1) {
			visittime[pos] = now_t++;
			pos = nextto[pos];
			if (visittime[pos]) {
				loopsize = now_t - visittime[pos];
				break;
			}
		}
	}
	int leftk = str_mod(k, loopsize) + loopsize * ((N + loopsize - 1) / loopsize);
	cout << simulation(leftk, a) + 1 << endl;
	// loopsizeでmodをとって，シュミレーション

	return 0;
}
