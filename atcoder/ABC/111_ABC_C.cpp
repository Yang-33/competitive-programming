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

/* -----  2019/02/27  Problem: ABC 111 C / Link: http://abc111.contest.atcoder.jp/tasks/abc111_c  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----



----解説ここまで---- */

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N; 
	cin >> N;
	
	vector<LL> a,b;
	for (int i = 0; i < N; ++i) {
		LL x; cin >> x;
		if (i % 2) {
			a.push_back(x);
		}
		else {
			b.push_back(x);
		}
	}
	auto f = [](VL & a) {
		// aの頻度2top
		map<LL, LL>M;
		for (auto it : a) {
			M[it]++;
		}
		vector<PII> b;
		for (auto it : M) {
			b.push_back(PII(it.second,it.first));
		}
		b.push_back(PII(0, INF));
		RSORT(b);

		VI res({b[0].second,b[1].second});
		return res;
	};


	// 頻度2top
	VI as = f(a);
	VI bs = f(b);
	auto g = [](const VL& a, const LL x) {
		LL cnt = 0;
		for (auto it : a) {
			if (it != x)cnt++;
		}

		return cnt;
	};
	ans = INF;
	for (auto aa : as) {
		for (auto bb : bs) {
			if(aa!=bb)
			ans = min(ans, g(a,aa)+g(b,bb));
		}
	}


	
	cout << ans << "\n";

	return 0;
}
