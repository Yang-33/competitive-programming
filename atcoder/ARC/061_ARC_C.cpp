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

/* -----  2018/03/04  Problem: 061_arc_c / Link: https://arc061.contest.atcoder.jp/tasks/arc061_c?lang=en  ----- */
/* ------問題------

すぬけ君の住んでいる街には地下鉄が走っています。駅は全部で N 個あり、路線は全部で M 本あります。 駅には 1 から N までの整数が付けられています。また、それぞれの路線はある 1 つの会社によって運営されており、 それぞれの会社には会社をあらわす整数がつけられています。
i 番目 ( 1≤i≤M ) の路線は、駅 pi と 駅 qi を相互に結んでいます。途中に他の駅はありません。 また、この路線は会社 ci によって運営されています。 同じ駅を通る路線が複数あるときは、その駅で乗り換えることができます。
それぞれの会社について、同じ会社の路線を使い続ける限り料金は 1 ですが、別の会社の路線に乗り換えるたびに新たに料金が 1 かかります。 ある会社を利用し、別の会社を利用してからまた最初の会社を利用する場合でも、再び料金を払う必要があります。
すぬけ君は、駅 1 を出発し、地下鉄を利用して駅 N に行きたいです。移動にかかる料金の最小値を求めてください。

-----問題ここまで----- */
/* -----解説等-----

駅と会社の二部グラフ的なものを考える。
このとき頂点間をコスト1で結ぶと二倍かかるけど目的のグラフを表現できていることになる。
同じ番号だが独立している会社の線路をわけないといけないが、これはUnionFindで各連結成分の代表点に番号を振って、別の会社として扱ってあげれば良い。
最後に二倍かかっているので半分にしたものが答え

切り分けるのできないかなーって思ったけどできた。

----解説ここまで---- */




struct UnionFind {
	vector<int> data;
	UnionFind(int n) { data.assign(n, -1); }
	bool unionSet(int x, int y) {
		x = root(x); y = root(y);
		if (x != y) {
			if (data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
		}
		return x != y;
	}
	bool same(int x, int y) { return root(x) == root(y); }
	int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
	int size(int x) { return -data[root(x)]; }
	void initV(int x) { data[x] = -1; }
};

VL Dijkstra(vector<vector<PLL>>& G, int s) {
	VL dist(SZ(G), LINF);
	dist[s] = 0;
	priority_queue<PLL, vector<PLL>, greater<PLL>> que;
	que.push(PLL(0LL, s));

	while (!que.empty()) {
		PLL p = que.top(); que.pop();
		int v; /* 頂点*/ long long d; /* 頂点vまでの距離 */
		tie(d, v) = p;

		if (d > dist[v]) continue; 

		FOR(i, 0, (int)G[v].size()) {
			int nv = G[v][i].first; 
			if (dist[nv] > dist[v] + G[v][i].second) {
				dist[nv] = dist[v] + G[v][i].second;
				que.push(PLL(dist[nv], nv)); 
			}
		}
	}
	return dist;
}


LL N, M;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	vector<vector<PLL>>G(1000006);
	vector<vector<PII>>CG(1000006);

	FOR(i, 0, M) {
		int a, b, c;
		cin >> a >> b >> c;
		a--; b--; c--;
		CG[c].push_back(PII(a,b));
	}


	// 集合を切り分ける
	UnionFind uf(N);
	VI used(N, 0);
	VI id(1000006,-1);
	int idnum = N;
	FOR(c, 0, 1000006) {
		FOR(i, 0, SZ(CG[c])) {
			PII cg = CG[c][i];
			uf.initV(cg.first); uf.initV(cg.second);
			id[cg.first] = -1; id[cg.second] = -1;
			used[cg.first] = used[cg.second] = 0;
		}

		FOR(i, 0, SZ(CG[c])) {
			PII cg = CG[c][i];
			uf.unionSet(cg.first, cg.second);
		}

		FOR(i, 0, SZ(CG[c])) {
			PII cg = CG[c][i];
			if (!used[cg.first]) {
				used[cg.first] = 1;
				int root = uf.root(cg.first);
				if (id[root] == -1)id[root] = idnum++;
				G[id[root]].push_back(PLL(cg.first, 1));
				G[cg.first].push_back(PLL(id[root], 1));
			}
			if (!used[cg.second]) {
				used[cg.second] = 1;
				int root = uf.root(cg.second);
				if (id[root] == -1)id[root] = idnum++;
				G[id[root]].push_back(PLL(cg.second, 1));
				G[cg.second].push_back(PLL(id[root], 1));
			}
		}
	}
	VL dist = Dijkstra(G, 0);
	if (dist[N - 1] >= LINF) {
		cout << -1 << endl;
	}
	else cout << dist[N - 1]/2 << endl;

	return 0;
}
