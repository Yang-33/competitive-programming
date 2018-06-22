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

/* -----  2018/06/24  Problem: AOJ 2821 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2821  ----- */
/* ------問題------

根なし木の同型性判定(tree in forest)

-----問題ここまで----- */
/* -----解説等-----

多項式hashにしたら落ちたので泣く泣く書き直した
あと手元だとstackoverflowしたので木の情報パートは非再帰ベースにした(最悪N回再帰する)
hashパートは中心からやるので非再帰でなくても大丈夫。(300000がダメで半分なら全然良い?)

北大コンテストは教育的でありがたい…

----解説ここまで---- */



typedef vector< vector<int> > Graph;
typedef long long int ll;

Graph ginput(int n, int m) {
	Graph G(n);
	for (int i = 0; i < m; i++) {
		int s, t; cin >> s >> t;
		s--; t--;
		G[s].push_back(t);
		G[t].push_back(s);
	}
	return G;
}

vector<Graph> Forest2Trees(Graph &G) {
	int n = (int)G.size();
	vector<int> vtxid(n, -1);

	vector<Graph> ret;
	for (int i = 0; i < n; i++) {
		if (vtxid[i] >= 0) continue;
		Graph Tree(1);
		int cur = 0;
		vtxid[i] = cur++;

		queue<int> q; q.push(i);
		while (!q.empty()) {
			int k = q.front(); q.pop();
			for (size_t x = 0; x < G[k].size(); x++) {
				int to = G[k][x];
				if (vtxid[to] >= 0) continue;
				vtxid[to] = cur++;
				Tree.push_back(vector<int>());
				Tree[vtxid[k]].push_back(vtxid[to]);
				Tree[vtxid[to]].push_back(vtxid[k]);
				q.push(to);
			}
		}
		ret.push_back(Tree);
	}
	return ret;
}

vector<int> vs;

void predfsStack(int rt, const vector<vector<int>>& G, vector<int>&cnt) {
	using T = pair<int, int>;
	int N = (int)G.size();
	vector<int>par(N);
	cnt = vector<int>(N, 1);
	stack<T> st;
	par[rt] = -1;
	st.emplace(rt, 0);
	while (!st.empty()) {
		int v = st.top().first;
		int &i = st.top().second;
		if (i < (int)G[v].size()) {
			int u = G[v][i++];
			if (u == par[v])continue;
			par[u] = v;
			st.emplace(u, 0);
		}
		else {
			st.pop();
			vs.push_back(v);
			for (int j = 0; j < (int)G[v].size(); j++) {
				int u = G[v][j];
				if (u == par[v])continue;
				cnt[v] += cnt[u];
			}
		}
	}
}

vector<int> getCenters1(Graph &G) {
	vs.clear();

	vector<int>cnt;
	predfsStack(0, G, cnt);

	vector<int> cs;
	int n = vs.size();
	for (int vv : vs) {
		bool ok = true;
		for (int ch : G[vv]) {
			if (cnt[ch] > cnt[vv])continue;
			if (cnt[ch] > n / 2)ok = false;
		}
		if (n - cnt[vv] > n / 2)ok = false;
		if (ok) {
			cs.push_back(vv);
		}
	}
	return cs;
}

map<string, ll> HASHMAP;
ll cntPattern, TreeHash;

ll getHash(Graph &G, int point, int parent = -1) {// 非再帰にするとえらいことになる
												  // leaf
	if (G[point].size() == 1 && parent != -1)
		return HASHMAP["0"] = 1;

	vector<string> rec;
	for (size_t i = 0; i < G[point].size(); i++) {
		int to = G[point][i];
		if (to == parent) continue;
		ll temp = getHash(G, to, point);
		rec.push_back(to_string(temp));
	}
	sort(rec.begin(), rec.end());
	string pat = "";
	for (size_t i = 0; i < rec.size(); i++) pat += rec[i];
	if (!HASHMAP.count(pat)) HASHMAP[pat] = ++cntPattern;
	return HASHMAP[pat];
}

int main() {
	cntPattern = 1;
	int s1, s2;
	int n1, m1; cin >> n1 >> m1;
	Graph Forest = ginput(n1, m1);
	vector<Graph> Trees = Forest2Trees(Forest);

	int n2; cin >> n2;
	Graph Pattern = ginput(n2, n2 - 1);
	vector<int> patCenters = getCenters1(Pattern);
	s1 = (int)patCenters.size();
	vector<ll> patHashes;
	for (int i = 0; i < s1; i++)
		patHashes.push_back(getHash(Pattern, patCenters[i]));

	int ans = 0;
	for (size_t i = 0; i < Trees.size(); i++) {
		if (Trees[i].size() != Pattern.size()) continue;
		vector<int> treeCenters = getCenters1(Trees[i]);
		s2 = (int)treeCenters.size();
		if (s1 != s2) continue;
		for (int j = 0; j < s2; j++) {
			ll treeHash = getHash(Trees[i], treeCenters[j]);
			if (treeHash == patHashes[0]) {
				ans++; break;
			}
		}
	}
	cout << ans << endl;
	return 0;
}