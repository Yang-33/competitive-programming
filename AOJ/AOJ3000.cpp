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

/* -----  2018/07/05  Problem: AOJ 3000 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/3000  ----- */
/* ------問題------

与えられた2つの角度θ1,θ2 のちょうど間の角度を求めよ。ここで、ちょうど間の角度を、下図のように「θ1 + t = θ2 − t を満たすtのうち絶対値が最も小さいものをt’としたときのθ1 + t’」と定義する。

-----問題ここまで----- */
/* -----解説等-----

問題文をそのまま実装する。角度がヤバそうなので適宜調節する。

----解説ここまで---- */

int f(int a) {
	int ret = a;
	ret += 7200;
	return ret % 720;
}
void solve() {

	int S1, S2;
	cin >> S1 >> S2;

	int ans = INF;
	S1 *= 2;
	S2 *= 2;
	if (S1 > S2) {
		S2 += 720;
	}
	int Mint = INF;
	int subans = INF;
	for (int t = -720; t < 360 * 2; t++) {
		if (f(S1 + t) == f(S2 - t)) {
			if (Mint >= abs(t)) {
				Mint = abs(t);
				subans = S1 + t;
			}
		}

	}
	while (subans >= 720) {
		subans -= 720;
	}
	while (subans < 0) {
		subans += 720;
	}
	ans = subans;
	cout << ans / 2.0 << endl;
}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	solve();

	return 0;

}