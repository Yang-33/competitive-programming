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

/* -----  2018/11/04  Problem: ARC 046 B / Link: http://arc046.contest.atcoder.jp/tasks/arc046_b  ----- */
/* ------問題------

高橋君と青木君は N 個の石からなる石の山を使って石取りゲームをすることにしました。ゲームのルールは以下の通りです。
プレイヤーは交互に 1 個以上の石を山から取る。
最後の石を取ったプレイヤーの勝利である。
先手の高橋君は一度に最大 A 個までの石を取ることが可能であり、後手の青木君は一度に最大 B 個までの石を取ることが可能です。
2 人が最適に行動したとき勝利するプレイヤーがどちらか判定するのがあなたの仕事です。

-----問題ここまで----- */
/* -----解説等-----

値が大きいほうが有利すぎる(grundy数をぶち壊せるので)

----解説ここまで---- */

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N; cin >> N;
	LL A, B; cin >> A >> B;
	if (N <= A) {
		ans = 1;
	}
	else {
		if (A == B) {
			if (N % (A + 1) != 0)ans = 1;
		}
		else {
			if (A > B)ans = 1;
		}
	}

	cout << (ans ? "Takahashi" : "Aoki") << "\n";

	return 0;
}
