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

/* -----  2018/08/27  Problem: yukicoder 260  / Link: http://yukicoder.me/problems/no/260  ----- */
/* ------問題------

ある芸人は「3の倍数 もしくは 3のつく数」の時「アホ」になり、「8の倍数」の時「青春」するという。
A 以上 B 以下の整数のうち、「アホ」になりかつ「青春」しない数がいくつあるかを 109+7 で割った時の余りで求めてください。

-----問題ここまで----- */
/* -----解説等-----

桁DPで解く。
dp[今rev(i)番目を見ている][3が含まれるか][8の倍数か][3の倍数か][less?]:=総数
いつものとして、lessは必要ない
引き算なあ　ああ引き算

今回はf(0)は0なのでf(B)-f(A-1)してよい。
for文でdpする人キチガイっぽそう どういう脳してるねん…

----解説ここまで---- */

LL dp[10004][3][8][2];
LL f(const string& s, int idx, int three=0, int eight=0, bool has=0, bool less=0) {
	if (idx == -1) {
		return (three == 0 || has) && (eight);
	}
	if (less && dp[idx][three][eight][has]!= -1 )return dp[idx][three][eight][has];
	int Max = less ? 9 : s[idx] - '0';
	LL ret = 0;
	FOR(nx, 0, Max + 1) {
		ret += f(s, idx - 1, (three+ nx) % 3, (eight * 10 + nx) % 8, has || nx == 3, less || (nx < Max));
		ret %= MOD;
	}
	if(less)return dp[idx][three][eight][has] = ret;
	else return ret;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);


	string A, B; cin >> A >> B;
	// f(B) - f(A-1)
	fill(***dp, ***dp + 10004 * 3 * 8 * 2, -1);
	// A = A-1
	FORR(i, SZ(A) - 1, 0 - 1) {
		if (A[i] != '0') {
			A[i]--;
			break;
		}
		else {
			A[i] = '9';
		}
	}
	if (A[0] == '0')A = A.substr(1);
	reverse(ALL(B)), reverse(ALL(A));
	LL ans = f(B, SZ(B) - 1);
	LL ret = f(A, SZ(A) - 1);
	ans -= ret;
	if (ans < 0)ans += MOD;
	cout << ans << "\n";

	return 0;
}
