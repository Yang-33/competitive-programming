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

/* -----  2018/04/17  Problem: yukicoder 081  / Link: http://yukicoder.me/problems/no/081  ----- */
/* ------問題------

与えられるN個の値の総和を求めよ。

-----問題ここまで----- */
/* -----解説等-----

桁落ちするので、小数点と整数部で分けて計算する。
簡単なお仕事ができませんでした。

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	VS vs(N);
	LL pA = 0, pB = 0;
	LL mA = 0, mB = 0;
	LL Base10 = 10000000000;
	FOR(i, 0, N) {
		cin >> vs[i];
		int pos = -1;
		int minus = 1;
		if (vs[i].front() == '-') {
			minus = -1;
			vs[i] = vs[i].substr(1);
		}
		FOR(j, 0, SZ(vs[i])) {
			if (vs[i][j] == '.')pos = j;
		}
		if (pos == -1) {
			pos = SZ(vs[i]);
			vs[i] += string(1, '.');
		}
		LL a = 0;
		FOR(j, 0, pos) {
			a *= 10;
			a += vs[i][j] - '0';
		}
		LL b = 0;
		vs[i] += string(15, '0');
		FOR(j, pos + 1, pos + 1 + 10) {
			b *= 10;
			b += vs[i][j] - '0';
		}
		if (minus == 1) {
			pA += a, pB += b;
			pA += pB / Base10;
			pB = pB % Base10;
		}
		else {
			mA += a, mB += b;
			mA += mB / Base10;
			mB = mB % Base10;

		}
	}
	// (+A.B) + (-A.B)
	LL ndiff = pA - mA;
	ndiff += -(pB - mB < 0);


	if (ndiff >= 0) {
		pB -= mB;
		if (pB < 0) {
			pB += Base10;
			mA++;
		}
		pA -= mA;
		printf("%lld.%010lld\n", pA, pB);
	}
	else {
		mB -= pB;
		if (mB < 0) {
			mB += Base10;
			pA++;
		}
		mA -= pA;
		printf("-%lld.%010lld\n", mA, mB);
	}


	return 0;
}
