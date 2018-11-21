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

/* -----  2018/11/21  Problem: ARC 055 C / Link: http://arc055.contest.atcoder.jp/tasks/arc055_c  ----- */
/* ------問題------

シカのAtCoDeerくんは、たかいたい(高い鯛)が大好きです。ところでこの文字列は空でない文字列ABCを使ってABCAC(文字列を連結したもの)と書けます(
そこで、AtCoDeerくんは文字列Sに対して、このような分割が何通りあるか求めることにしました。

-----問題ここまで----- */
/* -----解説等-----

// |A|B|C|A|C|のうち、ACの区間を決定して、
// AC←とA→の一致、
// AC→とC←の一致を見れば良い
これに気づくためには、どれかを切り出したときの構造に着目する必要がある。
例えば、Bを切り出した時、Aが決定されるので、CAC中にAが含まれるかを判定する必要がある。
これはsuffixarrayでできそう。(残りの区間はhashでやる)　
ん、できたけど…
同様にAやCを決める等すると、ACを決めた際に両方向から見れば一致長がわかるきがしてきて、これはLCPをみればできる

これ解法無限にありそう zalgorithmでもsaでもできるので…

----解説ここまで---- */

using uLL = unsigned long long;
const uLL _base = 1e9 + 7;
struct RollingHash {
	vector<uLL> hashed, power;
	RollingHash(const string& s) {
		int sz = s.size();
		hashed.assign(sz + 1, 0);
		power.assign(sz + 1, 0);

		power[0] = 1;
		for (int i = 0; i < sz; i++) {
			power[i + 1] = power[i] * _base;
		}
		for (int i = 0; i < sz; i++) {
			hashed[i + 1] = (hashed[i] + s[i]) * _base;
		}
	}
	uLL get(int l, int r) { // [l, r)
		return((hashed[r] - hashed[l] * power[r - l]));
	}
	int LCP(RollingHash& b, int l1, int r1, int l2, int r2) {
		int len = min(r1 - l1, r2 - l2);
		int low = -1, high = len + 1;
		while (high - low > 1) {
			int mid = (low + high) >> 1;
			if (get(l1, l1 + mid) == b.get(l2, l2 + mid)) low = mid;
			else high = mid;
		}
		return(low);
	}
};



int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string s; cin >> s;
	RollingHash pre(s);
	reverse(ALL(s));
	RollingHash suf(s);
	reverse(ALL(s));
	LL ans = 0;

	// |A|B|C|A|C|のうち、ACの区間を決定して、
	// AC←とA→の一致、
	// AC→とC←の一致を見れば良い

	for (int i = 2; 2 * i < SZ(s); ++i) {
		int Alcp = pre.LCP(pre, 0, SZ(s), SZ(s) - i, SZ(s));
		int Clcp = suf.LCP(suf, 0, SZ(s), i, SZ(s));
		int AClen = i;
		Alcp = min(Alcp, AClen - 1);
		Clcp = min(Clcp, AClen - 1);
		int ACid = SZ(s) - i;
		DD(de(s[ACid], Alcp, Clcp, AClen, ans));
		if (Alcp + Clcp < AClen)continue;
		if (Alcp == 0 || Clcp == 0)continue;
		ans += Alcp + Clcp - AClen + 1;
	}
	cout << ans << endl;

	return 0;
}
