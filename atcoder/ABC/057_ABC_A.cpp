#include<iostream>
using namespace std;

typedef long long ll;

/* -----  2017/03/27  Problem: ABC 057 A / Link: http://abc057.contest.atcoder.jp/tasks/abc057_a ----- */
/* ------蝠城｡---

イルカはプログラミングコンテスト好きで、今日はAtCoderのコンテストに参加します。
現在時刻は、24 時間表記 (0:00〜23:59) で A 時ちょうどであり、コンテストがちょうど B 時間後に始まります。
コンテストの開始時刻は、24 時間表記で何時ちょうどでしょうか?

-----問題ここまで----- */
/* -----解説等-----

mod => 24

----解説ここまで---- */

ll N,M;

ll ans = 0LL;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

    cin >> N >> M;
    cout << (N + M) % 24 << endl;

	cout << ans << endl;
	//
	return 0;
}
