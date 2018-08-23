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

/* -----  2018/08/23  Problem: yukicoder 219  / Link: http://yukicoder.me/problems/no/219  ----- */
/* ------問題------

累乗数の概算をしたいと思います。
AB≒X.Y∗10Z (A,B,X,Y,Zは整数、Xは1以上9以下、Yは0以上9以下、なおYより下位は切り捨てとする)
A,Bが複数与えられるので、あてはまるX,Y,Zを求めて下さい。なおZは0になることはないとします。

ただし、誤差の許容として、有効な出力をそれが表現する値で順序付けした時、想定解の出力の１つ隣に該当する値も許容する。

-----問題ここまで----- */
/* -----解説等-----

Cを有効数字2桁のの数字として、
A^B = C*10^Z となっている。底10の対数をとって、
Blog10(A) = Zlog10(C)である。
A,Bは既知なので、Zは一意に定まる。Cの決定はたくさんあるけど差分を取れば凸なので三分探索なり全探索なりをすればよい。

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N; cin >> N;
	FOR(i, 0, N) {
		double A, B; cin >> A >> B;
		double val = B * log10(A);
		LL Z = val;
		val -= Z;
		int XY = -1;
		double Diff = INF;
		FOR(j, 10, 100) {
			double x = j / 10.0;
			if (abs((val)-log10(x)) < Diff) {
				Diff = abs((val) - log10(x));
				XY = j;
			}
		}
		
		cout << XY / 10 << " " << XY % 10 << " " << Z << endl;
	}

	return 0;
}
