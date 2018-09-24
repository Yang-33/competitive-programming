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

/* -----  2018/09/23  Problem: CodeForces512 D div2 / Link: http://codeforces.com/contest/1058/problem/D  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

1/2 |x1y2-x2y1 | = N*M/K が成り立つためには、左辺を変更して割り切れればよい。
そこまではわかっていたけどあとは必ず作れると言い切れなかった。
作れるとすると、必ず分割可能で、割り切れると言えているので適当にgcdをつかって分割できる。

解けるだろ！！！！！

----解説ここまで---- */

LL gcd(LL x, LL y) {
	return __gcd(x, y);
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL W, H, K; cin >> W >> H >> K;

	if (2*W*H%K) {
		cout << "NO" << endl;
	}
	else {
		int even = 0;
		if (K % 2 == 0)K /= 2,even = 1;


		LL g = gcd(W, K);
		K /= g;
		LL A = W / g;

		LL B = H / K;
		if (!even) {
			if (A + A <= W) {
				A += A;
			}
			else if (B + B <= H) {
				B += B;
			}
			else {
				assert(0);
			}
		}
		cout << "YES" << endl;
		cout << 0 << " " << 0 << endl;
		cout << 0 << " " << B << endl;
		cout << A << " " << 0 << endl;
	}


	return 0;
}
