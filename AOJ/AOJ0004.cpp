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

/* -----  2017/10/03  Problem: AOJ 0004  / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0004&lang=jp ----- */
/* ------問題------

二元連立方程式を解く

-----問題ここまで----- */
/* -----解説等-----

手元に紙がないから行列式でパンチ

----解説ここまで---- */

LL N;

LL ans = 0LL;

template<typename T>
vector<T> gauss_jordan(const vector<vector<T>>& A, const vector<T>& b) {
	const double EPS = 1e-8;
	int n = (int)A.size();
	vector<vector<T>> B(n, vector<T>(n + 1));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			B[i][j] = A[i][j];
	}
	for (int i = 0; i < n; i++) {
		B[i][n] = b[i];
	}
	for (int i = 0; i < n; i++) {
		int pivot = i;
		for (int j = i; j < n; j++) {
			if (abs(B[i][j]) > abs(B[pivot][i]))pivot = j;
		}
		swap(B[i], B[pivot]);

		for (int j = i + 1; j <= n; j++)B[i][j] /= B[i][i];
		for (int j = 0; j < n; j++) {
			if (i != j) {
				for (int k = i + 1; k <= n; k++)
					B[j][k] -= B[j][i] * B[i][k];
			}
		}
	}
	vector<T> x(n);
	for (int i = 0; i < n; i++) {
		x[i] = B[i][n];
	}

	return x;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	double a, b, c, d, e, f; N = 2;
	while (cin >> a >> b >> c >> d >> e >> f) {
		vector<vector<double>>A(N, vector<double>(N));
		A[0][0] = a; A[0][1] = b;
		A[1][0] = d; A[1][1] = e;
		vector<double>B(N);
		B[0] = c; B[1] = f;
		vector<double>sol = gauss_jordan<double>(A, B);
		cout << fixed << setprecision(3);
		cout << sol[0] << " " << sol[1] << endl;
	}


	return 0;
}


