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

/* -----  2018/04/12  Problem: yukicoder 060  / Link: http://yukicoder.me/problems/no/060  ----- */
/* ------問題------

魔法少女Madokaは魔女Walpurgisnachtと戦っていた。
Walpurgisnachtは複数の使い魔を使役しているため、短時間ですべての敵にダメージを与えない限り倒せない。
そこでMadokaは範囲に対する攻撃魔法を使用し、効率的に敵を倒そうと考えた。

Walpurgisnachtとその使い魔の座標と体力、Madokaが攻撃した範囲と敵に与えるダメージが与えられるので、
倒せていない敵の残り体力の合計を答えよ。

-----問題ここまで----- */
/* -----解説等-----

範囲への加算はimos法でやるのがクエリの内容的にもよさそう。
先にあるマスにいると与えられるダメージを先に計算しておく。
その後敵の位置とHPから、体力の残りを計算すれば良い。

----解説ここまで---- */

LL N, K;

LL ans = 0LL;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> K;

	using tp = tuple<int, int, int>;
	vector<tp>infos(N);
	for (tp& info : infos) {
		int x, y, hp; cin >> x >> y >> hp;
		x += 500, y += 500;
		info = tie(x, y, hp);
	}
	VVL dm(1504, VL(1504, 0));
	FOR(_, 0, K) {
		int x, y, w, h, d; cin >> x >> y >> w >> h >> d;
		x += 500, y += 500;
		dm[x + 1][y + 1] += d;
		dm[x + 1][y + h + 1 + 1] += -d;
		dm[x + w + 1 + 1][y + 1] += -d;
		dm[x + w + 1 + 1][y + h + 1 + 1] += d;
	}

	FOR(i, 0, 1502)FOR(j, 0, 1502)dm[i + 1][j + 1] += dm[i + 1][j] + dm[i][j + 1] - dm[i][j];

	for (const tp& info : infos) {
		int x, y, hp;
		tie(x, y, hp) = info;
		int lefthp = hp - dm[x + 1][y + 1];
		if (lefthp > 0) {
			ans += lefthp;
		}
	}
	cout << ans << "\n";

	return 0;
}
