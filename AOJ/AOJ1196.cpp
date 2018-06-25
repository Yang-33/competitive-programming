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

/* -----  2018/06/25  Problem: AOJ 1196 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1196  ----- */
/* ------問題------

ICPC諸島は，かつて観光地として親しまれていたが， このたび，自然保護のため，全ての人工施設を撤廃して人の立ち入りを禁止することが決定された． このプロジェクトでいちばん難しいのは島々を結ぶ橋をすべて撤去することである．
ICPC諸島には島の数 n に対して n-1 個の橋があり，どの島から島へも， 橋を何回か渡れば到達することができるようになっている． 橋の撤去工事の作業チームは，好きな島からスタートして，繰り返し以下のいずれかの行動をとることができる．
今いる島に繋がっている橋を一つ渡って隣の島に移動する．
今いる島に繋がっている橋を一つ撤去する．撤去作業後は同じ島に留まる．
ただし当然ながら，一度撤去してしまった橋は二度と，どちらの方向にも渡ることができない． 橋を渡る場合も，橋を撤去する場合も，橋の長さに比例する時間がかかる． 全ての橋を撤去するのに必要な最短の時間を求めて欲しい． 作業チームのスタートする島と作業を終える島が異なっていても構わない．

-----問題ここまで----- */
/* -----解説等-----

次数1は考えない。するとのこったグラフについて直径をもとめればおわる。

----解説ここまで---- */

PLL didfs(int v, int p, const vector<vector<PLL>>&G) {
	PLL ret = PLL(0, v);
	FOR(i, 0, (int)G[v].size()) {
		if (G[v][i].first == p)continue;
		PLL temp = didfs(G[v][i].first, v, G);
		temp.first += G[v][i].second;
		ret = max(ret, temp);
	}
	return ret;
}

LL diamiter(int S, const vector<vector<PLL>>& G) {
	PLL p = didfs(S, -1, G);
	PLL q = didfs(p.second, -1, G);
	//return PLL(p.second, q.second);
	return q.first;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);


	int N;
	while (cin >> N, N) {
		using tp = tuple<int, int, int>;
		vector<tp>edge;
		VI deg(N+100000, 0);
		FOR(i, 0, N - 1) {
			int p; cin >> p;
			p--;
			deg[i+1]++; deg[p]++;
			edge.emplace_back(tp(i+1,p,0));
		}
		LL ans = 0;
		FOR(i, 0, N - 1) {
			int d; cin >> d;
			ans += d;
			int a, b;
			tie(a, b,ignore) = edge[i];
			edge[i] = tp(a, b, d);
		}
		vector<vector<PLL>>G(N+100000);
		LL travel = 0;
		int id;
		FOR(i, 0, N - 1) {
			int a, b, c;
			tie(a, b, c) = edge[i];
			if (deg[a] > 1 && deg[b] > 1) {
				id = a;
				G[a].push_back(PII(b, c));
				G[b].push_back(PII(a, c));
				travel += 2 * c;
			}
		}
		cout << ans + travel - diamiter(id,G) << endl;

	}

	return 0;
}
