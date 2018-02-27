#include <bits/stdc++.h>
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

/* -----  2018/02/27  Problem: 060_arc_b / Link: https://arc060.contest.atcoder.jp/tasks/arc060_b?lang=en  ----- */
/* ------問題------

2 以上の整数 b および 1 以上の整数 n に対し、関数 f(b,n) を次のように定義します。

n<b のとき f(b,n)=n
n≥b のとき f(b,n)=f(b, floor(n⁄b))+(n mod b)
ここで、floor(n⁄b) は n⁄b を超えない最大の整数を、 n mod b は n を b で割った余りを表します。

直感的に言えば、f(b,n) は、n を b 進表記したときの各桁の和となります。 例えば、

f(10, 87654)=8+7+6+5+4=30
f(100, 87654)=8+76+54=138
などとなります。

整数 n と s が与えられます。 f(b,n)=s を満たすような 2 以上の整数 b が存在するか判定してください。 さらに、そのような b が存在するならば、その最小値を求めてください。

-----問題ここまで----- */
/* -----解説等-----

全探索だけど最後の方は2進数になりはしょれる

----解説ここまで---- */

LL N;

LL ans = 0LL;


LL f(LL b, LL n) {
	if (n < b)return n;
	else return f(b, n / b) + n % b;
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);


	cin >> N;
	LL s; cin >> s;

	ans = LINF;
	if (N == s)ans = N + 1;

	for (LL i = 2; i*i <= N; i++) {
		LL val = f(i, N);
		if (val == s)
			ans = min(ans, i);
	}

	for (LL i = 1; i*i < N; i++) {
		LL b = (N - s) / i + 1;
		if (b > 1) {
			if (f(b, N) == s) {
				ans = min(ans, b);
			}
		}
	}

	if (ans == LINF)ans = -1;
	cout << ans << "\n";

	return 0;
}
