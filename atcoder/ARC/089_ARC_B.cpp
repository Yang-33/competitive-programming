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

/* -----  2018/03/02  Problem: 089_arc_b / Link: https://abc086.contest.atcoder.jp/tasks/arc089_b?lang=en  ----- */
/* ------問題------

シカのAtCoDeerくんは無限に広がる二次元グリッドを一辺が K の市松模様で塗ろうと考えています。 ただし、一辺が K の市松模様とは、各マスが白か黒で塗られたパターンであって、各色の各連結成分が K × K の正方形となっているようなものです。 例えば以下は一辺が 3 の市松模様の例です。
AtCoDeerくんは N 個の希望を持っています。 i 個目の希望は、 xi,yi,ci で表されます。 これは、ci が B ならマス (xi,yi) を黒で塗る、 W なら白で塗ることを意味しています。 同時に最大でいくつの希望を叶えることが出来るか答えてください。

-----問題ここまで----- */
/* -----解説等-----

座標の変換がアレだけど少なくとも2K * 4Kの領域に落とし込めるので、これを全探索する。
愚直はダメなので累積和を取っておく

----解説ここまで---- */

LL N, K;

LL ans = 0LL;

template<typename T>
struct CumulativeSum2D {//使うときは内部で1-indexになっているので普通に0-indexで使えばよい	
	int H, W;
	vector< vector< T > >data;
	CumulativeSum2D(int H_, int W_) : data(H_ + 1, vector< T >(W_ + 1)) { H = H_, W = W_; };
	inline void add(int y, int x, T val) { //a[y][x](0≦p<N)をdata[y][x]に(0<p≦N)
		if (y > (int)data.size() || x > (int)data[0].size()) return;
		data[y + 1][x + 1] += val;
	}//->buildする
	inline void build() {//data
		FOR(i, 0, H)FOR(j, 0, W)data[i + 1][j + 1] += data[i + 1][j];
		FOR(i, 0, H)FOR(j, 0, W)data[i + 1][j + 1] += data[i][j + 1];
	}
	inline void build2() {//かっこいい
		FOR(i, 0, H)FOR(j, 0, W)data[i + 1][j + 1] += data[i + 1][j] + data[i][j + 1] - data[i][j];
	}
	inline T query(int y, int x) {//アクセス位置変更用
		if (y < H && x < W)
			return (data[y + 1][x + 1]);
		else if (x < W)
			return (data[H][x + 1]);
		else if (y < H)
			return (data[y + 1][W]);
		else
			return (data[H][W]);
	}
	inline T querysumhei(int sy, int sx, int ty, int tx) {// 閉区間[(sy,sx),(ty,tx)]の和
		return query(ty, tx) - query(sy - 1, tx) - query(ty, sx - 1) + query(sy - 1, sx - 1);
	}
	inline T querysumhan(int sy, int sx, int ty, int tx) {//半開区間[(sy,sx),(ty,tx))の和
		return data[ty][tx] - data[sy][tx] - data[ty][sx] + data[sy][sx];
	}
};

void change(int x, int y, vector<PII>&  a) {
	int ydiv = y / K;
	int xdiv = x / K;
	int X = ((xdiv + ydiv) % 2 == 0 ? (x%K) : (x%K));
	int Y = ((xdiv + ydiv) % 2 == 0 ? (y%K) : (y%K) + K);
	int ym = -1;
	if ((xdiv + ydiv) % 2 == 0) {
		ym = 1;
	}
	FOR(k, 0, 4) {// x , y 
		a.push_back(PII(X + k*K, (k % 2 ? Y + K*ym : Y)));
	}
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> K;

	VVI w(K, VI(2 * K));
	VVI b(K, VI(2 * K));
	VI x(N), y(N);

	CumulativeSum2D<LL> BB(2 * K, 4 * K);
	CumulativeSum2D<LL> WW(2 * K, 4 * K);
	string s;
	int wc = 0, bc = 0;
	FOR(i, 0, N) {
		cin >> x[i] >> y[i] >> s;
		if (s[0] == 'B') {
			vector<PII> a;
			change(x[i], y[i], a);
			FOR(j, 0, SZ(a)) {
				BB.add(a[j].second, a[j].first, 1);
			}
		}
		else {
			vector<PII> a;
			change(x[i], y[i], a);
			FOR(j, 0, SZ(a)) {
				WW.add(a[j].second, a[j].first, 1);
			}

		}
	}
	WW.build();
	BB.build();
	FOR(y, 0, K) {// y
		FOR(x, 0, 2 * K) {
			LL res = 0;
			res += BB.querysumhan(y, x, y + K, x + K);
			//debug(res);
			res += WW.querysumhan(y, x + K, y + K, x + 2 * K);
			//debug(res);
			ans = max(ans, res);
		}
	}

	cout << ans << "\n";

	return 0;
}