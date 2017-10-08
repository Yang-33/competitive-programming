#include "bits/stdc++.h"
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

/* -----  2017/06/25  Problem: CodeForces420 E div2 / Link: http://codeforces.com/contest/821/problem/E  ----- */
/* ------問題------

x=[a,b],y=cに棒がある。この上を通らずに(0,0)から(K,0)への移動の仕方は何通りあるか。
移動は(x,y)から (x + 1, y + 1), (x + 1, y), or (x + 1, y - 1).に限るものとする。

-----問題ここまで----- */
/* -----解説等-----

これは最悪な繰り返しDPなので、行列累乗ができる。
遷移行列はC*Cなのでとても小さい。
O(NC^3logK)ぐらい
各棒の遷移のサイズは異なるのでここを工夫すればよい。

----解説ここまで---- */


int s = 0;

typedef vector<LL> Col;
typedef vector<Col> Matrix;

Matrix mul(const Matrix& A, const Matrix& B) {
	const int R = A.size(), C = B[0].size(), sz = B.size();
	Matrix AB(R, Col(C));

	for (int i = 0; i<R; ++i)
		for (int j = 0; j<C; ++j)
			for (int k = 0; k<sz; ++k)
				(AB[i][j] += A[i][k] * B[k][j] % MOD) %= MOD;

	return AB;
}
Matrix powA(const Matrix& A, LL n) {
	const int N = A.size();
	Matrix p(N, Col(N, 0)), w = A;
	for (int i = 0; i<N; ++i) p[i][i] = 1;

	while (n>0) {
		if (n & 1)
			p = mul(p, w);
		w = mul(w, w);
		n >>= 1;
	}

	return p;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, K;
	cin >> N >> K;
	Matrix crt(16, Col(1));
	crt[0][0] = 1;
	FOR(i,0, N) {
		LL a, b, c;
		cin >> a >> b >> c;
		if (K < b) b = K;
		VVL tmp(c + 1, Col(c + 1));
		FOR(i,0, c + 1) {
			if (i - 1 >= 0) tmp[i][i - 1] = 1;
			tmp[i][i] = 1;
			if (i + 1 < c + 1) tmp[i][i + 1] = 1;
		}
		tmp = powA(tmp, b - a);
		VVL y(c + 1, Col(1));
		FOR(i,0, min(c + 1, (LL)SZ(crt))) y[i][0] = crt[i][0];

		crt = mul(tmp, y);
	}
	cout << crt[0][0] << endl;

	return 0;
}