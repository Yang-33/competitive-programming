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

/* -----  2018/07/23  Problem: AOJ 0296 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0296  ----- */
/* ------問題------

４月に消費税が８％になってから、お財布が硬貨でパンパンになっていませんか。同じ金額を持ち歩くなら硬貨の枚数を少なくしたいですよね。硬貨の合計が１０００円以上なら、硬貨をお札に両替して、お財布のメタボ状態を解消できます。
お財布の中の硬貨の枚数が種類ごとに与えられたとき、硬貨をお札に両替できるかどうかを判定するプログラムを作成してください。

-----問題ここまで----- */
/* -----解説等-----

お財布メタボ診断って名前が好き

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int C[] = { 1,5,10,50,100,500 };
	int sum = 0;
	FOR(i, 0, 6) {
		int a; cin >> a;
		sum += a * C[i];
	}
	cout << (sum >= 1000) << endl;

	return 0;
}