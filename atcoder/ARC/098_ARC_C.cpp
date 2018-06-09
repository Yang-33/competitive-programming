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


// 一個決め打つとあとは分割列から選択できるだけ選択する感じになるので、解ける

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, K, Q; cin >> N >> K >> Q;
	VL a(N);
	FOR(i, 0, N) {
		cin >> a[i];
	}
	LL ans = LINF;

	a.push_back(-LINF);
	FOR(_, 0, N) {
		int Minbar = a[_];
		int cnt = 0;
		VL c;
		FOR(i, 0, N + 1) {// split a to b ->c
			if (Minbar > a[i]) {// s
				if (i - cnt >= K) {
					VL x;
					FOR(k, cnt, i) {
						x.push_back(a[k]);
					}
					SORT(x);
					FOR(k, 0, i - cnt + 1 - K) {
						c.push_back(x[k]);
					}
				}
				cnt = i + 1;

			}


		}
		if (SZ(c) >= Q) {
			SORT(c);
			ans = min(ans, c[Q - 1] - c[0]);
		}
	}



	cout << ans << endl;

	return 0;
}
