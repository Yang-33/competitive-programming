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

/* -----  2018/02/24  Problem: code-festival-2016-final_c / Link: https://cf16-final.contest.atcoder.jp/tasks/codefestival_2016_final_c?lang=en  ----- */
/* ------問題------

ある星には M 種類の言語があり、1-M の番号が付けられています。

この星のある年のCODE FESTIVALには星中から N 人の参加者が集まりました。

i(1≦i≦N) 人目の参加者は Ki 種類の言語 Li,1,Li,2,…,Li,Ki を話すことが出来ます。

ある 2 人は以下のいずれかの条件を満たすときに限り、コミュニケーションを取ることが出来ます。

2 人ともが話すことの出来る言語が存在する。
ある人 X が存在して、 2 人ともが X とコミュニケーションを取ることが出来る。
このとき、N 人すべての参加者が他のすべての参加者とコミュニケーションを取ることが出来るかどうかを判定してください。

-----問題ここまで----- */
/* -----解説等-----

何でもかんでも繋がっていれば良い
言語と人をつなぐとこのグラフについて人が連結になっていればコミュニケーションできるという意味になる

----解説ここまで---- */

LL N,M;

LL ans = 0LL;

void dfs(int v, int p, VVI &G, VI& visit) {
	visit[v] = 1;
	FOR(i, 0, SZ(G[v])) {
		int nx = G[v][i];
		if (nx != p && !visit[nx])dfs(nx, v, G, visit);
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N>>M;
	VVI G(N + M);
	FOR(i, 0, N) {
		int k;
		cin >> k;
		FOR(j, 0, k) {
			int lg;
			cin >> lg;
			lg--;
			lg += N;
			G[i].push_back(lg);
			G[lg].push_back(i);
		}
	}

	VI visit(N+M);
	dfs(0,-1,G,visit);
	ans = 1;
	FOR(i, 0, N) {
		if (!visit[i])ans = 0;
	}
	cout << (ans?"YES":"NO") << "\n";

	return 0;
}
