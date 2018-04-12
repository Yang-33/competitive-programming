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

/* -----  2018/04/12  Problem: yukicoder 054  / Link: http://yukicoder.me/problems/no/054  ----- */
/* ------問題------

今日はハロウィンなので、太郎君は近所の家におかしをもらいに行くことにしました。
近所には、太郎君の家以外に N軒の家があります。
それぞれのi家に行くとおかしをVi個もらえるのですが、
近所のこどもたちに平等におかしを配るため、
すでにおかしをTi個以上持っていると、おかしを一つももらえないことになっています。

太郎君は、最初におかしを一つも持っていないこととし、近所の家を周るのは好きな順番で周ることができるとき、
太郎君がもらえるおかしの最大の個数を求めてください。
同じ家には1回しか回れないとします。

-----問題ここまで----- */
/* -----解説等-----

順序が大事で、bitdpはできないので順序を自分で考える。
x番目とy番目で、どちらが先に訪れるのがうれしいかを考える。
x番目に先に訪れることでy番目を先に訪れた時よりも確実に良い結果を残すとき、
片側ではキャンディーを獲得できて片側では獲得できない状況が存在する。
つまり獲得について(y) or (x ->y)となる場合の比較基準を知りたい。

現在のキャンディー所持数をKとすると
K+v[x]<t[y], K+v[y]≧t[x]、と表現できる。
Kについて、t[x]-v[y]≦K<t[y]-v[x]、はさんでいる式について整理すれば
t[x]+v[x]<t[y]+v[y]のとき、xに先に訪れるのが最適といことになる。
したがってv+tが小さい順番に訪問していけばよく、これをdpで回していけばよい。

具体的にはある値Vについて、今までの情報から作成可能かつt[i]未満ならばV+v[i]も作成可能であるとすればよい。
dp[ 現在作成可能なキャンディー保持数 ]:=　作成可能/作成不可能

snukeさん
"""
家iを使うときは「今の値がTi以上ならViもらえる」ですが、適当な大きい数INFを使ってこれを言い換えて「値をINF-Ti増やしてから、INF-Ti-Vi減らす。ただし、途中で値がINFを超えては行けない」ということにする。これを折れ線で表してながめる。折れ線を後ろからくっつけていくことにしてみると、INF-Ti-Viが小さい順にくっつけていくのが良さそうなことが分かると思います。
"""
賢い。

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	vector<PII>a;
	VI v(N), t(N);
	FOR(i, 0, N) {
		cin >> v[i] >> t[i];
		a.push_back(PII(v[i] + t[i], i));
	}
	SORT(a);
	VI dp(20001, 0);
	dp[0] = 1;
	FOR(i, 0, N) {
		int id = a[i].second;
		FORR(h, t[id] - 1, 0 - 1) {
			dp[h + v[id]] |= dp[h];
		}
	}
	FOR(i, 0, 20001) {
		if (dp[i]) {
			ans = i;
		}
	}
	cout << ans << "\n";

	return 0;
}
