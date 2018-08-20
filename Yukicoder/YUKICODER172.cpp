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

/* -----  2018/07/28  Problem: yukicoder 172  / Link: http://yukicoder.me/problems/no/172  ----- */
/* ------問題------

ゆきちゃんは愛犬ルビーと一緒に日課の散歩中。
しかし突如現れたUFOが、ルビーをさらって逃げてしまった。
ルビーを助けるため、ゆきちゃんの超能力を発揮させてUFOを捕まえろ！

座標(0,0)にいるゆきちゃんは超能力によって、境界までのマンハッタン距離が自然数である結界を瞬時に作ることができる。
UFOは現在位置(x,y)、半径rの円であり、結界を作ったときにUFOが結界内部にいる場合、確保が成功する。
このとき、作った結界にUFOが触れていると逃げられてしまうので注意が必要だ。(※)

ゆきちゃんは他のUFO襲来にも備えて力を温存するため、結界の大きさは最小限にとどめたい。
UFOを確保するために作る結界サイズの最小値を出力せよ。


※結界は十分に薄いので、UFOが境界に触れているとは次の状態を指す。
UFOの境界上または内部に含まれ、かつ結界の境界上に位置するような点Pが存在する状態。

-----問題ここまで----- */
/* -----解説等-----

マンハッタン距離なのでひし形みたいなのができる。
これに接する円をかいたときの接点が最遠点なのでこれのマンハッタン距離の切り上げを答えれば良い。

----解説ここまで---- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	double x, y, r;
	cin >> x >> y >> r;
	x = abs(x), y = abs(y), r = abs(r);
	int ans = x + r*cos(PI / 4) + y + r*sin(PI / 4)+1;
	cout << ans << endl;


	return 0;
}
