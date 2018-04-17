#include <bits/stdc++.h>
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

/* -----  2018/04/17  Problem: yukicoder 085  / Link: http://yukicoder.me/problems/no/085  ----- */
/* ------問題------

yuki君が持っているテレビのリモコンには、ボタンが縦N段、横M列の長方形状に計N×M個並んでいる。
リモコンのX段目Y列目のボタンを押すと、テレビでチャンネル((X−1)×M+Y)を見ることができる。
（サンプルケース1の解説に具体例が記載されている）

yuki君はさっきチャンネルCのボタンを押し、そのままチャンネルCを見ている。
ところがyuki君は途中で他のチャンネルの内容を一通り見てみたくなった。
yuki君は素早く全チャンネルを巡回して元のチャンネルCに戻るため、以下のルールで順にボタンを押す。
最初に押すボタンは、さっき押したチャンネルCのボタンと上下左右いずれかに隣接したボタンである。
以降、直前に押したボタンと上下左右いずれかに隣接したボタンを押していく。
チャンネルC以外の全てのチャンネルのボタンをちょうど1回ずつ押した上で、最後にまたチャンネルCのボタンを押す。
N, M, Cが与えられたとき、上記ルールをすべて満たすボタンの押し順が存在するか答えよ。

-----問題ここまで----- */
/* -----解説等-----

odd*oddが到達できないことは二部グラフとであることとパリティで証明できる。

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int H, W, C; cin >> H >> W >> C;
	if (H > W)swap(H, W);
	if ((H == 1 && W > 2) || ((H*W) % 2 == 1)) {
		cout << "NO" << endl;
	}
	else {
		cout << "YES" << endl;
	}
	return 0;
}
