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

/* -----  2017/12/10  Problem: ARC 086 A / Link: http://arc086.contest.atcoder.jp/tasks/arc086_a  ----- */
/* ------問題------

高橋君は，N 個のボールを持っています． 最初，i 番目のボールには，整数Ai が書かれています．
高橋君は，いくつかのボールに書かれている整数を書き換えて，
N 個のボールに書かれている整数がK 種類以下になるようにしたいです．
高橋君は，少なくとも何個のボールの整数を書き換える必要があるでしょうか？

-----問題ここまで----- */
/* -----解説等-----

値が一緒なボールを集めて、大きい順からK個、書き換えないとすれば良い。

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL K; cin >> N >> K;
	VL a(N);
	VL c(N+100, 0);
	int cnt = 0;
	FOR(i, 0, N) {
		cin >> a[i];
		if (c[a[i]] == 0)cnt++;
		c[a[i]]++;
	}
	RSORT(c);
	FOR(i, 0, SZ(c)) {
		if (K > 0) {
			K--;
		}
		else {
			ans += c[i];
		}
	}


	cout << ans << "\n";

	return 0;
}
