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

/* -----  2017/05/04  Problem: CodeForces411 D div2 / Link: http://codeforces.com/contest/805/problem/D ----- */
/* ------問題------

AとBでできた文字列がある。
可能な限りabをbbaに置換していく。
最小のステップでこれを行うと、何手必要か。

-----問題ここまで----- */
/* -----解説等-----

例えばaaa ab bbb -> aaa bba bbbとなる。
これはabのaの位置が右に移動してかつ左にbを二個置いたような動作になる。
したがって一回の置換ではaの右側のbの数だけ置換を行うことになる。
これを繰り返すとbの数は二倍になることが分かる。
左側に影響が出ることが分かったので、右側から走査し、aが来るたびにその右側のbの数が分かるようにすればよい。
バグらせなければOK

----解説ここまで---- */

string s;
ll ans = 0LL;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
   
	cin>>s;
	int bnum = 0;
	FORR(i, s.size() - 1, 0) {
		if (s[i] == 'b'&&s[i - 1] == 'b')bnum++;
		else if (s[i] == 'b'&&s[i - 1] == 'a') {
			ans++;
			ans = (ans + bnum) % MOD;
			bnum = (1 + 2 * bnum) % MOD;
			s[i - 1] = 'b';
		}

	}
	
	
	cout<<ans<<endl;

	return 0;
}