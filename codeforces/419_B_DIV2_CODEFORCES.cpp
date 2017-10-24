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

/* -----  2017/06/17  Problem: CodeForces419 B div2 / Link: http://codeforces.com/contest/816/problem/B  ----- */
/* ------問題------

N個のコーヒーマシンがあり、これらはそれぞれ[Li,Ri]の温度のコーヒーを作ることができる。
Q個のクエリが来る。[Li,Ri]の温度のコーヒーをできるだけ作りたい。
ただしコーヒーを作る際にK種類つくれなければいけない。
各クエリごとに何杯まで作れるかを出力せよ。

-----問題ここまで----- */
/* -----解説等-----

いもす法で数を区間に足しこんだ後、その値がK以上なら(作成可能)としてもう一度累積和をとる。


----解説ここまで---- */

ll N;
ll K, Q;
int l[200020];
int r[200020];
int a[200020];
int b[200020];
ll ans = 0LL;
int x[200020];
int y[200020];
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
   
	cin>>N>>K>>Q;
	FOR(i, 0, N) {
		cin >> l[i] >> r[i];
	}
	FOR(i, 0, Q) {
		cin >> a[i] >> b[i];
	}
	
	FOR(i, 0, N) {
		x[l[i]]++;
		x[r[i] + 1]--;
	}
	FOR(i, 1, 200010) {
		x[i] += x[i - 1];
	}
	FOR(i, 0, 200010) {
		if (x[i] >= K)y[i] = 1;
	}
	FOR(i, 1, 200010) {
		y[i] += y[i - 1];
	}

	FOR(i, 0, Q) {
		cout << y[b[i]]-y[a[i]-1] << endl;
	}

	return 0;
}