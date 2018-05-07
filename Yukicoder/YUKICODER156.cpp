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

/* -----  2018/05/05  Problem: yukicoder 156  / Link: http://yukicoder.me/problems/no/156  ----- */
/* ------問題------

キャンディーが入っている箱がN個ある。
i番目の箱にはCi個のキャンディーが入っている。
A君は、その時の最もキャンディーの少ない箱から1つキャンディーを取っていく。
これを合計M個のキャンディーを取り終えるまで繰り返す。

M個のキャンディーを取り出した時に、空になった箱の数はいくつか？

-----問題ここまで----- */
/* -----解説等-----

sortして、小さい方から貪欲にとっていけば良い。

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, M; cin >> N >> M;
	VI a(N);
	FOR(i, 0, N) {
		cin >> a[i];
	}
	SORT(a);
	int i = 0;
	while (M&&i<N) {
		int diff = min(a[i], M);
		a[i] -= diff; M -= diff;
		if (a[i] == 0) {
			i++;
		}
	}
	ans = i;
	cout << ans << "\n";

	return 0;
}
