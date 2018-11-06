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
//#pragma GCC optimize ("-O3") 
#ifdef YANG33
#include "mydebug.hpp"
#else
#define DD(x) 
#endif
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/11/06  Problem: ARC 048 B / Link: http://arc048.contest.atcoder.jp/tasks/arc048_b  ----- */
/* ------問題------

AtCoderじゃんけんの大会が開かれています。AtCoderじゃんけんとは、2 人で行う以下のようなゲームです。
まず、2 人がそれぞれ独立にグー、チョキ、パーのいずれかの手を出す。
2 人のAtCoderのレーティングが等しくなければ、レーティングが高いほうを勝者とする。
2 人のAtCoderのレーティングが等しく、2 人の出した手が異なるならば、通常のじゃんけんの勝者を勝者とする。
2 人のAtCoderのレーティングが等しく、2 人の出した手も等しいならば、引き分けとする。
大会には N 人の参加者がおり、大会期間中同じ参加者は同じ手を出し続け、また大会期間中にレーティングが変化することはありません。
大会では、すべての参加者が、ほかの N−1 人の参加者とちょうど 1 回ずつAtCoderじゃんけんをします。
それぞれの人のレーティングと出す手が与えられるので、すべての参加者について、大会終了時の対戦成績が何勝何敗何引き分けかを答えてください。
ただし、通常のじゃんけんにおいては、グーはチョキに、チョキはパーに、パーはグーに、それぞれ勝つものとします。

-----問題ここまで----- */
/* -----解説等-----

累積和を使えばO(N)でできる。
また、rateが等しい人はじゃんけん別に分けておけばO(1)でメモを見るだけで良い。

----解説ここまで---- */

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N; cin >> N;
	vector<PII>a(N);
	FOR(i, 0, N) {
		cin >> a[i].first >> a[i].second;
		a[i].second--;
	}
	VL csum(100010);
	VVI hash(100010, VI(3, 0));
	FOR(i, 0, N) {
		csum[a[i].first]++;
		hash[a[i].first][a[i].second]++;
	}

	FOR(i, 1, 100010) {
		csum[i] += csum[i - 1];
	}
	FOR(i, 0, N) {
		LL iwin = csum[a[i].first - 1];
		iwin += hash[a[i].first][(a[i].second+1)%3];
		LL ilose = csum[100000] - csum[a[i].first];
		ilose+= hash[a[i].first][(a[i].second + 2) % 3];
		LL itie = hash[a[i].first][a[i].second]-1;
		cout << iwin << " " << ilose << " " << itie << endl;
	}
	return 0;
}
