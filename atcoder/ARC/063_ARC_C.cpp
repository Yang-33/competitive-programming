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

/* -----  2017/10/04  Problem: Nagoya_univ_contest_17_j  / Link: http://arc063.contest.atcoder.jp/tasks/arc063_c  ----- */
/* ------問題------

N 頂点の木があり、頂点には 1,2,…,N と番号が振られています。
i (1≦i≦N−1) 番目の辺は頂点 Ai と頂点 Bi を結んでいます。
高橋君は木の K 個の頂点に整数を書き込みました。具体的には、各 1≦j≦K について、
頂点 Vj に整数 Pj を書き込みました。その後、高橋君は居眠りを始めました。
木を見つけた青木君は、残りのすべての頂点に整数を書き込み、高橋君を驚かせようとしています。
高橋君を驚かせるためには、木が次の条件を満たさなければなりません。
条件: 辺で直接結ばれた 2 つの頂点に書かれている整数の差がちょうど 1 である。
残りのすべての頂点に書き込む整数を工夫することで、木が条件を満たすようにできるか判定してください。
もし可能な場合は、どのように整数を書き込めばよいかを具体的にひとつ求めて下さい。

-----問題ここまで----- */
/* -----解説等-----

値の埋まっているノードからの移動を考える。これに入る数字は次の点との偶奇の関係が二部グラフになっていることが分かる。
が、それは関係なくて、値の小さい方から大きく埋めていけばよい。

----解説ここまで---- */

LL N, K;

LL ans = 0LL;
int visit[100005];
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);


	cin >> N;
	vector<vector<int>>G(N, vector<int>());
	FOR(i, 0, N - 1) {
		int a, b; cin >> a >> b;
		a--; b--;
		G[a].PB(b);
		G[b].PB(a);
	}
	FOR(i, 0, 100005)visit[i] = -1;

	priority_queue<PII, vector<PII>, greater<PII>>pq;

	cin >> K;
	FOR(i, 0, K) {
		int a, b; cin >> a >> b;
		a--;
		visit[a] = b;
		pq.push(PII(b, a));
	}
	while (!pq.empty()) {
		int v = pq.top().second;
		pq.pop();
		FOR(i, 0, SZ(G[v])) {
			int u = G[v][i];
			if (visit[u] != -1) {
				if (abs(visit[u] - visit[v]) != 1) {
					cout << "No" << endl;
					return 0;
				}
			}
			else {
				visit[u] = visit[v] + 1;
				pq.push(PII(visit[u], u));
			}
		}

	}

	cout << "Yes" << "\n";
	FOR(i, 0, N) {
		cout << visit[i] << endl;
	}
	return 0;
}