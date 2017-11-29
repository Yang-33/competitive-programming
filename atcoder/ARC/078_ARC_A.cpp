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

/* -----  2017/11/29  Problem: 078_arc_a / Link: https://arc078.contest.atcoder.jp/tasks/arc078_a ----- */
/* ------問題------

すぬけくんとアライグマは N 枚のカードの山を作りました。カードの山の上から i 番目のカードには整数 ai が書かれています。
N 枚のカードを分け合うことにしました。 すぬけくんがカードの山の上から何枚かのカードを取ったあと、アライグマは残ったカード全てを取ります。 このとき、すぬけくんもアライグマも 1 枚以上のカードを取る必要があります。
すぬけくんとアライグマが持っているカードに書かれた数の総和をそれぞれ x,y として、|x−y| を最小化したいです。 |x−y| としてありうる値の最小値を求めなさい。

-----問題ここまで----- */
/* -----解説等-----

0~iまでの総和が分かっていれば、その差分で好きな区間の値が引き算で分かるため、
さきに累積和をもっておけばよい。

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	VL a(N, 0);
	VL cum(N + 1, 0);
	FOR(i, 0, N) {
		cin >> a[i];
		cum[i + 1] = cum[i] + a[i];
	}

	ans = numeric_limits<long long>::max();
	FOR(i, 1, N) {
		ans = min(ans, abs(cum[i] - (cum[N] - cum[i])));
	}

	cout << ans << "\n";

	return 0;
}
