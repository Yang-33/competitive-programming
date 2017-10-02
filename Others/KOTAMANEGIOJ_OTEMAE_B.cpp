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

/* -----  2017/08/01  Problem: KotamanegiOJ_Otemae B  / Link: https://kotamanegi.com/JudgeSystem/Problems/view/index.php?page=26  ----- */
/* ------問題------

olphe君とkotamanegi君は栗の木がたくさん生えている山にやってきました。
二人は栗の木の下で遊びたくなったので、遊ぶのにちょうどよい栗の木を探すことにしました。
olphe君の身長O、kotamanegi君の身長K、山に生えている木の数N、
それぞれの木の高さhiが与えられるので、二人が遊ぶのにちょうどよい木の数を求めてください。
但し、遊ぶのにちょうどよい木とは、olphe君とkotamanegi君の両方よりも高い木とします。

-----問題ここまで----- */
/* -----解説等-----

maxより大きい数のカウントをする。

----解説ここまで---- */

ll N,O,K;
int h[100005];
ll ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> O>>K>>N;
	ll M = max(O, K);
	FOR(i, 0, N) {
		cin >> h[i];
		if (h[i] > M)ans++;
	}


	cout << ans << endl;

	return 0;
}
