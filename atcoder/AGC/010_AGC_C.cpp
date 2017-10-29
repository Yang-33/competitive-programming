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

/* -----  2017/10/11  Problem: N18_f AGC010 C / Link: http://agc010.contest.atcoder.jp/tasks/agc010_c  ----- */
/* ------問題------

N 頂点からなる木があり、頂点には 1 から N の番号がついています。 また、N−1 本の辺の内、i 番目の辺は頂点 ai と頂点 bi を結んでいます。
今、各頂点 i には Ai 個の石が置いてあります。 以下の操作を繰り返して、全ての石を取り除くことができるか判定してください。
相異なる 2 つの葉を一組選ぶ。そして、その 2 頂点間のパス上にある頂点全てからちょうど 1 つ石を取り除く。
ただし、葉とは木の頂点で次数が 1 の頂点を指し、選んだ葉自体もパス上の頂点として考える。
石が置かれていない頂点がパス上にあるときは、その操作を行えないことに注意してください。

-----問題ここまで----- */
/* -----解説等-----

二段の根付き木を考える。このとき、親ノードの値は子ノードの総和の半分であればよい。
次に根以外を含む部分着について根以外の頂点を根として考える。
このとき、親ノードは子ノードの総和の半分以上であればまずはさらに上の部分木に情報を渡すことができる。
子ノードの総和が親ノードの二倍より大きい場合はこれは存在しない。
また、子ノードの値が必ず親ノードを通過して作成可能かを確認する必要がある。
これを再帰的に繰り返せばよい。
条件判定なので値の割り振りは考えなくてもよい。

----解説ここまで---- */

LL N;
LL a[100005];
LL ans = 1;//okか
vector<vector<LL>>G;

LL f(LL u, LL p) {
	VL v;
	FOR(i, 0, SZ(G[u])) {
		if (G[u][i] != p)v.push_back(G[u][i]);
	}
	
	if (SZ(v) == 0)return a[u];//not ch

	LL sum = 0; LL maxv = -1;
	FOR(i, 0, SZ(v)) {
		LL t = f(v[i], u);
		sum += t;
		maxv = max(maxv, t);
	}
	if (sum < a[u]) { ans = 0; return 0; }//普通にしたが少ない
	
	LL up = min(sum / 2, sum - maxv);//これだけしか操作ができない
	LL res = sum - a[u];//あまり
	if (res > up) { ans = 0; return 0; }//ゆるさない
	
	return sum - res * 2;//持ちあげるぶん
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	FOR(i, 0, N)cin >> a[i];
	G = vector<vector<LL>>(N, vector<LL>());
	FOR(i, 0, N - 1) {
		LL a, b; cin >> a >> b;
		a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	if (N == 2) {
		cout << ((a[0]==a[1])?"YES":"NO") << endl;
		return 0;
	}
	LL root = -1;
	FOR(i, 0, N)if (SZ(G[i]) >= 2)root = i;
	LL res=f(root, -1);
	
	cout << ((ans&&res==0)?"YES":"NO") << "\n";

	return 0;
}