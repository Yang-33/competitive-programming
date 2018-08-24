#include <bits/stdc++.h>
#include<omp.h>
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

/* -----  2018/08/24  Problem: yukicoder 229  / Link: http://yukicoder.me/problems/no/229  ----- */
/* ------問題------

長さ L の線分上を、3つの動点 P1,P2,P3 が、それぞれ一定の速さで往復しています。
各動点は、線分の端に達すると、もう一方の端に向かうように移動の向きが反転し、これを繰り返します。

動点 P1 は、 T1 秒で線分上を1往復します。
動点 P2 は、 T2 秒で線分上を1往復します。
動点 P3 は、 T3 秒で線分上を1往復します。

今、3つの動点は全て線分の左端にあり、右向きに移動を開始します。
次に3つの動点の位置が全て一致するのは、今から何秒後でしょうか？
既約分数の形でお答えください。

-----問題ここまで----- */
/* -----解説等-----

解の候補はlcm(ALL(a))/Xである。
Xについては、[1..10000]をみたすはずなので、これを全部しらべればよい。
あと、約分をする。

----解説ここまで---- */



long long  gcd(long long  a, long long  b) { return b ? gcd(b, a%b) : a; }
long long  lcm(long long  a, long long  b) { return a / gcd(a, b) * b; }


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	VI a(3); FOR(i, 0, 3)cin >> a[i];
	LL l = a[0];
	FOR(i, 0, 3) {
		l = lcm(l, a[i]);
	}
	VL c(3); FOR(i, 0, 3)c[i] = l / a[i];
	LL x = 1;
	const int T = 10000;
	VL pos(3);
	FOR(t, 1, T) {
		FOR(i, 0, 3)pos[i] = c[i] - c[i] / t * t;
		if ((pos[0] == pos[1] || pos[0] == t - pos[1]) && (pos[0] == pos[2] || pos[0] == t - pos[2])) {
			x = t;
		}
	}


	LL Gcd = gcd(l, x);
	cout << l / Gcd << "/" << x / Gcd << "\n";

	return 0;
}
