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

/* -----  2018/05/01  Problem: yukicoder 127  / Link: http://yukicoder.me/problems/no/127  ----- */
/* ------問題------

竹林とは、竹の長さを表す正の整数列 A1,A2…AN のことである。
門松もどきとは、1≤i1<i2<…<iM≤N を満たす竹林の部分列 Ai1,Ai2…AiM で
Ai1<AiM<Ai2<AiM−1<Ai3… もしくは AiM<Ai1<AiM−1<Ai2<AiM−2… を満たすものをいう。

最長の門松もどきの長さを答えよ。

-----問題ここまで----- */
/* -----解説等-----

topからよくある感じで再帰すれば良い。
区間を一つづつ伸ばして、条件が良いときは伸ばす方向を反転すれば良い。

vector + 参照をしたらめっちゃ遅かった
vectorが遅いっぽい(10倍変わった)
たかが知れてると思ったけどこれからはやめます(特に定数倍のとき)

----解説ここまで---- */

int memo[3000][3000][2];
int a[3000];
int N;
// [L,R] arrow ->
int f(int L, int R, int arrow) {
	if (L < 0 || R >= N)return 0;
	if (memo[L][R][arrow] != -1)return memo[L][R][arrow];
	int &ret = memo[L][R][arrow];
	ret = 0;

	if (arrow) {// R->
		if (R + 1 < N && a[L] > a[R + 1]) {
			ret = max(ret, f(L, R + 1, !arrow) + 1);
		}
		ret = max(ret, f(L, R + 1, arrow)); // not get
	}
	else {// <-L
		if (L - 1 >= 0 && a[L - 1] < a[R]) {
			ret = max(ret, f(L - 1, R, !arrow) + 1);
		}
		ret = max(ret, f(L - 1, R, arrow)); // not get
	}

	return ret;
}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	//a = VI(N);
	FOR(i, 0, N) {
		cin >> a[i];
	}
	int ans = 0;
	memset(memo, -1, sizeof(memo));
//	fill(**memo, **memo + 3000 * 3000 * 2, -1); // 若干遅い?
	FOR(i, 0, N) {
		ans = max({ ans, f(i,i,0) + 1, f(i,i,1) + 1 });
	}

	cout << ans << "\n";

	return 0;
}
