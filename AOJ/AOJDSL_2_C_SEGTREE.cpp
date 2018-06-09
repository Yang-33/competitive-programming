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

/* -----  2018/06/07  Problem: AOJ DSL_2_C / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_C  ----- */
/* ------問題------

いくつかの属性を持つレコードの集合（データベース）から、特定の属性の値が指定された領域に入るものを見つける問題を領域探索と呼びます。

２次元の平面上の点の集合に対し、与えられた領域に含まれる点を列挙してください。ただし、与えられた点の集合に対して、点の追加・削除は行われません。

出力
各クエリについて、点集合の中で sxi ≤ x ≤ txi かつ syi ≤ y ≤ tyi を満たす点の番号を、番号の昇順に出力してください。１つの点の番号を１行に出力し、各クエリに対する出力の最後に１つの空行を出力してください（条件を満たす点がない場合は１つの空行になります）。

-----問題ここまで----- */
/* -----解説等-----

segtree解 点が100個しかないためできる。

----解説ここまで---- */


vector<LL>ids;

struct nd {
	vector<PLL>vec;
	nd() { } // ! e
};
struct SegmentTreeFastAry {
	void merge(nd &ret, const nd &a, const nd &b) { 
		std::merge(a.vec.begin(), a.vec.end(), b.vec.begin(), b.vec.end(), back_inserter(ret.vec));
	}
	// -- setting -- // 
	int ARY_SIZE; vector<nd> node; 
	SegmentTreeFastAry(const vector<PLL> &a, const int _N) {
		ARY_SIZE = 1;
		while (ARY_SIZE < _N)ARY_SIZE *= 2;
		node = vector<nd>(2*ARY_SIZE);
		for (int i = 0; i < _N; ++i)node[i + ARY_SIZE].vec.push_back(a[i]);
		build();
	}
	void build() { for (int i = ARY_SIZE - 1; i >= 0; i--) merge(node[i], node[i<<1], node[(i<<1)+1]); }

	void query(int l, int r,int YL,int YU) {
		if (l >= r) return;
		for (l += ARY_SIZE, r += ARY_SIZE; l != r; l >>= 1, r >>= 1) {
			if (l & 1) {
				int k = l++;
				int s = lower_bound(ALL(node[k].vec), PLL(YL, -LINF)) - node[k].vec.begin();
				int t = lower_bound(ALL(node[k].vec), PLL(YU, LINF)) - node[k].vec.begin();
				FOR(y, s, t) {
					ids.push_back(node[k].vec[y].second);
				}
			}
			if (r & 1) {
				int k = --r;
				int s = lower_bound(ALL(node[k].vec), PLL(YL, -LINF)) - node[k].vec.begin();
				int t = lower_bound(ALL(node[k].vec), PLL(YU, LINF)) - node[k].vec.begin();
				FOR(y, s, t) {
					ids.push_back(node[k].vec[y].second);
				}
			}
		}	
	}
};


int main() {
	int x, y;
	int N;
	scanf("%d", &N);
	using tp = tuple<int, int, int>;
	vector<tp>info(N);
	vector<int>xs(N);
	FOR(i, 0, N) {
		scanf("%d%d", &xs[i], &y);
		info[i] = (tp(xs[i], y, i));
	}

	SORT(xs);
	SORT(info);
	vector<PLL> seginfo(N);
	FOR(i, 0, N) {
		seginfo[i] = { get<1>(info[i]), get<2>(info[i]) };
	}
	SegmentTreeFastAry seg(seginfo, N);

	int Q;
	scanf("%d", &Q);
	int sx, sy, tx, ty;
	FOR(i, 0, Q) {
		scanf("%d%d%d%d", &sx, &tx, &sy, &ty);
		ids.clear();
		int xl = lower_bound(ALL(xs), sx) - xs.begin();
		int xr = upper_bound(ALL(xs), tx) - xs.begin();
		seg.query(xl, xr, sy, ty);
		SORT(ids);
		for (LL id : ids) {
			printf("%d\n", id);
		}
		printf("\n");
	}



	return 0;
}
