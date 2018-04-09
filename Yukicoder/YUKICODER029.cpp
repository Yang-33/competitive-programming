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

/* -----  2018/04/09  Problem: yukicoder 029  / Link: http://yukicoder.me/problems/no/029  ----- */
/* ------問題------

Quinは、RPGをしている。
そのRPGでは、アイテムは10種類（それぞれ番号付けされている）あり、「同じアイテム」を2つ揃えるか、「任意のアイテム」を4つ揃えるとパワーアップする仕組みがある。
そして敵を倒したら、何かアイテムを３つもらうことができる。
（同じアイテムがもらえることもある。）
このとき、持てるアイテムの上限はないとし、アイテムの組み合わせは自由に決められる。（自動的にパワーアップすることはないとする。）

N回敵を倒すと考えたとき、その時のパワーアップする最大の回数を求めてください。

-----問題ここまで----- */
/* -----解説等-----

一つ残るものは最後までためておいて、最後にまとめてパワーアップに使えば良い。

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	VI a(11, 0);
	FOR(i, 0, N) {
		FOR(j, 0, 3) {
			int x; cin >> x;
			a[x]++;
		}
	}
	int left = 0;
	FOR(i, 1, 11) {
		ans += a[i] / 2;
		left += a[i] % 2;
	}
	ans += left / 4;

	cout << ans << "\n";

	return 0;
}
