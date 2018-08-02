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

/* -----  2018/08/02  Problem: yukicoder 201  / Link: http://yukicoder.me/problems/no/201  ----- */
/* ------問題------

yukicoderじゃんけん　とは

　じゃんけんをして、ゆるふわポイントの多い方が勝ち
 yukicoderじゃんけんをする二者の名前、ゆるふわポイント、じゃんけんの手が与えられるので、勝者の名前を出力してください。
 両者のゆるふわポイントが等しい場合は引き分けです。"-1"を出力してください。

-----問題ここまで----- */
/* -----解説等-----

レートが大きいので、数字の長さが同じときだけ場合分けをする。

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string Name[2],rate[2],Hand[2];
	FOR(i, 0, 2) {
		cin >> Name[i] >> rate[i] >> Hand[i];
	}
	if (rate[0] == rate[1]) {
		cout << -1 << endl;
	}
	else {
		auto f = [](const string &a,const string &b) {
			if (SZ(a) != SZ(b)) {
				return SZ(a) > SZ(b);
			}
			else {
				FOR(i, 0, SZ(a)) {
					if (a[i] == b[i])continue;
					else return a[i] > b[i];
				}
			}
		};
		cout << (f(rate[0], rate[1]) ? Name[0]:Name[1] ) << endl;
	}

	return 0;
}
