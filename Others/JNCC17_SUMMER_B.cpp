#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define FOR(i, s, e) for (ll(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (ll(i) = (s); (i) > (e); (i)--)
#define debug(x) cout << #x << ": " << x << endl
#define mp make_pair
#define pb push_back
const ll MOD = 1000000007;
const int INF = 1e9;
const ll LINF = 1e16;
const double PI = acos(-1.0);
int dx[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2017/08/05  Problem: JNCC17_summer B  / Link: https://www.hackerearth.com/ja/challenge/hiring/jnccsummer17/  ----- */
/* ------問題------

テストケースT個、
N*Mの領域において、右、左、下にのみ移動できてかつ一回の移動では同じ経路を通らないとき、
(x1,y1)->(x2,y2)への経路数はどれだけか。
T≦10^6
N,M,x1,y1,x2,y2≦10^8

-----問題ここまで----- */
/* -----解説等-----

どの地点で折り返すかを選択するだけ。
本番頭が無さ過ぎて解けなかったけど、scanfでは遅く、gets等をつかって頑張って高速に入出力を行うと100点取れるらしい。

----解説ここまで---- */

ll N;

ll ans = 0LL;

int powmod(ll x, ll n, ll mod) {
	ll res = 1;
	while (n > 0) {
		if (n & 1) {
			res = (res*x) % mod;
		}
		x = (x*x) % mod;
		n >>= 1;
	}
	return (int)res;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int T,M,N,x1,x2,y1,y2;
	scanf("%d", &T);
	FOR(_i, 0, T) {
		scanf("%d%d", &N, &M);
		scanf("%d%d%d%d", &x1, &y1,&x2,&y2);
		printf("%d\n", powmod(M, y2 - y1, MOD));
	}

	return 0;
}
