#pragma GCC optimize ("-O3") 
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define SZ(a) (unsigned int)((a).size())
#define FOR(i, s, e) for (unsigned int(i) = (s); (i) < (e); (i)++)

#ifdef YANG33
#include "mydebug.hpp"
#else
#define DD(x) 
#endif

/* -----  2019/06/14  Problem: AOJ 2403 / Link: https://o...content-available-to-author-only...c.jp/challenges/search/volumes/2403  ----- */

// 重み付き最大独立集合を求める(補グラフは重み最大クリーク)
// ※AOJの実装のために頂点0は必ず選択するようになっている(N-1頂点で解いていると思えばOK)
// g++ -O3 

// 基本的に(今選択した重みの和)+(まだ選択できる重みの和)<=(現在持っている解)　なら打ち切る
// できる限り定数倍を小さくする実装を心がけた

// [定数倍にからむもの]
// - 01の状態をbitsetで管理 (1/64倍 だいたい書き換えた)
// - 次数を管理して孤立点は予め削除 (実装した)
// - 非連結になったら別で解く (実装してない)

// [使用方法]
// - 入力ファイルはmtx形式のものを標準入力で渡す
// - 1-indexの入力
// - const int bssizeの値は頂点数+1 (定数倍高速化のため先に入力してコンパイルしないといけません...)


// [結果(N=40 aoj2403)]
// 1. ただの枝刈り(index順) sum:4.26s bitset使用
// 2. 逐次次数をみる sum: 0.17s bitset使用
// 3. 予め決めた重み降順 sum:0.04s bitset 使用  
// 4. BronKerbosch algorithm(クリークを求める実装) sum:0.68s bitset不使用
// 4-2. 4.をbitsetに書き換える sum:0.64s bitset使用
// 5. 逐次w(v)/deg(v)の降順でやる sum: 0.06s bitset使用



// [結果(N=64 E=704 hamming6-4)]
// 2. ave: 0s
// 5. ave: 0.02s

// [結果(N=70 E=1855 johnson8-4-4)]
// 2. ave: 0s
// 5. ave: 0s

// [結果(N=100 E=1824 hamming6-2)]
// 2. ave: 0s
// 5. ave: 0s

// [結果(N=100 E=100 SW-100-3-0d1-trail1)]
// 2. ave: 1.01s
// 5. ave: 35.02s
// 6. ave: 70.00s

// [結果(N=113 E=2196 infect-hyper)]
// 2. ave: 0.02s
// 5. ave: 0.7s

// [結果(N=143 E=623 email-enron-only)]
// 2. ave: 1600 s
// 5. ave: ? s

// [結果(N=200 E=14834 brock200-1)]
// 2. ave: 0s
// 5. ave: 0s

// [結果(N=200 E=1534 c-fat200-1)]
// 時間がかなりかかるので厳しい
// 2. ave:
// 5. ave:

// [結果(N=450 E=83198 frb30-15-1)]




// [TODO]
// using u32とかにしてわかりやすく
// 非連結の判定と実装
// Combinatorial Branch-and-Bound for the Maximum Weight Independent Set Problem の実装
// Exactly Solving the Maximum Weight Independent Set Problem on Large Real-World Graphs の実装
// 岩田先生が優勝していたやつの実装
// 「次数が多いものから見たほうが探索木の深さを浅くできる」⇨重みなし問題でなんとか

//using VI = vector<unsigned int>; for optimize TODO!!
using VI = vector<int>;
using VVI = vector<VI>;

using ULL = unsigned long long;
using VL = vector<ULL>;
using VVL = vector<VL>;

const int bssize = 450 + 1; // !!
using BS = bitset<bssize>;

template<size_t sz> struct bitset_comparer {
	bool operator() (const bitset<sz> &x, const bitset<sz> &y) const {
		for (int i = sz - 1; i >= 0; i--) { // Nが大きいときにもっと上手にやりたい
			if (x[i] ^ y[i]) return y[i];
		}
		return false;
	}
};



void f1(unsigned int id, const BS visit_mask, unsigned int cost,
	const VVI& G, const VI& W, const VI& suffix_sum, const vector<BS>& adj_mask, unsigned int& ans) {
	if (id == SZ(G)) {
		ans = max(ans, cost);
		return;
	}
	FOR(i, id, SZ(G)) {
		if (cost + suffix_sum[i] <= ans)break;
		if (visit_mask[i])continue;
		f1(i + 1, visit_mask | adj_mask[i], cost + W[i], G, W, suffix_sum, adj_mask, ans);
	}

	f1(SZ(G), visit_mask, cost, G, W, suffix_sum, adj_mask, ans);
}

void solve1(const VVI&G, const VI&W) {
	unsigned int N = SZ(W);
	vector<BS> adj_mask(N);
	FOR(i, 0, N) {
		adj_mask[i][i] = 1;
		for (auto&& j : G[i]) {
			adj_mask[i][j] = 1;
		}
	}
	VI suffix_sum(N, 0); // [i,N) これいらない…
	FOR(i, 0, N) {
		FOR(j, i, N) {
			suffix_sum[i] += W[j];
		}
	}
	unsigned int ans = 0;
	f1(1, adj_mask[0], W[0], G, W, suffix_sum, adj_mask, ans);
	printf("%u\n", ans);

}



// 孤立点の削除：なしだと遅い
unsigned int isolatedPoint(BS&visit, const VI&W, const vector<int>&deg) {
	unsigned int addscore = 0;
	// revをもてばvisitをこぴーせずできるけど…
	FOR(i, 0, SZ(W)) {
		if (deg[i] == 0 && visit[i] == 0) {
			addscore += W[i];
			visit[i] = 1;
		}
	}
	return addscore;
}
map<BS, unsigned int, bitset_comparer<bssize>>checked;

// 次数の降順
unsigned int f2(unsigned int usesum, unsigned int leftsum, unsigned int& ans, const BS& visit,
	const VVI& G, const VI& W, vector<int>& deg) {
	if (checked.find(visit) != checked.end()) {
		return checked[visit];
	}

	if (usesum + leftsum <= ans) {
		DD(de("!")); // 全然呼ばれない　何
		return 0;
	}
	// deg select v
	int v = -1;
	int mxdeg = 0;
	FOR(i, 0, SZ(W)) {
		if (visit[i])continue;
		if (mxdeg < deg[i]) {
			mxdeg = deg[i];
			v = i;
		}
	}
	unsigned int ret = 0;
	if (v >= 0) {
		// use v
		{
			VI nvs;
			BS nvisit = visit;
			nvisit[v] = 1; // v
			for (auto j : G[v]) {
				if (nvisit[j] == 0) {
					nvisit[j] = 1; // nx
					for (auto to : G[j]) {
						deg[to]--; // nnx
						nvs.push_back(to);
					}
				}
			}
			unsigned int isolated_score = isolatedPoint(nvisit, W, deg);

			ret = W[v] + isolated_score + f2(usesum + W[v] + isolated_score, leftsum - W[v] - isolated_score, ans, nvisit, G, W, deg);
			ans = max(ans, ret);

			{ // rev
				for (auto to : nvs) {
					deg[to]++;
				}

			}
		}


		{// no use v
			BS nvisit = visit;
			nvisit[v] = 1;
			for (auto j : G[v]) {
				deg[j]--;
			}

			unsigned int isolated_score = isolatedPoint(nvisit, W, deg);
			ret = max(ret, isolated_score + f2(usesum + isolated_score, leftsum - W[v] - isolated_score, ans, nvisit, G, W, deg));
			ans = max(ans, ret);
			for (auto j : G[v]) {
				deg[j]++;
			}
		}
	}
	return checked[visit] = ret;
}


// 逐次次数をみていくやつ
void solve2(const VVI&G, const VI&W) {
	checked.clear(); // test !

	unsigned int N = SZ(W);
	vector<int> deg(N);
	FOR(i, 0, N) {
		for (auto j : G[i]) {
			deg[j]++;
		}
	}
	BS visited;
	{ // for aoj 2403
		visited[0] = 1;
		for (auto j : G[0]) {
			if (!visited[j]) {
				visited[j] = 1;
				for (auto k : G[j]) {
					deg[k]--;
				}
			}
		}
	}
	unsigned int allsum = accumulate(W.begin(), W.end(), 0U);
	unsigned int isolated_score = isolatedPoint(visited, W, deg);
	unsigned int ans = 0;
	unsigned int ansv = W[0] + isolated_score + f2(W[0] + isolated_score, allsum - W[0] - isolated_score, ans, visited, G, W, deg);
	printf("%u\n", ansv);
}









void f3(unsigned int id, const BS visit_mask, unsigned int cost,
	const VVI& G, const VI& W, const VI& suffix_sum, const vector<BS>& adj_mask, const VI&idx, unsigned int& ans) {
	if (id == SZ(G)) {
		ans = max(ans, cost);
		return;
	}
	FOR(_, id, SZ(G)) {
		int i = idx[_];
		if (cost + suffix_sum[i] <= ans)break;
		if (visit_mask[i])continue;
		f3(_ + 1, visit_mask | adj_mask[i], cost + W[i], G, W, suffix_sum, adj_mask, idx, ans);
	}
	f3(SZ(G), visit_mask, cost, G, W, suffix_sum, adj_mask, idx, ans);
}

// 重み降順(意味なさそう) -> えーめっちゃ速い
void solve3(const VVI&G, const VI&W) {
	using PUU = pair<unsigned int, unsigned int>;
	unsigned int N = SZ(W);
	vector<PUU>ps(N);
	FOR(i, 1, N) {
		ps[i] = PUU(W[i], i);
	}
	sort(ps.begin() + 1, ps.end(), [](const PUU&a, const PUU&b) {
		if (a.first == b.first) {
			return a.second < b.second;
		}
		else {
			return a.first > b.first;
		}
	});

	VI idx(N, 0);
	FOR(i, 1, N)idx[i] = ps[i].second;

	vector<BS> adj_mask(N);
	FOR(i, 0, N) {
		adj_mask[i][i] = 1;
		for (auto&& j : G[i]) {
			adj_mask[i][j] = 1;
		}
	}
	VI suffix_sum(N, 0); // [i,N)
	for (auto i : idx) {
		bool ok = 0;
		for (auto j : idx) {
			if (i == j)ok = 1;
			if (ok) {
				suffix_sum[i] += W[j];
			}
		}
	}
	unsigned int ans = 0;

	f3(1, adj_mask[0], W[0], G, W, suffix_sum, adj_mask, idx, ans);
	printf("%u\n", ans);
}








inline unsigned int trail0(ULL s) { return (s ? __builtin_ctzll(s) : 64); }
int BronKerbosch(const vector<ULL>& g, ULL cur, ULL allowed, ULL forbidden, const VI& weights) {
	if (allowed == 0 && forbidden == 0) {
		// ここで集合がわかっているので処理
		int res = 0;
		bool ok = 0;
		for (unsigned int u = trail0(cur); u < SZ(g); u += trail0(cur >> (u + 1)) + 1) {
			ok |= u == 0;
			res += weights[u];// use vertex
		}
		if (!ok)res = 0;
		return res;
	}
	if (allowed == 0) return -1;
	int res = -1;
	unsigned int pivot = trail0(allowed | forbidden);
	ULL z = allowed & ~g[pivot];
	for (unsigned int u = trail0(z); u < SZ(g); u += trail0(z >> (u + 1)) + 1) {
		res = max(res, BronKerbosch(g, cur | (1ULL << u), allowed & g[u], forbidden & g[u], weights));
		allowed ^= 1ULL << u;
		forbidden |= 1ULL << u;
	}
	return res;
}

int maximum_independet_set(const VVI& G, const VI& weights) {
	unsigned int n = G.size();
	assert(n < 64);
	vector<ULL> g(n);
	FOR(i, 0, n) FOR(j, 0, n) if (i != j) g[i] |= (1ULL << j);
	FOR(i, 0, n) for (int j : G[i]) g[i] ^= (1ULL << j);
	return BronKerbosch(g, 0, (1ULL << n) - 1, 0, weights);
}

void solve4(const VVI&G, const VI&W) {
	int ans = maximum_independet_set(G, W);
	printf("%d\n", ans);
}












// 4. bitset ver.
inline unsigned int trail0(const BS& bs) {
	if (!bs.any())return bssize;
	return bs._Find_first();
}

int BronKerbosch_bs(const vector<BS>& g, BS cur, BS allowed, BS forbidden, const VI& weights) {
	if (allowed.count() == 0 && forbidden.count() == 0) {
		// ここで処理
		int res = 0;
		bool ok = 0;
		for (unsigned int u = trail0(cur); u < SZ(g); u += trail0(cur >> (u + 1)) + 1) {
			ok |= u == 0;
			res += weights[u];// use vertex
		}
		if (!ok)res = 0;
		return res;
	}
	if (allowed.count() == 0) return -1;
	int res = -1;
	unsigned int pivot = trail0(allowed | forbidden);
	BS z = allowed & ~g[pivot];
	for (unsigned int u = trail0(z); u < SZ(g); u += trail0(z >> (u + 1)) + 1) {
		BS t; t[u] = 1;
		res = max(res, BronKerbosch_bs(g, cur | t, allowed & g[u], forbidden & g[u], weights));
		allowed[u].flip();
		forbidden[u] = 1;
	}
	return res;
}

int maximum_independet_set_bs(const VVI& G, const VI& weights) {
	unsigned int n = G.size();
	assert(n < bssize);
	vector<BS> g(n);
	FOR(i, 0, n) FOR(j, 0, n) if (i != j) g[i][j] = 1;
	FOR(i, 0, n) for (int j : G[i]) g[i][j] = 0;
	BS cur, allowed, forbidden;
	FOR(i, 0, n)allowed[i] = 1;
	return BronKerbosch_bs(g, cur, allowed, forbidden, weights);
}

void solve4_2(const VVI&G, const VI&W) {
	int ans = maximum_independet_set_bs(G, W);
	printf("%d\n", ans);

}




map<BS, unsigned int, bitset_comparer<bssize>>checked5;

unsigned int f5(unsigned int usesum, unsigned int leftsum, unsigned int& ans, const BS& visit,
	const VVI& G, const VI& W, vector<int>& deg) {
	if (checked5.find(visit) != checked5.end()) { // memo
		return checked5[visit];
	}

	if (usesum + leftsum <= ans) {
		return 0;
	}
	// w(v)/deg(v) 
	int v = -1; {
		int mxW = -1;
		int mxdeg = 0;
		FOR(i, 0, SZ(W)) {
			if (visit[i])continue;
			if (mxW*deg[i] < W[i] * mxdeg) {
				mxdeg = deg[i];
				mxW = W[i];
				v = i;
			}
		}
	}
	unsigned int ret = 0;
	if (v >= 0) {
		{// use v
			VI nvs;
			BS nvisit = visit;
			nvisit[v] = 1; // v
			for (auto j : G[v]) {
				if (nvisit[j] == 0) {
					nvisit[j] = 1;
					for (auto to : G[j]) {
						deg[to]--;
						nvs.push_back(to);
					}
				}
			}
			unsigned int isolated_score = isolatedPoint(nvisit, W, deg);

			ret = W[v] + isolated_score + f5(usesum + W[v] + isolated_score, leftsum - W[v] - isolated_score, ans, nvisit, G, W, deg);
			ans = max(ans, ret);

			{ // rev
				for (auto to : nvs) {
					deg[to]++;
				}

			}
		}


		{// no use v
			BS nvisit = visit;
			nvisit[v] = 1;
			for (auto j : G[v]) {
				deg[j]--;
			}

			unsigned int isolated_score = isolatedPoint(nvisit, W, deg);
			ret = max(ret, isolated_score + f5(usesum + isolated_score, leftsum - W[v] - isolated_score, ans, nvisit, G, W, deg));
			ans = max(ans, ret);
			for (auto j : G[v]) {
				deg[j]++;
			}
		}
	}
	return checked5[visit] = ret;
}


// 逐次次数と重みを見る：w(v)/deg(v)
void solve5(const VVI&G, const VI&W) {
	checked5.clear();

	unsigned int N = SZ(W);
	vector<int> deg(N);
	FOR(i, 0, N) {
		for (auto j : G[i]) {
			deg[j]++;
		}
	}
	BS visited;
	{ // for aoj 2403
		visited[0] = 1;
		for (auto j : G[0]) {
			if (!visited[j]) {
				visited[j] = 1;
				for (auto k : G[j]) {
					deg[k]--;
				}
			}
		}
	}
	unsigned int allsum = accumulate(W.begin(), W.end(), 0U);
	unsigned int isolated_score = isolatedPoint(visited, W, deg);
	unsigned int ans = 0;
	unsigned int ansv = W[0] + isolated_score + f5(W[0] + isolated_score, allsum - W[0] - isolated_score, ans, visited, G, W, deg);
	printf("%u\n", ansv);
}


map<BS, unsigned int, bitset_comparer<bssize>>checked6;

unsigned int f6(unsigned int usesum, unsigned int leftsum, unsigned int& ans, const BS& visit,
	const VVI& G, const VI& W, vector<int>& deg) {
	if (checked6.find(visit) != checked6.end()) { // memo
		return checked6[visit];
	}

	if (usesum + leftsum <= ans) {
		return 0;
	}
	// w(v)/deg(v) 
	int v = -1; {
		int mxW = -1;
		int mxdeg = 0;
		FOR(i, 0, SZ(W)) {
			if (visit[i])continue;
			if (deg[i] > mxdeg) {
				mxdeg = deg[i];
				mxW = W[i];
				v = i;
			}
			else if (deg[i] == mxdeg) {
				if (mxW < W[i]) {
					mxW = W[i];
					v = i;
				}
			}
		}
	}
	unsigned int ret = 0;
	if (v >= 0) {
		{// use v
			VI nvs;
			BS nvisit = visit;
			nvisit[v] = 1; // v
			for (auto j : G[v]) {
				if (nvisit[j] == 0) {
					nvisit[j] = 1;
					for (auto to : G[j]) {
						deg[to]--;
						nvs.push_back(to);
					}
				}
			}
			unsigned int isolated_score = isolatedPoint(nvisit, W, deg);

			ret = W[v] + isolated_score + f6(usesum + W[v] + isolated_score, leftsum - W[v] - isolated_score, ans, nvisit, G, W, deg);
			ans = max(ans, ret);

			{ // rev
				for (auto to : nvs) {
					deg[to]++;
				}

			}
		}


		{// no use v
			BS nvisit = visit;
			nvisit[v] = 1;
			for (auto j : G[v]) {
				deg[j]--;
			}

			unsigned int isolated_score = isolatedPoint(nvisit, W, deg);
			ret = max(ret, isolated_score + f6(usesum + isolated_score, leftsum - W[v] - isolated_score, ans, nvisit, G, W, deg));
			ans = max(ans, ret);
			for (auto j : G[v]) {
				deg[j]++;
			}
		}
	}
	return checked6[visit] = ret;
}


// 逐次次数と重みを見る：deg if same max w
void solve6(const VVI&G, const VI&W) {
	checked6.clear();

	unsigned int N = SZ(W);
	vector<int> deg(N);
	FOR(i, 0, N) {
		for (auto j : G[i]) {
			deg[j]++;
		}
	}
	BS visited;
	{ // for aoj 2403
		visited[0] = 1;
		for (auto j : G[0]) {
			if (!visited[j]) {
				visited[j] = 1;
				for (auto k : G[j]) {
					deg[k]--;
				}
			}
		}
	}
	unsigned int allsum = accumulate(W.begin(), W.end(), 0U);
	unsigned int isolated_score = isolatedPoint(visited, W, deg);
	unsigned int ans = 0;
	unsigned int ansv = W[0] + isolated_score + f6(W[0] + isolated_score, allsum - W[0] - isolated_score, ans, visited, G, W, deg);
	printf("%u\n", ansv);
}


map<BS, unsigned int, bitset_comparer<bssize>>checked7;

unsigned int f7(unsigned int usesum, unsigned int leftsum, unsigned int& ans, const BS& visit,
	const VVI& G, const VI& W, vector<int>& deg) {
	if (checked7.find(visit) != checked7.end()) { // memo
		return checked7[visit];
	}

	if (usesum + leftsum <= ans) {
		return 0;
	}
	// w(v)/deg(v) 
	int v = -1; {
		int mxW = -1;
		int mxdeg = 1;
		FOR(i, 0, SZ(W)) {
			if (visit[i])continue;
			if (mxW*mxdeg < W[i] * deg[i]) {
				mxW = W[i];
				mxdeg = deg[i];
				v = i;
			}
			else if (mxW*mxdeg == W[i] * deg[i]) {
				if (mxdeg < deg[i]) {
					mxW = W[i];
					mxdeg = deg[i];
					v = i;
				}
			}
		}
	}
	unsigned int ret = 0;
	if (v >= 0) {
		{// use v
			VI nvs;
			BS nvisit = visit;
			nvisit[v] = 1; // v
			for (auto j : G[v]) {
				if (nvisit[j] == 0) {
					nvisit[j] = 1;
					for (auto to : G[j]) {
						deg[to]--;
						nvs.push_back(to);
					}
				}
			}
			unsigned int isolated_score = isolatedPoint(nvisit, W, deg);

			ret = W[v] + isolated_score + f7(usesum + W[v] + isolated_score, leftsum - W[v] - isolated_score, ans, nvisit, G, W, deg);
			ans = max(ans, ret);

			{ // rev
				for (auto to : nvs) {
					deg[to]++;
				}

			}
		}


		{// no use v
			BS nvisit = visit;
			nvisit[v] = 1;
			for (auto j : G[v]) {
				deg[j]--;
			}

			unsigned int isolated_score = isolatedPoint(nvisit, W, deg);
			ret = max(ret, isolated_score + f7(usesum + isolated_score, leftsum - W[v] - isolated_score, ans, nvisit, G, W, deg));
			ans = max(ans, ret);
			for (auto j : G[v]) {
				deg[j]++;
			}
		}
	}
	return checked7[visit] = ret;
}


// 逐次次数と重みを見る：deg if same max w
void solve7(const VVI&G, const VI&W) {
	checked7.clear();

	unsigned int N = SZ(W);
	vector<int> deg(N);
	FOR(i, 0, N) {
		for (auto j : G[i]) {
			deg[j]++;
		}
	}
	BS visited;
	{ // for aoj 2403
		visited[0] = 1;
		for (auto j : G[0]) {
			if (!visited[j]) {
				visited[j] = 1;
				for (auto k : G[j]) {
					deg[k]--;
				}
			}
		}
	}
	unsigned int allsum = accumulate(W.begin(), W.end(), 0U);
	unsigned int isolated_score = isolatedPoint(visited, W, deg);
	unsigned int ans = 0;
	unsigned int ansv = W[0] + isolated_score + f7(W[0] + isolated_score, allsum - W[0] - isolated_score, ans, visited, G, W, deg);
	printf("%u\n", ansv);
}

// optimize input
unsigned int ri() { unsigned int in; int y = scanf("%u", &in); y++; return in; }
string rs() { static char c[17]; int y = scanf("%s", c); y++; string s(c); return std::move(s); }

void Yang33Main() { // for aoj 2403
	double maxtime = 0;
	while (1) {
		unsigned int N = ri();
		if (!N)break;
		VVI G(N);
		VI W(N); {
			map<string, int>M;
			vector<vector<string>>g(N);
			FOR(i, 0, N) {
				string s = rs();
				M[s] = i;
				unsigned int w = ri();
				W[M[s]] = w;
				unsigned int n = ri();
				FOR(j, 0, n) {
					string t = rs();
					g[i].push_back(t);
				}
			}
			FOR(i, 0, N) {
				for (auto&& s : g[i]) {
					G[i].push_back(M[s]);
				}
			}
		}

		{
			clock_t beg = clock();
			{
				//solve1(G, W);
				//solve2(G, W);
				solve3(G, W);
				//solve4(G, W);
				//solve4_2(G, W);
				//solve5(G, W);
			}

			clock_t end = clock();
			maxtime = max(maxtime, double(end - beg) / CLOCKS_PER_SEC);
			//fprintf(stderr, "%.3f sec\n", double(end - beg) / CLOCKS_PER_SEC);
		}

		}
#ifdef YANG33
	fprintf(stderr, "worst case time [sec] :%.3f sec\n", maxtime);
#endif

	}


// 安心信頼の
#include<chrono>
#include<random>
struct randgen {
	mt19937_64 rng;
	randgen() :rng((int)std::chrono::steady_clock::now().time_since_epoch().count()) {}
	using LL = long long;
	LL getrand(LL s, LL t) { //[s,t)の乱数を得る
		return rng() % (t - s) + s;
	}
};

// graph
const VVI mtxparse() {
	// ゆっくりうけとってOK
	char str[100];
	scanf("%[^\n]", str);
	int N, X, M; cin >> N >> X >> M;
	cout << "V:=" << N << ", E:=" << M << endl;
	assert(N < bssize);
	VVI G(N);
	FOR(i, 0, M) {
		int a, b; cin >> a >> b;
		a--, b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	return G;
}

const VI randomWeight(const int N) {
	VI w(N);
	randgen r;
	FOR(i, 0, N) {
		w[i] = r.getrand(1, 10000);
	}
	return w;
}
int main() {
	//Yang33Main();
	auto G = mtxparse();
	auto W = randomWeight(SZ(G));
	if (0) {
		clock_t beg = clock();
		solve1(G, W);
		clock_t end = clock();
		cout << "solve1 " << double(end - beg) / CLOCKS_PER_SEC << endl;
	}
	{
		clock_t beg = clock();
		solve2(G, W);
		clock_t end = clock();
		cout << "solve2 " << double(end - beg) / CLOCKS_PER_SEC << endl;
	}
	if (0) {
		clock_t beg = clock();
		solve3(G, W);
		clock_t end = clock();
		cout << "solve3 " << double(end - beg) / CLOCKS_PER_SEC << endl;
	}
	 {
		clock_t beg = clock();
		solve4_2(G, W);
		clock_t end = clock();
		cout << "solve4.2 " << double(end - beg) / CLOCKS_PER_SEC << endl;
	}
	{
		clock_t beg = clock();
		solve5(G, W);
		clock_t end = clock();
		cout << "solve5 " << double(end - beg) / CLOCKS_PER_SEC << endl;
	}
	{
		clock_t beg = clock();
		solve6(G, W);
		clock_t end = clock();
		cout << "solve6 " << double(end - beg) / CLOCKS_PER_SEC << endl;
	}
	{
		clock_t beg = clock();
		solve7(G, W);
		clock_t end = clock();
		cout << "solve7 " << double(end - beg) / CLOCKS_PER_SEC << endl;
	}

	return 0;
}

