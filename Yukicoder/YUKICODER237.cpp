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

/* -----  2018/08/25  Problem: yukicoder 237  / Link: http://yukicoder.me/problems/no/237  ----- */
/* ------問題------

整数 A が与えられます。 3 以上 A 以下の整数 n のうち、定規とコンパスによって正 n 角形が作図可能であるようなものの個数を求めてください。

定規とコンパスによる作図、およびこの問題を解く上で必要な知識に関しては Wikipedia を参照してください：

-----問題ここまで----- */
/* -----解説等-----

wikipediaによるとフェルマー数にふくまれるフェルマー素数は5つで、これの部分集合の積*2^mが作図可能らしいのでこれを列挙する。

----解説ここまで---- */
long long mpow(long long a, long long b) {
	if (b == 0) return 1;
	return mpow(a * a, b / 2) * (b & 1 ? a : 1);
}
LL fermatNumber(int n) {
	LL index = mpow(2, n);
	return mpow(2, index) + 1;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N; cin >> N;
	VL fermatPrimes(5);
	FOR(i, 0, 5)fermatPrimes[i] = fermatNumber(i);
	VL fermatProducts(1 << 5);
	FOR(state, 0, 1 << 5) {
		LL ret = 1;
		FOR(i, 0, 5) {
			if (state & 1 << i)ret *= fermatPrimes[i];
		}
		fermatProducts[state] = ret;
	}
	VL drawableRegularPolygonNumbers;
	FOR(state, 0, 1 << 5) {
		LL val = fermatProducts[state];
		for (;val<=1e9;val<<=1) {
			drawableRegularPolygonNumbers.push_back(val);
		}
	}
	SORT(drawableRegularPolygonNumbers); UNIQ(drawableRegularPolygonNumbers);
	int ans = upper_bound(ALL(drawableRegularPolygonNumbers),N)- drawableRegularPolygonNumbers.begin() -2;
	cout << ans << "\n";

	return 0;
}
