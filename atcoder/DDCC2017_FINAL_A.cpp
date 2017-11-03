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

/* -----  2017/11/03  Problem: DDCC2017_final A / Link: http://ddcc2017-final.contest.atcoder.jp/tasks/ddcc2017_final_a  ----- */
/* ------問題------

直径 200 mmのウェーハ（円盤状の金属の薄い板）と、直径 300 mmのウェーハがあります。 この 2 つのウェーハから、縦横の長さが K mmの正方形のチップを作成しようとしています。
垂直方向・水平方向の 2 方向に、 円の端から K mmずつ等間隔にウェーハを切断していくことで、正方形のチップを作成していきます。
この時、直径 200 mmのウェーハで取れるチップの数と、直径 300 mmのウェーハから取れるチップの数を求めてください。
例えば、 K=20 の時、以下のようにチップを作成することができます。直径 200 mmのウェーハからは 60 個、直径 300 mmのウェーハからは 145 個のチップを取ることができます。

-----問題ここまで----- */
/* -----解説等-----

てんぱってしまったけど、これは商の偶奇で分割すればよい。
あとはそれぞれの場合においてｘ軸で分割していけばよい。

----解説ここまで---- */

LL N;

LL ans = 0LL;
int f(int x, double K, int r) {
	return min((sqrt(r*r - x*x)) / K, sqrt(r*r - (x + K)*(x + K)) / K);
}
int f2(int x, double K, int r) {
	return min((sqrt(r*r - x*x)-K/2) / K, (sqrt(r*r - (x + K)*(x + K))-K/2) / K);
}

int funca(int R, double K) {
	ans = 0;
	int l = -R; int r = R;
	for (int i = l; i < R; i += K) {
		LL ret = 0;
		ret += 2 * (int)f(i, K, r);
		ans += ret;
	}
	return ans;
}

int funcb(int R, double K) {
	ans = 0;
	int l = -R; int r = R;
	for (int i = l; i < r; i += K) {
		LL ret = 0;
		if (R * R >= i*i + (K / 2)*(K / 2) && R * R >= (i + K)*(i + K) + (K / 2)*(K / 2))ret += 1;
		ret += 2 * (int)f2(i, K, R);
		ans += ret;
	}
	return ans;
}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	double K; cin >> K;
	// x軸でやる

	if ((200 / (int)K) % 2 == 0) {
		cout << funca(100, K) << " ";
	}
	else cout << funcb(100, K) << " ";
	if ((300 / (int)K) % 2 == 0) {
		cout << funca(150, K) << endl;
	}
	else cout << funcb(150, K) << endl;
	

	return 0;
}
