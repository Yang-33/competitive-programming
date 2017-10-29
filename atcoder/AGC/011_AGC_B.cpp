#include "bits/stdc++.h"
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

/* -----  2017/10/11  Problem: N18_b AGC011 B / Link: https://agc011.contest.atcoder.jp/tasks/agc011_b  ----- */
/* ------問題------

すぬけ君は，N 匹の変わった生き物を見つけました． それぞれの生き物には色と大きさが定まっており，i 番目の生き物の色は i，大きさは Ai で表されます．
どの生き物も，大きさが自分の 2 倍以下であるような他の生き物を吸収することができます． 大きさ A，色 B の生き物が大きさ C，色 D の生き物を吸収すると (C≤2×A)，合体して大きさ A+C，色 B の生き物になります． ここで，2 匹の生き物の大きさによっては，どちらも他方を吸収することが可能な場合があります．
すぬけ君がこの生き物たちを観察していると，合体を繰り返して，最終的に 1 匹になりました． このとき，残った生き物の色として考えられるものは何種類あるかを求めてください．

-----問題ここまで----- */
/* -----解説等-----

昇順に並べると一番右が勝ちなのは明らか。
さらにその手前について考えると、自分よりも左側をすべて吸収して右を倒せればOKとなる。
これを累積和をとってやればいいことになる。
LLにしてなくて悲しい思いをした。

----解説ここまで---- */

LL N;
LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	VL a(N,0);
	FOR(i, 0, N)cin >> a[i];
	SORT(a);

	VL sum(N + 1,0);
	sum[0] = 0;
	FOR(i, 1, N+1) {
		sum[i] = sum[i - 1] + a[i-1];
	}
	ans = 1;
	int f = 1;

	FORR(i, N-2, -1) {
		if (a[i+1] <= 2 * sum[i+1 ]&&f)ans++;
		else f = 0;
	}
	cout << ans << "\n";

	return 0;
}