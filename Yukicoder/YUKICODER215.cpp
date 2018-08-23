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

/* -----  2018/08/23  Problem: yukicoder 215  / Link: http://yukicoder.me/problems/no/215  ----- */
/* ------問題------

素数サイコロとはそれぞれの面に 2,3,5,7,11,13 の整数が書かれているサイコロである。
合成数サイコロとはそれぞれの面に 4,6,8,9,10,12 の整数が書かれているサイコロである。
あるスゴロクでは、0 のマスからスタートし、N のマスに辿り着いたらゴールである。
各ターン、P 個の素数サイコロと C 個の合成数サイコロを振り、出た目の和を x として、今いるマスが k ならば min(k+x,N) のマスに移動する。
それぞれ素数サイコロと合成数サイコロは区別できないとして、ゴールする方法のパターン数を mod 1000000007 (109+7) で求めるプログラムを書いて下さい。

-----問題ここまで----- */
/* -----解説等-----

任意MODconvolutionでKitamasa法の積部分をO(N^2)からO(NlogN)にします。
時間をかけて書いて完成したのですがここには載せません(えー)

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	cout << ans << "\n";

	return 0;
}
