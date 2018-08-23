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

/* -----  2018/08/23  Problem: yukicoder 218  / Link: http://yukicoder.me/problems/no/218  ----- */
/* ------問題------

P君は、とあるソーシャルゲームで遊んでいます。

あるキャラクターをレベル最大まで強化するのに a だけ経験値が必要だとします。
強化素材ひとつで、キャラクターの経験値を b だけ上昇させることができます。
ときおり、「経験値1.5倍キャンペーン」というのが開催され、
このキャンペーンの期間中は強化素材ひとつで c だけ経験値を上昇させることができます。
(c=1.5bではない時もあリます。)
P君は、
キャンペーン期間中はレベル最大まで強化するのに必要な強化素材の数が、
通常期間に比べて 2/3 の割合で足りるのではないか（つまり、2/3 以下の個数で十分）
という仮説を立てました。

この仮説が正しいかどうかを判定してください。
ただし、ひとつの強化素材を必要な分だけ分割して使用する、ということはできません(サンプル2を参照)。

-----問題ここまで----- */
/* -----解説等-----

式を書くと、整数X,Yに対して、
BX≧A,CY≧A,X*2/3≧Yであれば仮設が正しい。

----解説ここまで---- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int A, B, C; cin >> A >> B >> C;
	int X = (A + B - 1) / B;
	int Y = (A + C - 1) / C;
	cout << (2*X>=3*Y? "YES" : "NO") << endl;

	return 0;
}
