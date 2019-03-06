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

/* -----  2019/02/28  Problem: ABC 108 D / Link: http://abc108.contest.atcoder.jp/tasks/abc108_d  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

2べきでつくりたくなるのはそう．
\sum 2^i = N+1なら0と数字をつなげるだけ．
それ以上のNである場合はどうするかが問題になる．
なんか折り返せば行けそう！みたいな考えを持ったけどN-1が2進で10101のときとかは厳しそう．
1,2,4,8,..は前から連続で取れば連続した値を作れることに着目する．
p+\sum 2^k で残った値を被覆することを考える．
これはlogなので覆っていけば良い．

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N; cin >> N;
	LL Mxidx = 1;
	int idxcnt = 0;
	while (Mxidx * 2 <= N)Mxidx *= 2, idxcnt++;
	DD(de(N, Mxidx, idxcnt));
	N--;
	// idxcnt分はつくる
	int ansN = idxcnt + 1;
	using tp = tuple<int, int, int>;
	vector<tp>ans;
	{
		FOR(i, 0, idxcnt) {
			ans.push_back(tp(i + 1, i + 2, 1 << i));
			ans.push_back(tp(i + 1, i + 2, 0));
		}
	}
	LL sum = 0;
	FOR(i, 0, idxcnt) {
		sum += 1 << i;
	}
	DD(de(sum, N));
	FOR(i, sum + 1, N + 1) {
		DD(de(i));
		int cur = i;
		int addsum = 0;
		FOR(j, 0, idxcnt) {
			int add = 1 << j;
			if (cur + add <= N) {
				cur += add;
				addsum += add;
			}
			else {

				ans.push_back(tp(j + 1, idxcnt + 1, i));
				i += addsum;
				break;
			}
		}
	}



	cout << ansN << " " << SZ(ans) << endl;
	for (auto it : ans) {
		int a, b, c; tie(a, b, c) = it;
		cout << a << " " << b << " " << c << endl;
	}

	return 0;
}
