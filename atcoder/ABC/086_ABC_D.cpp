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
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2019/03/11  Problem: ABC 086 D / Link: http://abc086.contest.atcoder.jp/tasks/abc086_d  ----- */


template<typename T>
struct CumulativeSum2D {
	int H, W;
	vector< vector< T > >data;
	CumulativeSum2D(int H_, int W_) : data(H_ + 1, vector< T >(W_ + 1, 0)) { H = H_, W = W_; };
	inline void add(int y, int x, T val) {
		if (y > (int)data.size() || x > (int)data[0].size()) return;
		data[y + 1][x + 1] += val;
	}
	inline void build() {
		FOR(i, 0, H)FOR(j, 0, W)data[i + 1][j + 1] += data[i + 1][j];
		FOR(i, 0, H)FOR(j, 0, W)data[i + 1][j + 1] += data[i][j + 1];
	}
	inline T query(int y, int x) {
		return (data[y + 1][x + 1]);
	}
	inline T QUERY(int sy, int sx, int ty, int tx) {
		return data[ty][tx] - data[sy][tx] - data[ty][sx] + data[sy][sx];
	}
};



int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, K; cin >> N >> K;
	CumulativeSum2D<LL>B(4 * K, 4 * K);
	CumulativeSum2D<LL>W(4 * K, 4 * K);
	auto ADD = [&](CumulativeSum2D<LL> &C, LL y, LL x) {
		C.add(y, x, 1);
		C.add(y + 2 * K, x, 1);
		C.add(y, x + 2 * K, 1);
		C.add(y + 2 * K, x + 2 * K, 1);
	};
	FOR(i, 0, N) {
		LL x, y; char c;
		cin >> x >> y >> c;
		x %= 2 * K, y %= 2 * K;
		if (c == 'B')ADD(B, y, x);
		else ADD(W, y, x);
	}
	W.build();
	B.build();
	LL ans = 0LL;
	FOR(ky, 0, 2 * K) {
		FOR(kx, 0, 2 * K) {
			{
				LL ret = W.QUERY(ky, kx, ky + K, kx + K);
				ret += W.QUERY(ky + K, kx + K, ky + 2 * K, kx + 2 * K);
				ret += B.QUERY(ky, kx + K, ky + K, kx + 2 * K);
				ret += B.QUERY(ky + K, kx, ky + 2 * K, kx + K);
				ans = max(ans, ret);
			}
			{
				LL ret = B.QUERY(ky, kx, ky + K, kx + K);
				ret += B.QUERY(ky + K, kx + K, ky + 2 * K, kx + 2 * K);
				ret += W.QUERY(ky, kx + K, ky + K, kx + 2 * K);
				ret += W.QUERY(ky + K, kx, ky + 2 * K, kx + K);
				ans = max(ans, ret);
			}
		}
	}


	cout << (ans) << "\n";

	return 0;
}
