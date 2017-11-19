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

/* -----  2017/11/19  Problem: ttpc2015_f / Link: __CONTEST_URL__  ----- */
/* ------問題------

太郎君はA円の買い物をした。 太郎君はX≥Aを満たす任意のX円を支払うことができる。 買い物の金額A、支払額X、お釣り(X−A)の3つの整数について10進数表記にしたとき、3つの数字が揃う桁の数を最大にしたい。
例えば、A=1980,X=2970の時、百の位の9と一の位の0の2箇所が揃う。
A = 1980
X = 2970
X-A =  990
また、A=1080,X=1080の時、一の位のみが揃う。十の位から千の位については、X−Aがその桁に数字がないため揃っていないものとする。
A = 1080
X = 1080
X-A =    0
Aが与えられるので、太郎君が揃えられる桁の数の最大値を求めよ。

-----問題ここまで----- */
/* -----解説等-----

0,9のときしか一致する条件はない。
が、桁DPで殴れる。
dp(i,carry):=上からi番目の桁を見ているときに、i+1番目の桁から桁下げを要求されているか
としてこれに最大値をもたせればよい。
判定は nx == num と、nxが桁下げされるかされないかで一致をみて条件を満たす、すなわち3つの数字が一致するときのみans++
とすればよい。

----解説ここまで---- */

LL N;
LL dp[102][2];
LL ans = 0LL;

LL f(string &s, int i, int cr = 0) {
	if (i == -1)return 0;
	if (dp[i][cr] != -1)return dp[i][cr];
	LL res = 0;

	int num = s[i] - '0';
	FORR(nx, 9, 0 - 1) {
		int c = 0;
		if (nx == num && ((10 + nx - cr - num) % 10 == num))c++;

		res = max(res, f(s, i - 1, nx-cr < num) + c);
	}


	return dp[i][cr] = res;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	fill(*dp, *dp + 102 * 2, -1);
	string s; cin >> s;
	ans = f(s, SZ(s));
	cout << ans << "\n";

	return 0;
}
