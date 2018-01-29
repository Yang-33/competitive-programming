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

/* -----  2018/01/29  Problem: ARC 090 B / Link: http://arc090.contest.atcoder.jp/tasks/arc090_b  ----- */
/* ------問題------

x 軸上に N 人の人が立っています。 人 i の位置を xi とします。 任意の i に対して、xi は 0 以上 109 以下の整数です。 同じ位置に複数の人が立っていることもありえます。
これらの人の位置に関する情報が M 個与えられます。 このうち i 個めの情報は (Li,Ri,Di) という形をしています。 この情報は、人 Ri は人 Li よりも距離 Di だけ右にいること、 すなわち、xRi−xLi=Di が成り立つことを表します。
これら M 個の情報のうちのいくつかに誤りがある可能性があることがわかりました。 与えられる M 個すべての情報と矛盾しないような値の組 (x1,x2,…,xN) が存在するかどうか判定してください。

-----問題ここまで----- */
/* -----解説等-----

相対値でいいので、一定の距離が決まっていれば反対側には負の辺を張れば良い。
連結とは限らない。

具体的には一箇所値を決めたら、その相対値を決定していく。
もし決めた値にアクセスするときは矛盾していないかを確認すれば良い。

別解として重み付きUFがあるらしい。(理解していない)

----解説ここまで---- */

LL N, M;

LL ans = 0LL;

void dfs(int v, int p, LL sum, vector<vector<PLL>>&G, VI& checked, VL &we) {

	//debug(v);
	checked[v] = 1;

	FOR(i, 0, SZ(G[v])) {
		int nx = G[v][i].first;
		LL pc = G[v][i].second;
		if (checked[nx]) {
			if (we[nx] != sum + pc) {
				ans = 0; return;
			}
			else { // ok
				;
			}
		}
		else {
			we[nx] = we[v] + pc;
			dfs(nx, v, we[nx], G, checked, we);
		}
	}

}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	VL L(M,0), R(M,0), D(M,0);
	VI checked(N, 0);
	VL we(N, 0);
	vector<vector<PLL>> G(N, vector<PLL>());

	FOR(i, 0, M) {
		cin >> L[i] >> R[i] >> D[i];
		L[i]--;
		R[i]--;
		G[L[i]].push_back(PLL(R[i], D[i]));
		G[R[i]].push_back(PLL(L[i], -D[i]));
	}
	ans = 1;
	/*debug(ans);
	we[L[0]] = 0;*/

	FOR(i, 0, N) {
		if (checked[i] == 0)
			dfs(i, -1, 0, G, checked, we);
	}
	if (ans == 1) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}

	return 0;
}
