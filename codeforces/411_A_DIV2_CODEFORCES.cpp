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

/* -----  2017/05/04  Problem: CodeForces411 A div2 / Link: http://codeforces.com/contest/805/problem/A ----- */
/* ------問題------

L,Rが与えられる。
[L,R]に含まれる値をもっともたくさん割り切るあたいは？

-----問題ここまで----- */
/* -----解説等-----

2,3,5を考えたとき明らかに2がたくさんの数字を割り切ることができる。
例外はL=R.

----解説ここまで---- */


int ans = 0;
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
   
	ll L, R;
	cin>>L>>R;
	/*if (R - L <= 1) {
		cout << R << endl;
		return 0;
	}
	if (R - L == 2) {
		cout << 2 << endl;
		return 0;
	}

	int id = 2;
	FOR(i, 2, 101) {
		int l = (L+i-1) / i;
		int r = (R) / i;
		if (ans <= r - l + 1) {
			ans = r - l + 1;
			id = i;
		}
	}*/
	if (L == R) {
		cout << L << endl;
	}
	else cout << 2 << endl;
	
//	cout<<id<<endl;

	return 0;
}