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

/* -----  2018/02/14  Problem: 066_arc_a / Link: https://arc066.contest.atcoder.jp/tasks/arc066_a?lang=en ----- */
/* ------問題------

1~N までの番号がついた、N 人の人がいます。
彼らは昨日、ある順番で左右一列に並んでいましたが、今日になってその並び方が分からなくなってしまいました。 
しかし、彼らは全員、「自分の左に並んでいた人数と自分の右に並んでいた人数の差の絶対値」を覚えています。
彼らの報告によると、人 i の、「自分の左に並んでいた人数と自分の右に並んでいた人数の差の絶対値」は Ai です。
彼らの報告を元に、元の並び方が何通りあり得るかを求めてください。
ただし、答えは非常に大きくなることがあるので、109+7 で割った余りを出力してください。
また、彼らの報告が間違っており、ありうる並び方がないこともありえます。 その際は 0 を出力してください。


-----問題ここまで----- */
/* -----解説等-----

元の状態を考えると、Nが偶数のときは2つの数字が対称になっていて、奇数のときは中央に0が一つだけ存在する。
これに反するものを弾いてあげて、後は2^(N/2)だけ組合せが存在する。

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	VI a(N);
	int ok = 1;
	ans = 1;
	if (N % 2 == 1) {
		FOR(i, 0, N) { // even only
			int v; cin >> v;
			if (v % 2 == 1)ok = 0;
			a[v]++;
			if (a[0] > 1)ok = 0;
		}
		FOR(i, 0, N/2) {
			ans *= 2;
			ans %= MOD;
		}
	}
	else {
		FOR(i, 0, N) { // odd only
			int v; cin >> v;
			if (v % 2 == 0)ok = 0;
			a[v]++;
		}
		FOR(i, 0, N/2) {
			ans *= 2;
			ans %= MOD;
		}
	}

	if (ok == 0)ans = 0;
	cout << ans << "\n";

	return 0;
}
