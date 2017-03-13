#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

typedef long long ll;
#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)

/* -----  2017/03/13  calclem: ARC055 / Link: http://arc055.contest.atcoder.jp/tasks/arc055_b ----- */
/* ------問題------

シカのAtCoDeerくんはせんべいが好きです。今、AtCoDeerくんは1‾Nの番号のついたN枚のせんべいをくれると噂の高橋くんに目をつけました。
番号が大きい方が大きくて価値があるので、AtCoDeer君は番号Nのせんべいは絶対に食べたいと考えました。
しかし、AtCoDeerくんはお腹がいっぱいになるためK枚までしかせんべいを食べることが出来ません。
高橋くんは事前にN枚のせんべいを並び替え、一枚ずつ順にせんべいをAtCoDeerくんにあげようとします。
AtCoDeerくんはi(1≦i≦N)枚目をもらうとき、そのせんべいを食べるかどうかをその時点で選択します。
しかし、既にK枚食べている場合は、これ以上食べることは出来ません。
食べない場合は高橋くんがそのせんべいを食べるので、後になってAtCoDeerくんがそのせんべいを食べることは出来ません。
AtCoDeerくんはせんべいを見てもその番号はわかりませんが、既に見た(食べたものも含む)全てのせんべいの大小を比べることは出来ます。
高橋くんがせんべいをあげる順番はランダム(N!個の順列のうちから等確率で選ばれる)で、AtCoDeerくんには事前にはわかりません。
AtCoDeerくんが最適な戦略をとった時、最終的に番号NのせんべいをAtCoDeerくんが食べられる確率を求めてください。

-----問題ここまで----- */
/* -----解説等-----

状態の遷移はある時点で食べる食べないであり、Ｎを食べたものを足して返却する。
dp [ これからstep番目を見るときに ][ あとk枚食べられる際に ] := Ｎがまだ選択されておらず、Ｎを選択する確率
としていく。Ｎを食べたら推移は終了してその値で終わりであるから 49 行目はこのような確率となっている。
最初は部分増加列に対する組み合わせ確率で求められると思い、とても時間がかかった。

----解説ここまで---- */

int N,K;
double memo[1010][1010];
ll ans = 0LL;

double dfs(int step, int k) {
	if (k <= 0) return 0;
	if (k >= N - step + 1) return 1; //食べられる
	if (memo[step][k] >= 0) return memo[step][k];

	int left = N + 1 - step; //見る前に何枚残っているか

	double yes = 1.0 / left; //このうち１枚が N
	double fake = (1 - yes) / step; //大きいがNではなく、今回も含めた中での最大
	double no = 1 - fake - yes; //最大ではない


	double take = (yes * 1 + fake*dfs(step + 1, k - 1)); //食べる　　(49)
	double nottake = (fake*dfs(step + 1, k)); //高いがNでなく、それを食べないとき

	return memo[step][k] = no*dfs(step + 1, k) + max(take, nottake);
}


int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N>>K;
	FOR(i, 0, 1010)FOR(j, 0, 1010)memo[i][j] = -1;

	printf("%.15f¥n", dfs(1, K));
	
	return 0;
}
