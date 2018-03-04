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

/* -----  2018/03/03  Problem: yahoo-procon-2018-qual_c / Link: https://yahoo-procon2018-qual.contest.atcoder.jp/tasks/yahoo_procon2018_qual_c?lang=en  ----- */
/* ------問題------

高橋君と青木君が取引をします。 はじめ、高橋君の所持金は 0 円です。
高橋君は 1 から N の番号がついた N 個の財宝を持っています。高橋君は青木君に財宝 i を売却すると xi 円得ることができます。
青木君は 1 から N の番号がついた N 個の商品を販売しています。商品 i は価値 vi を持ち、価格 ci 円で販売されています。

取引は以下の手順で行われます。
高橋君は財宝を売却するか、商品を購入するかを決める。前者ならば手順 2. へ、後者ならば手順 3. へ進む。
高橋君は持っている財宝のうち、最も番号が小さいものを青木君に売却しお金を得る。その後、青木君は商品を 1 つ選び販売を停止する。手順 1. へ戻る。
高橋君は販売中の 0 個以上の商品を購入し、取引を終了する。このとき、高橋君は所持金が 0 円未満になるように購入することはできない。
高橋君が購入した商品の価値の総和を得点とします。

高橋君は得点を最大化するように、青木君は得点を最小化するように行動するとき、得点はいくつになりますか？

-----問題ここまで----- */
/* -----解説等-----

とても時間がかかったので絶対本番で通せてない
時間の許す限りコスト表はたくさんつくっておいてもいいかもしれない

vectorでMLE...
chokuは持っているものを売る選択をするときに、売ったほうがいいのか/購入したほうがいいのかを選択する。
aokiは一つ販売を停止する際にどれを停止するとよいかは現時点ではわからないのでこれを全探索する。

----解説ここまで---- */

LL N;

LL ans = 0LL;
LL dp[19][1<<18][2];
LL pre[1<<18][19];

LL f(LL i, LL S, int turn) {
	LL &res = dp[i][S][turn];
	if (res != -1)return res;

	if (S == 0)return 0;
	if (turn == 0) {// choku
		res = -LINF;
		res = max(res, pre[S][i]);
		res = max(res, f(i + 1, S, 1));
	}
	else { // aoki
		res = LINF;
		FOR(j, 0, N) {
			if (S&(1 << j)) {
				res = min(res, f(i, S ^ (1 << j), 0));
			}
		}
	}

	return res;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	VL X(N), C(N), V(N);
	FOR(i, 0, N) {
		cin >> X[i];
	}
	FOR(i, 0, N) {
		cin >> C[i];
	}
	FOR(i, 0, N) {
		cin >> V[i];
	}
	VL chokusum(N + 1, 0);
	FOR(i, 0, N) {
		chokusum[i + 1] = chokusum[i] + X[i];
	}
	FOR(i, 0, 1 << N) {
		LL vsum = 0, csum = 0;
		FOR(j, 0, N) {
			if (i&(1 << j)) {
				vsum += V[j];
				csum += C[j];
			}
		}
		FOR(j, 0, N + 1) {
			if (csum <= chokusum[j]) {// chokuの売って得る金額よりも小さい
				pre[i][j] = max(pre[i][j], vsum);
			}
		}
	} // pre[S][i]:= 売っているものがSで手持ちをi回売却しているときにその後得られる価値の最大

	FOR(i, 0, N + 1) { //選択によっては集合が小さいほうがいいときもあるのでマージ
		FOR(S, 0, 1 << N) {
			FOR(j, 0, N) {
				if (!(S& (1 << j))) {
					pre[S | (1 << j)][i] = max(pre[S | (1 << j)][i], pre[S][i]);
				}
			}
		}
	}

	fill(**dp, **dp + (2 * (1 << 18) * 19), -1);
	ans = f(0, (1 << N) - 1, 0);
	cout << ans << "\n";

	return 0;
}
