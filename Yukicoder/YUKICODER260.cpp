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

/* -----  2017/11/02  Problem: yukicoder260 / Link: https://yukicoder.me/problems/no/260  ----- */
/* ------問題------

ある芸人は「3の倍数 もしくは 3のつく数」の時「アホ」になり、「8の倍数」の時「青春」するという。
A 以上 B 以下の整数のうち、「アホ」になりかつ「青春」しない数がいくつあるかを 109+7で割った時の余りで求めてください。

-----問題ここまで----- */
/* -----解説等-----

桁DP
dp[今i番目を見ている][3の倍数か][3が含まれるか][8の倍数か][less?]:=総数
慣れた

----解説ここまで---- */

LL N;

LL ans = 0LL;
LL dp[10004][3][2][8][2];
LL f(string &target, int i, int three = 0, int has = 0, int eight = 0, int less = 0) {
	if (i == -1) {
		return ((three == 0 || has == 1) && eight != 0);
	}
	if (dp[i][three][has][eight][less] != -1 && less == 1)return dp[i][three][has][eight][less];
	LL res = 0;
	int num = target[i] - '0';
	int Max = less ? 9 : num;
	FOR(nx, 0, Max + 1) {
		res += f(target, i - 1,(three+nx)%3,has||nx==3,(eight*10+nx)%8,less||(nx<Max))%MOD;
		res %= MOD;
	}
	if (less == 1)return (dp[i][three][has][eight][less] = res);
	return res;
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string A, B; cin >> A >> B;
	int i = SZ(A) - 1;
	while (i >= 0) {
		if (A[i] == '0') {
			A[i] = '9';
		}
		else {
			A[i]--;
			break;
		}
		i--;
	}
	if (A[0] == '0')A = A.substr(1);
	reverse(ALL(A));
	reverse(ALL(B));
	fill(****dp, ****dp + 10004 * 3 * 2 * 8 * 2, -1);
	ans = f(B, SZ(B) - 1);
	if(A!="0")ans -= f(A, SZ(A) - 1);

	cout << (ans+MOD)%MOD << "\n";

	return 0;
}
