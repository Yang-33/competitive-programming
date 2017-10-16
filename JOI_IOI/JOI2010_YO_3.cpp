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

/* -----  2017/10/16  Problem: nagoya_19_08 JOI2010予選 3 / Link: http://joi2010yo.contest.atcoder.jp/tasks/joi2010yo_c  ----- */
/* ------問題------

あなたはクリスマスパーティーに学校内の自分の友達と，自分の友達の友達を招待することにした． あなたの通う学校の生徒数は n 人であり，それぞれの生徒には 1 から n までの番号が割り振られている． あなたの番号は 1 である． あなたの手元には，誰と誰が友達であるかを記したリストがある． このリストをもとに， あなたがクリスマスパーティーに招待する生徒数を求めるプログラムを作成せよ．

-----問題ここまで----- */
/* -----解説等-----

bsfという関数名を書いて中身でdfsをして5分をどぶに捨てました
BFSをするとうれしくなれます。

----解説ここまで---- */

LL N, M;

LL ans = 0LL;
VVI G;
int cnt[502];
using T = tuple<int, int, int>;
void bfs() {
	queue<T>Q;
	Q.push(T(0, -1, 0));
	cnt[0] = 0;
	while (!Q.empty()) {
		int u, p, dep;
		tie(u, p, dep) = Q.front();
		Q.pop();
		FOR(i, 0, SZ(G[u])) {
			int nv = G[u][i];
			if (nv == p)continue;
			if (cnt[nv] != -1)continue;
			cnt[nv] = dep + 1;
			Q.push(T(nv, u, dep + 1));
		}
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	G = VVI(N, VI());
	FOR(i, 0, M) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	FOR(i, 0, N)cnt[i] = -1;
	bfs();
	FOR(i, 1, N) {
		if (cnt[i] >= 0 && cnt[i] <= 2)ans++;
	}

	cout << ans << "\n";

	return 0;
}