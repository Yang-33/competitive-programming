#include "bits/stdc++.h"
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

/* -----  2017/10/16  Problem: nagoya_19_14 JOI2012 本戦 4 / Link: http://joi2012ho.contest.atcoder.jp/tasks/joi2012ho4  ----- */
/* ------問題------

正三角形の一辺に並んでいる釘の本数 N と，JOI くんが持っている輪ゴムの数 M と，M 本の輪ゴムによ
る「よい正三角形」の囲い方が与えられたとき，1 本以上の輪ゴムで囲われた釘の本数を求めるプログラ
ムを作成せよ．

-----問題ここまで----- */
/* -----解説等-----

imos三角形バージョン。
一次関数のときみたいになるべく情報を減らしてその後部分で復元していけばよい。

----解説ここまで---- */

LL N, M;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	VVI sum(N + 10, VI(N + 10, 0));
	FOR(i, 0, M) {
		int a, b, x; cin >> a >> b >> x;
		sum[a][b]++;
		sum[a][b + 1]--;
		sum[a + x + 1][b]--;
		sum[a + x + 1 + 1][b + 1]++;
		sum[a + x + 1][b + x + 1 + 1]++;
		sum[a + x + 1 + 1][b + x + 1+1]--;
	}
	
	int W = N + 4;
	FOR(i, 0, W) {// ->
		FOR(j, 1, i + 3) {
			sum[i][j] += sum[i][j - 1];
		}
	}
	
	FOR(i, 1, W) {// 左下
		FOR(j, 0, W) {
			sum[i][j] += sum[i - 1][j];
		}
	}

	FOR(i, 0, W) {//右下
		FOR(j, 0, W-i) {
			if(j>0)sum[i + j][j] += sum[i + j - 1][j - 1];
		}
	}
	FOR(i, 0, W) {
		FOR(j, 0, W)if (sum[i][j] > 0)ans++;
	}
	cout << ans << "\n";

	return 0;
}