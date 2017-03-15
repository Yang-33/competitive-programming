#include<iostream>
using namespace std;

typedef long long ll;
#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)

/* -----  2017/03/15  Problem: ARC048 B / Link: http://arc048.contest.atcoder.jp/tasks/arc048_b ----- */
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

毎回勝利判定などは計算量が多すぎてできないので、あらかじめ値をハッシュとして記録しておく。
はじめはlower_bound？と思ったけれど必要がなかった。

----解説ここまで---- */

ll N;
int rate[100000], te[100000];
int m[100010][3];
int cnt[100010];
int sumc[100010];
ll ans = 0LL;


int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	FOR(i, 0, N) {
		cin >> rate[i] >> te[i];
		te[i]--;
		cnt[rate[i]]++;
		m[rate[i]][te[i]]++;
	}

	sumc[0] = 0;
	FOR(i, 1, 100010) {
		sumc[i] = sumc[i - 1] + cnt[i];
	}

	FOR(i, 0, N) {
		cout << sumc[rate[i] - 1] + m[rate[i]][(te[i] + 1) % 3] << " " << (sumc[100009] - sumc[rate[i]]) + m[rate[i]][(te[i] + 2) % 3] << " " << m[rate[i]][te[i]] - 1 << endl;
		//cout << sumc[100009] <<"  "<< - sumc[rate[i]] <<"  "<< m[rate[i]][(te[i] + 2) % 3] << endl;
	}

	return 0;
}