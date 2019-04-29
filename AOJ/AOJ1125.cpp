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
//#pragma GCC optimize ("-O3") 
#ifdef YANG33
#include "mydebug.hpp"
#else
#define DD(x) 
#endif
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);

/* -----  2019/04/29  Problem: AOJ 1125 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/1125  ----- */

template<typename T>
struct CumulativeSum2D {//使うときは内部で1-indexになっているので普通に0-indexで使えばよい	
	int H, W;
	vector< vector< T > >data;
	CumulativeSum2D(int H_, int W_) : data(H_ + 1, vector< T >(W_ + 1, 0)) { H = H_, W = W_; };
	inline void add(int y, int x, T val) { //a[y][x](0≦p<N)をdata[y][x]に(0<p≦N)
		if (y > (int)data.size() || x > (int)data[0].size()) return;
		data[y + 1][x + 1] += val;
	}//->buildする
	inline void build() {//data imos/cumsum
		FOR(i, 0, H)FOR(j, 0, W)data[i + 1][j + 1] += data[i + 1][j];
		FOR(i, 0, H)FOR(j, 0, W)data[i + 1][j + 1] += data[i][j + 1];
	}
	inline T query(int y, int x) {//アクセス位置変更用, (imos)
		return (data[y + 1][x + 1]);
	}

	inline T querysumhei(int sy, int sx, int ty, int tx) {// 閉区間[(sy,sx),(ty,tx)]の和(cumsum)
		return query(ty, tx) - query(sy - 1, tx) - query(ty, sx - 1) + query(sy - 1, sx - 1);
	}
};


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N;
	while (cin >> N, N) {
		int H, W; cin >> W >> H;
		CumulativeSum2D<LL> csum(H, W);
		FOR(i, 0, N) {
			int x, y; cin >> x >> y;
			x--, y--;
			csum.add(y, x, 1);
			DD(de(H,W,y,x))
		}
		csum.build();
		DD(de(N))
		int Hw, Ww; cin >> Ww >> Hw;
		DD(de(Ww,Hw))
		LL ans = 0LL;
		FOR(sy, 0, H-Hw+1) {
			FOR(sx, 0, W-Ww+1) {
				ans = max(ans, csum.querysumhei(sy, sx, sy + Hw-1, sx + Ww-1));
			}
		}


		cout << (ans) << "\n";

	}

	return 0;
}
