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

/* -----  2018/06/02  Problem: codeflyer-2018-qual D / Link: __CONTEST_URL__  ----- */
/* ------問題------

H 行 W 列のマス目が書かれた紙があります。 このマス目の上から i 行目、左から j 列目のマス (1≤i≤H, 1≤j≤W) をマス (i,j) と書きます。

このマス目の N 行 M 列ぶんと同じ大きさのハンコがあります。 このハンコの印影は N 個の長さ M の文字列 A1,A2,…,AN によって表されます。 ハンコの左上をマス (s,t) (1≤s≤H−N+1, 1≤t≤W−M+1) の左上に 合わせてハンコを押すと、ハンコに覆われた各マス (u,v) (s≤u≤s+N−1, t≤v≤t+M−1) の色は以下のように変化します。

文字列 Ai の j 文字目が # であるとき、マス (s+i−1,t+j−1) の色は黒に変化する。
文字列 Ai の j 文字目が . であるとき、マス (s+i−1,t+j−1) の色は変化しない。
はじめ、すべてのマスの色は白色です。 1≤s≤H−N+1, 1≤t≤W−M+1 を満たす各 s,t について、 ハンコの左上をマス (s,t) の左上に合わせてハンコを押しました。

色が黒に変化したマスの個数を求めてください。

-----問題ここまで----- */
/* -----解説等-----

2*Nよりも広い区間を塗りつぶすとき、内部は存在しない
そうではないとき、愚直にやっても良い。
長い部分では、2*N+1で全体を持って、その中央が塗られているならば長さ倍してよい

----解説ここまで---- */

int imos[2010][2010];

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int h, w;
	int n, m;
	cin >> h >> w >> n >> m;

	int nh = min(n + 2, h - n + 1);
	int mw = min(m + 2, w - m + 1);

	VS a(1010);
	FOR(i, 0, n) {
		cin >> a[i];
	}
	FOR(i, 0, n)FOR(j, 0, m) {
		if (a[i][j] == '.') continue;
		imos[i][j]++;
		imos[i + nh][j]--;
		imos[i][j + mw]--;
		imos[i + nh][j + mw]++;
	}

	FOR(i, 0, 2 * n + 1)FOR(j, 0, 2 * m + 1) {
		if (i - 1 >= 0) {
			imos[i][j] += imos[i - 1][j];
		}
		if (j - 1 >= 0) {
			imos[i][j] += imos[i][j - 1];
		}
		if (i - 1 >= 0 && j - 1 >= 0) {
			imos[i][j] -= imos[i - 1][j - 1];
		}
	}

	FOR(i, 0, 2 * n + 1)FOR(j, 0, 2 * m + 1) {
		LL cur = (imos[i][j] > 0);
		if (nh == n + 2 && i == n) {
			cur *= (h - 2 * n);
		}
		if (mw == m + 2 && j == m) {
			cur *= (w - 2 * m);
		}
		ans += cur;
	}

	cout << ans << endl;

	return 0;
}
