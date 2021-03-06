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

/* -----  2017/06/01  Problem: CodeForces417 C div2 / Link: http://codeforces.com/contest/812/problem/C ----- */
/* ------問題------

お店がN店並んでいる。予算がS円ありこの金額内でなるべくたくさん、安く買い物をしたい。
今からあなたがK店を決めてその店で商品を買う。
その店の値段は今買った商品の総和で値段が変わる。
(値段)=(その店の商品の値段)＋(買った個数)(K)
条件を満たす際の買った個数を使った金額を求めよ。

-----問題ここまで----- */
/* -----解説等-----

問題文が分かりにくすぎる。
買う個数について二分探索をして、
その戸数で買う際の各店の商品の値段を求めてから安いものを買っていけばよい。
予算Sを超えてはいけないので区間を[l,r)として探索する。
したがってans=l

----解説ここまで---- */

ll N, S;
ll a[100010];
ll ans = 0LL;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> S;
	FOR(i, 0, N)cin >> a[i];
	ll l = 0; ll r = N+1 ;
	ll res = 0;
	FOR(_i, 0, 200) {
		ll mid = (l + r) / 2;
		res = 0;
		ll A[100010];
		FOR(i, 0, N)A[i] = a[i] + (i + 1)*mid;
		sort(A, A + N);

		FOR(k, 0, min(N, mid )) {
			res += A[k];
		}
		if (res > S)r = mid;
		else l = mid;
	}
	ans = l;
	if (l == 0)res = 0;
	cout << ans << " " << res << endl;

	return 0;
}