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

/* -----  2017/05/01  Problem: JOI予選 2012 6  / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0581  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

最大K回まで最短経路から外れることができるので、実質移動で重複する範囲は2Kマスになる。
したがってこれらの経路を保存して、以前に移動した経路上に 現在いるならばここの値は加算しないようにすればよい。
bitでの経路保存を覚えた。
dp[ X ][ Y ][ 何回戻ったか ][ 2Kマス手前までの移動情報 ]:= (x,y)でk回戻ったときの集めたお土産の個数の最大値
計算量はＯ(HWK)?

----解説ここまで---- */


ll H, W, K;
string masu[55];
int dp[55][55][4][1 << 12];
int kkk;

int cal(int x, int y, int k, int bit) {//bit:= 移動経路の情報
	if (dp[x][y][k][bit] != -1)return dp[x][y][k][bit];
	if (x == W - 1 && y == H - 1 && k == 0)return 0;
	int prex = x; int prey = y;

	bool f = false;//訪れているかのフラグ

	FOR(i, 0, 2 * K) {//その判定
		prex += -dx[(bit >> (2 * i)) & 3];
		prey += -dy[(bit >> (2 * i)) & 3];
		if (prex == x&&prey == y) {
			f = true;
			break;
		}
	}

	int ret = 0;
	if (f == false && masu[y][x]!='#'&&masu[y][x]!='.')ret += masu[y][x] - '0';
	int res = -LINF;

	FOR(i, 0, 4) {
		if (k == 0 && (i & 1))continue;//戻れない
		int nx = x + dx[i]; int ny = y + dy[i];
		if (0 <= ny&&ny < H && 0 <= nx&&nx < W) {
			if (masu[ny][nx] != '#') {
				res = max(res, cal(nx,ny,k-(i&1),((bit<<2)|i)&kkk) + ret);
			}
		}
	}

	return dp[x][y][k][bit]=res;
}



int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int ans = 0;

	cin >> H >> W >> K;
	FOR(i, 0, H) {
		cin >> masu[i];
	}
	FOR(i, 0, 55)FOR(j, 0, 55)FOR(k, 0, 4)FOR(b, 0, 1 << 12)dp[i][j][k][b] = -1;
	kkk = (1 << (4 * K)) - 1;//bitmask 4k個1を立てる
	ans = cal(0, 0, K, 0);
	if (ans < 0)ans = 0;
	cout << ans << endl;

	return 0;
}
/*
0003000
0032300
0321230
3210123
0321230
0032300
0003000

*/