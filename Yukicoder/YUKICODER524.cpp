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

/* -----  2017/09/14  Problem: __CONTEST_NAME__ __ALPHA__  / Link: https://yukicoder.me/problems/no/524  ----- */
/* ------問題------

あなたは夢を見た。
飼い犬のちわわが魔王Yekocidurに誘拐される夢だ。
ちわわを助けるため、あなたは冒険を重ねついに魔王Yekocidurを倒した。
しかし余りにもあっけなく倒せたため疑問に思いつつちわわを探していると、
ちわわはなんかとんでもないことになっていた。
ちわわの横にはコインの乗った皿が数枚ある。
どうやらこれをつかったゲームに勝てばちわわは元に戻るようだ。
このゲームのルールは以下のとおりである。
自分は先攻、ちわわは後攻で交互にコインをとる。
コインは1度に何枚でも取れるが、1回毎に全て同じ皿から取らなければならない。
コインは必ず1枚以上取る。
コインがない状態で自分の番になったら負け。ゲームは終了し、負けなかったほうが勝ちとなる。
皿はNN枚あり、ii (1-indexed)枚目の皿にはコインがii枚乗っている。
NNが与えられるので、自分が勝つかどうか判定せよ。
但し、双方とも常に自分が勝つために最善を尽くすものとする。

-----問題ここまで----- */
/* -----解説等-----

手元で書いたらN%4==3で負け、あとは勝ちになった。

----解説ここまで---- */

ll N;

ll ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	int grundy = 0;
	grundy = N % 4;
	cout << ((grundy!=3)?"O":"X") << "\n";

	return 0;
}
