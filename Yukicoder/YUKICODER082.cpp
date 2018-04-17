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

/* -----  2018/04/17  Problem: yukicoder 082  / Link: http://yukicoder.me/problems/no/082  ----- */
/* ------問題------

幅Wと高さHと左上の色が指定されるので市松模様を描け。
市松模様は、黒と白が交互に現れる模様である。
模様は黒を'B'、白を'W'を使って描くものとする。

詳しくはサンプルを見てください。

-----問題ここまで----- */
/* -----解説等-----

45度回転させると楽で、(i,j)->(i+j,i-j)みたいなのをかんがえればよい。
すると、マンハッタン距離の偶奇を考えれば良くなる。

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int W, H; char C;
	cin >> W >> H>>C;
	string s = "BW";
	FOR(i, 0, H) {
		FOR(j, 0, W) {
			cout << s[(s[0] != C) ^ ((i + j) % 2)];
		}cout << endl;
	}

	return 0;
}
