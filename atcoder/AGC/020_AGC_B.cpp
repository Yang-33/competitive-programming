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

/* -----  2018/03/03  Problem: 020_agc_b / Link: https://agc020.contest.atcoder.jp/tasks/agc020_b?lang=en  ----- */
/* ------問題------

スケートリンクで、一人の大人の司会と N 人の子供がゲームを行います。 ゲームは K ラウンドからなり、ラウンド i では司会が次のように言います。
Ai 人組を作って！
すると、まだ脱落していない子供たちは Ai 人からなるグループをできるだけ多く組みます。 一人につき一つのグループにしか入れません。 グループに入れなかった子供たちは脱落し、その他は次のラウンドに進みます。 ラウンドで誰も脱落しないこともありえます。
最後まで、つまりラウンド K のあとまで残ったのは 2 人で、彼らが勝者となりました。
あなたは A1, A2, ..., AK の値を聞き、N の値は知りませんが、推定してみたくなりました。
ゲームの開始前にいた子供たちの人数として考えられる最小の値と、最大の値を求めてください。もしくは、考えられる N の値は存在しないと判定してください。

-----問題ここまで----- */
/* -----解説等-----

逆から実際の値の範囲を復元していく。
下限は次の条件を満たさないといけないので(a[i]での下限)
上限は条件を満たしていれば少し多くても大丈夫なので(上限 + (a[i]-1))

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	VI a(N);
	FOR(i, 0, N) {
		cin >> a[i];
	}
	reverse(ALL(a));
	ans = 1;
	if (a.front() != 2)ans = 0;

	LL L = 2, R = 2;

	FOR(i, 0, N) {
		LL x = (L + a[i] - 1) / a[i] * a[i];
		if (x < L || R < x)ans = 0;
		L = x;
		R = (R / a[i])* a[i] + (a[i] - 1); // 上げる
	}
	if (!ans) {
		cout << -1 << endl;
	}
	else {
		cout << L << " " << R << "\n";
	}
	return 0;
}
