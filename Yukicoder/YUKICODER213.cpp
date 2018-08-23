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

/* -----  2018/08/21  Problem: yukicoder 213  / Link: http://yukicoder.me/problems/no/213  ----- */
/* ------問題------

素数サイコロとはそれぞれの面に 2,3,5,7,11,13 の整数が書かれているサイコロである。
合成数サイコロとはそれぞれの面に 4,6,8,9,10,12 の整数が書かれているサイコロである。
あるスゴロクでは、0 のマスからスタートし、N のマスに辿り着いたらゴールである。
各ターン、P 個の素数サイコロと C 個の合成数サイコロを振り、出た目の和を x として、今いるマスが k ならば min(k+x,N) のマスに移動する。
それぞれ素数サイコロと合成数サイコロは区別できないとして、ゴールする方法のパターン数を mod 1000000007 (109+7) で求めるプログラムを書いて下さい。

-----問題ここまで----- */
/* -----解説等-----

DPが本質で行列累乗はおまけ
DPの解説:
区別しないので、(2,2,2,...,2)を要素ごとに変更していく感じのDPをする

----解説ここまで---- */

template<typename T>
vector<vector<T>> mul(vector<vector<T>> &A, vector<vector<T>> &B) {
	vector<vector<T>> C(A.size(), vector<T>(B[0].size()));
	FOR(i, 0, (int)A.size()) {
		FOR(k, 0, (int)B.size()) {
			if (A[i][k]) {
				FOR(j, 0, (int)B[0].size()) {
					C[i][j] = (C[i][j] + (A[i][k]) * (B[k][j])) % MOD;
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

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	VI pdice = { 2,3,5,7,11,13 };
	VI cdice = { 4,6,8,9,10,12 };

	LL N, P, C; cin >> N >> P >> C;
	auto makeDP = [](int n, const VI&dice) {
		VVI dp(n + 1, VI(dice.back() * n + 1, 0));
		dp[0][0] = 1;
		for (int d : dice) {
			FOR(i, 0, n) {
				FOR(x, 0, dice.back() * (i + 1) + 1 - d) {
					(dp[i + 1][x + d] += dp[i][x]) %= MOD;
				}
			}
		}
		return dp.back();
	};
	VI Pdp = makeDP(P, pdice);
	VI Cdp = makeDP(C, cdice);
	//FOR(i, 0, pdice.back()*P + 1) {
	//	cout << "Pdp[" << i << "]:=" << Pdp[i] << " ,";
	//}cout << endl;
	//debug(accumulate(ALL(Pdp), 0));
	LL sz = P * pdice.back() + C * cdice.back();
	VL cmtable(sz + 1, 0);
	FOR(i, 0, P*pdice.back() + 1) {
		FOR(j, 0, C*cdice.back() + 1) {
			(cmtable[i + j] += Pdp[i] * Cdp[j]) %= MOD;
		}
	}
	debug(sz);
	VVL T(sz, VL(sz, 0));
	FOR(i, 0, sz - 1)T[i + 1][i] = 1;
	FOR(i, 0, sz)T[0][i] = cmtable[i + 1];
	T = pow(T, N);

	LL ans = 0;
	FOR(i, 0, sz) {
		if (1)cout << i << ", " << T[0][i] << endl;
		(ans += T[0][i]) %= MOD;
	}
	cout << ans << "\n";

	return 0;
}
