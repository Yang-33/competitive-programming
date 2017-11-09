#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <set>
#include <sstream>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <climits>
#include <list>
#include <fstream>
using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef vector<string> VS;

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

/* -----  2017/11/10  Problem: POJ 3688 / Link: http://poj.org/problem?id=3688  ----- */
/* ------問題------

N枚のカードがあって各カードにはa[i]が書かれている。
プレイヤーはランダムにカードを選択し、カードに書かれている数石をとり、カードを削除する。
この時、石が最初に何個あれば先手必勝か。
M以下で何個選べるかを出力せよ。

-----問題ここまで----- */
/* -----解説等-----

勝ち負けを状態の結果として持って、
dp[のこり][player]:= 1:かち,0:まけとしてあとはメモリを潤沢に使った
基本DPをしていけばよい。
その結果から、先が勝ち後が負ける盤面の数をかぞえればよい。

10^9で通るのやめて

----解説ここまで---- */

LL N,M;

LL ans = 0LL;
bool dp[100005][2];
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	while (cin >> N >> M, N) {
		VI a(N);
		FOR(i, 0, N)cin >> a[i];
		//Alice が勝つWは何通りあるか
		fill(*dp, *dp + 100005 * 2, 0);
		// dp[のこり][player]:= 1:かち,0:まけ
		dp[0][1] = 1;
		FOR(i, 0, N) {
			FORR(j, M, a[i]-1) {
				if (dp[j-a[i]][0] == 1)dp[j][1] = 1;
				if (dp[j-a[i]][1] == 1)dp[j][0] = 1;
			}
		}
		ans = 0;
		FOR(i, 1, M + 1) {
			if (dp[i][0] == 1 && dp[i][1] == 0)ans++;
		}
		cout << ans << endl;
	}
	return 0;
}
