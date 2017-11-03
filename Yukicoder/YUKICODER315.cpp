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

/* -----  2017/11/02  Problem: yukicoder260 / Link: https://yukicoder.me/problems/no/315  ----- */
/* ------問題------

ある芸人のモノマネをする芸人が現れました。
彼は「3の倍数 もしくは 3のつく数」のとき「アホ」になり、「Pの倍数(Pは 8, 80, 800 のいずれか)」のとき「恥じらい」を見せます。
A 以上 B 以下の整数のうち、「アホ」になりかつ「恥じらい」を見せない数がいくつあるかを 10^9+7 で割った時の余りで求めてください。

-----問題ここまで----- */
/* -----解説等-----

適当な桁DPを考えると、dp[200005][3][2][2][800]とかになり、かなり厳しい思いになる。
そこで8*の倍数の判定を考える。
8,80,800の倍数判定を考えると、これらは下3,4,5桁が8の倍数であればいいことになる。
したがって、桁DPをしていくにあたって、下x桁になったときだけにメモリを増やしてあげればよい。

あとは場合分けをしていつものをかけばよい。初期化も必要ない。

----解説ここまで---- */

LL N;

LL ans = 0LL;
vector<LL> dp[200005][3][2][2];
int Eight;
map<int, int>eightmap = { { 8,3 },{ 80,4 },{ 800,5 } };
map<int, int>eightmemory = { {8,8},{80,80}, {800,800} };
LL f(string &target, int i, int three = 0, int has = 0, int eights = 0, int less = 0) {
	if (i == -1) {
		return ((three == 0 || has == 1) && eights%Eight != 0);
	}
	if (dp[i][three][has][less].empty()) {
		if (i + 1 > eightmap[Eight])dp[i][three][has][less].resize(1, -1);
		else dp[i][three][has][less].resize(eightmemory[Eight], -1);
	}
	if (i + 1 > eightmap[Eight]) {
		if (dp[i][three][has][less][0] != -1 && less == 1)return dp[i][three][has][less][0];
	}
	else {
		if (dp[i][three][has][less][eights] != -1 && less == 1)return dp[i][three][has][less][eights];
	}
	LL res = 0;
	int num = target[i] - '0';
	int Max = less ? 9 : num;
	FOR(nx, 0, Max + 1) {
		res += f(target, i - 1, (three + nx) % 3, has || nx == 3, (eights * 10 + nx) % Eight, less || (nx < Max)) % MOD;
		res %= MOD;
	}
	if (i + 1 > eightmap[Eight]) {
		if (less == 1)return dp[i][three][has][less][0] = res;
	}
	else if (less == 1)return dp[i][three][has][less][eights] = res;
	return res;
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string A, B; cin >> A >> B >> Eight;
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
	ans = f(B, SZ(B) - 1);
	//debug(ans);
	if (A != "0")ans -= f(A, SZ(A) - 1);

	cout << (ans + MOD) % MOD << "\n";

	return 0;
}
