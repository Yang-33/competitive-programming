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

/* -----  2018/12/15  Problem: EDU056 E / Link: __CONTEST_URL__  ----- */
/* ------問題------

1..Nがユニークで並んでいる長さNの数列A,Bが与えられる。以下のクエリをさばけ。
1. al ar bl br : Aの[al..ar]とB[bl..br]のうち、一致する要素数を答える。
2. x y : Bのx番目とy番目を交換する

-----問題ここまで----- */
/* -----解説等-----

2Dsegtreeで殴る。
2DにA,Bをそのままプロットする。
クエリは範囲和がわかれば良いので可能。
query2は結局Yの視点からみるとXが変わるだけ。よってこれをシュミレーションすれば良い。
swapのxが間違ってなければ時間内に通っていた...

----解説ここまで---- */
template< class T >
struct BinaryIndexedTree {
	vector< T > data;

	BinaryIndexedTree(int sz) {
		data.assign(++sz, 0);
	}

	T sum(int k) {
		T ret = 0;
		for (++k; k > 0; k -= k & -k) ret += data[k];
		return (ret);
	}

	void add(int k, T x) {
		for (++k; k < data.size(); k += k & -k) data[k] += x;
	}
};

template< typename structure_t, typename get_t, typename update_t >
struct SegmentTree2DCompressed {

	using merge_f = function< get_t(get_t, get_t) >;
	using range_get_f = function< get_t(structure_t &, int, int) >;
	using update_f = function< void(structure_t &, int, update_t) >;

	int sz;
	vector< structure_t > seg;
	const merge_f f;
	const range_get_f g;
	const update_f h;
	const get_t identity;
	vector< vector< int > > LL, RR;
	vector< vector< int > > beet;

	SegmentTree2DCompressed(int n, const merge_f &f, const range_get_f &g, const update_f &h, const get_t &identity)
		: f(f), g(g), h(h), identity(identity) {
		sz = 1;
		while (sz < n) sz <<= 1;
		beet.resize(2 * sz);
		LL.resize(2 * sz);
		RR.resize(2 * sz);
	}

	void update(int a, int x, update_t z, int k, int l, int r) {
		if (r <= a || a + 1 <= l) return;
		if (a <= l && r <= a + 1) return h(seg[k], x, z);
		update(a, LL[k][x], z, 2 * k + 0, l, (l + r) >> 1);
		update(a, RR[k][x], z, 2 * k + 1, (l + r) >> 1, r);
		return h(seg[k], x, z);
	}

	void update(int x, int y, update_t z) {
		y = lower_bound(begin(beet[1]), end(beet[1]), y) - begin(beet[1]);
		return update(x, y, z, 1, 0, sz);
	}

	get_t query(int a, int b, int x, int y, int k, int l, int r) {
		if (a >= r || b <= l) return identity;
		if (a <= l && r <= b) return g(seg[k], x, y);
		return f(query(a, b, LL[k][x], LL[k][y], 2 * k + 0, l, (l + r) >> 1),
			query(a, b, RR[k][x], RR[k][y], 2 * k + 1, (l + r) >> 1, r));
	}

	get_t query(int a, int b, int x, int y) {
		x = lower_bound(begin(beet[1]), end(beet[1]), x) - begin(beet[1]);
		y = lower_bound(begin(beet[1]), end(beet[1]), y) - begin(beet[1]);
		return query(a, b, x, y, 1, 0, sz);
	}

	void build() {
		for (int k = (int)beet.size() - 1; k >= sz; k--) {
			sort(begin(beet[k]), end(beet[k]));
			beet[k].erase(unique(begin(beet[k]), end(beet[k])), end(beet[k]));
		}
		for (int k = sz - 1; k > 0; k--) {
			beet[k].resize(beet[2 * k + 0].size() + beet[2 * k + 1].size());
			merge(begin(beet[2 * k + 0]), end(beet[2 * k + 0]), begin(beet[2 * k + 1]), end(beet[2 * k + 1]), begin(beet[k]));
			beet[k].erase(unique(begin(beet[k]), end(beet[k])), end(beet[k]));
			LL[k].resize(beet[k].size() + 1);
			RR[k].resize(beet[k].size() + 1);
			int tail1 = 0, tail2 = 0;
			for (int i = 0; i < beet[k].size(); i++) {
				while (tail1 < beet[2 * k + 0].size() && beet[2 * k + 0][tail1] < beet[k][i]) ++tail1;
				while (tail2 < beet[2 * k + 1].size() && beet[2 * k + 1][tail2] < beet[k][i]) ++tail2;
				LL[k][i] = tail1, RR[k][i] = tail2;
			}
			LL[k][beet[k].size()] = (int)beet[2 * k + 0].size();
			RR[k][beet[k].size()] = (int)beet[2 * k + 1].size();
		}
		for (int k = 0; k < beet.size(); k++) {
			seg.emplace_back(structure_t(beet[k].size()));
		}
	}

	void preupdate(int x, int y) {
		beet[x + sz].push_back(y);
	}
};

int read() { int in; scanf("%d", &in); return in; }
int mode[200005];
int la[200005];
int ra[200005];
int lb[200005];
int rb[200005];

int main() {

	int N = read(), M = read();
	using BIT = BinaryIndexedTree< int >;
	auto f = [](int x, int y) { return x + y; };
	auto g = [](BIT &k, int x, int y) { return k.sum(y - 1) - k.sum(x - 1); };
	auto h = [](BIT &k, int x, int y) { k.add(x, y); };
	SegmentTree2DCompressed< BIT, int, int > seg(N, f, g, h, 0);
	VI a(N), b(N);
	FOR(i, 0, N) {
		a[i]=read()-1;
	}
	FOR(i, 0, N) {
		b[i]=read()-1;
	}
	DD(De(a, b));
	VI reva(N, 0);
	VI revb(N, 0);
	FOR(i, 0, N) {
		reva[a[i]] = i;
		revb[b[i]] = i;
	}
	vector<PII>pos(N);
	FOR(i, 0, N) {
		pos[revb[i]] = PII(revb[i],reva[i]);// swap用
		seg.preupdate(revb[i], reva[i]);
	}
	FOR(i, 0, M) {
		mode[i] = read();
		if (mode[i] == 1) {
			la[i] = read()-1, ra[i] = read(), lb[i] = read()-1, rb[i] = read();
		}
		else {
			la[i] = read()-1, ra[i] = read()-1;
		}
	}
	vector<PII>valp = pos;
	FOR(i, 0, M) {
		if (mode[i] == 2) {
			int B1 = la[i], B2 = ra[i];
			swap(valp[B1].second, valp[B2].second);
			seg.preupdate(valp[B1].first, valp[B1].second);
			seg.preupdate(valp[B2].first,valp[B2].second);
		}
	}

	seg.build();
	FOR(i, 0, N) {
		seg.update(pos[i].first, pos[i].second, 1);
	}
	FOR(i, 0, M) {
		if (mode[i] == 1) {
			printf("%d\n", seg.query(lb[i], rb[i], la[i], ra[i]));

		}
		else { 
			int B1 = la[i], B2 = ra[i];
			DD(de(B1, B2));
			// del
			seg.update(pos[B1].first, pos[B1].second, -1);
			seg.update(pos[B2].first,pos[B2].second,-1);

			swap(pos[B1].second, pos[B2].second);
			// up
			seg.update(pos[B1].first, pos[B1].second, 1);
			seg.update(pos[B2].first, pos[B2].second, 1);
		}
		//cout << "--------" << endl;
		//FORR(i, N-1, 0-1) {
		//	FOR(j, 0, N) {
		//		cout << seg.query(i, i + 1, j, j + 1) << " ";
		//	}cout << endl;
		//}
		//FOR(k, 0, N) {
		//	cout << pos[k].first << "," << pos[k].second << endl;
		//}
	}
	return 0;
}
