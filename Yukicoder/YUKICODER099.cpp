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

/* -----  2018/04/19  Problem: yukicoder 099  / Link: http://yukicoder.me/problems/no/099  ----- */
/* ------問題------

一次元の数直線上の整数座標に駒が N 個あります．
各駒の初期座標は互いに異なり X1,X2,…,XN です．
1 回の操作では 1 個の駒を動かすことができ，今いる座標が x ならば x+2 または x−2 に移動できます．
ただし，移動先に既に駒がある場合はそのような移動はできず，また，移動するにあたって，駒を飛び越えた場合は，飛び越えた駒と飛び越えられた駒の両方が消滅します．
駒の数を最小化したいです．
操作は何回でもできるとして，最後まで残る駒の個数の最小値を求めるプログラムを書いて下さい．

-----問題ここまで----- */
/* -----解説等-----

偶奇の1pairで消滅するため、差分は消滅させることはできない。  

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	int even = 0, odd = 0;
	FOR(i, 0, N) {
		int x; cin >> x;
		(x % 2 ? odd++ : even++);
	}
	ans = abs(odd - even);
	cout << ans << "\n";

	return 0;
}
