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

/* -----  2017/09/14  Problem: atcoder ARC 013 C 笑いをとれるかな？  / Link: http://arc013.contest.atcoder.jp/tasks/arc013_3  ----- */
/* ------問題------

デビュー1年目の若手芸人「あっとこーだー」の高橋くんと青木くんは、地方ローカル番組に出演することになりました。
この番組では「ドキドキ☆ハバネロゲーム」というゲームが人気です。
以下が「ドキドキ☆ハバネロゲーム」の内容です。
参加する2人はお互いに直方体の豆腐を切り取って、切り取った部分を食べます。
ハバネロが含まれる部分を食べたほうが負けです。
高橋くんと青木くんはそれぞれ 1 回ずつ交互に切り取ります。
この豆腐のある部分にはハバネロが仕掛けられています。
豆腐は複数存在することがあります。
全ての豆腐にハバネロが必ず仕掛けられています。
高橋くんと青木くんはリアクション芸が苦手なので、ハバネロが含まれた部分を食べてしまうと視聴者の失笑を買うことはわかっています。
そのため、この2人は相方にハバネロを食べさせることで自分がすべることを全力で回避しようと考えています。

そこで、高橋くんと青木くんは相方に知られないように番組のプロデューサからハバネロの位置をこっそりと聞き出しました。
この2人が「ドキドキ☆ハバネロゲーム」において最善手を繰り返すとき、先にハバネロを食べてすべってしまうのはどちらでしょうか。
あなたは神の視点から、この滑稽な2人の行く末を高橋くんだけに教えることにしました。
なお、先攻は高橋くんで、豆腐の切り方は以下の通りです。
切り取り方は水平に 3 方向から切り取ることができます。つまり、斜めに切ることはできません。

-----問題ここまで----- */
/* -----解説等-----

分割ゲームに見えるがこれは3次元Nim.
各方向について独立なので、x,y,zの各面から見た分割可能回数について、grundy数をもてばよい。
それはハバネロを含まない領域の幅となる。
求めた豆腐のgrundy数のxorがこのゲームのgrundy数。

----解説ここまで---- */

ll N;
ll a[3];
ll b[102][3];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	ll grundy = 0;
	cin >> N;
	FOR(i, 0, N) {
		vector<ll>Ma(3, -1);
		vector<ll>mi(3, INF);

		FOR(j, 0, 3)cin >> a[j];
		int m; cin >> m;
		FOR(j, 0, m) {
			FOR(k, 0, 3) {
				ll num; cin >> num;
				Ma[k] = max(Ma[k], num);
				mi[k] = min(mi[k], num);
			}
		}

		FOR(j, 0, 3) {
			grundy ^= mi[j];
			grundy ^= a[j] - Ma[j] - 1;
		}
	}
	cout << ((grundy != 0) ? "WIN" : "LOSE") << "\n";

	return 0;
}
