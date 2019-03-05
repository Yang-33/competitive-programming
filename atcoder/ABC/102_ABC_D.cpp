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

/* -----  __MAKE_TIME__  Problem: __PROBLEM__ / Link: __CONTEST_URL__  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----



----解説ここまで---- */
struct Cumusum {
	vector<LL>csum;
	Cumusum(vector<LL>&a) {
		csum.assign((int)a.size() + 1, 0);
		for (int i = 0; i < (int)a.size(); i++) {
			csum[i + 1] = csum[i] + a[i];
		}
	}
	LL query(int l, int r) {
		return csum[r] - csum[l];
	}
};

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N;
	cin >> N;
	VL a(N);
	FOR(i, 0, N) {
		cin >> a[i];
	}
	Cumusum A(a);
	// [L,R)を絶対値の差が小さくなるように2つに分割する
	auto f = [](Cumusum&A, int Lidx, int Ridx) {
		LL L = Lidx; LL R = Ridx;
		FOR(i, 0, 60) {
			int m1 = (2 * L + R) / 3;
			int m2 = (L + 2 * R) / 3;
			LL dif1 = abs(A.query(Lidx, m1) - A.query(m1, Ridx));
			LL dif2 = abs(A.query(Lidx, m2) - A.query(m2, Ridx));
			if (dif1 < dif2) {
				R = m2;
			}
			else {
				L = m1;
			}
		}
		LL Diff = LINF; int midx = 0;
		FOR(k, 1, R - L) {
			int m = L + k;
			LL diff = abs(A.query(Lidx, m) - A.query(m, Ridx));
			if (Diff > diff) {
				Diff = diff;
				midx = m;
			}
		}
		return PLL(A.query(Lidx, midx), A.query(midx, Ridx));
	};
	LL ans = LINF;
	FOR(i, 2, N - 1) {
		PLL ab = f(A, 0, i);//[0,i)
		PLL cd = f(A, i, N);
		LL Mx = max({ ab.first,ab.second,cd.first,cd.second });
		LL Mn = min({ ab.first,ab.second,cd.first,cd.second });
		ans = min(ans, Mx - Mn);
	}


	cout << ans << "\n";

	return 0;
}
