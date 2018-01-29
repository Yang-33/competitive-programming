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

/* -----  2018/01/29  Problem: ABC 087 A / Link: http://abc087.contest.atcoder.jp/tasks/abc087_a  ----- */
/* ------問題------

あなたは、X 円を持ってケーキとドーナツを買いに出かけました。
あなたはまずケーキ屋で 1 個 A 円のケーキを 1 個買いました。 次に、ドーナツ屋で 1 個 B 円のドーナツをできるだけたくさん買いました。
これらの買い物のあと手元に残っている金額は何円ですか。

-----問題ここまで----- */
/* -----解説等-----

やる。あるいは left%=B

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int X, A, B;
	cin >> X >> A >> B;
	X -= A;
	while (X - B >= 0) {
		X -= B;
	}
	ans = X;
	cout << ans << "\n";

	return 0;
}
