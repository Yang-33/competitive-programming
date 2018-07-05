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

/* -----  2018/07/05  Problem: AOJ 1605 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/1605  ----- */
/* ------問題------

多くの小島からなる市があり，市民はそれらの島に住んでいる． 島から島へ渡るにはフェリーを使うしかなく，多くの市民は不便に感じている． そこで市長はすべての島を互いに行き来できるように橋を架けることにした．
市にはふたつの建設会社（A社とB社）がある． 市長がこれらに見積もりを請求し，いくつかの提案を次の形で得た： 「建設会社 A (または B) は島 u と島 v の間を結ぶ橋を w 億円で建造できる」．
市長はこれらの提案のうちいくつかを採用することで最も安い建造計画を作ろうとしている． ところが，もし市長が一方の会社の提案を多く採用すると，もう一方の会社は潰れてしまう． これはたったふたつしか建設会社がない市にとっては望ましくない． しかし一方で，無駄な建設だという批判を避けるには，全ての島を行き来できるようにするために必要最低限の本数の橋 (すなわち n−1 本の橋) しか採用できない． そこで，市長は予め建設会社 A の提案を丁度 k 個，建設会社 B の提案を丁度 n−1−k 個採用することに決めた．
あなたの仕事は，条件を満たす中で最も安い計画の費用を計算するプログラムを作ることである． ここで，計画の費用とは採用されるすべての提案の費用の合計のことをいう．

-----問題ここまで----- */
/* -----解説等-----

緩和問題&マトロイドらしい…
(証明をすると)貪欲でできる。
なるべくBに寄せた状態で、AをKに交換していけば良い。

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
};

#include<unordered_map>
int main() {

	using tp = tuple<int, int, int, int>;
	int N, M, K;
	while (scanf("%d%d%d",&N,&M,&K), N) {
		vector<tp>edge;
		int Asz = 0, Bsz = 0;
		FOR(i, 0, M) {
			int a, b, c; char d[2];
			scanf("%d%d%d%s", &a, &b, &c, d);
			a--, b--;
			edge.push_back(tp(d[0] == 'A', c, a, b));
			if (d[0] == 'A')Asz++;
			else Bsz++;
		}
		SORT(edge);
		int Acnt = 0, Bcnt = 0;
		unordered_map<int, bool>usededge;
		LL ans = 0;
		UnionFind uf(N);
		FOR(i, 0, M) {
			int isA, a, b, c;
			tie(isA, c, a, b) = edge[i];
			if (!uf.same(a, b)) {
				uf.unionSet(a, b);
				ans += c;
				usededge[i] = 1;
				if (!isA) {
					Bcnt++;
				}
				else Acnt++;
			}
		}
		// B to A 
		while (Acnt < K) {
			using ss = tuple<int, int, int>;
			ss Koho = ss(-INF,-1,-1);
			int checkF = 0;
			FOR(i, 0, Bsz) {// swpをきめる
				if (!usededge[i])continue;
				int c;
				tie(ignore, c, ignore, ignore) = edge[i];
				UnionFind uf2(N);
				FOR(j, 0, M) {
					if (i != j&&usededge[j]) {
						int x, y;
						tie(ignore, ignore, x, y) = edge[j];
						uf2.unionSet(x, y);
					}
				}
				FOR(j, Bsz, M) {
					int  e, f, g;
					tie(ignore, e, f, g) = edge[j];
					if (!uf2.same(f, g)) {
						Koho = max(Koho, ss(c-e, i,j));
						checkF = 1;
					}
				}

			}
			if (!checkF)break;
			int cc, vv, ww;
			tie(cc, vv, ww) = Koho;
			if (cc == -INF)break;
			usededge[vv] = 0;
			usededge[ww] = 1;
			ans -= cc;
			Acnt++;
			Bcnt--;

		}

		if (Acnt + Bcnt == N - 1 && Acnt == K) {
			cout << ans << endl;
		}
		else {
			cout << -1 << endl;
		}

	}

	return 0;
}
