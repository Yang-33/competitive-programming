#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
#define FORR(i,s,e) for(ll (i)=(s);(i)>(e);(i)--)
#define debug(x) cout<<#x<<": "<<x<<endl
#define mp make_pair
#define pb push_back
const ll MOD = 1000000007;
const int INF = 1e9;
const ll LINF = 1e16;
const double PI = acos(-1.0);
int dx[8] = { 0,0,1,-1,1,1,-1,-1 };
int dy[8] = { 1,-1,0,0,1,-1,1,-1 };

/* -----  2017/06/01  Problem: CodeForces417 B div2 / Link: http://codeforces.com/contest/812/problem/B ----- */
/* ------問題------

N解建ての、1フロアM+2の長さの建物がある。端の二点は階段になっている。
巡回しなければならない点が一階から順に00100010のように1で与えられる。
1階の右側から巡回する際、巡回が最も早く終わるような移動距離は。

-----問題ここまで----- */
/* -----解説等-----

N≦15,M≦100なので頑張って各自実装をすれば間に合う。
階段について左右からどういくかで最適な距離が変わるので
dp[ 今いる階 ][ 右側からの距離 ]:= 距離の最小値　とする。
入力とビルのイメージが異なることと、上の階について最上階までいかなくてもいい場合があるので
そこに気を付ける。

----解説ここまで---- */

ll N, M;
string s[20];
ll ans = 0LL;
ll sub[20];
ll dp[20][2];
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	FOR(i, 0, N)cin >> s[i];
	ll sum = 0;
	FOR(i, 0, N) {
		FOR(j, 0, M + 2) {
			if (s[i][j] == '1') {
				sum++;
				sub[i]++;
			}
		}
	}

	FOR(i, 0, 20)FOR(j, 0, 2)dp[i][j] = LINF;

	dp[0][0] = 0; dp[0][1] = M + 1;
	FOR(i, 0, N) {
		ll pos = 0;
		ll cost = 0;
		FOR(j, 0, M + 2) {
			if (s[N-i-1][j] == '1') {
				pos = j;
			}
		}
		//debug(dp[i][0]);
		//cout << "i: " << i << " pos: " << pos << endl;
		if (i == N - 1) {
			dp[i + 1][1] = min(dp[i + 1][1], dp[i][0] + pos);
			dp[i + 1][0] = min(dp[i + 1][0], dp[i][0] + pos);
		}
		else {
			dp[i + 1][1] = min(dp[i + 1][1], dp[i][0] + (M + 1) + 1);
			dp[i + 1][0] = min(dp[i + 1][0], dp[i][0] + 2 * pos + 1);
		}
		pos = M + 1;
		FORR(j, M + 2 - 1, -1) {
			if (s[N-i-1][j] == '1') {
				pos = j;
			}
		}
		if (i == 0) {
			dp[i + 1][1] = dp[0][1] + 1;
		}
		else 	if (i == N - 1) {
			dp[i + 1][1] = min(dp[i + 1][1], dp[i][1] + M + 1 - pos);
			dp[i + 1][0] = min(dp[i + 1][0], dp[i][1] + M + 1 - pos);
		}
		else {
			dp[i + 1][1] = min(dp[i + 1][1], dp[i][1] + 2 * (M + 1 - pos) + 1);
			dp[i + 1][0] = min(dp[i + 1][0], dp[i][1] + (M + 1) + 1);
		}
	}
	ans = min(dp[N][1], dp[N][0]);

	/*FOR(i, 0, 1+N) {
		FOR(j, 0, 2) {
			cout << dp[i][j] << " ";
		}cout << endl;

	}*/
	FOR(i,0,N) {
		bool f = 0;
		ll last = 0;
		ll first = M + 1;
		FOR(j, 0, M + 2) {
			if (s[i][j] == '1') {
				last = j;
			}
		}
		FORR(j, M + 2 - 1, -1) {
			if (s[i][j] == '1') {
				first = j;
			}
		}
		if (last != 0 || first != M + 1) {
		/*	debug(i);
			debug(dp[N - i - 1][0]);
			debug(dp[N - i - 1][1]);
	*/
			cout << min(dp[N-i-1][0] + last, dp[N-i-1][1] + M + 1 - first)<<endl;
			return 0;
		}
		ans--;
	}
//	debug(ans);
	if (ans <= 0)ans = 0;
	cout << ans << endl;


	return 0;
}