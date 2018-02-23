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

/* -----  2018/02/23  Problem: 068_arc_b / Link: https://arc068.contest.atcoder.jp/tasks/arc068_b?lang=en  ----- */
/* ------問題------

すぬけくんはカードゲームで遊ぶことにしました。 N 枚からなるカードの山があり、上から i 枚目のカードには整数 Ai が書かれています。
すぬけくんはこのカードの山に対し 0 回以上、以下の操作を行い、残ったカードに書かれた値が互いに異なるようにしたいです。最大で何枚のカードを残すことが可能か求めなさい。なお、N は奇数であり、少なくとも 1 枚のカードを残すことが可能であることが保証されます。
操作：カードの山から任意の 3 枚のカードを抜き出す。抜き出したカードのうち書かれた値が最大であるようなカード 1 枚と最小であるようなカード 1 枚の合計 2 枚を選んで食べる。その後残った 1 枚をカードの山に戻す。

-----問題ここまで----- */
/* -----解説等-----

数字をまとめて個数で考える。
3個以上のものは同じものだけを選択することで全部1か2になる。
2についてこれらは全て選択し他の2あるいは1も選択する。
2が偶数個あるときは数自体を減らさずに個数のみを減らせる。
奇数個のときは最後の1つだけが相手が見つからず誰かを消すことになる。
これを書けば良い。

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	VI a(N);
	VI cnt(100005);
	FOR(i, 0, N) {
		cin >> a[i];
		cnt[a[i]]++;
	}
	VI pq;
	FOR(i, 0, 100005) {
		if (cnt[i])pq.push_back(cnt[i]);

	}
	int even = 0;
	FOR(i, 0, SZ(pq)) {
		if (pq[i] % 2 == 0)even++;
	}
	ans = SZ(pq);
	if (even % 2 == 1)ans--;
	cout << ans << "\n";

	return 0;
}
