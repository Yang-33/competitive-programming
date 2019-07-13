#define _GLIBCXX_DEBUG
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

/* -----  2019/07/13  Problem: AOJ 0036 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0036  ----- */

struct RollingHash2D {
	typedef unsigned long long ull;

	struct RollingHash {
		typedef unsigned long long ull;
		string S;
		ull B;
		int len;
		vector<ull> hash, p;
		RollingHash() {}
		RollingHash(string S_, ull B_ = 1000000007LL) :
			S(S_), B(B_), len(S.length()), hash(len + 1), p(len + 1) {
			hash[0] = 0; p[0] = 1;
			for (int i = 0; i < len; i++) {
				hash[i + 1] = hash[i] * B + S[i];
				p[i + 1] = p[i] * B;
			}
		}
		//S[l,r)
		ull find(int l, int r) {
			return hash[r] - hash[l] * p[r - l];
		}
	};

	vector<string> S;
	int h, w, r, c;
	ull B;
	vector<ull> p;
	vector<vector<ull> > hash;
	vector<RollingHash> rh;
	RollingHash2D() {}
	RollingHash2D(vector<string> S_, int r_, int c_, ull B_ = 1000000009LL) :
		S(S_), h(S_.size()), w(S_[0].size()), r(r_), c(c_), B(B_),
		p(h + 1), hash(h + 1, vector<ull>(w - c + 1, 0)), rh(h) {
		for (int i = 0; i < h; i++) rh[i] = RollingHash(S[i]);
		p[0] = 1;
		for (int i = 0; i < h; i++) p[i + 1] = p[i] * B;
		for (int j = 0; j < w - c + 1; j++) {
			hash[0][j] = 0;
			for (int i = 0; i < h; i++)
				hash[i + 1][j] = hash[i][j] * B + rh[i].find(j, j + c);
		}
	}
	//[i,i+r) * [j,j+c)
	ull find(int i, int j) {
		return hash[i + r][j] - hash[i][j] * p[r];
	}
};
int main() {

	vector<VS> teto = { {"11","11"},{"1","1","1","1"},{"1111"},{"01","11","10"},{"110","011"},{"10","11","01"},{"011","110"} };
	const string ABCDEFG = "ABCDEFG";
	VS m(8);
	while (cin >> m[0]) {
		FOR(i, 1, 8)cin >> m[i];
		char ans = 1;
		FOR(i, 0, 7) {
			int marky = SZ(teto[i]);
			int markx = SZ(teto[i].front());
			RollingHash2D ori(m, marky,markx);
			RollingHash2D mark(teto[i], marky, markx);
			FOR(y, 0, 8) {
				FOR(x, 0, 8) {
					if (y + marky <= 8 && x + markx <= 8) {
						if (ori.find(y, x) == mark.find(0, 0))ans = ABCDEFG[i];
					}
				}
			}

		}
		cout << ans << "\n";
	}

	return 0;
}
