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

/* -----  2018/06/10  Problem: AOJ 2778 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2778  ----- */
/* ------問題------

N<=40枚のカードのシャッフルが与えられる。K<=N^2種類のシャッフルがあり、それぞれt[i]秒かかる。
T<=10^6病かけて、最終的にCが一番上になるようなシャッフルは何通りあるか。

-----問題ここまで----- */
/* -----解説等-----

行列累乗っぽい。(遷移サイズとTで明らかにDP加速タイプを感じる)
えーわからんという気持ちになるが、状態としては5項間漸化式のような形をしていることがわかる。
行列累乗のm項間漸化式を実装すれば良い。

行列のサイズは、位置の状態がN*1,遷移がN*Nなので拡大遷移が5N*5Nになる。

----解説ここまで---- */

//a*B
template<typename T>
vector<vector<T>> mul(vector<vector<T>> &A, vector<vector<T>> &B) {
	vector<vector<T>> C(A.size(), vector<T>(B[0].size()));
	FOR(i, 0, (int)A.size()) {
		FOR(k, 0, (int)B.size()) {
			if (A[i][k]) {// 0のときはやらない
				FOR(j, 0, (int)B[0].size()) {
					C[i][j] = (C[i][j] + (A[i][k]) * (B[k][j])) % MOD;
				}
			}
		}
	}
	return C;
}

//a^N べき乗法 logN
template<typename T>
vector<vector<T>> pow(vector<vector<T>> A, long long n) {
	vector<vector<T>> B((int)A.size(), vector<T>((int)A.size()));
	FOR(i, 0, (int)A.size()) {
		B[i][i] = 1;
	}
	while (n > 0) {
		if (n & 1) B = mul(B, A);
		A = mul(A, A);
		n >>= 1;
	}
	return B;
}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, K, C, T;
	cin >> N >> K >> C >> T;
	VVL A(5 * N, VL(1, 0));
	VVL B(5 * N, VL(5 * N, 0));
	FOR(k, 1, 5) {
		FOR(i, 0, N) {
			B[k*N + i][(k - 1)*N + i] = 1;
		}
	}
	C--;
	A[C][0] = 1;
	FOR(q, 0, K) {
		int a, b, t; cin >> a >> b >> t;
		t--;
		a--;
		FOR(i, 0, N) {
			if (a + b - 1 < i) { // c
				B[i][t*N + i]++;
			}
			else if (i < a) { // 
				B[b + i][t*N + i]++;
			}
			else { // 
				B[i - a][t*N + i]++;
			}
		}
	}
	if (0) {
		FOR(i, 0, 5 * N) {
			FOR(j, 0, 5 * N) {
				cout << B[i][j] << " ";
			}cout << endl;
		}
	}

	B = pow<LL>(B, T);//行列aのN乗
	if (0) {
		FOR(i, 0, 5 * N) {
			FOR(j, 0, 5 * N) {
				cout << B[i][j] << " ";
			}cout << endl;
		}
	}
	auto ans = mul<LL>(B, A);
	cout << ans[0][0] << endl;


	return 0;
}
