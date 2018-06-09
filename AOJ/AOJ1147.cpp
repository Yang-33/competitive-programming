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

/* -----  2018/06/10  Problem: AOJ 1147 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1147  ----- */
/* ------問題------

世界道化コンテスト (International Clown and Pierrot Competition; ICPC) は興行界で権威も人気も最高の行事である．

このコンテストの特色のひとつは，採点に当たる審判員の数が多いことで，と きには百人にも上る．審判の数は競技者ごとに異なる．というのは，採点対象 の競技者と少しでも関係のある審判は，その競技者の演技の採点から一時的に 外れるからである．

基本としては，ひとりの競技者の演技についての審判の点数の平均がその競技 者の点数になる．常軌を逸した視点から採点する審判が点数に大きな影響を与 えないよう，最高点と最低点は除外する．もし最高点をつけた審判が複数いた ら，そのうちのひとつだけを無視する．最低点についても同様である．平均点 には端数があるかもしれないが，それは切り捨てて最終的な点数は整数値とす る．

この行事をテレビ中継向けにスピードアップするため，ある演技の点数を審判 全員の採点から計算するプログラムを書くことを，あなたは頼まれた．

-----問題ここまで----- */
/* -----解説等-----

読解をする

----解説ここまで---- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int n, point[1000], sum;
	while (cin >> n, n) {
		sum = 0;
		for (int i = 0; i < n; ++i) {
			cin >> point[i];
		}
		sort(point, point + n);
		for (int i = 1; i < n - 1; ++i) {
			sum += point[i];
		}
		cout << sum / (n - 2) << endl;
	}

	return 0;
}
