#include "bits/stdc++.h"
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

/* -----  2017/10/18  Problem: 20_b  / Link:  http://joi2011ho.contest.atcoder.jp/tasks/joi2011ho2 ----- */
/* ------問題------

あなたの町には JOI 古本店という老舗の古本屋があり，あなたは JOI 古本店をよく利用している．それ
ぞれの本には基準価格が定まっており，JOI 古本店に行けばその価格で買い取ってもらえる．
JOI 古本店では，本を小説・漫画・雑誌など 10 種類のジャンルに分類して扱っている．ジャンルには 1
から 10 までの番号が付けられている．JOI 古本店には，同じジャンルの本をまとめて買い取ってもらうと
高値で買い取ってくれるというサービスがある．具体的には，同じジャンルの本をまとめて T 冊買い取っ
てもらう場合，そのジャンルの本の一冊あたりの買取価格が基準価格より T − 1 円高くなる．例えば，同
じジャンルで基準価格 100 円，120 円，150 円の本をまとめて JOI 古本店に売ったとすると，買取価格はそ
れぞれ 102 円，122 円，152 円となる．
さて，あなたは一身上の都合で急遽引越しをすることになった．あなたは N 冊の本を持っているが，新し
い住居にすべての本を持っていくことは困難なため，N 冊の本のうち K 冊を JOI 古本店に売ることにした．

-----問題ここまで----- */
/* -----解説等-----

値段の上昇の仕方から、各ジャンルの本については貪欲にとっていった方がいいことが分かる。
あとは組み合わせを特定することはできないのでDPをする。
dp[x]:=x冊での最大値

----解説ここまで---- */

LL N, K;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> K;
	VL c(N);
	VL g(N);
	VVL v(10, VL());
	FOR(i, 0, N) {
		cin >> c[i] >> g[i];
		g[i]--;
		v[g[i]].push_back(c[i]);
	}
	FOR(i, 0, 10) {
		RSORT(v[i]);
	}
	VL dp(K + 1, 0);
	FOR(i, 0, 10) {
		FORR(j, K, -1) {
			LL sum = 0;
			FOR(k, 0, SZ(v[i])) {
				sum += v[i][k];
				int nx = j + k + 1;
				if (nx > K)continue;
				dp[nx] = max(dp[nx], dp[j] + sum + (k + 1)*k);
			}
		}
	}


	ans = dp[K];
	cout << ans << "\n";

	return 0;
}