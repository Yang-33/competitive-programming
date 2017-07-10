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

/* -----  2017/07/09  Problem: AOJ 1068  / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1068  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

題意がそのまま二次元の区間の最小値を欲しいと言っているのでデータ構造を考える。
考える間もなく二次元セグメントツリーがあればいいことが分かる。
vectorだとメモリが足りないので配列で使いまわす。
セグ木にセグ木を載せてもできたかもしれないのでそれも解く。

----解説ここまで---- */

int H, W;
int datas[1 << 23];
void allupdate(vector<vector<int>> &a);

void init(vector<vector<int>> &a) {
	H = W = 1;
	int h = (int)a.size(); int w = (int)a[0].size();
	while (H < h)H *= 2;
	while (W < w)W *= 2;
	FOR(i, 0, 2 * H - 1)FOR(j, 0, 2 * W - 1)datas[i*(2*W-1)+j] = INT_MAX;
	// max値を入れておく、書き換えupdateはいいが加算addに注意
	allupdate(a);
}



void allupdate(vector<vector<int>> &a) { // 二次元上の区間をまとめあげる
	for (int i = 0; i < (int)a.size(); i++)
		for (int j = 0; j < (int)a[0].size(); j++)
			datas[(2 * W - 1)*(i + H - 1)+j + W - 1] = a[i][j];
	for (int i = 2 * H - 2; i > H - 2; i--)
		for (int j = W - 2; j >= 0; j--)
			datas[(2 * W - 1)*i+j] = min(datas[(2 * W - 1)*i+2 * j + 1], datas[(2 * W - 1)*i+2 * j + 2]);
	for (int i = H - 2; i >= 0; i--)
		for (int j = 0; j < 2 * W - 1; j++)
			datas[(2 * W - 1)*i+j] = min(datas[(2 * W - 1)*(2 * i + 1)+j], datas[(2 * W - 1) * (2 * i + 2)+j]);
}

void update(int ky, int kx, int val) {
	ky += H - 1;
	kx += W - 1;
	datas[W*ky+kx] = val;

	while (ky >= 0) { // 根まで再帰的に上る
		int tmp = kx;
		while (kx > 0) {
			kx = (kx - 1) / 2;
			datas[(2 * W - 1)*ky+kx] = min(datas[(2 * W - 1)*ky+kx * 2 + 1], datas[(2 * W - 1)*ky+kx * 2 + 2]); // merge
		}
		kx = tmp;
		if (ky == 0)break;
		ky = (ky - 1) / 2;
		datas[(2 * W - 1)*ky+kx] = min(datas[(2 * W - 1) * (2 * ky + 1)+kx], datas[(2 * W - 1) * (2 * ky + 2)+kx]); // merge
	}
}

//	int yquery(int sy, int ty, int kk, int k = 0, int l = 0, int r = _c) {
int yquery(int sy, int ty, int kk, int k, int l, int r) {
	if (r <= sy || ty <= l) return INT_MAX;
	if (sy <= l && r <= ty) return datas[(2 * W - 1)*kk+k];
	return min(yquery(sy, ty, kk, 2 * k + 1, l, (l + r) / 2),
		yquery(sy, ty, kk, 2 * k + 2, (l + r) / 2, r));
}
// 区間[(ax,ay),(tx,ty))の評価
//	int xquery(int sx, int sy, int tx, int ty, int k = 0, int l = 0, int r = _r) {
int xquery(int sx, int sy, int tx, int ty, int k, int l, int r) {
	if (r <= sx || tx <= l) return INT_MAX;
	if (sx <= l && r <= tx) return yquery(sy, ty, k, 0, 0, W);
	return min(xquery(sx, sy, tx, ty, 2 * k + 1, l, (l + r) / 2),
		xquery(sx, sy, tx, ty, 2 * k + 2, (l + r) / 2, r));
}
//[a,b)の評価
inline int query(int ax, int ay, int bx, int by) {
	return xquery(ax, ay, bx, by, 0, 0, H);
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	
	while (1) {
		int R, C, Q;
		cin >> R >> C >> Q;
		if (R == 0 && C == 0 && Q == 0)break;
		vector<vector<int>>a;
		a = vector<vector<int>>(R, vector<int>(C));
		FOR(i, 0, R) {
			FOR(j, 0, C) {
				cin >> a[i][j];
			}
		}
		//FOR(i, 0, R) {
		//	FOR(j, 0, C) {
		//		cout << a[i][j] << " ";
		//	}cout << endl;
		//}

		init(a);
		FOR(i, 0, Q) {
			int sx, sy, tx, ty;
			cin >> sx >> sy >> tx >> ty;
			int ans = query(sx, sy, tx + 1, ty + 1);
			cout << ans << endl;
		}
	}
	return 0;
}
