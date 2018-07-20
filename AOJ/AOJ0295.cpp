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

/* -----  2018/07/23  Problem: AOJ 0295 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0295  ----- */
/* ------問題------

選手のみなさん、パソコン甲子園にようこそ。パソコン甲子園の本選は会津大学で行われ、会場内では １つの机に１チームが割り当てられます。パソコン甲子園は１チーム２人なので、チーム数×２脚の椅子が必要です。大学では、他にも様々なイベントの会場設営で机と椅子を準備する機会がありますが、必要な机と椅子の数も様々です。そこで、あるイベントに対して準備する机の数と、机１つあたりに必要な椅子の数が与えられたとき、必要な椅子の総数を計算するプログラムを作成してください。

-----問題ここまで----- */
/* -----解説等-----

します。

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int a, b;
	cin >> a >> b;
	cout << a * b << endl;

	return 0;
}