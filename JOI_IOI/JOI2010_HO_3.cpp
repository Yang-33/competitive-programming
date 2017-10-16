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

/* -----  2017/10/16  Problem: nagoya_19_11 JOI2010本戦 3 / Link: http://joi2010ho.contest.atcoder.jp/tasks/joi2010ho_c  ----- */
/* ------問題------

つららさんなのだ

カナダに住む JOI 君の家の軒下には，立派なつららが出来ている．せっかくなの
で，JOI 君はつららについて調べてみることにした．
JOI 君の家の軒下には N 本（2 5 N 5 100000 = 105）のつららが出来ている．こ
れらのつららは一直線上に並んでおり，軒下の左端から i cm（1 5 i 5 N）の位置
に i 本目のつららが出来ている．i 本目のつららの長さは最初 ai cm（ai は 1 以上の
整数）である．これらのつららは，次のような規則によって伸びていく：
• i 本目のつららは，i − 1 本目のつららと i + 1 本目のつららの両方よりも長い場
合にのみ，1 時間につき 1 cm ずつ伸びる（ただし，両端のつららに関しては
片方の隣のみ考える．すなわち，1 本目のつららは 2 本目のつららより長けれ
ば伸び，N 本目のつららは N − 1 本目のつららより長ければ伸びる）．
• どのつららも，L cm（2 5 L 5 50000）に達した瞬間に，根元から折れる（折
れたつららは，以後長さ 0 cm のつららとみなす）．
最初の段階で，隣り合う 2 本のつららの長さはすべて異なっている．このとき，十分
な時間が経過すれば，N 本すべてのつららが折れて長さ 0 cm となる．JOI 君は，つ
ららがこのような状態になるまでの時間を知りたくなった．
N 本のつららの最初の長さとつららの限界の長さ L が与えられると，すべてのつ
ららが折れるまでにかかる時間を求めるプログラムを作成せよ．
-----問題ここまで----- */
/* -----解説等-----

高々1回しか各要素の時間を見ないので、再帰的に高いやつから計算していけばよい。
独立した要素もあるのでこれは再帰的にやった方がうれしい。

----解説ここまで---- */

LL N, M;

LL ans = 0LL;

LL dp[100005];

LL f(int t, VL &a) {
	if (dp[t] != -1)return dp[t];

	LL left = M - a[t];
	LL MX = 0;
	
	if (t&&a[t - 1] > a[t])MX = max(MX, f(t - 1, a));
	
	if (t != N - 1 && a[t] < a[t + 1])MX = max(MX, f(t + 1, a));
	
	return dp[t] = left + MX;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	FOR(i, 0, 100005)dp[i] = -1;

	cin >> N >> M;
	VL a(N);
	FOR(i, 0, N)cin >> a[i];
	FOR(i, 0, N)ans = max(ans, f(i, a));

	cout << ans << "\n";

	return 0;
}