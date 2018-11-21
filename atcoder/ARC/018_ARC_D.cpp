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
//#pragma GCC optimize ("-O3") 
#ifdef YANG33
#include "mydebug.hpp"
#else
#define DD(x) 
#endif
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/11/21  Problem: ARC 018 D / Link: http://arc018.contest.atcoder.jp/tasks/arc018_d  ----- */
/* ------問題------

高橋君の通う大学は、毎年 N 人の新入生を迎え入れています。 N 人の新入生には 1 から N の学籍番号が順番に振られていて、高橋君の学籍番号は 1 です。
さて、4月から大学に通う高橋君は他の N−1 人の新入生全員と友達になりたいと思っています。しかし、それを達成するには非常に費用が掛かることが知られています。
高橋君にとって、"x君と友達である"というのは高橋君の友達の友達の...というふうに交友関係を辿って、x君にたどり着くことが可能な状態のことを指します。
現在、新入生同士はお互いを全く知らず、互いに友達であるような学生はいません。当然、高橋君にも全く友達がいません。しかし、高橋君は特定の2人の学生(高橋君も含むことがあります)について、「少なくともどちらか一方が高橋君の友達もしくは高橋君自身であるような、学籍番号が A の学生と 学籍番号が B の学生を、C 円使って友達同士にする」という形式の手段を M 種類知っています。また、学生によって必要となる費用はバラバラであるため、同じ費用である手段の数はそこまで偏っていません。
最初、高橋君を含めた新入生に友達は全くおらず、高橋君は上記の手段を活用し、新入生全員と友達になることを考えています。また、高橋君はそれ以外の方法で友達を作ることはできません。しかし、高橋君の資金力にも限りがあり、出来るだけ少ない費用で新入生全員と友達になりたいと考えています。高橋君は忙しいので、プログラマーであるあなたに、この企てについての仕事を依頼することにしました。
高橋君からあなたに与えられた仕事を説明します。
まず、あなたには、大学に在籍する高橋君を含む新入生の数 N 、手段の数 M と、 M 種類の手段の情報が与えられます。 N 人の新入生には 1 から N の学籍番号が順番に振られていて、高橋君の学籍番号は 1 です。
あなたの仕事は、高橋君が新入生全員と友達になるために必要な合計の費用と、最小限の費用を達成する手段の選び方が何通りあるかを出力することです。手段を実行する順番のみが異なるものは同じ手段の選び方とみなします。正確には、選び方の数は非常に大きくなってしまうことがあるので、選び方の数を 1,000,000,007 で割った余りを出力してください。

-----問題ここまで----- */
/* -----解説等-----

全域木の数え上げは既出(こっちが先なんですが…)
SRM733 div1 medを参照。
ラプラシアン行列をいい感じに計算できれば良い。
コストが少ないことを活かすとできる。

----解説ここまで---- */

class BuildingSpanningTreesDiv1
{
public:

	int mod = 987654323;
	int add(int x, int y) { return (x += y) >= mod ? x - mod : x; }
	template<class... T> int add(int x, T... y) { return add(x, add(y...)); }
	int mul(int x, int y) { return 1LL * x * y % mod; }
	template<class... T> int mul(int x, T... y) { return mul(x, mul(y...)); }
	int sub(int x, int y) { return add(x, mod - y); }
	int modpow(int a, long long b) { int ret = 1; while (b > 0) { if (b & 1) ret = 1LL * ret * a % mod; a = 1LL * a * a % mod; b >>= 1; } return ret; }
	int modinv(int a) { return modpow(a, mod - 2); }
	typedef vector<int> Vec; typedef vector<Vec> Mat;
	void printVec(Vec a) { cout << "[\t"; FOR(i, 0, SZ(a)) cout << a[i] << "\t"; cout << "]" << endl; }
	void printMat(Mat a) { FOR(i, 0, SZ(a)) printVec(a[i]); }
	template<typename T> T det(Mat &a) {
		T ans = 1;
		FOR(i, 0, SZ(a)) {
			FOR(j, i + 1, SZ(a)) for (; a[j][i] != 0; ans = sub(0, ans)) {
				T r = mul(a[i][i], modinv(a[j][i]));
				FOR(k, i, SZ(a)) {
					T t = sub(a[i][k], mul(r, a[j][k]));
					a[i][k] = a[j][k];
					a[j][k] = t;
				}
			}
			ans = mul(ans, a[i][i]);
		}
		return ans;
	}
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

	int N, M;
	map<int, vector<pair<int, int>>> E;
	int ans1 = 0, ans2 = 1;

	void sol() {
		int cnt = N;
		UnionFind uf(101010), uf2(101010);
		for (auto p : E) {
			if (cnt == 1) return;

			vector<int> v;
			for (auto pp : p.second) {
				int a = uf.root(pp.first);
				int b = uf.root(pp.second);
				if (a != b) v.push_back(a), v.push_back(b);
			}
			SORT(v);
			UNIQ(v);

			for (auto pp : p.second) uf2.unionSet(pp.first, pp.second);

			map<int, vector<int>> m;
			for (int i : v) m[uf2.root(i)].push_back(i);
			for (auto q : m) {
				auto vv = q.second;
				int n = vv.size();

				ans1 += p.first * (n - 1);

				Mat m(n, Vec(n, 0));
				for (auto pp : p.second) {
					int a = uf.root(pp.first);
					int b = uf.root(pp.second);
					if (a == b) continue;

					int aa = lower_bound(vv.begin(), vv.end(), a) - vv.begin();
					int bb = lower_bound(vv.begin(), vv.end(), b) - vv.begin();

					if (n <= aa) continue;
					if (n <= bb) continue;
					if (vv[aa] != a) continue;
					if (vv[bb] != b) continue;

					m[aa][aa]++, m[bb][bb]++;
					m[aa][bb]--; m[bb][aa]--;
				}

				Mat mm(n - 1, Vec(n - 1, 0));
				FOR(y, 0, n - 1) FOR(x, 0, n - 1) mm[y][x] = (m[y][x] + mod) % mod;
				ans2 = mul(ans2, det<int>(mm));
			}

			for (auto pp : p.second) {
				int a = uf.root(pp.first);
				int b = uf.root(pp.second);
				if (a != b) {
					uf.unionSet(a, b);
					cnt--;
				}
			}
		}
	}
	int f = 0;
	void ydfs(int v, int p, VVI&G, VI&used) {
		used[v] = 1;
		FOR(i, 0, SZ(G[v])) {
			int nv = G[v][i];
			if (nv == p)continue;
			if (used[nv]) {
				f = 1;
			}
			else ydfs(nv, v, G, used);
		}
	}
	// SRM733 div1 med: 指定頂点を含むような全域木の個数
	int getNumberOfSpanningTrees(int n, vector<int> x, vector<int> y)
	{

		N = n;
		M = N * (N - 1) / 2;


		VVI G(N);
		set<PII>edge1;
		FOR(i, 0, SZ(x)) {
			edge1.insert(PII(x[i] - 1, y[i] - 1));
			G[x[i] - 1].push_back(y[i] - 1);
			G[y[i] - 1].push_back(x[i] - 1);
		}
		FOR(i, 0, N) {
			FOR(j, i + 1, N) {
				if (edge1.count(PII(i, j))) {
					E[1].emplace_back(i, j);
				}
				else E[10000].emplace_back(i, j);
			}
		}

		// 閉路検出
		VI visit(N, 0);
		FOR(i, 0, N) {
			if (!visit[i])ydfs(i, -1, G, visit);
		}
		if (f == 1) {// 閉路
			return 0;// ここで落ちた
		}
		sol();
		return ans2;
	}
	PLL solve2(int n, vector<int>x, vector<int>y, vector<int>c) {
		M = SZ(x);
		N = n;
		FOR(i, 0, M) {
			E[c[i]].push_back(PII(x[i], y[i]));
		}
		sol();
		return PLL(ans1, ans2);
	}
};

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, M; cin >> N >> M;
	VI a(M), b(M), c(M);
	FOR(i, 0, M) {
		cin >> a[i] >> b[i] >> c[i];
		a[i]--, b[i]--;
	}
	BuildingSpanningTreesDiv1 solver;
	solver.mod = MOD;
	auto res = solver.solve2(N, a, b, c);
	cout << res.first << " " << res.second << endl;

	return 0;
}