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

/* -----  2018/07/28  Problem: yukicoder 179  / Link: http://yukicoder.me/problems/no/179  ----- */
/* ------問題------

縦H,横Wのマスからなる長方形があります。各マスは白または黒で塗られています。
yuki君は黒のマス全てを赤か青に塗り替えることにしました。また、赤青それぞれ少なくとも1マスは塗り、赤で塗られたマスと青で塗られたマスが平行移動して一致するようにしたいと思っています。
yuki君の望む塗りかたが可能なら"YES"、不可能なら"NO"を出力してください。(""は不要です)

注：同じマスに複数の色を塗ることはできません。yuki君は白のマスは塗り替えません。

-----問題ここまで----- */
/* -----解説等-----

これを昔みて諦めた気がする。
2つの始点を全探索する。

----解説ここまで---- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int H, W; cin >> H >> W;
	VS vs(H);
	FOR(i, 0, H) {
		cin >> vs[i];
	}
	auto check = [&W, &H](VS a, int dh, int dw) {

		bool update = 0;
		FOR(i, 0, H) {
			FOR(j, 0, W) {
				if (a[i][j] == '.')continue;
				int ni = i + dh;
				int nj = j + dw;
#define IN(x,y,z) (x<=y&&y<z)
				if (!IN(0, ni, H) || !IN(0, nj, W))continue;
				if (a[ni][nj] != '#')continue;
				a[ni][nj] = a[i][j] = '.';
				update = 1;
			}
		}

		int f = 0;
		FOR(i, 0, H)FOR(j, 0, W)f |= (a[i][j] == '#');

		return !f && update;
		
	};


	int ans = 0;
	FOR(dh, -H + 1, H) {
		FOR(dw, 0, W) {
			if (!dh && !dw)continue;
			ans |= check(vs, dh, dw);
		}
	}


	cout << (ans ? "YES" : "NO") << "\n";

	return 0;
}
