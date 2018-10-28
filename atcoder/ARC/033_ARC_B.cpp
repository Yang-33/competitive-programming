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
//#pragma GCC optimize ("-O3") 
#ifdef YANG33
#include "mydebug.hpp"
#else
#define DD(x) 
#endif
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/10/27  Problem: ARC 033 B / Link: http://arc033.contest.atcoder.jp/tasks/arc033_b  ----- */
/* ------問題------

「foo」や「bar」「hoge」などの、特に意味を持たない変数の名前に使用される文字列のことを「メタ構文変数」と呼びます。
高橋君は今、メタ構文変数について調べています。メタ構文変数には色々な種類があることが分かり、見つけたメタ構文変数にそれぞれに番号をつけました。高橋君はアリの Ant さんと Bug くんのソースコードを読み、それぞれのソースコードに現れるメタ構文変数の番号を列挙しました。そして、Ant さんと Bug くんの使うメタ構文変数の集合がどれくらい似ているのかを調べるために「Jaccard 係数」を計算することにしました。Ant さんのソースコードに現れるメタ構文変数の集合を SA、Bug くんのソースコードに現れるメタ構文変数の集合を SB とするとこれらの集合の Jaccard 係数は、
||SA∩SB||⁄||SA∪SB||
という式で計算できます。ここで、||S|| は集合 S の要素数を表すものとします。別の言い方をすると、
「SA と SB の両方に現れる要素の個数」⁄「SA と SB の少なくともどちらか一方には現れる要素の個数」
となります。

-----問題ここまで----- */
/* -----解説等-----

mapで積集合と和集合を求めることができる。

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N1, N2; cin >> N1 >> N2;
	VI a(N1), b(N2);
	map<int, int>MapA;
	FOR(i, 0, N1) {
		cin >> a[i];
		MapA[a[i]]++;
	}
	int And = 0;
	FOR(i, 0, N2) {
		cin >> b[i];
		if (MapA.find(b[i]) != MapA.end())And++;
	}
	FOR(i, 0, N2) {
		MapA[b[i]]++;
	}
	int Or = SZ(MapA);

	double ans = And / 1.0 / Or;

	cout << fixed << setprecision(10) << ans << "\n";

	return 0;
}
