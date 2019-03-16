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

/* -----  2019/03/12  Problem: ABC 085 D / Link: http://abc085.contest.atcoder.jp/tasks/abc085_d  ----- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, H; cin >> N >> H;
	vector<LL> a(N), b(N);
	for (int i = 0; i < N; ++i) {
		cin >> a[i] >> b[i];
	}

	LL ans = 0LL;
	vector<PLL>x;
	FOR(i, 0, N) {
		x.push_back(PLL(a[i], 0));
		x.push_back(PLL(b[i], 1));
	}
	RSORT(x);
	for (auto it : x) {
		if (H <= 0)break;
		if (it.second) {
			H -= it.first;
			ans++;
		}
		else {
			LL k = (H - 1 + it.first) / it.first;
			ans += k;
			H -= k * it.first;
		}
	}
	
	
	cout << (ans) << "\n";

	return 0;
}
