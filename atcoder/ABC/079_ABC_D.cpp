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

/* -----  2017/11/18  Problem: ABC 079 D / Link: http://abc079.contest.atcoder.jp/tasks/abc079_d  ----- */
/* ------問題------

魔法少女のjoisinoお姉ちゃんは、この世にあるすべての数字を 1 に変えてやろうと思い立ちました。
1 つの数字を i から j(0≦i,j≦9) に書き変えるには魔力 ci,j が必要です。
今、目の前にある壁は縦方向に H、横方向に W のマス目になっていて、1 つ以上のマス目に 0 以上 9 以下の整数が 1 つずつ書かれています。
上から i(1≦i≦H) 番目、左から j(1≦j≦W) 番目のマスの情報として Ai,j が与えられ、
Ai,j≠−1 の場合はマスに Ai,j が書かれている
Ai,j=−1 の場合はマスに数字が書かれていない
ことを意味します。
この壁に書かれている数字を最終的に全て 1 に変えるのに必要な魔力の最小量を求めてください。

-----問題ここまで----- */
/* -----解説等-----

ワーシャルフロイドのノリでやるとsome->1への最小コストが求まる。
これがわかればあとはクエリが飛んでくるみたいになるのであとは最小コストの和を求めればよい。

----解説ここまで---- */

LL H,W;

LL ans = 0LL;


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> H>>W;
	VVI d(10, VI(10, 0));
	FOR(i, 0, 10) {
		FOR(j, 0, 10) {
			cin >> d[i][j];
		}
	}int V = 10;
	FOR(k, 0, V) {
		FOR(i, 0, V) {
			if (d[i][k] == LINF)continue;
			FOR(j, 0, V) {
				if (d[k][j] == LINF)continue;
				if (d[i][j] > d[i][k] + d[k][j]) {
					d[i][j] = d[i][k] + d[k][j];
				}
			}
		}
	}



	VVI a(H, VI(W, 0));
	FOR(i, 0, H) {
		FOR(j, 0, W) {
			cin >> a[i][j];
			if (a[i][j] != -1) {
				ans += d[a[i][j]][1];
			}
		}
	}

	cout << ans << "\n";

	return 0;
}
