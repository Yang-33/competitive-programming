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

/* -----  2018/03/03  Problem: code-festival-2016-ex-final_a / Link: https://cf16-exhibition-final.contest.atcoder.jp/tasks/cf16_exhibition_final_a?lang=en  ----- */
/* ------問題------

一次元の世界に N 個のパソコンと N 個の電源があります。 i 番目のパソコンの座標は ai であり、 i 番目の電源の座標は bi です。 これらの 2N 個の座標は相異なることが保証されています。
すぬけ君は、それぞれのパソコンをケーブルで電源につなぎたいです。 それぞれの電源は一つのパソコンにのみつなぐことができます。
何通りの方法で、ケーブルの長さの合計を最小化できるでしょうか？ 答えを modulo 109+7 で求めてください。

-----問題ここまで----- */
/* -----解説等-----

座標順に並べるとなんとなく連結成分っぽいものが見える場所と見えない場所がある。
これについて考えると小さいものから選択していくのがよく、座標で並べたときにつなぐ対称は交差してはいけないことがわかる。(判例を証明で消す)
したがって先頭から見ていくときに、現在の連結成分っぽいもののサイズを乗算していけばよい

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	VL a(N), b(N);
	vector<PLL>v;
	FOR(i, 0, N) {
		cin >> a[i];
		v.push_back(PLL(a[i], 1));
	}
	FOR(i, 0, N) {
		cin >> b[i];
		v.push_back(PLL(b[i], -1));
	}
	SORT(v);
	ans = 1;
	int size = 0;
	FOR(i, 0, SZ(v)) {
		if (size != 0 && (size > 0) != (v[i].second > 0)) {
			ans = (ans * abs(size)) % MOD;
		}
		size += v[i].second;
	}


	cout << ans << "\n";

	return 0;
}
