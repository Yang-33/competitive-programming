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

/* -----  2017/09/14  Problem: yukicoder002  / Link: https://yukicoder.me/problems/no/2  ----- */
/* ------問題------

最近素因数を習ったばかりのAliceとBobが数字に関するゲームをします。

ゲームの内容は以下のとおりです。
・まず初めに、先攻のプレイヤーに2以上の自然数NNが与えられます。
・その番のプレイヤーは、Nに対して、「Nの素因数」のどれかで割り、相手にその数を渡します。
・この時、同じ数であれば、割り切れる限り１回以上であれば何回割ってもいいこととします。
例えば、24の素因数は 2,3 (24=2×2×2×3) であるため 24を2で2回わった数6を相手に渡すことが出来ます。
・次のプレイヤーは渡された数を新たなNとし、以上の手順を繰り返します。
・渡された数が1になったプレイヤーが負けです。

まずAliceが先攻となりゲームを始めます。
この時、どちらも最善を尽くすと考えたとき、自然数NNが与えられた時の勝者を求めてください。

-----問題ここまで----- */
/* -----解説等-----

各素因数についてのNimと見れる。

----解説ここまで---- */

ll N;

ll ans = 0LL;


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	ll n = N;
	ll grundy = 0;

	for (ll i = 2; i * i <= n; i++) {
		ll cnt = 0;
		while (n%i == 0) {
			n /= i;
			cnt++;
		}
		grundy ^= cnt;
	}
	if (n != 1)grundy^=1;

	cout << ((grundy!=0)?"Alice":"Bob")<< endl;

	return 0;
}
