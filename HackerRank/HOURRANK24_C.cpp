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

/* -----  2017/11/02  Problem: hourrank24 C / Link: https://www.hackerrank.com/contests/hourrank-24/challenges/mutual-indivisibility  ----- */
/* ------問題------

互いに素な[L,R]にx個の要素を構成できればこれを出力し、作成不可能なら-1を出力せよ。

-----問題ここまで----- */
/* -----解説等-----

上から貪欲にとっていけばいいので、あとは倍数判定を行えばよい。

----解説ここまで---- */

VI solve(int a, int b, int x) {
	bool ok[10004];
	fill(ok, ok + 10004, 1);
	VI res;
	FORR(i, b, a - 1) {
		if (ok[i]) {
			res.push_back(i);
			for (int j = 1; j*j <= i; j++) {
				if (i%j == 0) {
					ok[j] = 0;
					ok[i / j] = 0;
				}
			}
		}
	}
	return res;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N; cin >> N;
	FOR(i, 0, N) {
		int a, b, x;
		cin >> a >> b >> x;
		VI v = solve(a, b, x);
		if (SZ(v) >= x) {
			FOR(j, 0, x)cout << v[j] << " ";
			cout << endl;
		}
		else cout << -1 << "\n";
	}

	return 0;
}
