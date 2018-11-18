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

/* -----  2018/11/18  Problem: ARC 052 B / Link: http://arc052.contest.atcoder.jp/tasks/arc052_b  ----- */
/* ------問題------

3次元空間( xyz 空間)上に N 個の円錐が互いに重なり合わないように浮いています。
どの円錐も底面が yz 平面と平行で、x 軸の正の方向にとがっています。
i 番目の円錐の底面の中心の x 座標の値は Xi で半径は Ri 、高さは Hi です。
以下のクエリに Q 個答えてください。
2 つの整数 A と B が与えられるので A≦x≦B となる空間の内いずれかの円錐の内側にある部分の体積をもとめよ。

-----問題ここまで----- */
/* -----解説等-----

愚直O(QN)をします
体積を求める際に変化する円錐の半径は比で求める事ができる。

----解説ここまで---- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, Q; cin >> N >> Q;
	vector<int>X(N), R(N), H(N);
	FOR(i, 0, N) {
		cin >> X[i] >> R[i] >> H[i];
	}
	auto f = [](double h, double r) {
		return r * r*PI*h / 3;
	};
	auto rr = [](double XS, double XT, double R, double X) {
		return (XT - X) / (XT - XS)*R;
	};
	FOR(_, 0, Q) {
		int a, b; cin >> a >> b;
		double ans = 0;
		FOR(i, 0, N) {
			int XS = X[i];
			const int XT = X[i] + H[i];
			if (b <= XS || XT <= a)continue;
			XS = max(XS, a);

			ans += f(XT - XS, rr(X[i],XT,R[i],XS));
			{
				int Cut = min(XT, b);
				double val = f(XT - Cut, rr(X[i], XT, R[i], Cut));
				ans -= val;
			}


		}
		cout << fixed << setprecision(10) << ans << endl;
	}

	return 0;
}
