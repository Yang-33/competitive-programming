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

/* -----  2018/08/23  Problem: yukicoder 221  / Link: http://yukicoder.me/problems/no/221  ----- */
/* ------問題------

Y市にはマフィアの構成員が多く住み、犯罪の温床となっている。
そこで、Y市はマフィア判定器を導入し、構成員と判定された者を
すべて逮捕することにした。
マフィア判定器とは、対象者が
一般市民か構成員か99％の精度で判定できる機器である。

Y市の全人口1,000,000をすべてに、
マフィア判定器で判定して「構成員」と判定された者を逮捕する。

しかし、実はY市には10,000人あたりN人しか構成員がいないということがわかった。
このとき、逮捕者が出た時、誤認逮捕である確率を求めよ。

答えの誤差は、絶対誤差、相対誤差±0.01まで許容される。

-----問題ここまで----- */
/* -----解説等-----

正しい判定をする確率をP,犯罪者である確率をQとする。
逮捕される確率は Q*P+ (1-Q)*(1-P)で、誤認逮捕される確率は (1-Q)*(1-P) なのでこれを出力すれば良い。

----解説ここまで---- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N; cin >> N;
	double trueJudge = 0.99;
	double criminalRate = N / 10000.0;
	double ans = (1 - criminalRate)*(1 - trueJudge) / (trueJudge*criminalRate + (1-trueJudge)*(1-criminalRate));
	cout <<fixed<<setprecision(10)<< ans*100 << "\n";

	return 0;
}
