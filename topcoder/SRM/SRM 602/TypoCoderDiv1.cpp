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

/* -----  xtimex  Problem: SRM 602 div1 easy / Link: __CONTEST_URL__  ----- */
/* ------問題------

ratingが2200以上をbrown coder,それ未満をciel coderと呼ぶ。
初期レートXとコンテストのrating変化Dが与えられる。これらに符号を割り当て、レートの変化を行う。
2200以上である状態が連続しないとしたとき、最大何回coderの名称を変化させられるか?

-----問題ここまで----- */
/* -----解説等-----

最後までどうするのが最適化わからないので、DPで解きたい。が、愚直なdpを考えると、
dp[t][i]:=t回目でレートがiになるときの変化の最大値となり、iの空間が10^9となってしまう。
ここで、2200以上が2回以上連続しないという制約を考えると、2200以上のものがそれ以上になるときは遷移しなくても良いということがわかり、2200以上はかなり疎であることがわかる。
したがってそのような遷移をmapの上で書けば良い。

O(Rating*NlogRating) (logはとれる)

----解説ここまで---- */


class 	TypoCoderDiv1 {
public:
	long long getmax(VI D, int X) {
		// mapでDPすればよさそう? =>定数4000以内でできるはず
		map<LL, LL>dp;
		dp[X] = 0;
		int N = SZ(D);
		FOR(i, 0, N) {
			LL d = D[i];
			map<LL, LL>nx;
			for (auto it : dp) {
				if (it.first < 2200) {
					LL sub = nx[it.first + d];
					nx[it.first + d] = max(sub, it.second + (it.first + d >= 2200));
					if (d) {
						LL rate = max(0LL, it.first - d);
						sub = nx[rate];
						nx[rate] = max(sub, it.second);
					}
				}
				if (it.first >= 2200 && it.first - d < 2200) {
					LL rate = max(0LL, it.first - d);
					LL sub = nx[rate];
					nx[rate] = max(sub, it.second + 1);
				}
			}
			nx.swap(dp);
		}
		LL ans = 0;
		for (auto it : dp) {
			ans = max(ans, it.second);
		}

		DD(de(ans));
		return ans;
	}

};