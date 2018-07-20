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

/* -----  2018/07/23  Problem: AOJ 0299 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0299  ----- */
/* ------問題------

わたしの住む街には、図のような N 個の駅からなる円環状の鉄道路線があります。この路線の各駅には 0 から N-1 までの番号が順番に割り当てられていて、隣の駅まで100 円で移動することができます。移動はどちらの方向にでも可能です。
わたしはこの路線上のいくつかの駅で買い物をしたいと思っています。そこで、プログラムを作成して移動費を計算することにしました。ある駅を始点として、買い物をするすべての駅を訪問する最小の費用（円）を求めるプログラムを作成してください。ただし、同じ駅を何度訪問しても良く、どのような順番で駅を訪問しても構いません。

-----問題ここまで----- */
/* -----解説等-----

やっかい感がある。
Pを含む環をcutすると見て良い。
このとき、cutした場所の右端と左端を、Pの剰余環での距離を求めれば良い。
Pをいれておくと、往復しないパターンも考慮できてしまうので、うれぴい。

----解説ここまで---- */

template<class T> using V = vector<T>; template<class T> using VV = V<V<T>>;


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, M, P; cin >> N >> M >> P;
	V<LL>pos(M);
	FOR(i, 0, M) {
		cin >> pos[i];
	}
	pos.push_back(P);
	LL ans = 1e18;
	// M-1回の移動を
	SORT(pos);
	pos.push_back(pos[0]);//i+1
	FOR(i, 0, SZ(pos) - 1) {
		LL L = pos[i] - P;
		if (L < 0)L += N;
		LL R = P - pos[i + 1];
		if (R < 0)R += N;
		ans = min({ ans, R * 2 + L,2 * L + R });
	}

	ans *= 100;
	cout << ans << endl;
	return 0;
}
