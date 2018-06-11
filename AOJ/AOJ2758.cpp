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
#define debug(x) cerr << #x << ": " << x << endl
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/06/10  Problem: AOJ 2758 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2758  ----- */
/* ------問題------

「あれ」は2人で行うゲームである．リズムに合わせて2人が同時に，防御，溜め，攻撃のいずれかのポーズを取ることを繰り返す．ここで，2人がポーズを取るタイミングのことを「回」と表記する．このゲームでは，ある回で勝敗がつき，かつ，それまでの回で勝敗がついていないとき，その勝敗がゲームの勝敗となる．
2人はそれぞれ「攻撃力」というパラメータを持ち，ゲーム開始時，攻撃力は 0 である．
攻撃のポーズを取った場合，その時点での攻撃力に応じて，次のようになる．
攻撃力が 0 のときに攻撃のポーズを取ると，反則負けとなる．ただし，相手も攻撃力が 0 で攻撃のポーズをした場合，その回では勝敗がつかない．
自分の攻撃力が 1 以上のときに攻撃のポーズをとると，相手に攻撃を加える．また，その回で相手も攻撃のポーズを取った場合，攻撃力のより高いプレイヤーが勝利する．ただし，両プレイヤーが同じ攻撃力で攻撃のポーズを取った場合には，その回では勝敗がつかない．
また，攻撃のポーズを取った回の終了時に，自分の攻撃力が 0 になる．
溜めのポーズを取ると，そのプレイヤーの攻撃力が 1 だけ上昇する．ただし，攻撃力が 5 である場合，そのプレイヤーが溜めのポーズを取っても，攻撃力は 5 のままである．溜めのポーズを取った回で，相手が攻撃を加えた場合，相手が勝利する．なお，溜めのポーズを取った回で，相手が攻撃以外のポーズをとった場合，勝敗がつかない．
防御のポーズを取った回に，相手が攻撃力 5 の攻撃を加えた場合，相手が勝利する．一方，防御のポーズを取った回に，相手が攻撃力 4 以下の攻撃を加えた場合や，溜めまたは防御のポーズを取った場合，その回では勝敗がつかない．なお，防御のポーズを取っても，そのプレイヤーの攻撃力に変化はない．
両プレイヤーのポーズが順に与えられるので，勝敗を出力せよ．なお，両プレイヤーは勝敗が決定した後もポーズをとり続けることがあるが，勝敗が決定した後のポーズは無視するものとする．

-----問題ここまで----- */
/* -----解説等-----

がんばるしかないためがんばります

----解説ここまで---- */



int main() {
	cin.tie(0);
	int n, iso_p = 0, naka_p = 0, flag = 2;
	string isono[100], nakajima[100];
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> isono[i];
	for (int i = 0; i < n; ++i) cin >> nakajima[i];
	for (int i = 0; i < n; ++i) {
		if (isono[i] == "kougekida" && nakajima[i] == "kougekida") {
			if (iso_p > naka_p) {
				flag = 0;
				break;
			}
			else if (iso_p < naka_p) {
				flag = 1;
				break;
			}
			iso_p = 0; naka_p = 0;
		}
		else if (isono[i] == "kougekida" && iso_p == 0) {
			flag = 1;
			break;
		}
		else if (nakajima[i] == "kougekida" && naka_p == 0) {
			flag = 0;
			break;
		}
		else if (isono[i] == "kougekida" && nakajima[i] == "mamoru") {
			if (iso_p >= 5) {
				flag = 0;
				break;
			}
			iso_p = 0;
		}
		else if (isono[i] == "kougekida" && nakajima[i] == "tameru") {
			flag = 0;
			break;
		}
		else if (nakajima[i] == "kougekida" && isono[i] == "mamoru") {
			if (naka_p >= 5) {
				flag = 1;
				break;
			}
			naka_p = 0;
		}
		else if (nakajima[i] == "kougekida" && isono[i] == "tameru") {
			flag = 1;
			break;
		}
		if (isono[i] == "tameru") {
			if (iso_p < 5) { iso_p++; }
		}
		if (nakajima[i] == "tameru") {
			if (naka_p < 5) { naka_p++; }
		}

	}
	if (flag == 0) cout << "Isono-kun" << endl;
	else if (flag == 1) cout << "Nakajima-kun" << endl;
	else cout << "Hikiwake-kun" << endl;
	return 0;
}