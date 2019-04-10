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

/* -----  2019/04/10  Problem: ABC 018 C / Link: http://abc018.contest.atcoder.jp/tasks/abc018_c  ----- */

template<typename T>
struct CumulativeSum2D {
	int H, W;
	vector< vector< T > >data;
	CumulativeSum2D(int H_, int W_) : data(H_ + 1, vector< T >(W_ + 1, 0)) { H = H_, W = W_; };
	inline void add(int y, int x, T val) {
		if (y > (int)data.size() || x > (int)data[0].size()) return;
		data[y + 1][x + 1] += val;
	}//->buildする
	inline void build() {
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
/*
- x
|  A...B
y  .   .
   .   .
   .   .
   .   .
   D...C

to
-x'
|
y'
	  A
	 . .
	.	.
   .	 .
  .  	  B
 D		 .
  .  	.
   .   .
	. .
	 C

*/

struct A {
	const int DY[4] = { 0,-1, 0 , 1 };
	const int DX[4] = { -1, 0, 1, 0 };
	int H, W;
	A(int H, int W) :H(H), W(W) {}
	PII access_point(int y, int x) {
		return PII(x + y, x - y + (H - 1));
	}
	PII access_max() {
		return PII(W + H - 1, W + H - 1);
	}
	vector<PII>access_from_center(int y, int x, int k) {
		vector<PII>res;
		FOR(d, 0, 4) {
			int ny = y + DY[d] * k, nx = x + DX[d] * k;
			res.push_back(this->access_point(ny, nx));
		}
		return res;
	}
	PII rev(int y, int x) {
		return PII((H - 1 + y - x) / 2, (x + y + 1 - H) / 2);
	}
};

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL H, W; cin >> H >> W;
	LL K; cin >> K;
	vector<string> s(H);
	for (int i = 0; i < H; ++i) {
		cin >> s[i];
	}

	A ac(H, W);
	auto r = ac.access_max();
	DD(de(r));
	CumulativeSum2D<LL> cumsum2(r.first, r.second);
	FOR(i, 0, H) {
		FOR(j, 0, W) {
			if (s[i][j] == 'x') {
				auto p = ac.access_point(i, j);
				DD(de(p));
				cumsum2.add(p.first, p.second, 1);
			}
		}
	}
	cumsum2.build();
	LL ans = 0LL;
	FOR(y, K - 1, H - K + 1) {
		FOR(x, K - 1, W - K + 1) {
			auto p = ac.access_from_center(y, x, K - 1);
			auto s = p.front(), t = p[2];
			DD(de(s, t));
			LL res = cumsum2.querysumhei(s.first, s.second, t.first, t.second);
			ans += res == 0;
		}
	}






	cout << (ans) << "\n";

	return 0;
}
