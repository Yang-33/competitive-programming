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
//#pragma GCC optimize ("-O3") 
#ifdef YANG33
#include "mydebug.hpp"
#else
#define DD(x) 
#endif
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/11/03  Problem: ARC 029 B / Link: http://arc029.contest.atcoder.jp/tasks/arc029_b  ----- */
/* ------問題------

高橋君は、部屋の整理をしていた。
高橋君が部屋の整理を行っているとき、中学生くらいのときに書いた「禁断の書」(という題名のノート)が出てきた！
数ページ見ただけでも(書いた本人が)悶絶するほどに人には見せられない「禁断」のノートであるため、箱にしまっちゃうことにした。
ノートは底面が縦 A センチ、横 B センチの長方形で高さ (厚み) がそれほどない直方体の形状をしている。
箱は N 個あり、それらには 1 から N までの番号がつけられている。箱 i(1≦i≦N) の形状は、箱の内側の底面が縦 Ci センチ、横 Di センチの長方形で、高さがノートの厚みよりわずかに大きいくらいの直方体の形をしている。
高橋君は几帳面なため、ノートの底面と箱の内側の底面を一致させて収納しなければ気が済まない。すなわち高橋君にとって、箱 i にノートが入る必要十分条件は、平面上で縦 A センチ、横 B センチの長方形 (ノートを表す長方形) を適切に回転および平行移動させて、同一平面上にある縦 Ci センチ、横 Di センチの長方形の内部に完全に収まるように配置できるということである。
どの箱に収納するか吟味する前に、どの箱に収納可能かを調べなければならない。それぞれの箱について、ノートが入るか入らないかを判定するプログラムを作成せよ。

-----問題ここまで----- */
/* -----解説等-----

http://www.creativ.xyz/arc029-b-453
幾何ライブラリで回転させまくってもダメだった。
これ賢いなあ

----解説ここまで---- */

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);


	double a, b; cin >> a >> b;
	int N; cin >> N;
	double L = sqrt(a * a + b * b);
	FOR(i, 0, N) {
		double c, d;
		cin >> c >> d;
		double boxL = sqrt(c * c + d * d);
		if (min(a, b) <= min(c, d) && max(a, b) <= max(c, d)) {
			cout << "YES" << endl;
		}
		else if (min(a, b) > min(c, d) || L > boxL) {
			cout << "NO" << endl;
		}
		else {
			if (a < b)swap(a, b);
			double th1 = 2 * atan2(b, a);
			double th2 = acos(c / L);
			double th3 = acos(d / L);
			if (PI / 2 - th2 - th3 > th1) {
				cout << "YES" << endl;
			}
			else {
				cout << "NO" << endl;
			}
		}
	}


	//cout << ans << "\n";

	return 0;
}
