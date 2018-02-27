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

/* -----  2018/02/27  Problem: 071_arc_b / Link: https://abc058.contest.atcoder.jp/tasks/arc071_b?lang=en  ----- */
/* ------問題------

2 次元平面上に x 軸と平行な直線が m 本と y 軸と平行な直線が n 本引いてあります。 x 軸と平行な直線のうち下から i 番目は y=yi で表せます。 y 軸と平行な直線のうち左から i 番目は x=xi で表せます。
この中に存在しているすべての長方形についてその面積を求め、 合計を 109+7 で割ったあまりを出力してください。

つまり、1≤i<j≤n と 1≤k<l≤m を満たすすべての組 (i,j,k,l) について、 直線 x=xi, x=xj, y=yk, y=yl で囲まれる 長方形の面積を求め、合計を 109+7 で割ったあまりを出力してください。

-----問題ここまで----- */
/* -----解説等-----

式を書くと2i-(N+1)回,a_iが呼ばれるので適当にやる

----解説ここまで---- */

LL H,W;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> W >> H;
	VL x(W);
	FOR(i, 0, W) {
		cin >> x[i];
	}
	VL y(H);
	FOR(i, 0, H) {
		cin >> y[i];
	}

	LL xsum = 0, bef;
	FOR(i, 1, W) {
		(xsum += bef) %= MOD;
		(xsum += (x[i] - x[i - 1])*i % MOD) %= MOD;
		(bef += (x[i] - x[i - 1])*i % MOD) %= MOD;
	}
	bef = 0;
	LL ysum = 0;
	FOR(i, 1, H) {
		(ysum += bef) %= MOD;
		(ysum += (y[i] - y[i - 1])*i % MOD) %= MOD;
		(bef += (y[i] - y[i - 1])*i % MOD) %= MOD;
	}
	ans = (xsum*ysum) % MOD;

	cout << ans << endl;


	return 0;
}
