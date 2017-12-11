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

/* -----  2017/12/11  Problem: AOJ 2163 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2163  ----- */
/* ------問題------

畳を敷き詰めたい。
このとき、交点において十字にならないようにしきつめたい。
H*Wの領域をしきつめて配置する場合、何通りあるか。

-----問題ここまで----- */
/* -----解説等-----

諦めて全列挙をしようとするとこれは強枝刈りになっているらしく、通る
なんかmaxでも400にしかならないっぽい、不思議だ

----解説ここまで---- */

LL ans;
LL H, W;
int masu[20][20];

bool have_same(int y, int x) {
	int b = masu[y][x - 1];
	int u = masu[y - 1][x];	int l = masu[y - 1][x - 1];
	return(b == u || b == l || u == l);
}

void f(int val, int y, int x) {
	if (y == H) {
		ans++; return;
	}
	else if (x == W) {
		f(val, y + 1, 0);
		return;
	}
	else if (masu[y][x] != -1) {
		f(val, y, x + 1);
		return;
	}
	else if (masu[y][x] == -1) {

		if (y + 1 < H && masu[y + 1][x] == -1) { //下に詰める
			masu[y][x] = val;
			masu[y + 1][x] = val;

			if (y > 0 && x > 0) {//上をチェックできるとき
				if (have_same(y, x)) f(val + 1, y, x + 1);
			}
			else f(val + 1, y, x + 1);

			masu[y][x] = -1;
			masu[y + 1][x] = -1;
		}

		if (x + 1 < W && masu[y][x + 1] == -1) { //右に詰める
			masu[y][x] = val;
			masu[y][x + 1] = val;

			if (y > 0 && x > 0) {//上をチェックできるとき
				if (have_same(y, x)) f(val + 1, y, x + 1);
			}
			else f(val + 1, y, x + 1);

			masu[y][x] = -1;
			masu[y][x + 1] = -1;
		}

	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);


	while (cin >> H >> W, H || W) {
		ans = 0;
		fill(*masu, *masu + 20 * 20, -1);

		f(0, 0, 0);

		cout << ans << endl;
	}
	return 0;
}