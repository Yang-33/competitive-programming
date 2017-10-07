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

/* -----  2017/05/04  Problem: CodeForces411 C div2 / Link: http://codeforces.com/contest/805/problem/C ----- */
/* ------問題------

1からnの学校がある。
i->jへ移動する際のコストは(i+j)mod(n+1)である。すべての学校に訪れる際の最小コストは。

-----問題ここまで----- */
/* -----解説等-----

実験。
なるべく0になるような移動を行うと、奇数回目は必ず0の移動ができる。
偶数回目は最小コストを考えると1で移動できる。
したがって0,1,0,1,0,1,0,1,...の和を求めればいいことが分かる。

----解説ここまで---- */

ll N;

ll ans = 0LL;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
   
	cin>>N;
	
	ans = (N-1) / 2 ;

	
	cout<<ans<<endl;

	return 0;
}