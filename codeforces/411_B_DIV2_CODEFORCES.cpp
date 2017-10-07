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

/* -----  2017/05/04  Problem: CodeForces411 B div2 / Link: http://codeforces.com/contest/805/problem/B ----- */
/* ------問題------

長さ以上の部分回分が存在しないように作成される、長さNの文字列のうち最小のものは？

-----問題ここまで----- */
/* -----解説等-----

aabbaabbaabbaabb.....だね

----解説ここまで---- */

ll N;

string ans;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
   
	cin>>N;
	if (N == 2) {
		cout << "aa" << endl; return 0;
	}
	if (N == 3) {
		cout << "aab" << endl; return 0;
	}

	FOR(i, 0, N/2) {
		if (i%2==0)ans += "aa";
		else ans += "bb";
	}
	if (N % 2 == 1) {
		if ((N / 2) % 2 == 0)ans += "a";
		else ans += "b";
	}
	
	cout<<ans<<endl;

	return 0;
}