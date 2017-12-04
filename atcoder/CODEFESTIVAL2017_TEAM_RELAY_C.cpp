#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
#include <cmath>

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

/* -----  2017/12/04  Problem: codefestival2017_team_relay C / Link: https://cf17-relay-open.contest.atcoder.jp/tasks/relay2_c  ----- */
/* ------問題------

あなたの家の庭には、東に果てしなく伸びる細長い花壇があります。あなたは、何も植えられていないこの花壇に N 種類の花を植えることにしました。便宜上、これらの花の種類を花 1, 2, …, N と呼びます。また、花壇の西端から p センチメートルの位置を位置 p と呼びます。
花 i (1≤i≤N) は、位置 wi に一つ植え、そこから di センチメートルおきに一つずつ、東へと無数に植えていくことにします。 すなわち、花 i は位置 wi, wi+di, wi+2di, … に植えられることになります。 複数の花が同じ位置に植えられることもありえます。
西から K 番目に植えられる花の位置を求めてください。なお、同じ位置に複数の花が植えられる場合、それらは個別に数えます。

-----問題ここまで----- */
/* -----解説等-----

愚直にやると間に合わないので、ある値X以下の花の数は、Xの値に対して単調増加なので、
二分探索ができる。

----解説ここまで---- */

LL N, K;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> K;
	VL w(N, 0), d(N, 0);
	FOR(i, 0, N) {
		cin >> w[i] >> d[i];
	}
	LL L = 0; LL R = LLONG_MAX;//  座標
	FOR(kim, 0, 70) {
		LL ret = 0;

		LL mid = (L + R) / 2LL;
		FOR(i, 0, N) {
			LL p = (mid - w[i]) / d[i];
			if (p > 0)ret += p;
			if (mid >= w[i])ret++;
			if (ret > K)break;
		}
		if (ret >= K) { R = mid; }
		else L = mid;
	}

	ans = R;
	cout << ans << "\n";

	return 0;
}
