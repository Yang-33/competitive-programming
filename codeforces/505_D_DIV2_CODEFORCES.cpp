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

/* -----  2018/08/19  Problem: CodeForces505 D div2 / Link: http://codeforces.com/contest/1025/problem/D  ----- */
/* ------問題------

列Aがある。これを二分木にできるか。ただし辺はgcd>1のみ。

-----問題ここまで----- */
/* -----解説等-----

見るからに区間DP O(N^3)の定数倍が軽いものを書く
回転ができるので、性質を保ったままDPができるとかなり楽そう。
二分木を下るときの区間幅を持ったDPをすると良い。

----解説ここまで---- */

LL N;
int a[702];
bool ok[702][702];
int dp[702][702][2];// state of lt and rt
// [L,P,R] 
int f(int L, int R, int P, bool side) {
	if (dp[L][R][side])return dp[L][R][side] == 1;
	if (L > R)return 1;
	if (L == R)return ok[L][P];
	FOR(nx, L, R + 1) {
		if (P != -1 && !ok[nx][P])continue;
		if (f(L, nx - 1, nx, 0) == 1 && f(nx + 1, R, nx, 1) == 1) {
			return dp[L][R][side] = 1;
		}
	}

	dp[L][R][side] = 2;
	return false;
}

int main() {
	scanf("%lld", &N);
	FOR(i, 0, N) {
		scanf("%d", &a[i]);
	}

	// 組はOKか
	FOR(i, 0, N) {
		FOR(j, i + 1, N) {
			ok[j][i] = ok[i][j] = (__gcd(a[i], a[j]) > 1);
		}
	}



	// 何を根にするか
	int ok = f(0, N - 1, -1, 0);


	if (ok)cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}