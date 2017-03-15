#include<iostream>
using namespace std;

typedef long long ll;
#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)

/* -----  2017/03/15  Problem: ARC051 / Link: http://arc051.contest.atcoder.jp/tasks/arc051_b ----- */
/* ------問題------

ユークリッドの互除法の試行回数に対する値の復元(?)

-----問題ここまで----- */
/* -----解説等-----

逆の操作を行えばよいので通常のGCDの終了一歩手前を初期解として復元していけばよい（復元ではないが）
K = 40 の値は確認したの一方で　意識はしなかったが
1≦K≦40をみたすときに値の制約があるので全探索は厳しいらしい。

----解説ここまで---- */

ll N;

ll ans = 0LL;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	int a = 2, b = 1;
	FOR(i, 1, N) {
		b = b + a;
		swap(a, b);
	}
	cout << a << " " << b << endl;

	return 0;
}