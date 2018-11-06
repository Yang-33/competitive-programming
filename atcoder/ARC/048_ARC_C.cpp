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

/* -----  2018/11/06  Problem: ARC 048 C / Link: http://arc048.contest.atcoder.jp/tasks/arc048_c  ----- */
/* ------問題------

高橋君には足が N 本あり、i 番目の足は Li 本の骨が一列につながった構造をしています。 すべての足の片方の端は、高橋君の胴体につながっています。高橋君の胴体には骨はありません。
今回高橋君は、自分のすべての足のすべての骨に 0 または 1 の文字を書き込むことにしました。
高橋君は文字の書き込み方に強いこだわりを持っており、任意の異なる 2 本の足 A,B について、 A の胴体につながっていないほうの端から B の胴体につながっていないほうの端までの胴体を経由する経路上にある骨に書かれた文字をすべて順に読むと回文になっているとき、またその時のみ満足します。
高橋君が満足する文字の書き込み方の数を 109+7 で割った余りを求めてください。

-----問題ここまで----- */
/* -----解説等-----

完全にエスパーになった。
まず最小の要素は全部色を変えることができる。
次に１つ選択するとすると、他のものはO(N^2)の制約を守るものになる。
そこで、影響範囲の伝播を考える。
実験するとユークリッドの互除法っぽい感じになるので、gcdでやる。

----解説ここまで---- */

const long long mod = 1e9 + 7;
long long modpow(long long a, long long b) {
	if (b == 0) return 1;
	return modpow(a * a % mod, b / 2) * (b & 1 ? a : 1) % mod;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N;
	cin >> N;
	VL a(N);
	FOR(i, 0, N) {
		cin >> a[i];
	}
	SORT(a);
	LL F = a.front();
	LL gcdVal = a.back() - F;
	FOR(i, 1, N) {
		gcdVal = __gcd(gcdVal, a[i] - F);
	}
	DD(de(gcdVal);)
		gcdVal++;
	LL ans = modpow(2, F + gcdVal / 2);

	cout << ans << "\n";

	return 0;
}
