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

/* -----  __MAKE_TIME__  Problem: __PROBLEM__ / Link: __CONTEST_URL__  ----- */
/* ------問題------

ある日、ドワンゴ社員のニワンゴくんは、長さ N の整数列 (a1,…,aN) を見つけました。ニワンゴくんは、数列 a の性質に興味を持っています。
数列 a の空でない連続する部分列 al,…,ar (1≤l≤r≤N) の 美しさ は、 al+…+ar と定義されます。ニワンゴくんは、ありうる N(N+1)⁄2 個の空でない連続する部分列のうち、 K 個を選んで取ってきて、それらの美しさのビット毎の論理積 (AND) を計算したとき、その最大値がどうなるかを知りたがっています (取ってくる部分列の間で重複する要素があっても構いません)。
彼の代わりに最大値を求めてください。

-----問題ここまで----- */
/* -----解説等-----

K個以上あるかだけ、見れば良い。

----解説ここまで---- */

int main() {
	cin.tie(0); 
	ios_base::sync_with_stdio(false);

	int N, K; cin >> N >> K;
	VI a(N);
	FOR(i, 0, N) {
		cin >> a[i];
	}
	VL sums(N + 1, 0); {
		FOR(i, 0, N) {
			sums[i + 1] = sums[i] + a[i];
		}
	}
	auto query = [&sums](int l , int r) {
		return sums[r] - sums[l];
	};
	VL subs; {
		FOR(i, 0, N) {
			FOR(j, i + 1, N+1) {
				subs.push_back(query(i, j));
			}
		}
	}
	DD(De(subs));
	N = SZ(subs);
	for (int i = 60; i >= 0; i--) {
		vector<LL> X;

		for (auto& r : subs) {
			if (r&(1LL << i)) {
				X.push_back(r);
				r ^= 1LL << i;
			}
		}

		if (X.size() >= K) subs = X;
	}

	cout << subs[0] << endl;

	return 0;
}
