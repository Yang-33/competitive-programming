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

/* -----  2018/07/29  Problem: yukicoder 175  / Link: http://yukicoder.me/problems/no/175  ----- */
/* ------問題------

A君はとても単純なDNAで知られるsimpleDNAの研究をしています。
simpleDNAの特徴は次のようなものです。

・simpleDNAは普通のDNAと同じく分岐しない塩基配列を持ちます。
・simpleDNAはとてもシンプルなので'A'と'B'の２種の塩基で構成されています。
・simpleDNAはとてもシンプルなので塩基配列の長さはせいぜい30までです。
・simpleDNAの塩基配列の長さはかならず3の倍数です。

このようなsimpleDNAからA君は次のようなsimpleDNAを探しています。

・塩基配列の末端が指定された終止コドンで終わるもの。

コドンとは3つの塩基配列の組み合わせのことを言います。
要は、最後の3つの塩基配列が終止コドンとして指定されるということです。
長さLと候補の終止コドンがいくつか指定されます。
このような条件を満たすsimpleDNAは何パターンありうるでしょうか？

※なお、普通のDNAについての説明はこちらをご覧ください。
http://en.wikipedia.org/wiki/DNA

-----問題ここまで----- */
/* -----解説等-----

おしりが一致することはないので、N*2^{L-3}個だけ別のものが存在する。

----解説ここまで---- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);


	int L, N; cin >> L >> N;
	VS vs(N);
	FOR(i, 0, N) { cin >> vs[i]; }

	LL ans = N*pow(2,L-3);
	cout << ans << "\n";

	return 0;
}
