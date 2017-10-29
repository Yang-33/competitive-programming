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
#define debug(x) cout << #x << ": " << x 
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2017/10/11  Problem: N18_e ARC060 E / Link: https://arc060.contest.atcoder.jp/tasks/arc060_c  ----- */
/* ------問題------

N 軒のホテルが一直線上に並んでいます。i (1≤i≤N) 番目のホテルは、座標 xi に位置しています。
旅行者である高橋君には、次の 2 つの信念があります。
高橋君の 1 日の移動距離は L を超えない。
高橋君は野宿をしない。すなわち、1 日の終わりには必ずいずれかのホテルにいなければならない。
Q 個のクエリが与えられます。j (1≤j≤Q) 番目のクエリとして、異なる 2 つの整数 aj, bj が与えられます。 
各クエリについて、前述の信念をともに守った上で、高橋君が aj 番目のホテルから bj 番目のホテルに移動するために必要な最小日数を求めてください。 
なお、高橋君が aj 番目のホテルから bj 番目のホテルに移動できることは保証されます。

-----問題ここまで----- */
/* -----解説等-----

ダブリングのコツ
これも半開区間にするとよい
はじっこがめんどくさいので、半開区間
結局移動できるということを利用する
おかづきさんに見てもらって直したけど
もういっかい自分でやった方がよさそう。

->やった
dist[j][i]のi=0を移動していないにしたのでクエリの応答がつらい添え次になった。つらいさんなのだ

----解説ここまで---- */

LL N, L, Q;
LL ans = 0LL;
LL dist[100005][31];
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	VL x(N, 0);
	FOR(i, 0, N) {
		cin >> x[i];
	}
	FOR(i, 0, 100005)FOR(j, 0, 31)dist[i][j] = -1;
	cin >> L >> Q;
	FOR(i, 0, N) {
		int id = upper_bound(ALL(x), x[i] + L) - x.begin();
		id--;

		dist[i][0] = i;
		dist[i][1] = id;
	}
	// ->だけつくる 2^(i-1)回の移動
	FOR(i, 1, 30) {
		FOR(j, 0, N) {
			dist[j][i + 1] = dist[dist[j][i]][i];
		}
	}

	FOR(i, 0, Q) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		if (a > b)swap(a, b);
		ans = 0;
		int pos = a;

		while (pos < b) {
			FOR(k, 2, 30) {
				if (b<=dist[pos][k]) {
					ans += 1 << (k-2);
					pos = dist[pos][k - 1];
					break;
				}
			}
		}
		cout << ans << endl;
	}

	return 0;
}