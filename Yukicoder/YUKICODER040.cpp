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

/* -----  2018/04/10  Problem: yukicoder 040  / Link: http://yukicoder.me/problems/no/040  ----- */
/* ------問題------

ある日の宿題で多項式の割り算の問題が出ました。
しかしあなたは多項式の割り算がとても苦手です。
そこであなたはプログラムをつくり代わりにコンピュータに計算してもらうことにしました。
与えられた多項式を x^3−x で割った余りを出力してください。

-----問題ここまで----- */
/* -----解説等-----

解法1:多項式の割り算の筆算をそのまま書く。O(N)
解法2:(与式) = Q(x)(x+1)x(x-1) + ax^2 + bx + cなので、x=1,0,-1を入れて連立方程式を解く。O(NlogN)

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	VI a(N + 1);
	FOR(i, 0, N + 1) {
		cin >> a[i];
	}
	FORR(i, N, 3 - 1) {
		a[i - 2] += a[i];
		a[i] = 0;
	}

	int idx = 2;
	while (idx&&a[idx] == 0)idx--;
	
	cout << idx << endl;
	FOR(i, 0, idx + 1) {
		cout << a[i] << " \n"[i == idx];
	}

	return 0;
}
