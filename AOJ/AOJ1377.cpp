#include "bits/stdc++.h"
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

/* -----  2017/10/10  Problem: AOJ 1377  / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1377  ----- */
/* ------問題------

以下は白、黒が2人で行うゲームである。
白か黒で塗られた立方体の箱が適当に垂直に積み重なった山が複数存在している。
先手は決められていない。
プレイヤーは交互に、自分の色の箱をひとつ選択しその箱を含めた上の箱をすべて取り除く。
最後の箱をとったものが勝利である。
どちらのプレイヤーを先手に指定しても互いに最適な手を打てば先手が勝ちになる、あるいは後手にして後手が勝ちになるような盤面を公平な盤面とする。
N個の山が与えられるので、その中からいくつかの山を選び初期局面とし、その初期局面の箱の数を最大化せよ。
出力はその箱の数。
N≦40, 1つの山の箱の数≦40

-----問題ここまで----- */
/* -----解説等-----

組合せゲーム理論の4,5章を読むと解けます。
これによって一つの山のゲーム値が決まるのでこれを全部組み合わせれば最大値が求めれれる。
しかし山は40個あるので半分全列挙をすることで解決ができる。
誤差は2進数なので回避できるというね...笑

----解説ここまで---- */

LL ans;
LL N;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);


	cin >> N;
	typedef pair<double,int> PDI;
	vector<PDI>subgame(N, PDI(0, 0));

	string player = "BW";
	FOR(i, 0, N) {
		string s; cin >> s;
		int pos = 0;
		double dyadic_val;
		int bef;
		if (s[pos] == player[0])dyadic_val = 1, bef = 0;
		else dyadic_val = -1, bef = 1;
		int conti = 1;
		double base = 1.0;
		FOR(j, 1, SZ(s)) {
			if (conti >= 1 && s[j] == player[bef]) {
				dyadic_val += (dyadic_val > 0 ? 1 : -1);
				conti++;
			}
			else if (s[j] == player[0]) {
				conti = 0;
				base *= 2.0;
				dyadic_val += 1 / base;
			}
			else if (s[j] == player[1]) {
				conti = 0;
				base *= 2.0;
				dyadic_val -= 1 / base;
			}
			//debug(conti);
		}
		subgame[i] = PDI(dyadic_val,SZ(s));
		//debug(dyadic_val);
	}

	//SZで半分全列挙、ただしdoubleが0.
	int N1 = N / 2;
	vector<PDI>v1(1 << N1, PDI(0, 0));
	FOR(i, 0, 1 << N1) {
		FOR(j, 0, N1) {
			if (i & (1 << j)) {
				v1[i].first += subgame[j].first;
				v1[i].second+=subgame[j].second;
			}
		}
	}
	SORT(v1);
	int N2 = N - N1;
	FOR(i, 0, 1 << N2) {
		int sz = 0;
		double dyval = 0.0;
		FOR(j, 0, N2) {
			if (i&(1 << j)) {
				dyval+=subgame[N1 + j].first;
				sz+=subgame[N1 + j].second;
			}
		}
		int id = lower_bound(ALL(v1), PDI(-dyval,INF))-v1.begin();
		id--;
		if (id >= 0) {
			if (v1[id].first == -dyval) {
				ans = max(ans,(LL)v1[id].second+sz );
			}
		}
	}

	cout << ans << endl;


	return 0;
}

