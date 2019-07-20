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

/* -----  2019/07/20  Problem: ABC 134 E / Link: http://abc134.contest.atcoder.jp/tasks/abc134_e  ----- */

template<typename Monoid>
struct SegmentTreeFastAry {
	using nd = typename Monoid::type;
	const int ARY_SIZE;
	vector<nd> node;
public:
	SegmentTreeFastAry(int n) : ARY_SIZE(n), node(2 * ARY_SIZE, Monoid::id()) {}
	void set_val(int i, const nd val) {
		i += ARY_SIZE; node[i] = val;
		while (i > 1) { i >>= 1;	node[i] = Monoid::op(node[i << 1], node[(i << 1) + 1]); }
	}
	inline nd query(int l, int r) {
		if (l >= r) return Monoid::id(); nd vl = Monoid::id(), vr = Monoid::id();
		for (l += ARY_SIZE, r += ARY_SIZE; l != r; l >>= 1, r >>= 1) {
			if (l & 1) vl = Monoid::op(vl, node[l++]); if (r & 1) vr = Monoid::op(node[--r], vr);
		}	return Monoid::op(vl, vr);
	}
	nd operator[](int i) { return node[i + ARY_SIZE]; }
};

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N; cin >> N;
	struct TwoMin {
		using type = PLL;
		static type id() { return PLL(INF + 2, INF + 2); }
		static type op(const type&l, const type&r) {
			return min(l, r);
		}
	};

	SegmentTreeFastAry<TwoMin>seg(N);
	vector<LL> a(N);
	vector<PLL>ord;
	FOR(i, 0, N) {
		cin >> a[i];
		seg.set_val(i, PLL(a[i], -i));
		ord.emplace_back(a[i], -i);
	}

	SORT(ord);
	LL ans = 0;
	for (auto it : ord) {
		LL idx = -it.second;
		if (seg[idx].first > INF)continue;
		ans++;
		seg.set_val(idx, TwoMin::id());
		while (idx < N) {
			PLL ne = seg.query(idx + 1, N);
			LL nid = -ne.second;
			if (nid < 0)break;
			seg.set_val(nid, TwoMin::id());
			idx = nid;
		}
	}

	cout << (ans) << "\n";
}
