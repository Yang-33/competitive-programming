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

/* -----  2017/11/11  Problem: ABC 085 C / Link: http://arc085.contest.atcoder.jp/tasks/arc085_c  ----- */
/* ------問題------

宝石がN 個あり，それぞれ1,2,...,N と数が書かれています。
あなたは，以下の操作を好きなだけ行うことが出来ます(一度も行わなくてもよいです)。
正整数x を選ぶ。x の倍数が書かれた宝石を全て叩き割る。
そして，i が書かれていた宝石が割られずに残っていた場合，
ai 円貰います。 ただし，このai は負の場合もあり，その場合はお金を払わなくてはいけません。
うまく操作を行った時，あなたは最大で何円お金を貰えるでしょうか？

-----問題ここまで----- */
/* -----解説等-----

埋める燃やすのスライドを参考
二分類な問題でDPが厳しいときは最小カットを考えるとよいらしい
yosupoさんブログも参照。

二分類するときにA-Bが同じばしょにふくまれないときに罰金を考える。
燃やすを考えると負であるa[i]はあるとダメなので選択する側と異なるときSから|a[i]|の辺を張る。
埋めるを考えると正であるa[i]は選択される側では嬉しくない。これは先にa[i]を貰っているときに選択していないときにa[i]だけ回収されてしまう
とみれるので、a[i]をTに張る。
今回はjがiの倍数でiが壊されているならばjも壊されてないといけないため、INFをi->jに張る。
以上で全ての制約を最小カットに与えることができた。
これで非負のsigma a[i] - (最小カット)が答えになる。
PSP最強のお気持ちになった！

----解説ここまで---- */

LL N;

LL ans = 0LL;


struct DINIC {
#define  MAX_V 305
	const LL INF = 1LL<<60LL;
	struct edge {
		int to; LL cap, rev;
		edge() {}
		edge(int to, LL cap, LL rev) :to(to), cap(cap), rev(rev) {}
	};

	vector<edge> G[MAX_V];
	LL level[MAX_V], iter[MAX_V];

	void add_edge(int from, int to, LL cap) {
		G[from].push_back(edge(to, cap, G[to].size()));
		G[to].push_back(edge(from, 0, G[from].size() - 1));
	}

	void bfs(int s) {
		memset(level, -1, sizeof(level));
		queue<int> q;
		level[s] = 0;
		q.push(s);
		while (!q.empty()) {
			int v = q.front(); q.pop();
			FOR(i, 0, (int)G[v].size()) {
				edge &e = G[v][i];
				if (e.cap > 0 && level[e.to] < 0) {
					level[e.to] = level[v] + 1;
					q.push(e.to);
				}
			}
		}
	}

	LL dfs(int v, int t, LL f) {
		if (v == t) return f;
		for (LL &i = iter[v]; i < (int)G[v].size(); ++i) {
			edge &e = G[v][i];
			if (e.cap > 0 && level[v] < level[e.to]) {
				LL d = dfs(e.to, t, min(f, e.cap));
				if (d > 0) {
					e.cap -= d;
					G[e.to][e.rev].cap += d;
					return d;
				}
			}
		}
		return 0;
	}

	LL max_flow(int s, int t) {
		LL flow = 0;
		while (true) {
			bfs(s);
			if (level[t] < 0) return flow;
			memset(iter, 0, sizeof(iter));
			LL f;
			while ((f = dfs(s, t, INF)) > 0)
				flow += f;
		}
	}

#undef  MAX_V 
};


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	scanf("%lld", &N);
	VL a(N);
	LL sum = 0;
	FOR(i, 0, N) {
		scanf("%lld", &a[i]);
		if(a[i]>0)sum += a[i];
	}
	DINIC F;
	int s = 0;
	int t = N + 4;
	FOR(i, 0, N) {
		if (a[i] < 0)
			F.add_edge(s, i + 1, -a[i]);
		else F.add_edge(i+1, t, a[i]);
	}
	FOR(i, 1, N + 1) {
		FOR(j, i+1, N + 1) {
			if (j%i == 0) {
				F.add_edge(i, j, 1LL<<50LL);
			}
		}
	}

	ans = sum-F.max_flow(s,t);



	printf("%lld\n", ans);

	return 0;
}
