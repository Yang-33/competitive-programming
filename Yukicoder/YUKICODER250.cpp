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

/* -----  2018/08/26  Problem: yukicoder 250  / Link: http://yukicoder.me/problems/no/250  ----- */
/* ------問題------

atetubouくんはコンテストに参加している真っ最中です。
atetubouくんは実装が重い問題をなんとかコンテスト終了3分前にコーディングしおわりサブミットしようとしているところです。
頑張って書いたコードがTLEすると悲しくなってしまうので改善しようとコード見直すことにしました。
今取り組んでいる問題の時間がかかりそうなところはfor文を何重にも回すところで以下のようになっています。

for i <- 0..X 
	for j <- 0..X 
	   for k <- 0..X 
		  for l <- 0..X 
			  if i + j + k + l== X: 
				 //program 

atetubouくんはこのコードが以下のように改善できることに気づきました。

for i <- 0..X 
	for j <- 0..(X-i) 
	   for k <- 0..(X - i - j) 
		  l <- X - i - j - k
		  //program 

atetubouくんは改善したところでコンテスト終了まで残り10秒になりました。
//programの部分に入る回数がT回だと間に合うと見積もったatetubouくんはどのくらい入るか調べることにしました。
atetubouくんのコードは無事ACされるのでしょうか。
programの部分では、変数Xの書き換えは行われず、breakなどでループが抜けることはないとする。

-----問題ここまで----- */
/* -----解説等-----

組合せで解ける。和がXになるようにD-1個の変数を用いるので、(D-1+X)C(D-1)が組み合わせの回数。
modを取らないと死ぬので、適当に上限を設定する。

! 
また、文字通り組み合わせなので、dp(i,j):=i変数でXを割り振る組み合わせ数として、
dp(i+1,j):=dp(i,[0,j])のO(N^2)dpでも解ける。

----解説ここまで---- */

#define nCk_MAX 3030
long long  comb[nCk_MAX + 1][nCk_MAX + 1];
/* nCk を求める */
void calcomb() {
	int  i, j;
	for (i = 0; i <= nCk_MAX; i++) {
		for (j = 0; j <= i; j++) {
			if (j == 0 || j == i)
				comb[i][j] = 1;
			else {
				comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
				if (comb[i][j] >= 1e16)comb[i][j] = 1e16;
			}
		}
	}
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	calcomb();
	int Q; cin >> Q;
	FOR(_, 0, Q) {
		LL D, X, T; cin >> D >> X >> T;
		cout << (comb[X+D-1][D-1]<=T?"AC":"ZETUBOU") << "\n";
	}

	return 0;
}
