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

/* -----  2017/10/29  Problem:  / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0626  ----- */
/* ------問題------

スタンプラリー２ (Collecting Stamps 2)
JOI 商店街には大通りに沿ってN 個の店があり，JOI 商店街の入口から出口に向かってそれぞれ
1,2,...,N の番号が付けられている．JOI 商店街は一方通行で，入口から出口方向へしか移動することはできない．
まちおこしのため，JOI 商店街でスタンプラリーを行うことになった．
このスタンプラリーでは，それぞれの店はJ，O，I のいずれかのスタンプを用意し，店で買い物をした人はスタンプカードにスタンプを押してもらう．
スタンプラリーに参加する人はちょうど 3 つの店に入る．
商店街の入口では 3 つの欄のあるスタンプカードを配り，1 回目に入った店，2 回目に入った店，3 回目に入った店のスタンプを押してもらう．
商店街の出口でスタンプカードを回収し，押されたスタンプが先に入った店のものから順にJ，O，Iになっているとき，出口で商品券がもらえるキャンペーンを実施することになった．
押されたスタンプの種類や順番が異なるときは商品券はもらえない．
すでにN 個のすべての店はどのスタンプを用意するか決めたが，新たに1 つの店をJOI 商店街に出すことになり，新しく出店する場所と，その店が用意するスタンプを決めることになった．
新しい店を出す場所は，店i と店i+1 の間(1≤i≤N−1)，入口と店1 の間，店N と出口の間のいずれかから決める．また，新しい店のスタンプは J，O，I の 3 通りから決める．
商品券をもらえるような店の選び方の数が大きいほど，スタンプラリーが盛り上がると商店街は考えた．
そこで，新しく出す店の場所と用意するスタンプを決めたときの，上記の店の選び方の数の最大値を求めたい．

-----問題ここまで----- */
/* -----解説等-----

Jを追加するなら先頭、
Iを追加するなら末尾である。
Oは追加する位置によってJ,Iとの対応が変わるのでこれを全探索すればよい。

----解説ここまで---- */


ll ans = 0LL;
ll a[3][100010];

int main() {

	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N;
	string S;
	cin >> N >> S;
	FOR(i, 0, S.size()) {
		if (S[i] == 'J')a[0][i + 1]++;
		if (S[i] == 'O')a[1][i + 1]++;
		if (S[i] == 'I')a[2][i + 1]++;
	}


	FOR(i, 1, S.size() + 1) {
		FOR(j, 0, 3)a[j][i] += a[j][i - 1];
	}

	ll num = 0;
	FOR(i, 0, S.size()) { //O
		if (S[i] == 'O') {
			num += a[0][i] * (a[2][N] - a[2][i]);
		}
	}
	ans = 0;
	FOR(i, 0, S.size()) { // J
		if (S[i] == 'O') {
			ans += (a[0][i]+1) * (a[2][N] - a[2][i]);
		}
	}
	ll an = 0;
	FOR(i, 0, S.size()) { // I
		if (S[i] == 'O') {
			an += a[0][i] * (a[2][N]+1 - a[2][i]);
		}
	}

	ans = max(ans, an);
	FOR(i, 1, N) {//ＯはＮ－１か所
		ll x = a[0][i] * (a[2][N] - a[2][i]);
		ans = max(num + x, ans);
	}
	cout << ans << endl;

	return 0;
}
