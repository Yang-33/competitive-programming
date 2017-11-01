#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define FOR(i,s,e) for(int i = s;i < e;i++)
#define debug(x) cout << #x << ": " << x << endl
const int INF = (1 << 30);
const ll LINF = (1LL << 60);

/* -----  2017/11/01  Problem: AOJ1144  / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1144  ----- */
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

図 D-2: 石の動きの例
以上の条件のもとで, スタート位置にある石をゴール位置に到達させることができるか, できるなら最小何回滑らせればよいかを知りたい.

-----問題ここまで----- */
/* -----解説等-----

盤面が変化する。
したがって参照は使えないのでここに気を付けるだけであとはシュミレーションをする。

----解説ここまで---- */
int ans = -1;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

void dfs(pii at,int n, vector<vector<int>> masu) {
	if (n == 10) return;
	int y = at.first, x = at.second;
	for (int i = 0; i < 4; i++) {
		int yy = y + dy[i], xx = x+  dx[i];
		if (masu[yy][xx] == 1) continue;
		if (masu[yy][xx] == -1)  continue; 
		if (masu[yy][xx] == 3) { if (ans == -1) ans = n+1; else ans = min(ans, n+1); return; }
		bool f = false;
		while (masu[yy + dy[i]][xx + dx[i]] != 1) {
			yy += dy[i];
			xx += dx[i];
			if (masu[yy][xx] == -1) { f = true; break; }
			if (masu[yy][xx] == 3) { if (ans == -1) ans = n + 1; else ans = min(ans, n + 1); return; }
		}
		if (f) continue;
		if (masu[yy + dy[i]][xx + dx[i]] == 1) {
			masu[yy + dy[i]][xx + dx[i]] = 0;
			dfs({ yy,xx }, n + 1, masu);
			masu[yy + dy[i]][xx + dx[i]] = 1;
		}
	}
	return;
}


int main() {
	cin.tie(0); ios::sync_with_stdio(false);
	int w, h;
	while (cin >> w >> h, w|h) {
		ans = -1;
		vector<vector<int>> masu(h + 2, vector<int>(w + 2, -1));
		pii s;
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				cin >> masu[i][j];
				if (masu[i][j] == 2) s = { i,j };
			}
		}
		dfs(s,0, masu);
		cout << ans << endl;
	}
}