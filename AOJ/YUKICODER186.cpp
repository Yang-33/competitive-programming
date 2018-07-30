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
#define debug(x) cerr << #x << ": " << x << endl
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/07/30  Problem: yukicoder 186  / Link: http://yukicoder.me/problems/no/186  ----- */
/* ------問題------

諸外国では，○＋□＝8のように，答えがたくさんある問題があるようですが，採点が大変ですよね．
今度は，中華風にアレンジしてみましょう．
3 個の整数の 2 つ組 (X1,Y1),(X2,Y2),(X3,Y3) が与えられるので，
　　□ mod Yk=Xk,k=1,2,3
を同時に満たす□に当てはまる正整数を求めてください．
あれ，これは，答えがたくさんあるかもしれません．
その場合は，最も小さいものを求めてください．

-----問題ここまで----- */
/* -----解説等-----

中国剰余定理で一意に定まる。
正整数なあ…

----解説ここまで---- */

LL add(LL a, LL m) {
	return (a % m + m) % m;
}

LL extgcd(LL a, LL b, LL &p, LL &q) {
	if (b == 0) { p = 1; q = 0; return a; }
	LL d = extgcd(b, a%b, q, p);
	q -= a / b * p;
	return d;
}

PLL ChineseRem(const VL &b, const VL &m) {
	LL r = 0, M = 1;
	FOR(i, 0, SZ(b)) {
		LL p, q;
		LL d = extgcd(M, m[i], p, q);
		if ((b[i] - r) % d != 0) return PLL(0, -1);
		LL tmp = (b[i] - r) / d * p % (m[i] / d);
		r += M * tmp;
		M *= m[i] / d;
	}
	return PLL(add(r, M), M);
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N = 3;
	int f = 0;
	VL x(N), y(N);
	FOR(i, 0, N) {
		cin >> x[i] >> y[i];
		if (x[i] == 0)f = 1;
	}
	PLL a = ChineseRem(x, y);
	LL ans;
	if (a.second == -1 ) ans = -1;
	else  if (f)ans = a.second;
	else ans = a.first;
	cout << ans << "\n";

	return 0;
}
