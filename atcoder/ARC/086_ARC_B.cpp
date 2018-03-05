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

/* -----  2018/03/05  Problem: 086_arc_b / Link: https://arc086.contest.atcoder.jp/tasks/arc086_b?lang=en  ----- */
/* ------問題------

すぬけ君は長さ N の数列 a を持っています。a の (1-indexedでの) i 番目の数は ai です。
すぬけ君は以下の操作を何度でも行うことができます。
操作：1 以上 N 以下の整数 x,y を選び、ay に ax を加算する。
すぬけ君はこの操作を 0 回以上 2N 回以下行って a が下記の条件を満たすようにしたいです。そのような操作手順の一例を示してください。 なお、この問題の制約下で、条件を満たすような操作の手順が必ず存在することが証明できます。

条件：a1≤a2≤…≤aN

-----問題ここまで----- */
/* -----解説等-----

N-1回で符号を全部おなじになるように整地する。
その後N-1回で累積和を取れば良い

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	VL a(N);
	FOR(i, 0, N) {
		cin >> a[i];
	}
	LL Min = LINF;
	LL Max = -LINF;
	FOR(i, 0, N) {
		Min = min(Min, a[i]);
		Max = max(Max, a[i]);
	}
	cout << 2 * N - 1 << endl;
	if (abs(Max) > abs(Min)) {
		int pos; // 全部正
		FOR(i, 0, N) {
			if (Max == a[i])pos = i;
		}
		FOR(i, 0, N) {
			cout << pos + 1 << " " << i + 1 << endl;
		}
		FOR(i, 0, N - 1) {
			cout << i + 1 << " " << i + 2 << endl;
		}
	}
	else { //全部負
		int pos;
		FOR(i, 0, N) {
			if (Min == a[i])pos = i;
		}
		FOR(i, 0, N) {
			cout << pos + 1 << " " << i + 1 << endl;
		}
		FORR(i, N - 2, 0 - 1) {
			cout << i + 2 << " " << i + 1 << endl;
		}
	}

	return 0;
}
