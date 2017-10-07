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

/* -----  2017/10/07  Problem: HackerRank Hourrank19 B / Link:  https://www.hackerrank.com/contests/hourrank-19/challenges/what-are-the-odds/problem ----- */
/* ------問題------

複数山のNim
後手は先に盤面の[L,R]を削除できる。
このような時、勝つような削除の仕方は何通りか。
N≦10^5
a[i]≦10^9

-----問題ここまで----- */
/* -----解説等-----

Nimゲームの理解が足りていないのであとで。
Xorとるといいみたいだけどなんでだろう。

-> 理解した
[L,R]を除いたgrundy数が0になるような選択をすればよい。
これは、[L,R]と残りの部分が等価であるような選択をすることになる。
N^2では間に合わないので、さらに考えると、残りの値が0ということは[0,L-1]^[R+1,N-1]が0ということになる。
これは部分問題としてとれるので、[R+1,N-1]をキーにして右区間の数を数えればよい。

----解説ここまで---- */

ll N;

ll ans = 0LL;
ll a[500005];
ll L[500005];
ll R[500005];
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	FOR(i, 0, N) {
		cin >> a[i];
	}
	L[0] = a[0];
	FOR(i, 1, N)L[i] = L[i - 1] ^ a[i];
	R[N] = 0;
	FORR(i, N - 1, -1)R[i] = R[i + 1] ^ a[i];

	map<int, ll>cnt;
	cnt[0] = 1;//全部
	FOR(i, 0, N) {
		ans += cnt[R[i + 1]];
		cnt[L[i]]++;
	}

	cout << ans << endl;

	return 0;
}
