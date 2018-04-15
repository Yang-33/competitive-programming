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

/* -----  2018/04/15  Problem: yukicoder 067  / Link: http://yukicoder.me/problems/no/067  ----- */
/* ------問題------

ユキさんは N 本の棒を持っていて、i 番目の棒の長さは Li です。
棒は（長さを分割する方向に）自由に切ることができますが、繋げることはできません。
ユキさんは同じ長さの K 本の棒を作りたいのです。
作れる K 本の棒の長さの最大値を求めるプログラムを書いて下さい。

-----問題ここまで----- */
/* -----解説等-----

f(x):=長さxの棒をK本以上作れるかとすると小さいxについて単調性があるので、これを二分探索する。

----解説ここまで---- */


bool f(double x, LL K, VL& L) {
	LL ret = 0;
	FOR(i, 0, SZ(L)) {
		ret += L[i] / x;
	}
	return ret >= K;
}
LL N;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	VL L(N);
	FOR(i, 0, N) {
		cin >> L[i];
	}
	LL K; cin >> K;
	double ok = 0; double no = 1e11;
	FOR(i, 0, 100) {
		double mid = (no - ok) / 2 + ok;
		if (f(mid, K, L)) {
			ok = mid;
		}
		else
			no = mid;
	}

	double ans = ok;
	cout << fixed << setprecision(10) << ans << "\n";

	return 0;
}
