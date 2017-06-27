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

/* -----  2017/06/25  Problem: CodeForces420 A div2 / Link: http://codeforces.com/contest/821/problem/A  ----- */
/* ------問題------

正方行列が与えられる。要素の値は1以上である、
1より大きい値はこの要素の行あるいは列の値の2値の和で表せるかを確認せよ。

-----問題ここまで----- */
/* -----解説等-----

確認せよと言われたので確認します。

----解説ここまで---- */

ll N;

ll ans = 0LL;
int a[60][60];

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	FOR(i, 0, N) {
		FOR(j, 0, N)cin >> a[i][j];
	}
	bool f = 1;
	FOR(i, 0, N) {
		FOR(j, 0, N) {
			int target = a[i][j];
			if (target == 1)continue;
			int y = i; int x = j;
			vector<int>l;
			FOR(k, 0, N) {
				if (k == y)continue;
				l.pb(a[k][x]);
			}
			bool flag = 0;
			FOR(k, 0, N) {
				if (k == x)continue;
				FOR(n, 0, N) {
					if (l[n] + a[y][k] == target)flag = 1;
				}
			}
			if (flag == 0)f = 0;
		}
	}

	if (f)cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}