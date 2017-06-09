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
int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};

/* -----  2017/05/27  Problem: AGC 015 B / Link: http://agc015.contest.atcoder.jp/tasks/agc015_b  ----- */
/* ------問題------

すけぬ君は、N 階建てのビルを建てました。ビルにはエレベーターが 1 基あり、すべての階に止まります。

すけぬ君は、各階に上下の方向ボタンを設置しましたが、うっかりしていたため、どの階にも上向きか下向きの片方のボタンしかありません。
そのため、どの階からも上か下のどちらかにしか進むことができません。
Si が U のとき i 階には上向きのボタンしかなく、上にしか進めないことを、D のとき下向きのボタンしかなく、 下にしか進めないことを表します。

ある階から目的の階へと移動したい住民は、仕方がないので必要があれば他の階を経由して目的の階へと向かうことにしました。
全ての階の順序対 (i,j) についての、i 階から j 階へ行くときのエレベーターに乗る回数の最小値の合計を求めてください。

-----問題ここまで----- */
/* -----解説等-----

必ず二手以内で好きな階へ到達できる。
上にしか行けないエレベーターでは自分より上の階へは一手で行ける。
下の階へは2手で行ける。
i(0,1,2,...,N-1)階では下にi階、上にN-(i+1)階ある。
このことからi階からの移動回数がＯ(1)で求められるので合わせてＯ(N)で解ける。

----解説ここまで---- */



string s;
ll ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> s;
	int n = s.size();
	FOR(i, 0, s.size()) {
		if (s[i] == 'U') {
			ans += n - (i + 1);
			ans += 2 * (i);
		}
		else {
			ans += i;
			ans += 2 * (n - (i + 1));
		}

	}
	cout << ans << endl;

	return 0;
}