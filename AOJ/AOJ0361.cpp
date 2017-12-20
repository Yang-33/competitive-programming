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

/* -----  2017/12/20  Problem: AOJ 0361 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0361  ----- */
/* ------問題------

ぼくは内装職人です。今回依頼があったお客さんの家には、長方形の壁一面にパネルがぴったりと敷き詰められています。
パネルはすべて横の長さが２ｍ、縦の長さが１ｍの長方形で、横方向にx 枚、縦方向にy 枚並んでいます。この壁の左上隅から右下隅まで、まっすぐ電線を張ることになりました。
電線は図のように、壁の隅を含めたパネルの継ぎ目と電線の交点で固定することにします。下の図の場合には、交点の数は９つです（○が交点の位置を示しています）。
パネルの横方向と縦方向の枚数が与えられたとき、パネルの継ぎ目と電線の交点の数を求めるプログラムを作成せよ。ただし、パネルの継ぎ目の太さと電線の太さは考えないものとする。

-----問題ここまで----- */
/* -----解説等-----

どうみてもGCDなので端に注意してやる

----解説ここまで---- */

LL N;
long long  gcd(long long  a, long long  b) { return b ? gcd(b, a%b) : a; }

long long  lcm(long long  a, long long  b) { return a / gcd(a, b) * b; }

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int X, Y;
	cin >> X >> Y;
	cout << X + Y + 2 - (gcd(X, Y) + 1) << endl;

	return 0;
}
