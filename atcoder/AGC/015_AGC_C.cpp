#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define FOR(i, s, e) for (ll(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (ll(i) = (s); (i) > (e); (i)--)
#define debug(x) cout << #x << ": " << x << endl
#define mp make_pair
#define pb push_back
const ll MOD = 1000000007;
const int INF = 1e9;
const ll LINF = 1e16;
const double PI = acos(-1.0);
int dx[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2017/05/27  Problem: AGC 015 C / Link: http://agc015.contest.atcoder.jp/tasks/agc015_c  ----- */
/* ------問題------

ぬすけ君は、N×M のグリッドを持っています。行には上から順に 1 から N、列には左から順に 1 から M の番号がついています。 
グリッドの各マスは白か青かに塗られており、Si,j が 1 のとき i 行 j 列のマスは青マス、0 のとき白マスです。
青く塗られた任意の二つのマス a,b について、a からはじめて、現在いるマスから辺を共有する青いマスに進むことを繰り返して b に至るような経路のうち、
同じマスを 2 度以上通らないようなものは、高々 1 通りです。

ぬすけ君の永遠のライバルである怪盗スヌークは、ぬすけ君に Q 個の質問をしました。
i 個目の質問は、4 つの整数 xi,1,yi,1,xi,2,yi,2 からなり、 
グリッドの xi,1 行目から xi,2 行目まで、yi,1 列目から yi,2 列目までの範囲の長方形領域を切り出したときに、 その範囲の青マスからなる連結成分がいくつあるかを答える質問です。

怪盗スヌークの質問すべてに答えてください。

-----問題ここまで----- */
/* -----解説等-----

条件から閉路が存在しないことが分かる。
このことからこの青色の連結グリッドは木の集合、すなわち森であることが分かる。
したがってこれを切断した際にできる連結グリッドも森であり、これは木の集合である。
一つの連結成分は{頂点-(縦辺と横辺の和)}で表される。
元の集合がすでに森なので先の値が連結成分の数になる。
これを速く計算したいので、先に二次元累積和で頂点、縦辺、横辺を計算しておく。
あとはいつもの要領でクエリに対応できる。

----解説ここまで---- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	ll H, W, Q;
	ll v[2005][2005];
	ll ex[2005][2005];
	ll ey[2005][2005];
	ll ans = 0LL;

	cin >> H >> W >> Q;
	string s[2000];
	FOR(i, 0, H)cin >> s[i];
	FOR(i, 0, H) {
		FOR(j, 0, W) {
			int c = 0;
			if (s[i][j] == '1')c = 1;
			v[i + 1][j + 1] = c;
		}
	}

	//頂点
	FOR(i, 0, H)FOR(j, 0, W)v[i + 1][j + 1] += v[i + 1][j];

	FOR(i, 0, H)FOR(j, 0, W)v[i + 1][j + 1] += v[i][j + 1];

	//横辺
	FOR(i, 0, H)FOR(j, 0, W - 1) {
		if (s[i][j] == '1'&&s[i][j + 1] == '1')ex[i + 1][j + 1] = 1;
	}
	FOR(i, 0, H)FOR(j, 0, W - 1) {
		ex[i + 1][j + 1] += ex[i + 1][j];
	}
	FOR(i, 0, H)FOR(j, 0, W - 1) {
		ex[i + 1][j + 1] += ex[i][j + 1];
	}

	//縦辺
	FOR(i, 0, H - 1)FOR(j, 0, W) {
		if (s[i][j] == '1'&&s[i + 1][j] == '1')ey[i + 1][j + 1] = 1;
	}
	FOR(i, 0, H - 1)FOR(j, 0, W) {
		ey[i + 1][j + 1] += ey[i + 1][j];
	}
	FOR(i, 0, H - 1)FOR(j, 0, W) {
		ey[i + 1][j + 1] += ey[i][j + 1];
	}

	FOR(i, 0, Q) {
		int ax, ay, bx, by;
		cin >> ax >> ay >> bx >> by; ax--; ay--;
		int vv = v[bx][by] + v[ax][ay] - v[ax][by] - v[bx][ay];
		int exx = ex[bx][by - 1] + ex[ax][ay] - ex[ax][by - 1] - ex[bx][ay];
		int eyy = ey[bx - 1][by] + ey[ax][ay] - ey[ax][by] - ey[bx - 1][ay];
		ans = vv - exx - eyy;
		cout << ans << endl;

	}

	return 0;
}
