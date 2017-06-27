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

/* -----  2017/06/25  Problem: CodeForces420 B div2 / Link: http://codeforces.com/contest/821/problem/B  ----- */
/* ------問題------

ばなな園があって、y=-1/M+Bの直線の下の領域がバナナ園の本領である。
(X,Y)にはX+Yのバナナがある。
ある点を選択すると(0,0)から(X,Y)までの長方形内のバナナをすべて得ることができる。
最大いくつのバナナを回収できるか。

-----問題ここまで----- */
/* -----解説等-----

x,yについてみるとxの増加はy+1段だけΣが存在して、
yも同様の形をとる。
このうちの最大値をとればいい。
xの値ではなくyの値で調べた方が早く検索できるのでいいと思った。

----解説ここまで---- */

ll M, B;

ll ans = 0LL;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> M >> B;


	FOR(i, 0, M*B + 1) {
		ll y = -((i + M - 1) / M) + B;
		ll x = i;

		ll ret = (y + 1)*(x*(x + 1)) / 2;
		ret += (x + 1)*(y*(y + 1)) / 2;
		ans = max(ans, ret);
	}


	cout << ans << endl;

	return 0;
}