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

/* -----  2017/09/17  Problem: fbai_game  / Link: 出典無し  ----- */
/* ------問題------

石がn個積まれている(n≥2)。交互に1つ以上の石を取り去り、最後の石を取れば勝ちである。ただし次のルールを守らなければいけない。

(1) 先手は最初に全ての石をとってはいけない。

(2) 相手が直前に取った石の数の2倍より多く取ってはいけない。

-----問題ここまで----- */
/* -----解説等-----

http://fibonacci-freak.hatenablog.com/entry/2017/07/17/150239
でした。びっくり
フィボナッチ数であれば後手必勝

----解説ここまで---- */


const double EPS = 1e-8;
typedef vector<LL> vec;
typedef vector<vec> mat;
/* 行列累乗 */

//H = 行列の縦, W = 行列の横, M = modをとるときに使う(無い場合は消す)
const int  MatMod = 1000;
int H, W;

//A*B
mat mul(mat &A, mat &B,const int mod) {
	mat C(A.size(), vec(B[0].size()));
	FOR(i, 0, A.size()) {
		FOR(k, 0, B.size()) {
			FOR(j, 0, B[0].size()) {
				C[i][j] = (C[i][j] + (A[i][k]) * (B[k][j])) % mod;
			}
		}
	}
	return C;
}

//A^n べき乗法 logN
mat pow(mat A, long long n) {
	mat B(A.size(), vec(A.size()));
	FOR(i, 0, A.size()) {
		B[i][i] = 1;
	}
	while (n > 0) {
		if (n & 1) B = mul(B, A,MatMod);
		A = mul(A, A,MatMod);
		n >>= 1;
	}
	return B;
}

LL solve(LL n) {
	H = W = 2;//cin >> H >> W;
	mat A(H, vec(W));
	A[0][0] = A[0][1] = A[1][0] = 1;
	A[1][1] = 0;
	A = pow(A, n);

	return A[1][0];
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int ans = -1;

	LL Pile;  cin >> Pile;
	unsigned long long L = 0, R = ULLONG_MAX;

	while (ans==-1) {
		unsigned long long mid = (L + R) / 2ULL;
		if (Pile <= solve(mid)) {
			R = mid;
			if (Pile == solve(mid))ans = 1;
		}
		else L = mid;
	}
	cout << ((ans==-1)?"First":"Second") << "\n";

	return 0;
}
