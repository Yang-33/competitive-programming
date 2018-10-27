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
//#pragma GCC optimize ("-O3") 
#ifdef YANG33
#include "mydebug.hpp"
#else
#define DD(x) 
#endif
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/10/24  Problem: ARC 036 B / Link: http://arc036.contest.atcoder.jp/tasks/arc036_b  ----- */
/* ------問題------

高橋くんは、東西方向に並んだ地点の高さをまとめたデータを持っている。西から i(1≦i≦N) 番目の地点の高さは hi である。このデータの中には同じ高さの地点は存在しなかった。
高橋くんはデータに対し、以下のように「山」および「山の大きさ」を定義することにした。
3 つの整数の組 (s,t,u)(1≦s≦t≦u≦N) について、以下の条件を満たすとき、この組は山を表しているとする。
山の西側に関する条件 : s≦i≦t−1 を満たす任意の整数 i に関して、hi<hi+1が成立する。
山の東側に関する条件 : t≦i≦u−1 を満たす任意の整数 i に関して、hi>hi+1が成立する。
このような条件を満たす整数組 (s,t,u) に関して、山の大きさは、u−s+1 で定義される。
高橋くんは、データ中にある山の中で、山の大きさの最大値がいくらになるのかを調査することにした。
山の大きさとして考えられる最大値を求めるプログラムを作成せよ。

-----問題ここまで----- */
/* -----解説等-----

連続列の増加を左右からやれば良い。

----解説ここまで---- */

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N; cin >> N;
	VL h(N);
	FOR(i, 0, N) {
		cin >> h[i];
	}
	auto f = [](const VL& a) {
		int N = SZ(a);
		VL res(N,0);
		FOR(i, 0, N-1) {
			if (a[i] < a[i + 1]) {
				res[i+1] = res[i] + 1;
			}
			else {
				res[i+1] = 0;
			}
		}

		return res;
	};

	VL L = f(h);
	reverse(ALL(h));
	VL R = f(h);
	reverse(ALL(R));
	DD(De(L, R));
	FOR(i, 0, N) {
		ans = max(ans, L[i] + R[i] + 1);
	}
	
	cout << ans << "\n";

	return 0;
}
