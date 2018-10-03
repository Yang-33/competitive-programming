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

/* -----  2018/10/03  Problem: ARC 041 B / Link: http://arc041.contest.atcoder.jp/tasks/arc041_b  ----- */
/* ------問題------

縦 N マス、横 M マスの盤面がある。 上から i (1≦i≦N) マス目、左から j (1≦j≦M) マス目の位置を (i,j) と表す。
はじめ、マス (i,j) には aij 匹のアメーバがいた。 ただし、盤面の端にアメーバはいなかった。 すなわち、i=1,N または j=1,M ならば aij=0 である。
高橋君が大声を出すと、アメーバたちは驚いてそれぞれ次の行動をとった。
1 匹のアメーバが 4 匹に分裂し、上下左右のマスへ 1 匹ずつ移動した。
その結果、マス (i,j) には bij 匹のアメーバがいることになった。
今のアメーバの配置 (bij) が与えられるので、はじめのアメーバの配置 (aij) を 1 つ求めよ。 ただし、(aij) は少なくとも 1 つ存在する。

-----問題ここまで----- */
/* -----解説等-----

類問をよく見る。
こういう問題で解の保証があるときは、上から取り除いても問題ない。やるだけになってしまう。

----解説ここまで---- */

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int H, W; cin >> H >> W;

	vector<string>vs(H);
	VVI a(H, VI(W, 0));
	FOR(i, 0, H) {
		cin >> vs[i];
		FOR(j, 0, W) {
			a[i][j] = vs[i][j] - '0';
		}
	}

	VVI b(H, VI(W, 0));
	auto f = [&](int i, int j) {
		int val = a[i][j];
		if (val) {
			b[i + 1][j] += val;
			a[i][j] -= val;
			a[i + 2][j] -= val;
			a[i + 1][j - 1] -= val;
			a[i + 1][j + 1] -= val;
		}
	};

	FOR(i, 0, H - 2) {
		FOR(j, 1, W - 1) {
			f(i, j);
		}
	}

	FOR(i, 0, H) {
		FOR(j, 0, W) {
			cout << b[i][j];
		}cout << endl;
	}

	return 0;
}
