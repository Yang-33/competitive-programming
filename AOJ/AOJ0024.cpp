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

/* -----  2017/10/03  Problem: AOJ 0024  / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0024&lang=jp ----- */
/* ------問題------

地球上で物体を静かに落下させたとき、空気抵抗などの影響を考えないとすると、
t 秒後の物体の速度v,t 秒中に物体が落下した距離y は、
v=9.8t , y=4.9t^2 で与えられます。
ある人が、建物の高い位置からガラスの球を落下させて、ガラスの球が割れるかどうかを調べる実験を行っています。
入力データとして、球が割れるのに必要な最低速度
v が与えられます。球を割るには、建物の少なくとも何階以上から落とす必要があるかを求め、その階を出力するプログラムを作成して下さい。なお、建物の
N 階の高さは5×N−5 で与えられるものとします。

-----問題ここまで----- */
/* -----解説等-----

式変形をして自分好みの形にすればよい。

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	double v;
	while (cin >> v) {
		ans = 0;
		double t = v / 9.8;
		double h = 4.9*t*t;
		ans = ceil((h + 5.0) / 5.0);
		cout << ans << "\n";

	}
	
	

	return 0;
}
