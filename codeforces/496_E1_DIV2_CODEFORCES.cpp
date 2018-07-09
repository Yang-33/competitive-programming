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

/* -----  2018/07/10  Problem: CodeForces496 E1 div2 / Link: http://codeforces.com/contest/1005/problem/E  ----- */
/* ------問題------

数列の中央値がMになるような総数
(偶数長のときは小さい方をとる)

-----問題ここまで----- */
/* -----解説等-----

Mが一つしか無いので、これを中心にして、LRを設定する問題になる。
あるLを決めたときに、MまでのMより大きい/小さい数がわかれば、Rはそれに対応した数を持つ位置を(複数箇所)取ることができる。
O(N^2)->O(NlogN)にできればよい。累積和をmapに乗せておけばできる。

----解説ここまで---- */

int main() {
	int N, M;
	LL ans = 0;

	scanf("%d%d", &N, &M);
	VI a(N);
	int Mpos = 0;
	FOR(i, 0, N) {
		scanf("%d", &a[i]);
		if (a[i] == M)Mpos = i;
	}
	map<LL, LL>RightVal;
	LL overM = 0;
	FOR(i, Mpos, N) {
		if (M < a[i]) {
			overM++;
		}
		else if(M>a[i]){
			overM--;
		}
		RightVal[overM]++;
	}
	overM = 0;
	for (int i = Mpos; i >= 0; i--) {

		if (M < a[i])overM++;
		else if (M > a[i])overM--;
		ans += RightVal[-overM];
		// 偶数長
		if (overM <= 0) {
			ans += RightVal[-overM + 1];
		}
		else {
			ans += RightVal[-overM + 1];
		}
	}

	cout << ans << "\n";

	return 0;
}
