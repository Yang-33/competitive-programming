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

/* -----  2018/04/15  Problem: yukicoder 064  / Link: http://yukicoder.me/problems/no/064  ----- */
/* ------問題------

整数列 {Fk} を次の漸化式で定義する。

Fk=Fk−1⊕Fk−2(k≥2)

ただし、⊕ はビット XOR の記号である。
F0,F1 が与えられたとき、FN を計算せよ。

-----問題ここまで----- */
/* -----解説等-----

XORの性質、X^X = 1より、A=B^C -> A^C=Bである。  
したがって順番に数を生成したとき、生成される数は3種類のみ。

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	VL F(100, 0);
	cin >> F[0] >> F[1] >> N;
	F[2] = F[1] ^ F[0];
	ans = F[N % 3];
	cout << ans << "\n";

	return 0;
}
