#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<map>
#include<list>
#include<stack>
#include<queue>
#include<climits> //INT_MIN/MAX
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
#define FORR(i,s,e) for(ll (i)=(s);(i)>(e);(i)--)
#define MOD 1000000007
#define debug(x) cout<<#x<<": "<<x<<endl
typedef long long ll;

/* 2017/01/29 問題 ----- ABC036 D /Link http://abc036.contest.atcoder.jp/tasks/abc036_d */
/* -----解説等-----
問題: N 個の島があります。 島には 1 から N までの番号がついています。
また、N−1 個の橋があります。 i 番目の橋は ai 番の島と bi 番の島をつないでいます。
どの島からどの島へも橋をいくつか経由して到達できることがわかっています。

すぬけ君は、それぞれの島を白または黒に塗ることにしました。
ただし、両端の島が黒で塗られているような橋があってはいけません。
色の塗り方が何通りあるか、10^9+7 で割った余りを求めてください。

反省

*/

int N;
ll dp[100010][2];
vector<int>x[100010];
ll ans = 0;
enum { White, Black };

ll dfs(int v, int p, int c) {

	if (dp[v][c] >= 0)return dp[v][c];
	if (x[v].size() == 1 && x[v][0] == p)return 1;

	dp[v][c] = 1;
	FOR(i, 0, x[v].size()) {
		int w = x[v][i];

		if (w == p)continue;
		ll a = 0;
		a = (a + dfs(w, v, White)) % MOD;
		if (c != Black) {
			a = (a + dfs(w, v, Black)) % MOD;
		}
		dp[v][c] = (dp[v][c] * a) % MOD;
	}

	return dp[v][c];
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	int s, t;
	FOR(i, 0, N - 1) {
		cin >> s >> t;
		s--; t--;
		x[s].push_back(t);
		x[t].push_back(s);
	}

	FOR(i, 0, 100010)FOR(j, 0, 2)dp[i][j] = -1;

	ans = (dfs(0, -1, White) + dfs(0, -1, Black)) % MOD;

	cout << ans << endl;

	return 0;
}
