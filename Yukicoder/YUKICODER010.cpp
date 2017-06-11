#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define FOR(i, s, e) for (ll(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (ll(i) = (s); (i) > (e); (i)--)
#define debug(x) cout << #x << ": " << x << endl
#define mp make_pair
#define pb push_back
const ll MOD = 1000000007;
const int INF = 1e9;
const ll LINF = 1e16;
const double PI = acos(-1.0);
int dx[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2017/06/11  Problem: yukicoder010 / Link: http://yukicoder.me/problems/no/10  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

メモ化再帰または経路復元dp.
メモ化再帰では、i個目まで見て、総和がsumの状況を探索したかどうかをmemoした。(あと枝狩り)
dpでは,演算結果がtargetの値になるかを確認したい上でtargetが10^5以下であること、Nが50以下であることがわかっているので、
dp[ 今何個目の数字も見ているか ][ 作成可能な値 ] := 作成可能/作成不可能　とする。
これによってtargetの値が作成可能かどうかを判定することができる。
経路復元ではこのdpの値意外にも値を選択できることを利用して、dp:= 何を選択したか(+/*)をもった。
これにより最適な状態を二値で表すことができるようになる。具体的にはbitがたっている場合には'*',
立っていない場合には'+'を選択したことにすれば最小の値を持つものは'+'.'*'を辞書順最小で使っていることになる。
したがって経路復元ではdp[N-1][target]の桁についてこれを順番に見ていけばよい。

経路復元はhttp://rsujskf.s602.xrea.com/?yukicoder_10
でもできるみたい。(dpにもつ情報がもっと大事なものだったらこれは天才！)

作成: dp[i][j] will be 1 <= dp[i+1][j+a[i]] is 1 
復元: x=a[0]として、dp[i+1][x+a[[i]] == 1 ならx=x+a[i]として+を復元

様々な経路復元、できるようにしたい。

----解説ここまで---- */

ll N, target;
ll a[50];
bool memo[51][100110];
ll ans = 0LL;
string s = "";
void f(int i, ll sum) {
	//cout << s << endl;
	if (sum > target)return;
	if (i == N&&sum == target) {
		cout << s << endl;
		exit(0);
	}
	if (i >= N)return;
	if (memo[i][sum])return;
	memo[i][sum] = 1;
	s += '+';
	f(i + 1, sum + a[i]);
	s.erase(s.size() - 1);
	s += '*';
	f(i + 1, sum * a[i]);
	s.erase(s.size() - 1);

	return;
}

ll dp[50][100010];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	//FOR(i, 0, 50)FOR(j, 0, 100011) memo[i][j] = 0;

	cin >> N >> target;
	FOR(i, 0, N)cin >> a[i];
	//f(1, a[0]);
	FOR(i, 0, N)FOR(j, 0, 100010)dp[i][j] = LINF;
	dp[0][a[0]] = 0;
	FOR(i, 1, N) {
		FOR(j, 0, target+1) {
			if (dp[i-1][j] == LINF)continue;
			if (j + a[i] <= target) {
				dp[i][j + a[i]] = min(dp[i][j+a[i]], dp[i - 1][j] * 2);
			}
			if (j * a[i] <= target) {
				dp[i][j * a[i]] = min(dp[i][j*a[i]], dp[i - 1][j] * 2 + 1);

			}
		}
	}
	ans = dp[N - 1][target];
	FORR(i, N -2, -1) {
		if (ans & 1LL << i)s += "*";
		else s += "+";
	}
	//FOR(i, 0, N-1) {
	//	if (ans & 1LL << i)s += "*";
	//	else s += "+";
	//}
	////s.pop_back();
	//reverse(s.begin(), s.end());
	cout << s << endl;
	return 0;
}
