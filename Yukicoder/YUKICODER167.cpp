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

/* -----  2018/07/26  Problem: yukicoder 167  / Link: http://yukicoder.me/problems/no/167  ----- */
/* ------問題------

N^M mod 10を求めよ。

-----問題ここまで----- */
/* -----解説等-----

Nの下一桁について埋め込んだ
埋め込むとmod4でまとめられるので、mmod4をもとめればよい。これは下2桁の情報があればよい。

powするという頭はなかった。

----解説ここまで---- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string n, m; cin >> n >> m;
	int under = n.back() - '0';

	VVI res(10);
	res[0] = { 0 };
	res[1] = { 1 };
	res[2] = { 6,2,4,8 };
	res[3] = { 1,3,9,7 };
	res[4] = { 6,4 };
	res[5] = { 5 };
	res[6] = { 6 };
	res[7] = { 1,7,9,3 };
	res[8] = { 6,8,4,2 };
	res[9] = { 1,9 };
	if (m == "0")cout << 1 << endl;
	else {
		m = "00" + m;
		int ret = 0;
		int sz = SZ(m);
		FOR(i, sz - 2, sz) {
			ret *= 10;
			ret += m[i] - '0';
		}
		int mval = ret;

		int ans = res[under][mval%SZ(res[under])];
		cout << ans << "\n";
	}
	return 0;
}
