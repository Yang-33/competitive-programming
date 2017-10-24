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

/* -----  2017/10/20  Problem: uva 01121  / Link:   ----- */
/* ------問題------

区間和がS以上になる最小の幅

-----問題ここまで----- */
/* -----解説等-----

しゃくとりは尾をひっぱたり頭をひっぱたりどっちもできる！
mainが尾がいどうする
コメントは頭が移動するほう
どうせO(N)なのでどっちも動かさなくていい

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL s;

	while (cin >> N >> s) {
		VI a(N);
		FOR(i, 0, N) {
			cin >> a[i];
		}
		ans = INF;
		LL subsum = 0;
		for (int i = 0, j = 0; i < N; i++) {
			subsum += a[i];
			while (subsum -a[j]>= s&&j+1 <= i) {
				subsum -= a[j]; j++;
			}
			if (subsum >= s)ans = min(ans, (LL)i - j + 1);

		}

		if (ans == INF)ans = 0;
		cout << ans << "\n";
	}

	return 0;
}


/*

while (cin >> N >> s) {
VI a(N);
FOR(i, 0, N) {
cin >> a[i];
}
ans = INF;
LL subsum = 0;
for (int i = 0, j = 0; i < N; i++) {

while (j < N&&subsum < s) {
subsum += a[j]; j++;
}
if (subsum >= s)ans = min(ans, (LL)j - i);
subsum -= a[i];
}

if (ans == INF)ans = 0;
cout << ans << "\n";
}
*/