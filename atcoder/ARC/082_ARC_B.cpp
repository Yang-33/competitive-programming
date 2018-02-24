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

/* -----  2018/02/23  Problem: 082_arc_b / Link: https://arc082.contest.atcoder.jp/tasks/arc082_b?lang=en  ----- */
/* ------問題------

1,2,..,N からなる順列 p1,p2,..,pN が与えられます。 次の操作を何回か (0回でもよい) 行うことが出来ます。
操作: 順列で隣り合う二つの数を選んでスワップする。
何回か操作を行って、任意の 1≤i≤N に対して pi≠i となるようにしたいです。 必要な操作の最小回数を求めてください。

-----問題ここまで----- */
/* -----解説等-----

片側からやっていくと最後の数以外が必ず条件を満たす。
これは順序を入れ替えることで解決可能であるから、そのままチェックをかけるだけで良い。

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

	FOR(i, 0, N-1) {
		if (a[i] == i+1) {
			swap(a[i], a[i + 1]);
			ans++;
		}
	}
	if (a[N - 1] == N)ans++;
	cout << ans << "\n";

	return 0;
}
