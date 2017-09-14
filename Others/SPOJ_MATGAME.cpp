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

/* -----  2017/09/14  Problem: __CONTEST_NAME__ __ALPHA__  / Link: http://www.spoj.com/problems/MATGAME/  ----- */
/* ------問題------

N*Mの盤面に数字が並んでいる。2人で交互に以下の操作を行う。
一列選んでその列の一番左にある正の数字の大きさまでの数、好きなだけ減らす。
最後に操作したプレイヤーの勝利。

-----問題ここまで----- */
/* -----解説等-----

操作できるのは一番左だけなのでNimではない。
各列のgrundy数を計算してその直和が0かを判定すればよい。
grundy数は、(0)->0, (a)->a, (1,a)->0, (b,a)->b-1である。
しかし遷移を追うとわかるが(b,a)はaの値によって盤面の値を変えうる。(grundy数は次の盤面と重複しないので)
そこを場合分けすればよい。

----解説ここまで---- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int T; cin >> T;
	FOR(t, 0, T) {
		int H, W; cin >> H >> W;
		int grundy = 0;
		vector<vector<int>> a(H, vector<int>(W, 0));
		FOR(i, 0, H) {
			FOR(j, 0, W) {
				cin >> a[i][j];
			}

			int subg = 0;
			FORR(j, W - 1, -1) {
				if (subg >= a[i][j] )subg = a[i][j] - 1; // b != a[i][j]-1 は直前について
				else subg = a[i][j];
			}
			grundy ^= subg;
		}
		cout << ((grundy != 0) ? "FIRST" : "SECOND") << "\n";
	}

	return 0;
}