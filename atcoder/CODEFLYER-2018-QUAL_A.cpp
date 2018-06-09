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

/* -----  2018/06/02  Problem: codeflyer-2018-qual A / Link: __CONTEST_URL__  ----- */
/* ------問題------

あなたは予選・本選の二部からなるプログラミングコンテストの開催を計画しています。 そのために、何人を本選に参加させるかを決めなければなりません。

本選参加者数は次の 2 つの条件を満たす必要があります。

会場の大きさの都合上、参加者数は A 以下でなければならない。
懇親会で B 人がけのテーブルに座ってもらうため、参加者数は B の倍数でなければならない。
あなたはできるだけ多くの人に本選に参加してもらいたいと考えています。 上の 2 条件を満たす本選参加者数であって最大のものを求めてください。

-----問題ここまで----- */
/* -----解説等-----

お熱ですぎで全然問題文読めなかった
サンプルからエスパーする

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int A, B;
	cin >> A>>B;
	FOR(i, 0, A + 1) {
		if (i%B==0) {
			ans = i;
		}
	}
	cout << ans << "\n";

	return 0;
}
