#include "bits/stdc++.h"
#include "complex"
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

/* -----  2017/10/03  Problem: AOJ 0021  / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0021&lang=jp ----- */
/* ------問題------

2線分の平行判定

-----問題ここまで----- */
/* -----解説等-----

外積。ゼロなら平行

----解説ここまで---- */

LL N;
typedef double R;
typedef complex<R> P;

const R EPS = 1e-10;
const R PI = acos(-1);
int sgn(R a) {
	if (a < -EPS) return -1;
	if (a > EPS) return 1;
	return 0;
}


bool near(P a, P b) {
	return !sgn(abs(a - b));
}

double cross(const P &a, const P &b) { return imag(conj(a)*b); }
double dot(const P &a, const P &b) { return real(conj(a)*b); }
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	FOR(i, 0, N) {
		P p[4];
		FOR(j, 0, 4) {
			R x, y;
			cin >> x >> y;
			p[j] = P(x, y);
		}
		if (!sgn(cross(p[0] - p[1], p[2] - p[3]))) {
			cout << "YES" << "\n";
		}
		else cout << "NO" << "\n";
	}


	return 0;
}
