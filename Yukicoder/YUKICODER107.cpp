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

/* -----  2018/04/23  Problem: yukicoder 107  / Link: http://yukicoder.me/problems/no/107  ----- */
/* ------問題------

N匹のモンスターがいる。
モンスターには2種類ある。
悪いモンスターと良いモンスターの2種類である。
悪いモンスターとは1匹に対し1回戦わないといけない。
戦うと体力が減りレベルが1上がる。
レベルが1上がると最大体力が100上がる。
もし体力が減って0以下になればそこで終了する。
良いモンスターは1匹につき1回だけ体力を回復してくれる。
ただし、回復する体力は最大体力を越えることはない。

自分の最初の体力は100で最大体力も100である。
悪いモンスターをすべて倒したい。
また、最後に残った体力をできるだけ多くしたい。
モンスターには自由な順番で出会える。
最後までどれだけの体力を残せるだろうか？
どのようにしても途中で体力が0以下になる場合は0を答えとする。

ただし、良いモンスターを倒すことは出来ない。

-----問題ここまで----- */
/* -----解説等-----

dp[state][lv] := いままで出会ったモンスターがstateでレベルがlvのときの体力の最大値、
とするとbitDPができ、計算時に体力の上限もわかるため、計算できる。

追記: 出会ったモンスターからレベルわかるね...
dp[state] :=いままで出会ったモンスターがstateのときの体力の最大値

----解説ここまで---- */

LL N;

LL solve1(VI &d) {
	VI dp(1 << N, 0);
	dp[0] = 100;
	FOR(state, 0, 1 << N) {
		if (dp[state] == 0)continue;

		int lv = 1;
		FOR(i, 0, N) {
			if (state & 1 << i && d[i] < 0)lv++;
		}
		FOR(i, 0, N) {
			if (state & 1 << i)continue;
			dp[state | 1 << i] = max(dp[state | 1 << i], min(dp[state] + d[i], lv * 100));

		}
	}
	return  dp[(1 << N) - 1];
}

LL solve2(VI& d) {
	VVI dp(1 << N, VI(N + 2, 0));
	FOR(i, 0, N) {
		if (d[i] > 0) {
			dp[1 << i][0] = 100;
		}
		else if (d[i] > -100) {
			dp[1 << i][1] = 100 + d[i];
		}
	}

	FOR(lv, 0, N + 1) {
		FOR(state, 1, 1 << N) {
			FOR(i, 0, N) {
				if (dp[state][lv] == 0)continue;
				if (state & 1 << i)continue;
				int nx = state | 1 << i;
				if (d[i] > 0)
					dp[nx][lv] = max(dp[nx][lv], min(dp[state][lv] + d[i], (lv + 1) * 100));
				if (dp[state][lv] + d[i] > 0 && d[i] < 0)
					dp[nx][lv + 1] = max(dp[nx][lv + 1], min(dp[state][lv] + d[i], (lv + 2) * 100));
			}
		}
	}
	LL ret = 0;
	FOR(lv, 0, N + 2) {
		ret = max(ret, (LL)dp[(1 << N) - 1][lv]);
	}
	return ret;
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	VI d(N);
	FOR(i, 0, N) {
		cin >> d[i];
	}
	LL ans = solve1(d);
	//LL ans = solve2(d);
	cout << ans << "\n";

	return 0;
}
