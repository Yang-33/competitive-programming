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

/* -----  2018/05/03  Problem: yukicoder 143  / Link: http://yukicoder.me/problems/no/143  ----- */
/* ------問題------

yukiさんは一袋 K 粒だけ豆が入った袋を N 袋拾いました．
ところで，節分には年齢の数だけの豆を食べる習慣があります．
yukiさんの家族は F 人家族で，それぞれの年齢は A1,A2,…,AF 歳です．
それぞれが年齢の数だけの豆を食べたら最終的に何粒残るかを求める下さい．
ただし，全員が年齢の数だけ豆を食べることができないなら -1 を出力して下さい．

-----問題ここまで----- */
/* -----解説等-----

やっていく。

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int K, N, F; cin >> K >> N >> F;
	int ans = K*N;
	FOR(i, 0, F) {
		int a; cin >> a;
		ans -= a;
	}
	cout << (ans>=0?ans:-1) << "\n";

	return 0;
}
