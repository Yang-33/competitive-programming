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

/* -----  2017/11/29  Problem: 080_arc_b / Link: https://arc080.contest.atcoder.jp/tasks/arc080_b ----- */
/* ------問題------

縦 H 行、横 W 列のマス目があります。 すぬけ君は、このマス目を色 1, 2, …, N で塗り分けようとしています。 このとき、次の条件が成り立つようにします。
各 i (1≤i≤N) について、色 i のマスはちょうど ai 個存在する。 ただし、a1+a2+…+aN=HW である。
各 i (1≤i≤N) について、色 i のマスは上下左右に連結である。 すなわち、どの色 i のマスからどの色 i のマスへも、上下左右に隣り合う色 i のマスのみを辿って行き来できる。
条件を満たす塗り分け方をひとつ求めてください。 解は必ず存在することが示せます。

-----問題ここまで----- */
/* -----解説等-----

問題から、連結になるように塗ればいいので、上から順に一筆書きで塗ればいいことが分かる。
これを実装する。

----解説ここまで---- */

LL H, W, N;
inline void next(int &y, int &x) {
	if (y % 2 == 0) {
		if (x == W - 1) { y++; }
		else { x++; }
	}
	else { // % 2 ==1
		if (x == 0) { y++; }
		else { x--; }
	}
}

void go(VVI &masu, VI &a) {
	int y = 0, x = 0, id = 0;
	FOR(i, 0, H) {
		FOR(j, 0, W) {
			while (a[id] == 0)id++;
			masu[y][x] = id + 1;
			a[id]--;
			next(y, x);
		}
	}
}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> H >> W >> N;
	VI a(N);
	FOR(i, 0, N) {
		cin >> a[i];
	}
	VVI masu(H, VI(W, 0));

	go(masu, a);

	FOR(i, 0, H) {
		FOR(j, 0, W) {
			cout << masu[i][j] << (j != W - 1 ? ' ' : '\n');
		}
	}

	return 0;
}
