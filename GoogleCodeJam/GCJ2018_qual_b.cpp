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

/* -----  2018/04/07  Problem: GCJ2018_qual B / Link: __CONTEST_URL__  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

sortがこわれているので、偶奇でsort

----解説ここまで---- */



int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);



	int T; cin >> T;
	FOR(t, 0, T) {
		cout << "Case #" << t + 1 << ": ";

		int N; cin >> N;
		VL a(N);
		FOR(i, 0, N) {
			cin >> a[i];
		}
		VI x,y;
		for (int i = 0; i < N; i += 2) {
			x.push_back(a[i]);
		}
		for (int i = 1; i < N; i += 2) {
			y.push_back(a[i]);
		}
		SORT(x); SORT(y);
		VI c;
		FOR(i, 0, N) {
			if (i % 2 == 0)c.push_back(x[i/2]);
			else c.push_back(y[i/2]);
		}
		int id = -1;
		FOR(i, 0, N - 1) {
			if (c[i] >c[i+1]) {
				id = i;
				break;
			}
		}
		cout << (id == -1 ? "OK" : to_string(id)) << endl;

	}


	return 0;
}
