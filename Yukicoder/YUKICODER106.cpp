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

/* -----  2018/04/23  Problem: yukicoder 106  / Link: http://yukicoder.me/problems/no/106  ----- */
/* ------問題------

素数が嫌いな本田君は、少ない素数で構成される数(相異なる素因数の数が少ない数)をあまり使いたくないです。 そこで、2〜Nまでの数字のうち素因数をK個以上持つ数しか使わないことにしました。しかし、使える数が少なすぎるのは嫌だと思ったので、あらかじめいくつの数を使うことができるかを調べておくことにしました。

NとKが与えられた時、使用できる数の個数を出力してください。

-----問題ここまで----- */
/* -----解説等-----

エラトステネスの篩っぽく書けば良い。
O(NlogN)

----解説ここまで---- */

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, K; cin >> N >> K;
	VI cnt(N + 1, 0);
	FOR(i, 2, N + 1) {
		if (!cnt[i]) {
			for (int j = i; j <= N; j += i) {
				cnt[j]++;
			}
		}
	}
	FOR(i, 2, N + 1) {
		ans += cnt[i] >= K;
	}
	cout << ans << "\n";

	return 0;
}
