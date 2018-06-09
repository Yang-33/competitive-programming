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

/* -----  2018/06/10  Problem: AOJ 2629 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2629  ----- */
/* ------問題------

マンハッタンでは，道路がx 座標またはy 座標が整数のところに通っている．すぬけ君の家とすめけ君の家はどちらも道路上にあり，直線距離(ユークリッド距離) はちょうど d である．すぬけ君の家からすめけ君の家まで道路に沿って移動するときの最短距離として考えられる最大値を求めよ．

-----問題ここまで----- */
/* -----解説等-----

-- O(1)は嫌い(楽しいけど) --

sampleから、なんかブロックの反対側で1を稼げるっぽい。
一方で、sqrt(2)倍っぽいこともできる。
場合分けをしてmaxを取れば良い。

----解説ここまで---- */

int main() {

	long double d;
	cin >> d;
	if (d < 1) {
		cout << fixed << setprecision(10) << d*sqrtl(2.0) << endl;
	}

	else if (d >= 1 && d <= sqrtl(2)) {
		cout << fixed << setprecision(10) << 2.0 << endl;
	}
	else {
		int dd = d;
		cout << fixed << setprecision(10) << max((long double)dd + 1, d*sqrtl(2.0)) << endl;
	}

}