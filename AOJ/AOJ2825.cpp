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

/* -----  2018/06/23  Problem: AOJ 2825 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2825  ----- */
/* ------問題------

あなたはクイズ番組のディレクターである． クイズ番組には解答者として N 人が出演予定であり，それぞれ 1 から N まで番号付けられている．
問題は M+1 問出題する予定であり，それぞれの問題は 1 から M+1 まで番号付けられている． 問題は番号順に出題され，それぞれ早押しで最初に正解した人にのみ得点が入る．i 問目の問題の得点は整数 Si である． M+1 問目の問題を終えた時点で総合得点が最大の人が優勝する． ただし，最大得点の人が複数人存在する場合，優勝者は存在しない．
現在 M 問目まで配点を決めたので，M+1 問目の配点を決めようと考えている． 最後の問題は，誰でも逆転できる点数にするのがクイズ番組のお約束である． しかし，その場で解答者たちの総合得点を見て問題の点数を決めると，解答者たちのやる気を削ぐ可能性がある．そこで， どんな点数状況でも全員に逆転のチャンスがあるような点数設定をあらかじめ考えることにした．
幸い，1 から M 問目まではそれぞれ正解する可能性がある解答者が分かっている．M+1 問目は全員が正解する可能性のある問題である．正解する可能性がある解答者の中で，早押しで正解した1名のみが問題の得点 Si を得る．問題への解答は正解した解答者が現れた時点で締め切られ，同じ解答者は何度でも解答を行うことができるため，ある問題の得点 Si を誰も得られない場合は考慮しなくてよい．また，複数人の解答者がある問題の得点 Si を重複して獲得したり，得点を分け合ったりすることもない．
各問の配点と正解可能な解答者の情報を基に， 起こりうるどのような得点状況においても，最後の問題を正解すれば必ず誰でも優勝できるように最後の問題の点数 SM+1 を設定したい． 条件を満たす整数 SM+1 として最小の値を求めよ．

-----問題ここまで----- */
/* -----解説等-----


----解説ここまで---- */

using ll = LL;
int N, M;
ll solve() {
	ll res = 0;
	vector<ll> scores(N, 0), minscores(N, 0);
	for (int i = 0; i < M; i++) {
		int S, k; cin >> S >> k;
		if (k == 1) {
			int c; cin >> c;
			c--;
			scores[c] += S;
			minscores[c] += S;
		}
		else {
			for (int j = 0; j < k; j++) {
				int c; cin >> c; c--;
				scores[c] += S;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		ll T = INF;
		for (int j = 0; j < N; j++) {
			if (i == j) continue;
			T = min(T, minscores[j]);
		}
		if (scores[i] < T) continue;
		res = max(res, scores[i] - T + 1);
	}
	return res;
}
int main(void) {
	cin.tie(0); ios_base::sync_with_stdio(false);
	while (cin >> N >> M, N) {
		cout << solve() << endl;
	}
	return 0;
}