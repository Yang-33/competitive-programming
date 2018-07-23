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

/* -----  2018/07/23  Problem: AOJ 2005 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/2005  ----- */
/* ------問題------

21XX 年，ついに人類は火星への移住計画を開始させた．火星への移住第一陣に選抜されたあなたは，火星行政中央局（the Administrative Center of Mars）に配属され，火星で起こる様々な問題に対処している．行政中央局の目下の最大の問題は自立した需要供給サイクルの確保である．月からの援助物資が届くまでには数ヶ月単位の時間がかかるため，基本的には火星内の需要は火星内で解決する必要がある．それに加えて，循環システムを確立するまでは資源を極力節約することが求められる．
行政中央局は極地にある氷の採掘を開始した．太陽光でこれを溶かし，水として個々の基地に供給することが最終目標である．最初の段階として，水源のある基地から2つの主要基地までの導水管を敷設することにした．また，現時点ではいくつかの基地とそれらを結ぶ道路以外には開拓されておらず，未開拓のところに導水管を敷設するには多大なるコストと燃料を要するため，道路に沿って導水管を敷設することにした．さらに，技術上の制約のため，彼らの導水管は常に一方向だけに水が流れる．
あなたの仕事は，これらの条件のもとで，導水管の敷設にかかるコストを最小にするプログラムを作成することである．

-----問題ここまで----- */
/* -----解説等-----

日本語が悪いのでSやGiから水が分かれるとも取れる。
×彼らの導水管は常に一方向だけに水が流れる
○頂点を流れる水は常に一方向である
頂点について一方向だと、分岐点を全探索するのみ。

----解説ここまで---- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);


	int N, M, S, G1, G2;
	while (cin >> N >> M >> S >> G1 >> G2,N) {
		const int intINF = 2e9 / 3;
		VVI dist(N, VI(N,intINF ));
		S--, G1--, G2--;
		FOR(i, 0, N)dist[i][i] = 0;
		FOR(i, 0, M) {
			int a, b, c; cin >> a >> b >> c; a--; b--;
			dist[a][b] = c;
		}
		FOR(k, 0, N)FOR(i, 0, N)FOR(j, 0, N)dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
		int ans = INF;
		FOR(i, 0, N) {
			ans = min(ans, dist[S][i] + dist[i][G1] + dist[i][G2]);
		}
		cout << ans << "\n";

	}

	return 0;
}
