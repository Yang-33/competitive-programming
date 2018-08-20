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

/* -----  2018/07/30  Problem: yukicoder 183  / Link: http://yukicoder.me/problems/no/183  ----- */
/* ------問題------

kamipeipaa君は頭が悪いので勉強を始めました。今kamipeipaa君が解いている問題は以下のような問題です。

N個のスイッチを発見した。i番目のスイッチにはAiという整数が書かれている。あなたはi番目のスイッチを押すことで、ある整数Xに対して
X=X⊕Ai
という操作を行うことができる。ただし⊕とはビットXORの記号である(参考)。
一度押したスイッチは二度と使用することはできない。
Xははじめ0である。
あなたが作ることができる整数は何種類あるか。

kamipeipaa君と一緒にあなたも解いてあげてください。

-----問題ここまで----- */
/* -----解説等-----

解法1:dp

解法2:mod2で方程式のrankをとる

----解説ここまで---- */

void solve1() {
	int N; cin >> N;
	VI dp(1 << 15, 0);
	dp[0] = 1;
	FOR(i, 0, N) {
		int a; cin >> a;
		VI Nx = dp;
		FOR(j, 0, 1 << 15) {
			Nx[j^a] |= dp[j];
		}
		dp.swap(Nx);
	}
	LL ans = accumulate(ALL(dp), 0LL);
	cout << ans << "\n";
}


typedef unsigned long long Val;
vector<Val> gaussianEliminationMod2(vector<Val> v, int B) {// B:= digit
	int n = v.size();
	vector<Val> t(B, 0);
	int used = 0;
	for (int j = B - 1; j >= 0; j--) {
		int i = used;
		while (i < n && (~v[i] >> j & 1)) i++;
		if (i < n) {
			Val x = v[i];
			swap(v[i], v[used++]);
			t[j] = x;
			for (i = used; i < n; i++)
				if (v[i] >> j & 1)
					v[i] ^= x;
		}
	}
	return t;
}

void solve2() {
	int N; cin >> N;
	vector<Val> a(N);
	FOR(i, 0, N) {
		cin >> a[i];
	}
	auto vec = gaussianEliminationMod2(a, 62);

	int zeros = count(ALL(vec), 0);
	LL ans = 1LL << (SZ(vec)- zeros);
	cout << ans << endl;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);


	// solve1();
	solve2();

	return 0;
}
