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

/* -----  2018/07/30  Problem: yukicoder 187  / Link: http://yukicoder.me/problems/no/187  ----- */
/* ------問題------

諸外国では，○＋□＝8のように，答えがたくさんある問題があるようですが，採点が大変ですよね．
今度は，中華風にアレンジしてみましょう．
N 個の整数の 2 つ組 (X1,Y1),(X2,Y2),…,(XN,YN) が与えられるので，
　　□ mod Yk=Xk,k=1,2,…,N
を同時に満たす□に当てはまる正整数を求めてください．
あれ，これは，答えがたくさんあるかもしれません．
その場合は，最も小さいものを求めてください．
最も小さいものでも大きい数になるかもしれないので，答えを 109+7 で割った余りだけ答えてください．

-----問題ここまで----- */
/* -----解説等-----

100%写経 記事ありがとうございます(https://qiita.com/drken/items/ae02240cd1f8edfc86fd)

----解説ここまで---- */



long long GCD(long long a, long long b) {
	if (b == 0) return a;
	else return GCD(b, a % b);
}

long long PreGarner(vector<long long> &b, vector<long long> &m, long long MOD) {
	long long res = 1;
	for (int i = 0; i < (int)b.size(); ++i) {
		for (int j = 0; j < i; ++j) {
			long long g = GCD(m[i], m[j]);

			if ((b[i] - b[j]) % g != 0) return -1;

			m[i] /= g; 
			m[j] /= g; 
			long long gi = GCD(m[i], g), gj = g / gi;
			do {
				g = GCD(gi, gj);
				gi *= g, gj /= g;
			} while (g != 1);
			m[i] *= gi, m[j] *= gj;
			b[i] %= m[i], b[j] %= m[j];
		}
	}
	for (int i = 0; i < (int)b.size(); ++i) (res *= m[i]) %= MOD;
	return res;
}

inline long long add(long long a, long long m) {
	long long res = a % m;
	if (res < 0) res += m;
	return res;
}

long long extGCD(long long a, long long b, long long &p, long long &q) {
	if (b == 0) { p = 1; q = 0; return a; }
	long long d = extGCD(b, a%b, q, p);
	q -= a / b * p;
	return d;
}

long long modinv(long long a, long long m) {
	long long x, y;
	extGCD(a, m, x, y);
	return add(x, m); 
}

long long Garner(vector<long long> b, vector<long long> m, long long MOD) {
	m.push_back(MOD);
	vector<long long> coeffs((int)m.size(), 1);
	vector<long long> constants((int)m.size(), 0);
	for (int k = 0; k < (int)b.size(); ++k) {
		long long t = add((b[k] - constants[k]) * modinv(coeffs[k], m[k]), m[k]);
		for (int i = k + 1; i < (int)m.size(); ++i) {
			(constants[i] += t * coeffs[i]) %= m[i];
			(coeffs[i] *= m[k]) %= m[i];
		}
	}
	return constants.back();
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N; cin >> N;
	int f = 0;
	VL x(N), y(N);
	FOR(i, 0, N) {
		cin >> x[i] >> y[i];
		if (x[i])f = 1;
	}
	LL lcms = PreGarner(x, y, MOD);

	LL ans;
	if (!f)ans = lcms;// 0
	else if (lcms == -1)ans = -1;
	else ans = Garner(x,y,MOD);
	cout << ans << "\n";

	return 0;
}
