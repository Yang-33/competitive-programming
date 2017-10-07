#include "bits/stdc++.h"
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

/* -----  2017/10/06  Problem: CodeForces439 C div2 / Link: http://codeforces.com/contest/869/problem/C  ----- */
/* ------問題------

青、赤、紫の石がそれぞれ何個かある。(≦5*10^3)
これを同じ色は少なくとも3以上の距離となるようにつないだとき何通りのつなぎ方があるか。
全部つながなくてもよいし独立につないでもよい。

-----問題ここまで----- */
/* -----解説等-----

ぐっとにらむと、構築の際には各色を巡回していくように交互につなげていくしかないことがわかる。
したがって色を選ぶ際につなぎ方はmin(a,b)までしかなく、これを全部生成すればよい。
それぞれの対応について、2色の間でK本つなぐならばK!選択があるので、aCk*bCk*k!を足しこんでいけばよい。
三つの色の境界はそれぞれ独立なのであとはこれをかけあわせればよい。

----解説ここまで---- */

LL a, b, c;

const LL mod = 998244353LL;

LL ans = 0LL;
long long  powmod(long long  x, long long  n, long long  mod) {
	long long  res = 1;
	while (n > 0) {
		if (n & 1) {
			res = (res*x) % mod;
		}
		x = (x*x) % mod;
		n >>= 1;
	}
	return res;
}

LL F[10005], R[10005];
void make() {
	F[0] = 1;
	for (int i = 1; i<10005; i++) F[i] = F[i - 1] * i%mod;
	for (int i = 0; i<10005; i++) R[i] = powmod(F[i], mod - 2,mod);
}
LL C(int a, int b) {
	return F[a] * R[b] % mod*R[a - b] % mod;
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> a >> b >> c;
	make(); 
	LL ret = 0, ret2 = 0, ret3 = 0;

	for (int x = 0; x <= min(a, b); x++) {
		ret += C(a, x) * C(b, x) % mod * F[x] % mod;
		ret %= mod;
	}
	for (int x = 0; x <= min(c, b); x++) {
		ret2 += C(c, x) * C(b, x) % mod * F[x] % mod;
		ret2 %= mod;
	}
	for (int x = 0; x <= min(a, c); x++) {
		ret3 += C(a, x) * C(c, x) % mod * F[x] % mod;
		ret3 %= mod;
	}
	cout << (ret*ret2%mod*ret3%mod)%mod << endl;

	return 0;
}