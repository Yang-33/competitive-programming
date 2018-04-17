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

/* -----  2018/04/17  Problem: yukicoder 089  / Link: http://yukicoder.me/problems/no/089  ----- */
/* ------問題------

とある高校のアニメーション同好会が文化祭に向けドーナツで誓いを立てていた。
彼女たちは女子高生なのでカロリーが気になる。しかし、買ってきたドーナツにはカロリーが記載されていなかった。
買ってきたドーナツを上から見るときれいな２重円に見え、またドーナツの輪っかを切断するときれいな円になっていた。(つまり円環体ということ)
そこで彼女たちはドーナツが1cm3あたりCkcalであることを利用してカロリーを求めることにした。

-----問題ここまで----- */
/* -----解説等-----

積分の式を書く。久しぶりすぎてヤバイ…ってなった。

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	double C; cin >> C;
	int Rin, Rout; cin >> Rin >> Rout;
	double r = (Rout - Rin) / 2.0;
	double R = Rin + r;
	double ans = 2.0*PI*PI*r*r*R*C;
	cout << fixed << setprecision(5) << ans << "\n";

	return 0;
}
