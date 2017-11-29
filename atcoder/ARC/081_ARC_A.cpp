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

/* -----  2017/11/29  Problem: 081_arc_a / Link: https://arc081.contest.atcoder.jp/tasks/arc081_a  ----- */
/* ------問題------

太さが無視できる棒が N 本あります． i 番目の棒の長さは Ai です．

すぬけ君は，これらの棒から 4 本の異なる棒を選び，それらの棒を辺として長方形（正方形を含む）を作りたいです． 作ることができる最大の長方形の面積を求めてください．

-----問題ここまで----- */
/* -----解説等-----

最大のものが2つ以上あればやっていく

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

	SORT(a);
	int f = 0;
	FORR(i, N - 1, -1+1) {
		if (!f&&a[i] == a[i - 1]) {
			ans = a[i];
			i--; f = 1;
		}
		else if (f==1&&a[i] == a[i - 1]) {
			ans *= a[i];
			f = 2;
		}
	}

	cout << ans << "\n";

	return 0;
}
