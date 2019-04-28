#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC optimize(3)
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC target("sse3","sse2","sse")
#pragma GCC target("avx","sse4","sse4.1","sse4.2","ssse3")
#pragma GCC target("f16c")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#pragma GCC diagnostic error "-fwhole-program"
#pragma GCC diagnostic error "-fcse-skip-blocks"
#pragma GCC diagnostic error "-funsafe-loop-optimizations"
#pragma GCC diagnostic error "-std=c++14"
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
#ifdef YANG33
#include "mydebug.hpp"
#else
#define DD(x) 
#endif
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);

/* -----  2019/04/28  Problem: square869120Contest_01 H / Link: __CONTEST_URL__  ----- */

template<typename M>
struct BIT0 { // 0-index
	using T = typename M::t1;
	int N;
	int nn;
	vector<T> data;
	BIT0(int n) {
		N = n + 1;
		data = vector<T>(n + 1, M::id1());
	}
	void update(int i, const T& w) { // a[i] += w
		i++;
		for (int x = i; x < N; x += x & -x) {
			data[x] = M::op1(data[x], w);
		}
	}
	T query(int i) { // iまでの和 [0,i)
		T ret = 0;
		for (int x = i; x > 0; x -= x & -x) {
			ret = M::op1(ret, data[x]);
		}
		return ret;
	}
	// [l, r)
	T query(int l, int r) {
		return M::op1(query(r), M::inv1(query(l)));
	}
};


template< typename structure_t, typename M >
struct SegmentTree2DCompressed {
	using T = typename M::t1;

	int sz;
	vector< structure_t > rmqs;
	vector< vector< int > > LL, RR;
	vector< vector< int > > seg;

	SegmentTree2DCompressed(int n) {
		sz = 1;
		while (sz < n) sz <<= 1;
		seg.resize(2 * sz);
		LL.resize(2 * sz);
		RR.resize(2 * sz);
	}

	void update(int a, int x, const T& z, int k, int l, int r) {
		if (r <= a || a + 1 <= l) return;
		if (a <= l && r <= a + 1) return rmqs[k].update(x, z);
		update(a, LL[k][x], z, 2 * k + 0, l, (l + r) >> 1);
		update(a, RR[k][x], z, 2 * k + 1, (l + r) >> 1, r);
		return rmqs[k].update(x, z);
	}
	// (y,x) <- z
	void update(int y, int x, const T& z) {
		x = lower_bound(begin(seg[1]), end(seg[1]), x) - begin(seg[1]);
		return update(y, x, z, 1, 0, sz);
	}

	T query(int a, int b, int x, int y, int k, int l, int r) {
		if (a >= r || b <= l) return M::id1();
		if (a <= l && r <= b) return rmqs[k].query(x, y);
		return M::op1(query(a, b, LL[k][x], LL[k][y], 2 * k + 0, l, (l + r) >> 1),
			query(a, b, RR[k][x], RR[k][y], 2 * k + 1, (l + r) >> 1, r));
	}
	// [sy,ty),[sx,ty)
	T query(int a, int b, int x, int y) {
		x = lower_bound(begin(seg[1]), end(seg[1]), x) - begin(seg[1]);
		y = lower_bound(begin(seg[1]), end(seg[1]), y) - begin(seg[1]);
		return query(a, b, x, y, 1, 0, sz);
	}

	void build() {
		for (int k = (int)seg.size() - 1; k >= sz; k--) {
			sort(begin(seg[k]), end(seg[k]));
			seg[k].erase(unique(begin(seg[k]), end(seg[k])), end(seg[k]));
		}
		for (int k = sz - 1; k > 0; k--) {
			seg[k].resize(seg[2 * k + 0].size() + seg[2 * k + 1].size());
			merge(begin(seg[2 * k + 0]), end(seg[2 * k + 0]), begin(seg[2 * k + 1]), end(seg[2 * k + 1]), begin(seg[k]));
			seg[k].erase(unique(begin(seg[k]), end(seg[k])), end(seg[k]));
			LL[k].resize(seg[k].size() + 1);
			RR[k].resize(seg[k].size() + 1);
			int tail1 = 0, tail2 = 0;
			for (int i = 0; i < (int)seg[k].size(); i++) {
				while (tail1 < (int)seg[2 * k + 0].size() && seg[2 * k + 0][tail1] < (int)seg[k][i]) ++tail1;
				while (tail2 < (int)seg[2 * k + 1].size() && seg[2 * k + 1][tail2] < (int)seg[k][i]) ++tail2;
				LL[k][i] = tail1, RR[k][i] = tail2;
			}
			LL[k][seg[k].size()] = (int)seg[2 * k + 0].size();
			RR[k][seg[k].size()] = (int)seg[2 * k + 1].size();
		}
		for (int k = 0; k < (int)seg.size(); k++) {
			rmqs.emplace_back(structure_t(seg[k].size()));
		}
	}

	void preupdate(int y, int x) {
		seg[y + sz].push_back(x);
	}
};



void make_element(int i, int e, LL ab, LL ac, int nouse_cnt, const VL& a, vector < vector<PLL>> &ainfo) {
	if (i == e) {
		ainfo[nouse_cnt].push_back(PLL(ab, ac));
		return;
	}
	make_element(i + 1, e, ab - a[i], ac - a[i], nouse_cnt, a, ainfo);
	make_element(i + 1, e, ab + a[i], ac, nouse_cnt, a, ainfo);
	make_element(i + 1, e, ab, ac + a[i], nouse_cnt, a, ainfo);
	if (nouse_cnt < 2)make_element(i + 1, e, ab , ac, nouse_cnt + 1, a, ainfo);
}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, D, E; cin >> N >> D >> E;
	vector<LL> a(N);
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
	}
	vector<vector<PLL>>A1(3);
	make_element(0, N / 2, 0, 0, 0, a, A1);
	vector<vector<PLL>>A2(3);
	make_element(N / 2, N, 0, 0, 0, a, A2);

	LL ans = 0LL;

	FOR(i, 0, E + 1) {
		vector<PLL>& points = A1[i];
		VL ys, xs;
		vector<PII>pc;
		using tp = tuple<int, int, int, int>;
		vector<tp>qc; {
			for (auto it : points) {
				ys.push_back(it.first);
				xs.push_back(it.second);
			}
			SORT(ys); UNIQ(ys);
			SORT(xs); UNIQ(xs);
			for (auto it : points) {
				int y = lower_bound(ALL(ys), it.first) - ys.begin();
				int x = lower_bound(ALL(xs), it.second) - xs.begin();
				pc.push_back(PII(y, x));
			}
		}
		struct Abel {
			using t1 = int;
			static t1 id1() {
				return 0;
			}
			static t1 op1(const t1& l, const t1& r) {
				return l + r;
			}
			static t1 inv1(const t1 &x) {
				return -x;
			}
		};
		SegmentTree2DCompressed<BIT0<Abel>, Abel>seg(SZ(ys));
		for (auto it : pc) {
			seg.preupdate(it.first, it.second);
		}
		seg.build();
		for (auto it : pc) {
			seg.update(it.first, it.second, 1);
		}

		FOR(j, 0, E + 1) {
			if (i + j <= E) {
				auto& querys = A2[j];
				for (auto it : querys) {
					int y1 = lower_bound(ALL(ys), -it.first - D) - ys.begin();
					int y2 = lower_bound(ALL(ys), -it.first + D + 1) - ys.begin();
					int x1 = lower_bound(ALL(xs), -it.second - D) - xs.begin();
					int x2 = lower_bound(ALL(xs), -it.second + D + 1) - xs.begin();

					LL a = seg.query(y1, y2, x1, x2);
					ans += a;
				}
			}
		}
	}


	cout << (ans) << "\n";

	return 0;
}
