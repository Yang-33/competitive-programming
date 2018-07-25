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

/* -----  2018/07/26  Problem: AOJ 0257 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0257  ----- */
/* ------問題------

openとcloseの命令

-----問題ここまで----- */
/* -----解説等-----

場合分けをします。

----解説ここまで---- */

template<class T> using V = vector <T>; template <class T> using VV = V<V<T>>;


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	V<int>a(3);
	FOR(i, 0, 3) {
		cin >> a[i];
	}
	if (a[0] == 1 && a[1] == 1 && a[2] == 0) {
		cout << "Open" << endl;
	}
	else if (a[0] == 0 && a[1] == 0 && a[2] == 1) {
		cout << "Open" << endl;
	}
	else {
		cout << "Close" << endl;
	}

	return 0;
}