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

/* -----  2017/11/01  Problem: AOJ 0631 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0631  ----- */
/* ------問題------

JOI 商店街ではポイントカードのサービスを行っている．各ポイントカードには 2N 個のマスがある．
商品を購入すると，くじを引くことができ，結果によって「当たり」か「はずれ」の印がマスに押される．
同じマスに印が 2 回押されることはない．2N 個のマスのうち N 個以上のマスに当たりの印が書かれたポイントカードは，景品と交換することができる．
また，ポイントカードの印は，1 マスにつき 1 円で書き換えてもらうことができる．
JOI 君は 2N 個のマスが全て埋まっているポイントカードを M 枚持っている．
ポイントカード i (1 ≦ i ≦ M) には，Ai 個の当たり印と，Bi 個のはずれ印が押されている．JOI 君は M - 1 個以上の景品が欲しい．
JOI 君が M - 1 個以上の景品を得るために必要な費用の最小値を求めよ

-----問題ここまで----- */
/* -----解説等-----

aを降順に並べればよい。
その後M-1個を順にみて、お金を払う必要があれば書き換えてもらう。

----解説ここまで---- */

LL N,M;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N>>M;
	VI p;
	FOR(i, 0, M) {
		int a, b;
		cin >> a >> b;
		p.push_back(a);
	}
	RSORT(p);
	FOR(i, 0, M-1) {
		if (p[i] >= N)continue;
		ans += N - p[i];
	}
	cout << ans << "\n";

	return 0;
}
