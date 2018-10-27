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

/* -----  2018/10/24  Problem: ARC 035 C / Link: http://arc035.contest.atcoder.jp/tasks/arc035_c  ----- */
/* ------問題------

高橋くん様は、アットコーダー王国の王様です。彼が統治するアットコーダー王国は、1 から N までの番号が付けられた N 個の都市とそれらを結ぶ双方向に行き来可能な M 本の道路からなります。それぞれの道路には長さがあります。 アットコーダー王国の任意の都市の組み合わせ (A,B) について、A からいくつかの道路を辿って B に辿り着けることが保障されています。
高橋くん様は、アットコーダー国民の幸せが、交通の利便性に大きく依存していると考えています。 国民がどれくらい幸せかを調べるために、ありうる全ての都市間の最短経路長の総和 S を求めたいと思っています。
都市 i と j の間の最短経路長を D(i,j) とすれば S は、と表されます。
また、高橋くん様は公共事業で、K 本の新たな道路を建設しようと思っています。 この建設によって、ある都市間を直接結ぶ道路が 2 本以上存在してしまうことがありますが、その場合、既にある道路は取り壊さず、新しく追加します。
あなたの仕事は、新たな道路を与えられた順番に建設していき、建設の度に前述の S を計算するプログラムを書くことです。

-----問題ここまで----- */
/* -----解説等-----

iを経由とすればO(N^2)で更新可能
同じ：http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0526

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);


	// 連結
	LL N, M; cin >> N >> M;
	VVL dist(N, VL(N, LINF));
	FOR(i, 0, N)dist[i][i] = 0;
	FOR(i, 0, M) {
		LL a, b, c; cin >> a >> b >> c;
		a--, b--;
		dist[a][b] = dist[b][a] = min(dist[a][b], c);
	}
	FOR(k, 0, N) {
		FOR(i, 0, N) {
			FOR(j, 0, N) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	int K; cin >> K;
	FOR(_, 0, K) {
		LL a, b, c; cin >> a >> b >> c;
		a--, b--;
		dist[a][b] = dist[b][a] = min(dist[a][b], c);
		//k 固定なので
		VL ks({a,b});
		for (int k : ks) {
			FOR(i, 0, N) {
				FOR(j, 0, N) {
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}
		LL ans = 0;
		FOR(i, 0, N) {
			FOR(j, i + 1, N) {
				ans += dist[i][j];
			}
		}
		cout << ans << "\n";
	}



	return 0;
}
