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

/* -----  2018/01/21  Problem: ARC 089 A / Link: http://arc089.contest.atcoder.jp/tasks/arc089_a  ----- */
/* ------問題------

シカのAtCoDeerくんは二次元平面上で旅行をしようとしています。 
AtCoDeerくんの旅行プランでは、時刻 0 に 点 (0,0) を出発し、 1 以上 N 以下の各 i に対し、時刻 ti に 点 (xi,yi) を訪れる予定です。

AtCoDeerくんが時刻 t に 点 (x,y) にいる時、 時刻 t+1 には 点 (x+1,y), (x−1,y), (x,y+1), (x,y−1) のうちいずれかに存在することができます。
その場にとどまることは出来ないことに注意してください。 AtCoDeerくんの旅行プランが実行可能かどうか判定してください。


-----問題ここまで----- */
/* -----解説等-----

二部グラフ的な感じなので、到達可能性は時刻と座標、時刻と前回からの移動距離でわかる。

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	VI t(N), x(N), y(N);
	VL p(N);
	int f = 1;
	FOR(i, 0, N) {
		cin >> t[i] >> x[i] >> y[i];
		LL sum = x[i] + y[i];
		if (sum % 2 != t[i] % 2) {
			f = 0;
		}
		p[i] = sum;
		if (i) {
			LL sa = t[i] - t[i - 1];
			if (sa < p[i] - p[i - 1]) {
				f = 0;
			}
		}
		else {
			if (t[i] < sum)f = 0;
		}

	}
	if (f) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}

	return 0;
}

