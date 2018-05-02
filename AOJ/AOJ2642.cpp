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

/* -----  2018/05/02  Problem: AOJ 2642 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2642  ----- */
/* ------問題------

日本語なので略

-----問題ここまで----- */
/* -----解説等-----

明らかにDPとかができない

選択用の比較関数が事前にわからないとむりなので、考える
k回自炊をしていて、i日目に自炊をするとする。

増分は、-C[i] + (Q-2*k-i)*P
このままではO(N^2)っぽいけど、意味論的にはk回自炊をするときの評価となるので、
累積を考えることになる。
あるkのときiを選択できるようになるので、初期値を考えるとO(N)

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	LL P, Q;
	cin >> N >> P >> Q;
	VL c(N);
	VL comp(N);
	FOR(i, 0, N) {
		cin >> c[i];
		comp[i] = c[i] + i*P;
	}
	SORT(comp);
	LL sum = accumulate(ALL(c), 0LL);
	LL val = 0;
	ans = sum;
	FOR(i, 1, N + 1) {
		val += comp[i - 1];
		LL ret = sum + i*P*Q + P*i*(i - 1) - val;
		ans = max(ans, ret);
	}
	cout << ans << "\n";

	return 0;
}
