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

/* -----  2018/02/24  Problem: code-festival-2016-qual-c_c / Link: https://code-festival-2016-qualc.contest.atcoder.jp/tasks/codefestival_2016_qualC_c?lang=en  ----- */
/* ------問題------

アルピニストである高橋君と青木君は最近ある有名な山脈を踏破しました。この山脈はN 個の山からなっており、西から東に向けて山1,山2,…,山Nと一直線に並んでいます。高橋君は西から、青木君は東からこの山脈を踏破しました。
山i の高さはhi ですが、二人とも各hi の値は忘れてしまいました。その代わり、各i(1≦i≦N) に対して、山i の山頂にたどり着いた時の、それまでに登った山(山i も含む)の高さの最大値を記録しています。 高橋君の記録した値はTi で、青木君の記録した値はAi です。
各山の高さhi が正の整数であることはわかっています。山の高さの列としてありうるものが何通りあるかを109+7 で割ったあまりを求めてください。
ただし記録が間違っていてありうる山の高さの列が存在しないこともあります。この場合は0を出力してください。

-----問題ここまで----- */
/* -----解説等-----

これ昔全くわからなかった
まず不正を検出する。
値が変化するときに着目すればよく、両側から変化するときは一致する
片側のみ変化の際はもう片方よりも大きくはならない(一緒か反対側にもっと大きいものが存在するはず)
これに反するものがあれば不正となる。
不正がない状態では、小さい方の値だけ組合せが存在する。

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	VL a(N);
	VL t(N);
	FOR(i, 0, N) {
		cin >> t[i];
	}
	FOR(i, 0, N) {
		cin >> a[i];
	}
	ans = 1;
	if (t.back() != a.front())ans = 0;
	FOR(i, 1, N-1) {
		if (t[i] != t[i - 1] && a[i] != a[i + 1]) {
			if (t[i] != a[i]) {
				ans = 0;
			}
		}
		else if (t[i] != t[i - 1]) {
			if (t[i] > a[i]) {
				ans = 0;
			}
		}
		else if (a[i] != a[i + 1]) {
			if (a[i] > t[i]) {
				ans = 0;
			}
		}
		else {
			ans *= min(a[i], t[i]);
			ans %= MOD;
		}
	}



	cout << ans << "\n";

	return 0;
}
