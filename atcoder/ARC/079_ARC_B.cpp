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

/* -----  2018/03/05  Problem: 079_arc_b / Link: https://arc079.contest.atcoder.jp/tasks/arc079_b?lang=en  ----- */
/* ------問題------

長さ N の非負整数列 ai に対し、数列の最大値が N−1 以下になるまで以下の操作を繰り返し行うことを考えます。
数列のうち最も大きい要素を求める、複数ある場合はどれか 1 つ選ぶ。この要素の値を N 減らす。これ以外の要素の値を 1 増やす。
なお、この操作を行い続けると、いつかは数列の最大値が N−1 以下になることが証明できます。
ここで、整数 K が与えられるので、この操作を行う回数がちょうど K 回になるような数列 ai を 1 つ求めてください。なお、この問題の入出力の制約下では、かならず 1 つは条件を満たすような数列が存在することが示せます。

-----問題ここまで----- */
/* -----解説等-----

復元を端折れば良い

----解説ここまで---- */

LL N,K;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> K;
	N = 50;
	VL a(50, 49);
	LL base = K/N;
	LL modulo = K%N;
	FOR(i, 0, N) {
		a[i] += base;
	}
	FOR(m, 0, modulo) {
		FOR(i, 0, N) {
			if (i == m) a[i]+=N;
			else a[i]--;
		}
	}

	cout << N << endl;
	FOR(i, 0, N) {
		cout << a[i] << " ";
	}cout << endl;

	return 0;
}
