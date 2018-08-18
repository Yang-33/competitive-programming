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
const LL MOD = 998244353;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/08/18  Problem: edu049 E / Link: __CONTEST_URL__  ----- */
/* ------問題------

k枚以上で構成される同色のみで構成された長方形が存在してはいけない

-----問題ここまで----- */
/* -----解説等-----

// dp[i][j]:=size iの正方形に、最大j個の大きさで連続している長方形がある
置くことのできるマスは確定してしまうので右上の核をけっていして並べればよく、これはxorっぽく並べていけば良い。

----解説ここまで---- */


LL dp[502][502];
inline LL add(LL a, LL b) { a += b; if (a >= MOD)a -= MOD; return a; }
inline LL mul(LL a, LL b) { a *= b;  if (a >= MOD)a %= MOD; return a; }

int main() {

	dp[0][0] = 1;

	FOR(i, 0, 501)FOR(j, 0, 501)FOR(k, 1, 502 - i) {
		dp[i + k][max(j, k)] = add(dp[i + k][max(j, k)], dp[i][j]);
	}
	// dp[i][j]:=size iの正方形に、最大j個の大きさで連続している長方形がある

	int N, K;
	scanf("%d%d", &N, &K);
	LL ans = 0;
	FOR(i, 1, N + 1) {
		FOR(j, 1, N + 1) {
			if (i*j < K)
				ans = add(ans, mul(dp[N][i], dp[N][j]));
		}
	}


	cout << mul(ans, 2) << endl;


	return 0;
}
