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

/* -----  2018/05/03  Problem: yukicoder 147  / Link: http://yukicoder.me/problems/no/147  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

なんか実験するとフィボナッチ数がみえる.
したがって ans = Πfib(c)^d となる。
dがヤバイので、この処理を考えると、X^(d-1) ≡ 1 (mod M)がフェルマーの少定理からわかるので、MOD-1で剰余を取れば良い。  
コーナーケースとして、fib(c)==0のとき、d==0だと1が出力されてしまうが、これは嘘で、0(気がつくのにめっちゃ時間がかかった)
注意力なあ…

----解説ここまで---- */


int H, W;

template<typename T>
vector<vector<T>> mul(vector<vector<T>> &A, vector<vector<T>> &B) {
	vector<vector<T>> C(A.size(), vector<T>(B[0].size()));
	FOR(i, 0, (int)A.size()) {
		FOR(k, 0, (int)B.size()) {
			if (A[i][k]) { 
				FOR(j, 0, (int)B[0].size()) {
					C[i][j] = (C[i][j] + (A[i][k]) * (B[k][j]))%MOD;
				}
			}
		}
	}
	return C;
}

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

LL fib(LL x) {
	vector<vector<LL>> A(2, VL(2, 1));
	A[1][1] = 0;
	A = pow<LL>(A, x+1);
	return A[0][0]%MOD;
}


LL string_mod(string& s) {
	LL ret = 0;
	FOR(i, 0, SZ(s)) {
		ret *= 10;
		ret += s[i] - '0';
		ret %= (MOD-1);
	}

	return ret;
}
long long  powmod(long long  x, long long  n, long long  mod) {
	long long  res = 1;
	while (n > 0) {
		if (n & 1) {
			res = (res*x) % mod;
		}
		x = (x*x) % mod;
		n >>= 1;
	}
	return res;
}

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	ans = 1;
	FOR(i, 0, N) {
		LL c; string d;
		cin >> c >> d;
		LL D = string_mod(d);
		LL F = fib(c);
		if (F == 0)ans = 0;
		LL ret = powmod(F,D,MOD);
		ans *= ret;
		ans %= MOD;
	}
	cout << ans << "\n";

	return 0;
}
