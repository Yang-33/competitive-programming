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

/* -----  2017/09/14  Problem: __CONTEST_NAME__ __ALPHA__  / Link: https://yukicoder.me/problems/no/103  ----- */
/* ------問題------

ちょっと前に素因数を習ったばかりのAliceとBobが再び数字に関するゲームをします。

ゲームの内容は以下のとおりです。
・N個の整数が与えられます。M1 M2 …Mi… MNと表します。
・その番のプレイヤーは、N個の整数のうち、i番目の数字を選び「Miの素因数」のどれかで割り、i番目の数をその商で更新します。
・この時、同じ素因数であれば、割り切れる限り1回以上、2回まで割ることができます。
例えば、i番目の値が24だった場合、その素因数は 2,3 (24=2×2×2×3) であるため 24を2で2回割った数の6に更新することができます。
・以上の手順をプレイヤーを入れ替え繰り返し、N個のすべての数11にしたプレイヤーが勝ちです。


まずAliceが先攻となりゲームを始めます。
この時、どちらも最善を尽くすと考えたとき、N個の整数が与えられた時の勝者を求めてください


-----問題ここまで----- */
/* -----解説等-----

各山二個までしか取れないときのNimのNim.grundy数は簡単で、各素因数の数のmod3をとったもの。

----解説ここまで---- */

ll N;

ll ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	int grundy = 0;
	FOR(j, 0, N) {
		int x; cin >> x;

		for (ll i = 2; i * i <= x; i++) {
			int cnt = 0;
			while (x%i == 0) {
				x /= i;
				cnt++;
			}
			grundy ^= cnt % 3;
		}
		if (x != 1)grundy ^= 1 % 3;
	}
	cout << ((grundy != 0) ? "Alice" : "Bob") << "\n";

	return 0;
}
