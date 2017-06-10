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
#define ALL(x) x.begin(),x.end()
const ll MOD = 1000000007;
const int INF = 1e9;
const ll LINF = 1e16;
const double PI = acos(-1.0);
int dx[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2017/04/15  Problem: AGC 013 C / Link: http://agc013.contest.atcoder.jp/tasks/agc013_c  ----- */
/* ------問題------

周の長さ L の円があります。 この円の周上には座標が設定されていて、座標の値は、ある基準点からどれだけ時計回りに進んだかを表しています。

この円周上に N 匹の蟻がいます。 蟻には、座標の小さいものから順に、1 から N までの番号がついています。 i 番目の蟻は座標 Xi にいます。

これから、N 匹の蟻は一斉に動き出します。 i 匹目の蟻は、Wi が 1 なら時計回りに、Wi が 2 なら反時計回りに動き始めます。
全ての蟻の移動速度は常に、1 秒間にちょうど 1 の距離を進む速さです。 蟻が動いていくと、二つの蟻がぶつかることがあります。
その時はどちらの蟻も、ぶつかった瞬間に進む向きを反転して動き続けます。

蟻が動き始めてから T 秒後にそれぞれの蟻がいる位置を求めて下さい。

-----問題ここまで----- */
/* -----解説等-----

なんかね、できた

----解説ここまで---- */

const int N = 3e5 + 500;

int n, L, pos[N], ra[N], dir[N], ans[N];
bool cmp(int x, int y) { return pos[x] < pos[y]; }
ll T;


int main() {
	cin >> n >> L >> T;
	FOR(i, 0, n) {
		char ch[10];
		cin >> pos[i] >> ch;
		pos[i]; ra[i] = i;
		dir[i] = ch[0] == '2' ? -1 : 1;
	}
	sort(ra, ra + n, cmp);
	int t = 0;
	FOR(i, 0, n) {
		if (dir[i] == 1) t += (pos[i] + T) / L%n;
		else t += (pos[i] - T - L + 1) / L%n;
		t = (t%n + n) % n;
		pos[i] = pos[i] + T%L*dir[i];
		pos[i] = (pos[i] % L + L) % L;
	}
	sort(pos, pos + n);
	FOR(i, 0, n)
		ans[ra[(i + n - t) % n]] = pos[i];

	FOR(i, 0, n)
		printf("%d\n", ans[i]);
	return 0;
}