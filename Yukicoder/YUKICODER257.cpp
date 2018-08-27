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

/* -----  2018/08/27  Problem: yukicoder 257  / Link: http://yukicoder.me/problems/no/257  ----- */
/* ------問題------

あなたとGrantは、いわゆる「21言っちゃダメゲーム（棒取りゲームというところも）」をすることにした。

ルールを拡張して正整数 N と K を使って以下のゲームを考える。

1. まず先攻のプレイヤーは 0 が与えられる。
2. そこから N 以上を宣言しないように（宣言したら負けになる）与えられた整数に 1～K のどれかの整数を加算したものを宣言し相手プレイヤーに渡す。
3. 勝負がつくまで代わり代わりに 2. を繰り返す。

実際にGrantと対戦し勝利してください。

最初にN,K が与えられ、
あなたは、先攻後攻どちらかを自由に選べる。
時間の都合上、相手は、5ターン連続で勝てる見込みがないと判断すると諦めることになっている。
相手が諦めた場合、ゲームの状態には関係なくN以上（N+K以下の数）が宣言される。これは相手が諦めたものであると解釈し、あなたの勝ちとし、プログラムを終了すること

-----問題ここまで----- */
/* -----解説等-----

常に言えるので、grundy数がzeroを出力すれば良い

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, K; cin >> N >> K;

	auto ask = [](int x) {
		cout << x << endl;
		int val; cin >> val;
		return val;
	};

	int next = 0;
	if ((N - 1) % (K + 1) == 0) { // 後攻
		next = 0;
	}
	else {
		next = (N - 1) % (K + 1);
	}

	while (1) {
		int res = ask(next);
		if (N <= res)break;
		else {
			next += (K + 1);
		}
	}

	return 0;
}
