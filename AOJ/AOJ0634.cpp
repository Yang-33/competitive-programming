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

/* -----  2017/10/29  Problem:  / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0634  ----- */
/* ------問題------

尾根 (Ridge)
問題
JOI カルデラは景観の良さが多くの登山家に愛される美しい地形である． 特に，尾根と呼ばれる場所からの景観は絶景である．
JOI カルデラの土地は南北 H キロメートル，東西 W キロメートルの長方形である． 南北，東西に 1 キロメートルごとに JOI カルデラの土地を分け，これら H×W 個の領域を区域と呼ぶ．
すべての区域において，その中では標高は等しい．また，異なる区域の標高は異なる．
ある区域に雨が降ると，雨水はその区域に東西南北に隣り合う最大で 4 つの区域のうち， 標高がその区域より低いような区域のすべてに流れる．
そのような区域がない場合，雨水はその区域に溜まる． 他の区域から流れてきた雨水についても同様である． 
JOI カルデラの外側は，外輪山の急峻な崖に囲まれているため，雨水が JOI カルデラの外に流れ出すことはない．
ある区域について，その区域のみに雨が降った場合，最終的に複数の区域に雨水が溜まるとき，その区域を尾根と呼ぶ．
絶景をこよなく愛する登山家たちのために，尾根の区域がいくつあるかを求めるプログラムを作成せよ．

-----問題ここまで----- */
/* -----解説等-----

なんか愚直に小さい方から見ていく、をしていったら通ってしまった(高速でないのに通るのやめて)
O(H^2*W^2)?やばいね

(2017/10)最小のものから見ていくときに、周りに流せる尾根があるならばこれも尾根、といえるので
あとは小さい順に1マスずつみていけばよい。O(HW)

----解説ここまで---- */

ll H, W;
ll ans = 0LL;
ll masu[1010][1010];
vector<int >VER[1010][1010];
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> H >> W;
	vector<pii>v;
	FOR(i, 0, H) {
		FOR(j, 0, W) {
			cin >> masu[i][j];
			v.push_back(mp(masu[i][j], i * 1010 + j));
		}
	}
	sort(v.begin(), v.end());


	FOR(i, 0, v.size()) {
		int high = v[i].first;
		int y = (v[i].second) / 1010; int x = (v[i].second) % 1010;
		if (VER[y][x].size() == 0)VER[y][x].pb(high);
		sort(VER[y][x].begin(), VER[y][x].end());
		VER[y][x].erase(unique(VER[y][x].begin(), VER[y][x].end()), VER[y][x].end());
		FOR(k, 0, 4) {
			int nx = x + dx[k]; int ny = y + dy[k];
			if (0 <= nx &&nx< W && 0 <= ny&&ny < H) {
				if(masu[y][x]<masu[ny][nx])
				FOR(j, 0, VER[y][x].size()) {
					VER[ny][nx].push_back(VER[y][x][j]);
				}
			}

		}

	}
	FOR(i, 0, H) {
		FOR(j, 0, W) {
			
			sort(VER[i][j].begin(), VER[i][j].end());
			VER[i][j].erase(unique(VER[i][j].begin(), VER[i][j].end()), VER[i][j].end());
			if ((int)VER[i][j].size() > 1)ans++;
		}
	}
	cout << ans << endl;

	return 0;
}
