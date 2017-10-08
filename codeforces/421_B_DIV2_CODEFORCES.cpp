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

/* -----  2017/06/27  Problem: CodeForces421 B div2 / Link: http://codeforces.com/contest/820/problem/B  ----- */
/* ------問題------

正N角形の頂点を結んでできる角度のうちa度に最も近い頂点集合の名前は.
ex: 4 45: ans:1 2 4

-----問題ここまで----- */
/* -----解説等-----

正多角形の一つの頂点からほかの頂点に線を引くと最小単位が180/Nでできていることに気が付く。
これを何倍かしたものについて、aに最も近い角度を求め、2 1 X と出力すればいい。

----解説ここまで---- */

ll N;

ll ans = 0LL;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int a;
	cin >> N >> a;
	double ee = 180.0 / N;
	double aa = INF;
	int id = -1;
	FOR(i, 0, N - 2) {
		if (abs(ee*(i + 1) - a) < aa) {
			aa = abs(ee*(i + 1)-a);
			id = i + 1;
		}
	}
	cout << 2 + id << " " << 1 << " " << 2 << endl;



	return 0;
}