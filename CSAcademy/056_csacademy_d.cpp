#include "bits/stdc++.h"
#include <unordered_map>
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

/* -----  2017/11/08  Problem: 056_csacademy D / Link: __CONTEST_URL__  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

マージすればよくないですか？よいですね
というわけでノードを順次持ち上げていき、重なったらuniqすればよい。
計算量はNlog(Maxval)となり間に合ってくれる。
最初は二分木で頂点作成をしたけどメモリ制約がとてもきびしくてつらかった

----解説ここまで---- */


//
//LL N;
//unordered_map<LL, bool>dat;
//LL ans = 0LL;
//void add(LL k) {
//	if (dat[k] == 1)return ;
//	dat[k] = 1;
//	while (k) { // 根まで再帰的に上る
//		k = (k - 1) / 2;
//		if (dat[k] == 1)break;
//		else dat[k] = 1;
//	}
//}
int main() {


	int N; scanf("%d", &N);
	VL a(N);
	FOR(i, 0, N)
		cin >> a[i];

	SORT(a);

	LL ans = 0;

	queue<LL>tempnode;
	while (a.size()||tempnode.size()) {
		LL mx = LLONG_MAX;
		if (tempnode.size()) {
			mx = tempnode.front();
		}
		else {
			mx = a.back();
		}
		if (a.size()) {
			mx = max(mx, a.back());
		}
		ans += 1;
		if (mx > 1) {
			tempnode.push(mx / 2);
		}

		while (tempnode.size() && tempnode.front() == mx) {
			tempnode.pop();
		}
		while (a.size() && a.back() == mx) {
			a.pop_back();
		}
	}


	printf("%lld\n", ans-1);

	return 0;
}
