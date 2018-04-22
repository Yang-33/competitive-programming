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

/* -----  2018/04/19  Problem: yukicoder 093  / Link: http://yukicoder.me/problems/no/093  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

重要な点として愚直に状態を管理すると2^{N}だけメモリが必要。 
またコマを一箇所に置くとその縦横には置けない、置いたコマの2つ上のマスの段では3つだけ場所が制限される。  
このままでは厳しいので問題を次のように読み替える。  
コマを置いたy座標を数字と見ると、禁止条件は|yi-yj|=2なので、  
隣接する数字の差が2でないように1~Nの数字を並び替えたときの組み合わせ数を求めろ。という問題になる。  

これは挿入DP?と呼ばれるもので解くことができて、条件をみたしていないものを状態に含めるとかなり計算量が落ちる。  
dp(i,j,x,y):=1~iまで入れて、j個条件を満たさないものがあり、かつその中に[x:i-2,i-4],[y:i-1,i-3]が隣接しているか否か  
箱根(AOJ)は理解できなかったけど、この問題を解いて挿入DPを理解できた。

----解説ここまで---- */

LL N;
LL ans = 0LL;

LL dp[1003][1003][2][2];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	dp[1][0][0][0] = 1;
	dp[2][0][0][0] = 2;
	// dp(i,j,x,y):=iまで入れて、j個ダメがあり、かつその中にx:i-2,i-4,y:i-1,i-3,が隣接しているか否か
	FOR(i, 2, N) {
		FOR(j, 0, N) {


			{
				LL dp00 = dp[i][j][0][0];
				dp[i + 1][j + 1][0][1] += (2)*dp00; // o i-2 o
		   if(j)dp[i + 1][j - 1][0][0] += (j)*dp00; // [j]
				dp[i + 1][j    ][0][0] += (i - j - 1)*dp00; // other
			}
		    if(j){
				LL dp01 = dp[i][j][0][1];
				dp[i + 1][j - 1][0][0] += (1)*dp01; // i-1 o i-3
				dp[i + 1][j + 1][1][1] += (2)*dp01; // o i-2 o
				dp[i + 1][j - 1][1][0] += (j - 1)*dp01; // [j]
				dp[i + 1][j    ][1][0] += (i - j - 1)*dp01; // other 
			}
			if(j){

				LL dp10 = dp[i][j][1][0];
				dp[i + 1][j-1+1][0][1] += (1)*dp10; // i-2 o i-4
				dp[i + 1][j + 1][0][1] += (1)*dp10; // o i-2 i-4
				dp[i + 1][j - 1][0][0] += (j - 1)*dp10; // [j]
				dp[i + 1][j   ][0][0] += (i - j)*dp10; // other 
			}
			if(j){
				LL dp11 = dp[i][j][1][1];
				dp[i + 1][j-1+1][1][1] += (1)*dp11; // i-2 o i-4
				dp[i + 1][j + 1][1][1] += (1)*dp11; // o i-2 i-4
				dp[i + 1][j - 1][0][0] += (1)*dp11; // i-1 o i-3
				dp[i + 1][j - 1][1][0] += (j - 2)*dp11; // [j]
				dp[i + 1][j    ][1][0] += (i - j)*dp11; // other 
			}
		}
		// mod
		FOR(j, 0, N + 1)FOR(x, 0, 2)FOR(y, 0, 2)dp[i + 1][j][x][y] %= MOD;
	}




	ans = dp[N][0][0][0]%MOD;
	cout << ans << "\n";

	return 0;
}