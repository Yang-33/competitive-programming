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

/* -----  2018/04/16  Problem: yukicoder 075  / Link: http://yukicoder.me/problems/no/075  ----- */
/* ------問題------

1個のサイコロを何回か振って目の合計をちょうどKにしたい。
もしKを超えてしまったら合計を0にリセットする。
ただしサイコロを振った回数はリセットされない。
例えば、K=5のときサイコロを1回振って6が出たとする。
この場合はKを超えてしまったので合計を0に戻し2回目を振ることになる。
サイコロは目の合計がちょうどKになるまで振り続ける。
サイコロを振る回数の期待値を求めよ。

-----問題ここまで----- */
/* -----解説等-----

典型らしい。知らなかったので嬉しい。
解法1: P(0) = P(K+1) = P(K+2) ...よりK+1本の連立方程式 で解ける(これは思いつこう☆)
解法2: P(0)が全てに絡むので、dp(i) = Ai dp(0) + Bi として解ける(大事そう☆)
解法3: dp(K+x)=mと仮定してDPし、dp(0)≧mかどうかを判定する。これは二分探索でできる(たしかに☆)
解法4: ガウスサイデル法で反復し解の収束を行なう(それはそうだね)
解法5: モンテカルロ(うんうん)

----解説ここまで---- */
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
			cerr << "error be." << endl;
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


void solve1(int K) { // 連立方程式
	vector<vector<double>>A(K + 1, vector<double>(K + 1, 0));
	vector<double> b(K + 1, 0);
	FOR(i, 0, K) {
		A[i][i] = 6.0;
		FOR(j, 1, 6 + 1) {
			if (i + j <= K)A[i][i + j]--;
			else A[i][0]--;
		}
		b[i] = 6;
	}
	A[K][K] = 1;
	vector<double>E = gauss_jordan(A, b);
	cout << fixed << setprecision(5) << E[0] << endl;

}
void solve2(int K) { // 漸化式
	vector<double>A(K + 7, 0), B(K + 7, 0);

	// dp[K] = A[K](=0) * dp[0] + B[K](=0) = 0, DP[0] = DP[K+1] = DP[K+2] = (1) * DP[0] + (0)
	FORR(i, K - 1, 0 - 1) {
		FOR(j, 1, 6 + 1) {
			if (i + j <= K) {
				A[i] += 1.0 / 6.0*A[i+j];
				B[i] += 1.0 / 6.0*B[i+j];
			}
			else {
				A[i] += 1.0 / 6.0;
			}
		}
		B[i] += 1.0;

	}

	// x = Ax+B -> x = B / (1-A)
	cout << fixed << setprecision(5) << B[0]/(1-A[0]) << endl;
}
void solve3(int K) { // DP 二分探索

	double L = 0, R = 1e7;
	FOR(i, 0, 100) {
		double mid = (L + R) / 2;
		vector<double>dp(K + 1, 0);
		dp[K] = 0;
		FORR(i, K - 1, 0 - 1) {
			double sum = 0;
			FOR(j, 1, 6 + 1) {
				if (i + j > K)sum += mid;
				else sum += dp[i + j];
			}
			dp[i] = 1.0 + sum / 6.0;
		}
		if (dp[0] <= mid) {
			R = mid;
		}
		else {
			L = mid;
		}
	}


	cout << fixed << setprecision(5) << R << endl;
}
void solve4(int K) { // 収束
	vector<double>dp(K + 6, 0);
	FOR(t, 0, 10000) {
		FOR(i, 0, K) {
			double tmp = 6;
			FOR(j, 1, 6 + 1) {
				if (i + j > K)tmp += dp[0];
				else tmp += dp[i + j];
			}
			dp[i] = tmp / 6.0;
		}
	}
	cout << fixed << setprecision(5) << dp[0] << endl;
}
void solve5(int K) { //モンテカルロ法
	LL sum = 0;
	for (int t = 0; t < 100000; t++) {
		int k = 0;
		for (int i = 1; ; i++) {
			k += 1 + rand() % 6;
			if (k == K) {
				sum += i;
				break;
			}
			else if (k > K) k = 0;
		}
	}
	cout << fixed << setprecision(5) << sum / 100000.0 << endl;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int K; cin >> K;
	solve3(K);

	return 0;
}
