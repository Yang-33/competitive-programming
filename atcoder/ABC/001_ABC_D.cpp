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

/* -----  2019/04/22  Problem: ABC 001 D / Link: http://abc001.contest.atcoder.jp/tasks/abc001_d  ----- */

class SegmentMap : public std::map<signed, signed> {
private:
	bool flagToMergeAdjacentSegment;
public:
	// if merge [l, c] and [c+1, r], set flagToMergeAdjacentSegment to true
	SegmentMap(bool flagToMergeAdjacentSegment) :
		flagToMergeAdjacentSegment(flagToMergeAdjacentSegment) {}
	// __exist -> iterator pair(l, r) (contain p)
	// noexist -> map.end()
	auto get(signed p) const {
		auto it = upper_bound(p);
		if (it == begin() || (--it)->second < p) return end();
		return it;
	}
	// insert segment [l, r]
	void insert(signed l, signed r) {
		auto itl = upper_bound(l), itr = upper_bound(r + flagToMergeAdjacentSegment);
		if (itl != begin()) {
			if ((--itl)->second < l - flagToMergeAdjacentSegment) ++itl;
		}
		if (itl != itr) {
			l = std::min(l, itl->first);
			r = std::max(r, std::prev(itr)->second);
			erase(itl, itr);
		}
		(*this)[l] = r;
	}
	// remove segment [l, r]
	void remove(signed l, signed r) {
		auto itl = upper_bound(l), itr = upper_bound(r);
		if (itl != begin()) {
			if ((--itl)->second < l) ++itl;
		}
		if (itl == itr) return;
		int tl = std::min(l, itl->first), tr = std::max(r, std::prev(itr)->second);
		erase(itl, itr);
		if (tl < l) (*this)[tl] = l - 1;
		if (r < tr) (*this)[r + 1] = tr;
	}
	// Is p and q in same segment?
	bool same(signed p, signed q) const {
		const auto&& it = get(p);
		return it != end() && it->first <= q && q <= it->second;
	}
};


int main() {

	auto trans = [](int t, bool up) {
		int h = t / 100;
		int m = t % 100;
		int geta = (up ? 4 : 0);
		int nm = ((m + geta) / 5) * 5;
		return h * 60 + nm;

	};
	auto rev_trans = [](int t) {
		return (t / 60) * 100 + t % 60;
	};

	int N; cin >> N;
	SegmentMap segmap(false);
	FOR(i, 0, N) {
		int a, b;
		scanf("%d-%d", &a, &b);
		segmap.insert(trans(a, 0), trans(b, 1));
	}
	for (auto it : segmap) {
		printf("%04d-%04d\n", rev_trans(it.first), rev_trans(it.second));
	}
	return 0;
}
