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

/* -----  2017/10/03  Problem: AOJ 0010  / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0010&lang=jp ----- */
/* ------問題------

二次元座標中の三角形の3点が与えられる。この三角形の外接円の中心座標と半径は。

-----問題ここまで----- */
/* -----解説等-----

高校数学。
3点を通る円は
x^2+y^2+a[0]x+a[1]y+a[2]=0
これは連立方程式として解けるので解く。
式変形をすれば中心、半径もわかるのでOK

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

		if (abs(B[i][i]) < EPS) { //解がないか一意でない
								  //cout << "error be." << endl;
			return vector<T>();
		}

		for (int j = i + 1; j <= n; j++)B[i][j] /= B[i][i];
		for (int j = 0; j < n; j++) {
			if (i != j) {
				for (int k = i + 1; k <= n; k++)
					B[j][k] -= B[j][i] * B[i][k];
			}
		}
	}
	vector<T> x(n);//解
	for (int i = 0; i < n; i++) {
		x[i] = B[i][n];
	}

	return x;//veci.
}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	double x[3], y[3];
	FOR(i, 0, N) {
		vector<vector<double>>A(3, vector<double>(3));
		vector<double>B(3);

		FOR(j, 0, 3) {
			cin >> x[j] >> y[j];
			A[j][0] = x[j];
			A[j][1] = y[j];
			A[j][2] = 1;
			B[j] = -(x[j] * x[j] + y[j] * y[j]);
		}
		vector<double>X=gauss_jordan(A,B);

		cout << fixed << setprecision(3);
		cout << -X[0]/2<<" "<<-X[1]/2<<" "<< sqrt((X[0]*X[0]+X[1]*X[1])/4.0-X[2]) << endl;
	}
	
	return 0;
}
