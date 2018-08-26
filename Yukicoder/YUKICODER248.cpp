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

/* -----  2018/08/26  Problem: yukicoder 248  / Link: http://yukicoder.me/problems/no/248  ----- */
/* ------問題------

ミラー君は，ある N 個の互いに異なる奇素数 p1,p2,...,pN によって計算された 2 つの積，
P=∏i=1Npi,  Q=∏i=1N(pi−1)

を受け取った時に，手計算で P を素因数分解する宿題をしなくてはいけません．

ミラー君は，調子の良いときには，ある数が素数であるかどうかについては一瞬で正しく判断することができるのですが，素因数分解は得意ではありません．

あなたはミラー君の手助けをするため，以下のような乱択アルゴリズムを教えることにしました．

乱択アルゴリズム: F(P,Q) 
入力: 正の整数 P,Q
出力: P の素因数の集合
P が 1 であれば，空集合 ∅ を返す．
P が素数であれば，{P} を返す．
それ以外の場合は，0<r≤P なる正の整数 r を一様ランダムに選択し，g=gcd(r,P) を計算して，
g=P であったならば，F(P,Q) を返す．
1<g<P であったならば，F(g,Q)∪F(P/g,Q) を返す．
g=1 であったならば，Q を奇数 q と非負整数 e を用いて，Q=2e×q と書き直し，c=rq(modP) を計算する．次に，c2≠1(modP) である限り，c←c2(modP) と更新し続ける．その後，
1<c<P−1 であったならば，h=gcd(c−1,P) として，F(h,Q)∪F(P/h,Q) を返す．
c=1 または c=P−1 であったならば，F(P,Q) を返す．

乱択アルゴリズムを教えてもらったミラー君ですが，F(P,Q) の計算によって P の素因数分解を得ようとしたときに，関数 F が再帰的に何回呼び出されるのか予想できず，その不安から未だに宿題に手を付けることができていません．

そこであなたはミラー君を安心させるために，F(P,Q) の計算が停止するまでに関数 F が呼び出される回数の期待値 E を教えることにしました． 


-----問題ここまで----- */
/* -----解説等-----

大変厳しい　パスで良さそう

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	cout << ans << "\n";

	return 0;
}
