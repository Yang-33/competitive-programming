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

/* -----  2018/07/30  Problem: yukicoder 185  / Link: http://yukicoder.me/problems/no/185  ----- */
/* ------問題------

諸外国では，○＋□＝8のように，答えがたくさんある問題があるようですが，採点が大変ですよね．
そこで，やっぱり和風に答えが一意定まるように条件を加える事としましょう．
おや，条件を加えすぎたかもしれません．
N 個の正整数の 2 つ組 (X1,Y1),(X2,Y2),…,(XN,YN) が与えられるので，
　　□ +Xk=Yk,k=1,2,…,N
  を同時に満たす□に当てはまる正整数を求めてください．

-----問題ここまで----- */
/* -----解説等-----

解の候補を全部集めておき、これが1つよりも大きいor生でないなら-1を出力する。

----解説ここまで---- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N; cin >> N;
	map<LL, LL>Map;
	FOR(i, 0, N) {
		LL x, y; cin >> x >> y;
		Map[y-x]++;
	}

	if (SZ(Map) == 1 && (*Map.begin()).first > 0) {
		cout << (*Map.begin()).first << endl;
	}
	else {
		cout << -1 << endl;
	}

	return 0;
}
