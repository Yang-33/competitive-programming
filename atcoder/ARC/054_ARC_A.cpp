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

/* -----  2018/11/19  Problem: ARC 054 A / Link: http://arc054.contest.atcoder.jp/tasks/arc054_a  ----- */
/* ------問題------

高梁空港には、周長 L の円形の動く歩道があり、その床面は 1 秒間に距離 X 進む速度で時計回りに動いています。 動く歩道のある円周上の点の位置は、その中で最も北にある点から時計回りに測った距離 ( 0 以上 L 未満) であらわされます。 動く歩道の外周の位置 D の点には出口があり、そこから動く歩道の外に出ることができるようになっています。 それ以外の外周と内周には手すりがあるため、高橋君は出口以外の場所から外に出ることはできません。
高橋君は動く歩道の床面に対して 1 秒間に距離 Y 進む速度で時計回りまたは反時計回りに歩くことができ、動く歩道上の位置 S の点に乗っています。
高橋君が出口にたどり着くまでにかかる最小の時間を求めてください。
なお、出口の 1 箇所しかない動く歩道にわざわざ乗るような物好きな人は高橋君以外にはいないので、動く歩道を逆走しても誰にも迷惑をかけることはありません。

-----問題ここまで----- */
/* -----解説等-----

昔よりきれいに記述できている気がする

----解説ここまで---- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL L, X, Y, S, D; cin >> L >> X >> Y >> S >> D;
	double ans = LINF;
	ans = min(ans, 1.*((D-S+L)%L) / (X+Y));
	if(Y>X)ans = min(ans,1.*((S-D + L) % L) /(Y-X) );


	cout <<fixed<<setprecision(10)<< ans << "\n";

	return 0;
}
