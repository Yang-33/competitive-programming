#include "bits/stdc++.h"
using namespace std;

using VS = vector<string>;    using LL = long long;
using VI = vector<int>;       using VVI = vector<VI>;
using PII = pair<int, int>;   using PLL = pair<LL, LL>;
using VL = vector<LL>;        using VVL = vector<VL>;

#define ALL(a)  begin((a)),end((a))
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define EB emplace_back
#define MP make_pair
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

/* -----  2017/10/04  Problem: Nagoya_univ_contest_17_d  / Link: http://tenka1-2017-beginner.contest.atcoder.jp/tasks/tenka1_2017_b  ----- */
/* ------問題------

何人かの人がゲームをしました。全ての人の点数は異なる非負整数でした。
高橋君は、N 個の情報を持っています。
i 個目の情報は、得点の大きいほうから Ai 番目の人の得点が Bi 点であったことを表します。
ゲームの参加人数としてありうる最大値を求めてください。

-----問題ここまで----- */
/* -----解説等-----

順位の高い人は点数を何点としてもよいので、
最低の順位の人の下に入ることのできる人数を考えればよい。

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	int max = -1;
	FOR(i, 0, N) {
		int a, b;
		cin >> a >> b;
		if (a > max) {
			ans =b+a;
			max = a;
		}
	}
	
	cout << ans << "\n";

	return 0;
}