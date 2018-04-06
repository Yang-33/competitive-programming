#include <bits/stdc++.h>
using namespace std;

using VS = vector<string>;    using LL = long long;
using VI = vector<int>;       using VVI = vector<VI>;
using PII = pair<int, int>;   using PLL = pair<LL, LL>;
using VL = vector<LL>;        using VVL = vector<VL>;

#define ALL(a)  begin((a)),end((a))
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define SZ(a) int((a).size())
#define SORT(c) sort(ALL((c)))
#define RSORT(c) sort(RALL((c)))
#define UNIQ(c) (c).erase(unique(ALL((c))), end((c)))
#define FOR(i, s, e) for (int(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (int(i) = (s); (i) > (e); (i)--)
#define debug(x) cerr << #x << ": " << x << endl
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/04/06  Problem: yukicoder 009  / Link: http://yukicoder.me/problems/no/009  ----- */
/* ------問題------

HeliaはRPGゲームをしている。そのRPGゲームは味方のモンスターのレベル上げていきゲームを進めるゲームである。
Heliaは手持ちにN匹のモンスターのパーティーがいてレベル上げしたいと思っている。

レベル上げは、敵のモンスターと1対1で戦い、敵のレベルの半分小数切り捨てを獲得できる。（自分の戦ったモンスターのレベルに加算する）
例えば、自分のモンスターのレベルが1で相手のモンスターのレベルが5の時、
戦ったあと、自分のモンスターのレベルは3になる。
戦いに関してはアイテムを駆使してでも勝つため、レベル差に関係なく勝てるとする。

ここで、敵のモンスターが円状に時計回りに並んでいて、最初に戦うモンスターを決めると時計回りの順番に全員と一度だけ戦うことができる狩場がある。
（最初に戦えるモンスターは自由に選べる）
Heliaは、自分の手持ちのモンスターの中から、１戦毎、その時に一番レベルが低い、複数いる場合は、一番戦いをしてないモンスターを戦わせるとする。
この狩場のモンスターを全て倒すとして、手持ちのパーティー中で戦闘回数が一番多い回数がもっとも低くなるよう狩場で最初に戦うモンスターを選んだとき、その中で一番戦闘回数が多い数を求めてください。

注意：速い言語でないと時間的に厳しいかもしれません。

-----問題ここまで----- */
/* -----解説等-----

愚直にやる。
ただし自分の手持ちのモンスターを選ぶのを毎回やるとダメなので適当なヒープを持ってくる。
yukicoderははやい

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	VL a(N), b(N);
	FOR(i, 0, N) {
		cin >> a[i];
	}
	FOR(i, 0, N) {
		cin >> b[i];
	}
	ans = INF;
	FOR(s, 0, N) {
		priority_queue<PLL, vector<PLL>, greater<PLL>>pq;
		FOR(i, 0, N) { 
			pq.push(PLL(a[i], 0));
		}
		LL ret = 0;
		FOR(i, 0, N) {
			int id = (i + s) % N;
			PLL mine = pq.top(); pq.pop();
			pq.push(PLL(mine.first+b[id]/2 , mine.second+1));
			ret = max(ret, mine.second + 1);
		}
		ans = min(ret, ans);
	}

	cout << ans << "\n";

	return 0;
}
