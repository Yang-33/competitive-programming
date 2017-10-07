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

/* -----  2017/10/07  Problem: DDCC2017_qual D  / Link: http://ddcc2017-qual.contest.atcoder.jp/tasks/ddcc2017_qual_d  ----- */
/* ------問題------

南北方向に H 、東西方向に W のグリッド状の庭があり、北から i(1≦i≦H) 番目、西から j(1≦j≦W) 番目のマスを (i,j) とします。
ただし、 H と W は偶数とします。
各マスには石が高々 1 つ置かれており、また、 1 つ以上のマスに石が置かれています。
なお、最初の庭の状態は、文字列 mi,j を用いて、 (i,j) に石があるなら mi,j = S、石がないなら mi,j = . として与えられます。
これらの石を 1 つずつ取り除いていきます。
石を取り除いた直後に、庭の石の配置が南北方向に対称なら A の幸福度、東西方向に対称なら B の幸福度が得られます。
ただし、南北方向にも東西方向にも対称のときは A+B の幸福度が得られることとします。
全ての石を自由な順番で取り除くとき、得られる最大の幸福度を求めてください。
なお、南北方向に対称とは、以下のことが成り立つ場合です。
すべての i,j(1≦i≦H,1≦j≦W) において (i,j) に石があるなら (H+1−i,j) にも石があり、 (i,j) に石がなければ (H+1−i,j) に石がない。
また、東西方向に対称とは、以下のことが成り立つ場合です。
すべての i,j(1≦i≦H,1≦j≦W) において (i,j) に石があるなら (i,W+1−j) にも石があり、 (i,j) に石がなければ (i,W+1−j) に石がない。

-----問題ここまで----- */
/* -----解説等-----

初手無駄うちできるかぐらい場合分けしましょうね
全部に対称なものは、次の対称までにmax(A,B)+A+Bを得ることができるので、
縦のみの対称形と横のみの対称形は先に消したい気持ちになる。
あとは縦横対称形になるようにしていく2パターンを書いておわり

----解説ここまで---- */

ll H, W, A, B;
string s[202];
ll ans = 0LL;



int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> H >> W;
	cin >> A >> B;


	int cnt = 0;
	FOR(i, 0, H) {
		cin >> s[i];
		FOR(j, 0, W)if (s[i][j] == 'S')cnt++;
	}
	ll tate = 0, yoko = 0;

	FOR(i, 0, H / 2) {
		FOR(j, 0, W) {
			if (s[i][j] == s[H - i - 1][j] && s[i][j] == 'S')tate++;
		}
	}
	FOR(i, 0, H) {
		FOR(j, 0, W / 2) {
			if (s[i][j] == s[i][W - j - 1] && s[i][j] == 'S')yoko++;
		}
	}
	ll kyo = 0;
	FOR(i, 0, H / 2) {
		FOR(j, 0, W / 2) {
			if (s[i][j] == s[H - i - 1][j] && s[i][j] == s[i][W - j - 1] && s[i][j] == s[H - i - 1][W - j - 1] && s[i][j] == 'S')kyo++;
		}
	}
	//cout << setw(3) << setfill('.') << ans << " " << tate << " " << yoko << " " << kyo << endl;
	tate -= 2 * kyo;
	yoko -= 2 * kyo;
	tate = max(tate, 0LL);
	yoko = max(yoko, 0LL);
	//cout << setw(3) << setfill('.') << ans << " " << tate << " " << yoko << " " << kyo << endl;


	ll ret = 0;
	if (cnt - 4 * kyo - 2 * tate > 0) ret += A;
	ret += tate * A;
	if (cnt - 4 * kyo > 0) ret += B;

	ans = max(ans, ret);

	ret = 0;
	if (cnt - 4 * kyo - 2 * yoko > 0) ret += B;
	ret += yoko * B;
	if (cnt - 4 * kyo > 0) ret += A;
	ans = max(ans, ret);

	ans += kyo*(max(A, B) + A + B);
	cout << ans << endl;

	return 0;
}
