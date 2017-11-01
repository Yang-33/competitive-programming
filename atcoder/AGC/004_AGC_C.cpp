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

/* -----  2017/09/23  Problem: 004_agc_c  / Link: http://agc004.contest.atcoder.jp/tasks/agc004_c  ----- */
/* ------問題------

 高橋君と青木君は、縦 H マス、横 W マスの透明な方眼紙を 1 枚ずつ手に入れました。

高橋君は、自分の方眼紙のいくつかのマスを赤く塗りました。 このとき、赤いマスは上下左右に連結でした。 つまり、どの赤いマスからどの赤いマスへも、上下左右に隣り合う赤いマスのみを辿って行き来できます。

また、青木君は、自分の方眼紙のいくつかのマスを青く塗りました。 このとき、青いマスは上下左右に連結でした。

その後、高橋君と青木君は、2 枚の方眼紙をそのままの向きでぴったりと重ねました。 すると、赤いマスと青いマスが重なるマスのみが紫色になって見えました。

紫色のマスの配置が、長方形に並ぶ文字 aij (1≤i≤H，1≤j≤W) として与えられます。 上から i 行目、左から j 列目のマスが紫色ならば、aij は # であり、紫色でなければ、aij は . です。 このとき、最も外側のマスは紫色でないことが保証されます。 つまり、i=1，H または j=1，W ならば、aij は . です。

問題文の条件を満たすような、赤いマスの配置と青いマスの配置のペアをひとつ求めてください。 解は必ず存在することが示せます。

-----問題ここまで----- */
/* -----解説等-----

じっくり考えると、Eみたいな文字を組重なるようにはいちしておけば、そのままでは紫色のマスはできない。
その後与えられた文字を反映することでこれを紫にすることができる。

----解説ここまで---- */

LL H, W;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> H >> W;
	VS s(H);
	VS a(H);
	VS b(H);
	FOR(i, 0, H) {
		cin >> s[i];
		//a[i] = b[i] = s[i];
	}
	FOR(i, 0, H) {
		a[i] = b[i] = string(W, '.');
		if (i % 2 == 0)a[i] = string(W, '#'),a[i][0]='.';
		else if (i % 2 == 1)b[i] = string(W, '#'),b[i][W-1]='.';
	}


	FOR(i, 1, H - 1) {
		a[i][W - 1] = '#';
		b[i][0] = '#';
	}
	a[0][0] = '#';
	if(H%2==0)b[H-1][W-1] = '#';
	b[H-1][0] = '#';

	FOR(i, 0, H) {
		FOR(j, 0, W) {
			if (s[i][j] == '#') {
				a[i][j] = '#';
				b[i][j] = '#';
			}
		}
	}
	FOR(i, 0, H) {
		cout << a[i] << endl;
	}
	cout << endl;
	FOR(i, 0, H) {
		cout << b[i] << endl;
	}

	
	//cout << ans << "\n";

	return 0;
}