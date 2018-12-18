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
const LL MOD = 998244353;                   const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/10/25  Problem: EDU053 E / Link: __CONTEST_URL__  ----- */
/* ------問題------

[L:R]にふくまれる数のうち、使用される数字の数がK個以下のものの総和は?

-----問題ここまで----- */
/* -----解説等-----

桁DPを場合の数と数字の両方でやるだけ

----解説ここまで---- */

int k;
PLL dp[20][1024][10][2][2];
LL ten[20];
const PLL ee = PLL(-1, 0);
PLL f(const string& s, int id, int num = 0, int mask = 0, bool lz = 1, bool less = 0) {
	if (id < 0) {
		return PLL(1, 0);
	}
	if (dp[id][mask][num][lz][less] != ee)return dp[id][mask][num][lz][less];

	PLL res = PLL(0, 0);


	int Max = less ? 9 : s[id] - '0';
	FOR(nx, 0, Max + 1) {
		bool nlz = lz;
		if (lz&& nx==0)nlz = 1;
		else nlz = 0;

		int nmask = mask;
		if (nlz==0)nmask |= 1 << nx;

		if (__builtin_popcount(nmask) > k)continue;

		PLL a = f(s, id - 1, nx, nmask, nlz, less || (nx < Max));
		res.first += a.first;
		res.first %= MOD;
		res.second += (nx*ten[id] % MOD)*a.first%MOD + a.second%MOD;
		res.second %= MOD;
	}

	return dp[id][mask][num][lz][less] = res;
}




int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	ten[0] = 1;
	FOR(i, 1, 20) {
		ten[i] = ten[i - 1] * 10;
		ten[i] %= MOD;
	}
	LL L, R; cin >> L >> R;
	cin >> k;
	L--;
	string Ls = to_string(L);
	string Rs = to_string(R);
	DD(de(Ls, Rs, k));
	reverse(ALL(Ls));
	reverse(ALL(Rs));
	fill(****dp, ****dp + 20 * 1024 * 10 * 2 * 2, ee);
	LL ans = f(Rs, SZ(Rs) - 1).second;
	DD(de(ans));
	fill(****dp, ****dp + 20 * 1024 * 10 * 2 * 2, ee);
	LL ret = f(Ls, SZ(Ls) - 1).second;
	if (ret < 0)ret += MOD;
	ans -= ret;
	ans += MOD;
	ans += MOD;
	ans %= MOD;
	cout << ans << "\n";

	return 0;
}
