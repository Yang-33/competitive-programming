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

/* -----  2018/10/24  Problem: ARC 035 D / Link: http://arc035.contest.atcoder.jp/tasks/arc035_d  ----- */
/* ------問題------

高橋くんの住む国には N 個の街があります。それぞれ 1 から N の整数で番号付けされています。 しかし、これらの街の間を移動する手段がまだありません。 そこで国が補助金を出して、異なる 2 つの街を結ぶ道路を、いくつか敷設することになりました。 各道路は個別の長さを持っています。 敷設される道路は結んだ 2 つの国のどちらからでも、もう一方の国に移動することが出来ます。つまり双方向に移動できる道路です。
ところで、高橋くんは偶数が大好きです。 高橋くんは道路を使って、たとえそれが遠回りになろうとも、同じ道を何度通ろうとも、移動距離の合計が偶数メートルになるように移動しようとします。 また、高橋くんは中途半端なことが嫌いなので、道の途中で来た道を引き返すことはしません。
高橋君はときどき、2 つの街を指定して、その間を偶数メートルで移動できるかどうかあなたに質問します。 先述の通り、今は道路を増やしている最中なので、質問のタイミングによっては新しく敷設された道路の影響で、偶数メートルで移動できるかどうかが変わり得るに注意してください。
なお、街の中での移動は移動距離の合計に含まないものとします。
道路の敷設と、高橋くんの質問の情報を時系列順に与えるので、高橋くんの質問に答えるプログラムを作成してください。

-----問題ここまで----- */
/* -----解説等-----

頂点倍化UFをやればよい

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

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, Q; cin >> N >> Q;
	UnionFind uf(2 * N);
	FOR(i, 0, Q) {
		int w, x, y, z; cin >> w >> x >> y >> z;
		x--, y--;
		if (w == 1) {
			if (z % 2 == 1) {
				uf.unionSet(x, y + N);
				uf.unionSet(y, x + N);
			}
			else {
				uf.unionSet(x, y);
				uf.unionSet(y + N, x + N);
			}
		}
		else {
			if (uf.same(x, y)) {
				cout << "YES" << endl;
			}
			else {
				cout << "NO" << endl;
			}
		}
		//DD(de(w,z,y,z,uf));
	}

	return 0;
}
