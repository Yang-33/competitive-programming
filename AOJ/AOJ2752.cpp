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
#define debug(x) cerr << #x << ": " << x << endl
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/06/10  Problem: AOJ 2752 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2752  ----- */
/* ------問題------

肉西くんは指の数を増やしたり減らしたりできる．
肉西くんの前には n 個のまんじゅうがある．
肉西くんは指を折ってまんじゅうの個数を数えようとしている．
肉西くんの指が取れる形は折れているか折れていないかの 2 つしか無い．
肉西くんは 2 進数を理解している．
肉西くんは各指に 2 進数の桁を対応させて数を数えることが出来る．
肉西くんは対数を理解していない．
肉西くんのかわりにまんじゅうを数え上げるのに必要な指の本数の最小値を求めよ．

-----問題ここまで----- */
/* -----解説等-----

求めます

----解説ここまで---- */

int main() {
	LL n;
	cin >> n;
	LL i = 1;
	int cnt = 0;
	while (i <= n) {
		i <<= 1;
		cnt++;
	}
	cout << cnt << endl;

	return 0;
}