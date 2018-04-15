#include <bits/stdc++.h>
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

/* -----  2018/04/15  Problem: yukicoder 063  / Link: http://yukicoder.me/problems/no/063  ----- */
/* ------問題------

ハルカちゃんとユウちゃんはとっても仲良しなので、２人でポッキーゲームをすることにしました。
長さが L(mm) のポッキーを２人はそれぞれ両端から中央に向かって齧っていきます。
２人とも毎回 K(mm) ずつ同じタイミングでポッキーを齧ります。
ユウちゃんは恥ずかしがり屋さんなので、
次のタイミングで２人ともポッキーを齧ろうとしたら唇が触れてしまうと分かった時点で齧り進めるのを止めて、
残りは全部ハルカちゃんが食べてしまいます。
このとき、ユウちゃんが食べるポッキーの長さは何mmか？

-----問題ここまで----- */
/* -----解説等-----

ちょうどふたりがKmmずつたべて唇が触れないようにするとき、L-1の長さを考えれば良い。  
ターン数は(長さ)/(2K)であるから、食べる長さは(L-1)/(2K)*Kとなる。

----解説ここまで---- */

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL L, K; cin >> L >> K;

	ans = (L - 1) / (2 * K) *K;
	cout << ans << "\n";

	return 0;
}
