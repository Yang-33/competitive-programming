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

/* -----  2018/07/26  Problem: yukicoder 166  / Link: http://yukicoder.me/problems/no/166  ----- */
/* ------問題------

H行×W列のマスがある。
1〜Nの番号の付いた人達が1番の人から順番に空いている好きな1マスを埋めていく。
N番まで回ったら1番の人に戻る。
最後のマスを埋めてしまった人の負けになる。
K番の人が負けるならYES、負けないならNOを出力せよ。

値が231を超える場合がある。

-----問題ここまで----- */
/* -----解説等-----

剰余を取れば良い。
N==KだとK>0なのにずれてしまう。ここだけずらせばよい。

----解説ここまで---- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL H, W, N, K;
	cin >> H >> W >> N >> K;
	LL sum = (H*W)%N;
	int ans = ( sum==0&&N==K )|| (sum==K);


	cout << (ans?"YES":"NO") << "\n";

	return 0;
}
