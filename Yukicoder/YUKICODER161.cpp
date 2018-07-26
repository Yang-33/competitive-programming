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

/* -----  2018/07/26  Problem: yukicoder 161  / Link: http://yukicoder.me/problems/no/161  ----- */
/* ------問題------

yuki君は友人と制限ジャンケンで遊ぶことにした。
この制限ジャンケンでは、全部でN回のジャンケンを行う（あいこも１回に数える）。
yuki君はN回のうち、グーをG回、チョキをC回、パーをP回しか出すことができない。
yuki君は1回ジャンケンで勝利すると３ポイント、あいこだと１ポイントを得る。負けるとポイントの増減はない。
幸い、yuki君は超能力で友人の手を事前にすべて読むことができた。
yuki君が最適手を取った場合、N回のジャンケンで得られるyuki君の合計取得ポイントの最大値を求めよ。

-----問題ここまで----- */
/* -----解説等-----

貪欲にとっていきたいが最後まで最適な手がわからない気がする。勝てるだけ勝ちたいのでこれを割り振ってから、あいこをできるだけ取る。

----解説ここまで---- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int G, C, P; cin >> G >> C >> P;
	LL ans = 0;
	string s; cin >> s;

	int tg = 0, tc = 0, tp = 0;
	FOR(i, 0, SZ(s)) {
		if (s[i] == 'C')tg++;
		if (s[i] == 'G')tp++;
		if (s[i] == 'P')tc++;
	}

	ans += 3 * min(G, tg);
	int t = min(G, tg); G -= t, tg -= t;
	ans += 3 * min(C, tc);
	t = min(C, tc); C -= t, tc -= t;
	ans += 3 * min(P, tp);
	t = min(P, tp); P -= t, tp -= t;

	if (tg) {// Gはない　チョキ
		int t = min(tg, C);
		ans += t;
		tg -= t, C -= t;
	}
	if (tc) {
		int t = min(tc, P);
		ans += t;
		tc -= t, G -= t;

	}
	if (tp) {
		int t = min(tp, G);
		ans += t;
		tp -= t, G -= t;
	}
	cout << ans << "\n";

	return 0;
}