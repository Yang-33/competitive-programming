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

/* -----  2017/06/27  Problem: CodeForces421 A div2 / Link: http://codeforces.com/contest/820/problem/A  ----- */
/* ------問題------

cぺーシの本をv0で読む。次の日Lページもどって、v0+aの速度で読む。最大でもv1の速度は越えない。
ある日にちで読めることが確定している際に何日で読めるか。

-----問題ここまで----- */
/* -----解説等-----

いわれたとおりに書く。
TLEしなかったけどa,lの条件次第では1ページしか読めないものがあってこれだけ場合分けしてもよさそう。

----解説ここまで---- */

ll N;

ll ans = 0LL;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int c, v0, v1, a, l;
	cin >> c >> v0 >> v1 >> a >> l;
	int readed = 0;
	while (1) {
		ans++;
		readed += v0;
		if (readed >= c)break;

		v0 += a;
		if (v0 >= v1)v0 = v1;
		readed -= l;
	}


	cout << ans << endl;

	return 0;
}