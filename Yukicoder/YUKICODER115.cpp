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

/* -----  2018/04/24  Problem: yukicoder 115  / Link: http://yukicoder.me/problems/no/115  ----- */
/* ------問題------

直樹くんは遠足のおやつを買いに駄菓子屋さんに来ました。
駄菓子屋さんは 1,2,3…N 円の N 種類のお菓子を売っています。

直樹くんが買えるおかしは合計で D 円までで、買える個数は K 個までです。
いっぱいおかしが食べたい直樹くんは次のルールを追加しました。

お金があまったらもったいないので、合計が D 円ぴったりになるようにおかしを買う
いっぱい食べたいので K 個おかしを買う
種類もいっぱい食べたいので、ある金額のおかしは買うなら 1 個までにする
このルールを満たすようなおかしの買い方で辞書順最小になるものを答えてください。
もしそのようなおかしの買い方がないなら −1 を出力してください。

辞書順最小についてはサンプルを参照してください。

-----問題ここまで----- */
/* -----解説等-----

dp[d][k]:= k枚でd円を作れるか?
としてDPして、最後に復元すれば良い。

また、貪欲でも解ける。  
使用できる金額が連続する整数であるから、解をもつならば小さい方から貪欲にやっても解ける。  


----解説ここまで---- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, D, K; cin >> N >> D >> K;
	VVI dp(D + 1, VI(K + 1, 0));
	dp[0][0] = 1;
	FOR(i, 1, N + 1) {
		FORR(k, K - 1, 0 - 1) {
			FOR(d, 0, D) {
				if (d + i <= D)dp[d + i][k + 1] |= dp[d][k];
			}
		}
	}
	if (dp[D][K]) {

		LL ans = 0LL;
		VI a;
		int leftD = D; int leftK = K;
		FOR(i, 1, N + 1) {
			if (leftD - i >= 0 && leftK > 0 && dp[leftD - i][leftK - 1]) {
				a.push_back(i);
				leftD -= i;
				leftK--;
			}
		}
		FOR(i, 0, K) {
			cout << a [i]<< " \n"[i==K-1];
		}
	}
	else {
		cout << -1 << endl;
	}

	return 0;
}
