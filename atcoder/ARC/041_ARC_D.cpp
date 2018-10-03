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

/* -----  2018/10/03  Problem: ARC 041 D / Link: http://arc041.contest.atcoder.jp/tasks/arc041_d  ----- */
/* ------問題------

N 個の頂点と M 本の辺からなる無向グラフが与えられる。 グラフは連結で、自己ループや多重辺を含まない。 辺は 1 から M まで番号が振られている。

はじめ、辺には色が塗られていない。 高橋君は i (1≦i≦M) 番目の辺に色 ci が塗られているようにしたい。 ただし、ci は r（赤）または b（青）である。 高橋君は次のようにして辺に色を塗る。

まず、好きな頂点を始点に選ぶ。以降、「隣接する頂点へ移動する」というステップを好きなだけ繰り返す。
各ステップごとに使われた辺に色を塗る。このとき、奇数回目のステップでは赤を塗り、偶数回目のステップでは青を塗る。
既に色が塗られている辺に色を塗ると、新しい色で上書きされる。
すべての辺に目標の色が塗られているようにできるか判定せよ。

-----問題ここまで----- */
/* -----解説等-----

順番に考えると壊れる。奇数閉路をたどると割と強いが奇数閉路自体の値の割り振りを思いつくことができなかったので冷えていた。

逆から考える。すると、一番上だけを考えることになるのでその後の遷移を無視できる。(最初のものは実質上書きされるので)
無視したらあとは実際に塗れるかを判定すれば良いことになる。
これは、ある点を終端としたときに戻ってくる方を割り当てるだけなので、戻ってくる必要はなくなる。
よってO(M)の巡回をするだけになる。

また、奇数閉路は登場して、奇数閉路を作成できるならばOKになる。必要十分を考えようね…
非自明だけど面白いし賢い！

----解説ここまで---- */


int visit[2003];
int color[2003];
int a[2003], b[2003], c[2003];
VVI G;
void f(int v, int co, int t) {
	if (color[v] < 0) { color[v] = t; }
	else if ((t - color[v]) % 2) { fill(visit, visit + 2003, 1); return; }

	for (int id : G[v]) {
		int nxa = a[id];
		int nxb = b[id];
		int nxc = c[id];
		int to = v ^ nxa ^ nxb;
		if (visit[id])continue;
		if (nxc == co) {
			visit[id] = 1;
			f(to, !co, t + 1);
		}
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, M; cin >> N >> M;

	G = VVI(N);
	FOR(i, 0, M) {
		char cc;
		cin >> a[i] >> b[i] >> cc;
		a[i]--, b[i]--;
		c[i] = cc == 'r';
		G[a[i]].push_back(i);
		G[b[i]].push_back(i);
	}

	// 末尾からやっていく ある辺をedge C で塗って移動できるか 先に塗った色は考慮しなくて良いので、適当に塗れる

	FOR(s, 0, N)FOR(sc, 0, 2) {
		fill(visit, visit + 2003, 0);
		fill(color, color + 2003, -1);
		f(s, sc, 0);
		bool res = 1;
		FOR(i, 0, M) {
			res &= visit[i];
		}
		if (res) {
			cout << "Yes" << endl;
			return 0;
		}
	}



	cout << "No" << endl;

	return 0;
}
