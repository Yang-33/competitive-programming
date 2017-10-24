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

/* -----  2017/10/24  Problem: AOJ_DSL_3_B  / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_B&lang=jp  ----- */
/* ------問題------

The Smallest Window II
長さN の数列a1,a2,a3,...,aN と整数K が与えられます。
1 からK までの整数 1, 2, ...,K をすべて含む連続する部分列のうち、最も短いものの長さ（smallest window length）を求めてください。
ただし、そのような部分列が存在しない場合は 0 と報告してください。

-----問題ここまで----- */
/* -----解説等-----

しゃくとりをする。頭を進めて条件を満たしている間は削減する感じでよい。

----解説ここまで---- */

LL N, K;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> K;
	VL a(N);
	FOR(i, 0, N) {
		cin >> a[i];
	}

	ans = INF;
	VI cnt(100005, 0);
	int k = 0;
	for (int i = 0, j = 0; i < N; i++) {
		if (a[i] <= K) {
			cnt[a[i]]++;
			if (cnt[a[i]] == 1)k++;
		}
		while (k == K&&j <= i) {
			ans = min(ans, (LL)i - j + 1);
			if (a[j] <= K) {
				cnt[a[j]]--;
				if (cnt[a[j]] == 0)k--;
			}
			j++;
		}
	}
	if (ans > N)ans = 0;
	cout << ans << "\n";

	return 0;
}