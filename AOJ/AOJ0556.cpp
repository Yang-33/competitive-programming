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

/* -----  2017/10/31  Problem: AOJ 0556 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0556  ----- */
/* ------問題------

JOI 高校では， 1 × 1 の正方形のタイルを使って N × N の正方形の壁画を作り，文化祭で展示することになった
．タイルの色は，赤，青，黄の 3 種類である．壁画のデザインは次の通りである．まず，最も外側の周に赤のタイルを貼り，その内側の周に青のタイルを貼る．
さらにその内側の周に黄色のタイルを貼る．これを N × N の正方形が埋め尽くされるまで繰り返す．用いるタイルの色は，一番外側の周から順番に赤，青，黄，赤，青，黄，…である．
文化祭が近づいてきたある日，壁画のうち K 枚のタイルがはがれていることが判明した．そこで，新しいタイルを購入して，はがれた箇所に新しいタイルを貼ることにした．
入力として壁画の一辺の長さ N と，はがれたタイルの枚数 K， K 枚のはがれたタイルの位置が与えられたとき，はがれたタイルの色を求めるプログラムを作成せよ．

-----問題ここまで----- */
/* -----解説等-----

対称性から、1/8の領域に移動させるとy座標だけみればいいことになる。

----解説ここまで---- */

LL N, K;
int YRB[3] = { 3,1,2 };
LL ans = 0LL;
void solve(int x, int y, LL N) {
	x = (x < N - x + 1 ? x : N - x + 1);
	y = (y < N - y + 1 ? y : N - y + 1);
	if (x < y)swap(x, y);//x>y
	cout << YRB[y % 3] << endl;
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> K;
	int x, y;
	FOR(i, 0, K) {
		cin >> x >> y;
		solve(x, y, N);
	}
	return 0;
}
