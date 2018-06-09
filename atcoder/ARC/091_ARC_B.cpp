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

/* -----  2018/03/11  Problem: ARC 091 B / Link: http://arc091.contest.atcoder.jp/tasks/arc091_b  ----- */
/* ------問題------

高橋君は、N 以下の正の整数の 2 つ組 (a,b) を持っていましたが、忘れてしまいました。 高橋君は、a を b で割ったあまりが K 以上であったことを覚えています。 高橋君が持っていた組としてあるうるものの個数を求めてください。

-----問題ここまで----- */
/* -----解説等-----

解けませんでした(は？)(おいコラァ！)
bを固定してみたとき、aの数列は 0,1,2,3,4,...,b-1,0,1,2,3,4,...となっているので、
bの倍数で考えられるので適当にこれは求まる。
最後のあまりの部分も適当に求められる。

----解説ここまで---- */

LL N, K;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> K;
	if (K == 0) {
		cout << N*N << endl;
		return 0;
	}


	//FOR(i, 1, N + 1) {
	//	FOR(j, 1, N + 1) {
	//		cout << i%j << '\t';
	//	}cout << endl;
	//}
	FOR(b, K + 1, N + 1) {//
		LL ret = 0;
		ret += (b - K)*(N / b);
		ret += max(0LL, N%b - K + 1);
		ans += ret;
	}
	cout << ans << "\n";

	return 0;
}
