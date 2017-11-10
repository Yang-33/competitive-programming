#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <set>
#include <sstream>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <climits>
#include <list>
#include <fstream>
using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef vector<string> VS;

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

/* -----  2017/11/11  Problem: POJ 3009 / Link: http://poj.org/problem?id=3009  ----- */
/* ------問題------

MM-21星でもオリンピック以来カーリングが流行している. しかし, そのルールは地球のものとはすこし異なっており, マス目状の氷の盤上で石を一つだけ使って行われる. スタート位置からゴール位置まで石を到達させる移動回数の少なさを競うのである.
図 D-1 に盤面の例を示す. 盤上のマス目には障害物が配置されていることがある. 盤面には, スタートとゴールという特別なマスが一つずつあり, そこには障害物はない. (スタートとゴールが一致することはない.) 滑りはじめた石は障害物がないかぎりどこまでも進んでいくので, ゴールに到達させるには, 障害物を利用していったん石を止め, あらためて滑らせてやる必要もあろう.
石の動きは以下の規則に従う:

ゲームの開始時に, 石はスタートで止まっている.
石の動きは x, y 方向に限る. ななめには動けない.
止まっている石は, 滑らせることによって動き出す. その時の方向は, すぐ次のマスに障害物がない方向ならどちらでもよい(図 D-2(a)).
動き出した石は, 次のいずれかが起こるまで, 同じ方向に動き続ける.
障害物にぶつかった場合(図 D-2(b), (c)).
石は障害物の一つ手前のマスで止まる.
障害物は消滅する.
盤外に出た場合.
失敗でゲームは終わる.
ゴールの上に来た場合.
そこで石は止まり, 成功でゲームは終わる.
1 回のゲーム中の滑らせる回数の最大は 10 である. この回数でゴールに石を到達させることができない場合, 失敗でゲームは終わる.
以上の条件のもとで, スタート位置にある石をゴール位置に到達させることができるか, できるなら最小何回滑らせればよいかを知りたい.

-----問題ここまで----- */
/* -----解説等-----

盤面を変化させた後にもどせばいいですね。おわり

----解説ここまで---- */

int H, W;
VVI m;
LL ans = 0LL;
int sy, sx, ty, tx;
bool IN(int y, int x) { return (0 <= x&&x < W && 0 <= y&&y < H); }

int dfs(int ay, int ax, int dep,VVI &masu) {
	if (dep > 10)return dep;
	int res = 11;
	FOR(k, 0, 4) {
		int ny = ay + DY[k]; int nx = ax + DX[k];
		if (!IN(ny, nx) || masu[ny][nx] != 0)continue;
		while (IN(ny, nx) && masu[ny][nx] == 0) {
			if (ny == ty&&nx == tx)return dep + 1;
			ny += DY[k]; nx += DX[k];
		}
		if (!IN(ny, nx))continue;
		masu[ny][nx] = 0;
		res = min(res, dfs(ny-DY[k], nx-DX[k], dep + 1,masu));
		masu[ny][nx] = 1;
	}

	return res;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	while (cin >> W >> H, H) {
		m = VVI(H, VI(W, 0));
		FOR(i, 0, H) {
			FOR(j, 0, W) {
				cin >> m[i][j];
				if (m[i][j] == 2) {
					sy = i; sx = j;
					m[i][j] = 0;
				}
				else if (m[i][j] == 3) {
					ty = i; tx = j;
					m[i][j] = 0;
				}
			}
		}

		ans = dfs(sy,sx,0,m);
		if (ans > 10)ans = -1;



		cout << ans << "\n";
	}

	return 0;
}
