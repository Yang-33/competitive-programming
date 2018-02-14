#include <bits/stdc++.h>
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

/* -----  2018/02/14  Problem: 085_abc_c / Link: https://abc085.contest.atcoder.jp/tasks/abc085_c?lang=en  ----- */
/* ------問題------

日本でよく使われる紙幣は、10000 円札、5000 円札、1000 円札です。以下、「お札」とはこれらのみを指します。

青橋くんが言うには、彼が祖父から受け取ったお年玉袋にはお札が N 枚入っていて、合計で Y 円だったそうですが、嘘かもしれません。
このような状況がありうるか判定し、ありうる場合はお年玉袋の中身の候補を一つ見つけてください。
なお、彼の祖父は十分裕福であり、お年玉袋は十分大きかったものとします。

-----問題ここまで----- */
/* -----解説等-----

最後のパラメーターは全探索しなくても決定するのでO(N^2)ぐらいで解ける。

----解説ここまで---- */

LL N,Y;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);



	cin >> N>>Y;
	FOR(i, 0, 2001) {
		FOR(j, 0, 4001) {
			int s = N - i - j;
			if (s < 0)continue;
			LL ret = 10000LL * i + 5000LL * j + 1000LL * s;
			if (ret == Y) {
				cout << i << " " << j << " " << s << endl;
				return 0;
			}
		}
	}
	cout <<"-1 -1 -1" << "\n";

	return 0;
}
