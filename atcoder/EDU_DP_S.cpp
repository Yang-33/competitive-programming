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

/* -----  2017/10/31  Problem: ketadp2 / Link: http://tdpc.contest.atcoder.jp/tasks/tdpc_number  ----- */
/* ------問題------

N 以下の正整数であって、十進法表記したときの各桁の数の和が D の倍数であるものの個数を mod 1,000,000,007 で求めよ。

-----問題ここまで----- */
/* -----解説等-----

dp[今i番目の数を見ている][mod D][target未満が確定しているか？->1]:=総数
として桁DP

----解説ここまで---- */


LL ans = 0LL;
LL dp[10004][102][2];
int D;
LL f(string &target, int i, int d = 0, int less = 0) {
	if (i == -1) {
		if (d%D == 0)return 1;
		else return 0;
	}

	if (dp[i][d][less] != -1 && less == 1)return dp[i][d][less];
	LL res = 0;
	int num = target[i] - '0';
	int Max = less ? 9 : num;
	FOR(nx, 0, Max + 1) {
		res += f(target, i - 1, (d + nx) % D, less || (nx<Max)) % MOD;
	}
	if (less == 1)
		return  (dp[i][d][less] = (res%MOD));
	return res;
}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string N;
	cin >> N>>D;
	fill(**dp, **dp + 10004 * 102 * 2, -1);
	reverse(ALL(N));
	ans = f(N, SZ(N) - 1);
	ans--;
	//debug(ans);

	cout << (ans + MOD) % MOD << "\n";

	return 0;
}
