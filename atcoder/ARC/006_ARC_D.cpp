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

/* -----  2018/12/15  Problem: ARC 006 D / Link: http://arc006.contest.atcoder.jp/tasks/arc006_d  ----- */
/* ------問題------

　高橋君は友人にこのようなパズルを出題されました。
 　まず、図 1 のような縦 7 マス・横 7 マスの 49 マスの白黒で作られた A,B,C の図形が与えられます。

  図 1：与えられる A,B,C の形
  　与えられる図の中に、先程の A,B,C の形がそれぞれいくつあるかを答えます。与えられる図に存在する黒マスは全て A,B,C のいずれかの一部であり、A,B,C 以外の図形は存在しません。 しかし、A,B,C は任意の正の整数倍に拡大した形も、同じ形とみなされます。そのため、図 2(a) の 3 つの A は全て A として数えられます。 加えて、図 2(b) のように、形が 90 度きざみで回転しているものも同じ形とみなされます。

   図 2(a)：2 倍、3 倍に拡大された A の例　　　図 2(b)：回転した A の例
   　なお、A,B,C の図形はまわりにある白マスの部分も含めてそのアルファベットと判断され、図 3 のように A を構成する縦 7 マス・横 7 マスと、別の図形である B を構成する縦 7 マス・横 7 マスが重なるような入力は与えられません。

	図 3：入力として与えられない他の図形が重なっている例
	　与えられる図の中から、A,B,C の図形がそれぞれいくつずつあるか答えなさい。

-----問題ここまで----- */
/* -----解説等-----

12*K^2,16*K^2,11*K^2の大きさになる。
よく睨むと、{3,1,11}*(k^2*m)の形になることが分かる。(二乗の和の積)
これがわかったのでbfsしながらサイズをカウントして、最後にサイズを縮小すれば良い。

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL H, W; cin >> H >> W;
	VS vs(H); FOR(i, 0, H) {
		cin >> vs[i];
	}
	VVI used(H, VI(W, 0));
	auto f = [&used,&vs,&W,&H](int Y,int X) {
		int res = 1;
		queue<PII>q;
		used[Y][X] = 1;
		q.push(PII(Y, X));
		while (!q.empty()) {
			int y, x; tie(y, x) = q.front(); q.pop();
			FOR(k, 0, 8) {
				int ny = y + DY[k], nx = x + DX[k];
#define IN(a,A) (0<=a&&a<A)
				if (IN(ny, H) && IN(nx, W)) {
					if (!used[ny][nx]&&vs[ny][nx]=='o') {
						used[ny][nx] = 1;
						res++;
						q.push(PII(ny, nx));
					}
				}
			}
		}

		return res;
	};
	auto g = [](int n) {
		for (int i = 2; i*i <= n; i++) {
			int p2 = i * i;
			while (n%p2==0){
				n /= p2;
			}
		}
		if (n == 3)return 0;
		if (n == 1)return 1;
		if (n == 11)return 2;
		assert(0);
	};
	VI ans(3,0);
	FOR(i, 0, H) {
		FOR(j, 0, W) {
			if (used[i][j]||vs[i][j]=='.')continue;
			int sz = f(i,j);
			int id = g(sz);
			ans[id]++;
		}
	}
	FOR(i, 0, 3) {
		cout << ans[i] << " \n"[i == 2];
	}

	return 0;
}
