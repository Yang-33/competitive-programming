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

/* -----  2018/08/18  Problem: edu049 F / Link: __CONTEST_URL__  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

上限+UF

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

int a[1000006];
int c[2000006];
int b[1000006];
int main() {
	int N;
	scanf("%d", &N);
	FOR(i, 0, N) {
		scanf("%d%d", &a[i], &b[i]);
		c[i] = a[i], c[i + N] = b[i];
	}
	sort(c, c + 2 * N);
	FOR(i, 0, N) {
		a[i] = lower_bound(c, c + 2 * N, a[i]) - c;
		b[i] = lower_bound(c, c + 2 * N, b[i]) - c;
	}

	auto f = [&](int x) { // [0,x]までを許可してできるか
		UnionFind uf(x + 1);
		FOR(i, 0, N) {
			if (a[i] > x)return false;
			if (b[i] <= x) {
				uf.unionSet(a[i], b[i]);
			}
		}
		VI cnt(x + 1, 0);// group内の数
		FOR(i, 0, N) {
			cnt[uf.root(a[i])]++;
		}
		FOR(i, 0, x + 1) {
			if (uf.root(i) == i) {
				if (cnt[uf.root(i)] > uf.size(i))return false;
			}
		}
		return true;
	};

	int L = 0;
	int R = 2 * N;
	FOR(i, 0, 25) {
		int mid = (L + R) / 2;
		(f(mid) ? R : L) = mid;
	}
	if (R == 2 * N)cout << -1 << endl;
	else cout << c[R] << endl;



	return 0;
}
