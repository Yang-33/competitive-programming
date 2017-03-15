#include<iostream>
using namespace std;

typedef long long ll;

/* -----  2017/03/15  Problem: ARC046 B / Link: http://arc046.contest.atcoder.jp/tasks/arc046_b ----- */
/* ------問題------

高橋君と青木君は N 個の石からなる石の山を使って石取りゲームをすることにしました。ゲームのルールは以下の通りです。
プレイヤーは交互に 1 個以上の石を山から取る。
最後の石を取ったプレイヤーの勝利である。
先手の高橋君は一度に最大 A 個までの石を取ることが可能であり、後手の青木君は一度に最大 B 個までの石を取ることが可能です。
2 人が最適に行動したとき勝利するプレイヤーがどちらか判定するのがあなたの仕事です。

-----問題ここまで----- */
/* -----解説等-----

A=BのときはA+1の倍数を踏んだ人の勝ちであるから剰余が0のときにはＢ，そうでないときはＡの勝ちである。
一方A>BであればＡが主導権を握ることができるのでシュミレーションをする必要はない。

----解説ここまで---- */

ll N;
ll A, B;
ll ans = 0LL;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> A >> B;
	if (N <= A)ans = 1;
	else {
		if (A == B) {
			if (N % (A + 1) == 0)ans = 0;
			else ans = 1;
		}
		else {
			if (A > B)ans = 1;
			else ans = 0;
		}
	}

	if(ans==1)
	cout << "Takahashi" << endl;
	else cout << "Aoki" << endl;
	
	return 0;
}