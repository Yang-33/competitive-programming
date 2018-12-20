#include <bits/stdc++.h>
using namespace std;

using VS = vector<string>;    using LL = long long;
using VI = vector<int>;       using VVI = vector<VI>;
using PII = pair<int, int>;   using PLL = pair<LL, LL>;
using VL = vector<LL>;        using VVL = vector<VL>;

#define ALL(a)  begin((a)),end((a))
#define RALL(a) (a).rbegin(), (a).rend()
#define SZ(a) int((a).size())
#define SORT(c) sort(ALL((c)))
#define RSORT(c) sort(RALL((c)))
#define UNIQ(c) (c).erase(unique(ALL((c))), end((c)))
#define FOR(i, s, e) for (int(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (int(i) = (s); (i) > (e); (i)--)
//#pragma GCC optimize ("-O3") 
#ifdef YANG33
#include "mydebug.hpp"
#else
#define DD(x) 
#endif
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/12/21  Problem: codefestival2015_team_relay E / Link: __CONTEST_URL__  ----- */
/* ------問題------

あなたはあさプロに寝坊してしまった！ しかしまだ慌てるのは早い。あなたは魔法の道具「反転時計」で時間を操ることが出来るのだ。
時間を操ることが出来るといっても自由に時間を戻せるわけではない。 反転時計は盤に数字が書かれていない 12 時間制のアナログ時計で、180 度回転させることによって回転後の針が指す時間に移動することが出来る。具体的には、午前 h 時 m 分に反転時計を回転させると、同日の午前 ((h+6)%12) 時 ((m+30)%60) 分に移動する。例えば午前 9 時 30 分に反転時計を使うとその日の午前 3 時 00 分に戻ることが出来る。（どうやら短針の細かい位置は気にしなくてよいらしい。）
ただし反転時計の力は 1 日に 1 回しか使うことが出来ない。 また、一旦正午を過ぎてしまうと午前に戻ることはできなくなってしまうので、あまりのんびりしている時間はない。 急いであさプロが始まる時間に戻れるかどうかを考えよう。

-----問題ここまで----- */
/* -----解説等-----

頭が悪いので全探索した。
O(1)判定もできる。

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int Th, Tm; cin >> Th >> Tm;
	int Sh, Sm; cin >> Sh >> Sm;
	int nt = Sh * 60 + Sm;
	int ans = 0;
	if (Th > Sh) {
		ans = 1;
	}
	else if (Th == Sh && Tm >= Sm) {
		ans = 1;
	}
	FOR(t, nt, 60 * 12) {
		int H = t / 60;
		int M = t % 60;
		H = (H + 6) % 12;
		M = (M + 30) % 60;
		if (Th > H) {
			ans = 1;
		}
		else if (Th == H && Tm >= M) {
			ans = 1;
		}
	}
	cout << (ans ? "Yes" : "No") << endl;
	return 0;
}