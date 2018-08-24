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

/* -----  2018/08/24  Problem: yukicoder 226  / Link: http://yukicoder.me/problems/no/226  ----- */
/* ------問題------

縦H, 横Wのマスからなる長方形があり、各マスには'0'か'1'か'?'のいずれかが書かれている。
今、'?'の書かれている全てのマスに対し、以下の条件を満たすように、'?'を消して'0'か'1'を書き込みたい。
そのような方法のパターン数を mod. 1000000007 で求めるプログラムを書いて下さい。

(条件)
どの2×2の正方形ボードを取り出しても、0が丁度2個、1が丁度2個含まれている。
より正確には、ボードの上からi番目 (1-index)、左からj番目 (1-index) のマスの値をv(i,j)と表したとき、
任意の 1≤i≤H−1, 1≤j≤W−1 に対し、4個の値 v(i,j),v(i,j+1),v(i+1,j),v(i+1,j+1) のうち、
丁度2個が'0'で、丁度2個が'1'となっている。

-----問題ここまで----- */
/* -----解説等-----

DPかとおもったけどお絵かきしたらおーってなった

----解説ここまで---- */

template<class T>void rotate2dR(vector<vector<T>>& a) { // rorateToR
	vector<vector<T>> res(a[0].size(), vector<T>(a.size()));
	FOR(i, 0, (int)a.size())FOR(j, 0, (int)a[0].size())res[j][a.size() - i - 1] = a[i][j];
	a = res;
}

LL decideTopGrid(const vector<vector<char>>& a) {
	LL ret = 1; // e 
	int H = SZ(a), W = SZ(a[0]);
	// 2^W個ありえます
	FOR(j, 0, W) {
		int state = 0;
		FOR(b, 0, 2) {
			char top = '0' + b;
			if (isdigit(a[0][j]) && a[0][j] != top)continue;

			bool ok = 1;
			FOR(i, 1, H) {
				if (a[i][j] == '?')continue;
				if (i & 1)ok &= (a[i][j] != top);
				else ok &= (a[i][j] == top);
			}
			state += ok;
		}

		ret *= state;
		ret %= MOD;
	}
	return ret;
}

// [0,2] 市松模様の個数
LL countCheckeredPattern(const vector<vector<char>>& a) {
	int H = SZ(a), W = SZ(a[0]);
	LL ret = 0;
	FOR(b, 0, 2) {
		bool ok = 1;
		char top = '0' + b;
		if (a[0][0] == '?' || a[0][0] == top) {
			FOR(j, 0, W) {
				FOR(i, 0, H) {
					if (a[i][j] == '?')continue;
					if ((i^j) & 1) {
						ok &= (a[i][j] != top);
					}
					else {
						ok &= (a[i][j] == top);
					}
				}
			}
			ret += ok;
		}
	}
	return ret;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int H, W; cin >> H >> W;
	vector<vector<char>>a(H, vector<char>(W));
	FOR(i, 0, H) {
		FOR(j, 0, W) {
			cin >> a[i][j];
		}
	}

	LL ans = decideTopGrid(a);
	rotate2dR(a);
	ans += decideTopGrid(a);
	ans %= MOD;
	ans -= countCheckeredPattern(a);

	ans += MOD; ans %= MOD;
	cout << ans << "\n";

	return 0;
}
