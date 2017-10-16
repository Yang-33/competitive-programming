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

/* -----  2017/10/16  Problem: nagoya_19_09 JOI2012予選 3 / Link: http://joi2012yo.contest.atcoder.jp/tasks/joi2012yo_c  ----- */
/* ------問題------

K 理事長は，JOI 市の中心部にある JOI ピザ店の常連客である．彼はある事情により，今月から節約生活を始めることにした．そこで彼は，JOI ピザ店で注文できるピザのうち，1 ドルあたりのカロリーが最大となるようなピザを注文したいと思った．このようなピザを「最高のピザ」と呼ぶことにしよう．「最高のピザ」は 1 種類とは限らない．
JOI ピザでは N 種類のトッピングから何種類かを自由に選び，基本の生地の上に載せたものを注文することができる．同種のトッピングを 2 つ以上載せることはできない．生地にトッピングを 1 種類も載せないピザも注文できる．生地の値段は A ドルであり，トッピングの値段はいずれも B ドルである．ピザの値段は，生地の値段と載せたトッピングの値段の合計である．すなわち，トッピングを k 種類 (0 ≦ k ≦ N) 載せたピザの値段は A + k × B ドルである．ピザ全体のカロリーは，生地のカロリーと載せたトッピングのカロリーの合計である．
生地の値段とトッピングの値段，および，生地と各トッピングのカロリーの値が与えられたとき，「最高のピザ」の 1 ドルあたりのカロリー数を求めるプログラムを作成せよ．

-----問題ここまで----- */
/* -----解説等-----

三分探索っぽいが、貪欲にカロリーを高いものからとっていってこれをシュミレーションすればよい。

----解説ここまで---- */

LL N,A,B,C;
LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N>>A>>B>>C;
	VL d(N);
	FOR(i, 0, N)cin >> d[i];
	RSORT(d);
	VL sum(N + 1);
	FOR(i, 0, N) {
		sum[i + 1] += sum[i] + d[i];
	}
	FOR(i, 0, N+1) {
		ans = max(ans, (C + sum[i]) / (A + i*B));
	}

	cout << ans << "\n";

	return 0;
}