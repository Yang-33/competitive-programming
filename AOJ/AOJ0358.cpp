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

/* -----  2017/12/20  Problem: AOJ 0358 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0358  ----- */
/* ------問題------

あなたは、今日発売された新刊「プログラミング甲子園必勝法」を買うために、友達のＡ君と本屋に来ています。あなたはどうしてもその本を買いたいので、手持ちの金額で足りないときは、Ａ君からお金を借りようと思っています。それでも足りなければ、今回はあきらめるしかありません。
あなたの手持ちの金額、Ａ君の手持ちの金額、本の値段が与えられたとき、本を買うためにＡ君から借りなければならない最小の金額を出力するプログラムを作成せよ。

-----問題ここまで----- */
/* -----解説等-----

3つの場合分け

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int m, f, b;
	cin >> m>>f>>b;
	if (f + m - b >= 0) {
		cout << max(min(0,m-b),b-m) << "\n";
	}
	else {
		cout << "NA" << endl;
	}

	return 0;
}
