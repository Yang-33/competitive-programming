#include <bits/stdc++.h>
using namespace std;

using VS = vector<string>;    using LL = long long;
using VI = vector<int>;       using VVI = vector<VI>;
using PII = pair<int, int>;   using PLL = pair<LL, LL>;
using VL = vector<LL>;        using VVL = vector<VL>;

#define ALL(a)  begin((a)),end((a))
#define RALL(a) (a).rbegin(), (a).rend()
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

/* -----  2018/06/30  Problem: AOJ 1232 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/1232  ----- */
/* ------問題------

いま素数p,qを選んで、pq<=mをみたす最大の組を選択したい。
ただし1>=p/q>=a/b

-----問題ここまで----- */
/* -----解説等-----

素数を前に列挙してやる。
順序を逆にするとTLEした。

----解説ここまで---- */


bool pr[100010];
int a[100000];
void solve() {
	int M, A, B;
	// Mまでの素数で^2すればよい

	FOR(i, 0, 100010) {
		pr[i] = 1;
	}
	pr[0] = pr[1] = 0;
	int cnt = 0;
	FOR(i, 2, 100001) {
		if (pr[i]) {
			a[cnt++] = i;
			for (int j = i * 2; j <= 100001; j += i) {
				pr[j] = 0;
			}
		}
	}
	while (cin >> M >> A >> B, M) {
		long long area = 0;
		int ap = 0, aq = 0;
		FOR(j, 0, cnt) {
			int Q = a[j];
			FOR(i, 0, j + 1) {
				int P = a[i];
				if (A*Q <= P * B) {
					if (area <= P * Q&&P*Q <= M) {
						area = P * Q;
						ap = P;
						aq = Q;
					}
				}
				if (P*Q > M)break;
			}
		}

		cout << ap << " " << aq << endl;
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	solve();

	return 0;
}