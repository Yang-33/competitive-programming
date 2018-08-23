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

/* -----  2018/08/23  Problem: yukicoder 211  / Link: http://yukicoder.me/problems/no/211  ----- */
/* ------問題------

素数サイコロとはそれぞれの面に 2,3,5,7,11,13 の整数が書かれているサイコロである。
合成数サイコロとはそれぞれの面に 4,6,8,9,10,12 の整数が書かれているサイコロである。
素数サイコロと合成数サイコロを 1 つずつ振った時、出目の積が K となる確率を求めるプログラムを書いてください。
各面が出る確率はすべて 1/6 で、それぞれのサイコロについて出る面は独立です。

-----問題ここまで----- */
/* -----解説等-----

実際に全部調べる

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int K;
	while (cin >> K) {
		int cnt = 0;
		VI pdice = { 2,3,5,7,11,13 };
		VI cdice = { 4,6,8,9,10,12 };
		for (int p : pdice) {
			for (int c : cdice) {
				if (p*c == K)cnt++;
			}
		}

		double ans = cnt / 36.0;

		cout << fixed << setprecision(15) << ans << "\n";
	}

	return 0;
}
