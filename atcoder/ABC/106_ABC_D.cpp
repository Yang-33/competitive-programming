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

/* -----  2019/02/28  Problem: ABC 106 D / Link: http://abc106.contest.atcoder.jp/tasks/abc106_d  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----



----解説ここまで---- */
template<typename type>
struct BIT { // 0-index
	int N;
	vector<type> data;
	BIT(int n) : N(n), data(n + 1, 0) {}
	void add(int i, type w) { // a[i] += w
		for (int x = i; x < N; x |= x + 1) {
			data[x] += w;
		}
	}
	type sum(int i) { // a[0] +...+ a[i-1] !!! [0,i)
		type ret = 0;
		for (int x = i - 1; x >= 0; x = (x&(x + 1)) - 1) {
			ret += data[x];
		}
		return ret;
	}
	type sum(int l, int r) { //a[l]+...+a[r-1] !!! [l,r)
		return sum(r) - sum(l);
	}
};


// 閉区間で入力を与える
vector<int>RangeInRangeCount(const vector<PII>& Range, const vector<PII>& Query, int Width) {
	Width++;
	int N = (int)Range.size();
	int Q = (int)Query.size();
	vector<vector<int>>ranges(Width);
	vector<vector<PII>>querys(Width);
	for (int i = 0; i < N; i++) {
		ranges[Range[i].second].push_back(Range[i].first);
	}
	for (int i = 0; i < Q; i++) {
		querys[Query[i].second].push_back(PII(Query[i].first, i));
	}

	BIT<int>bit(Width);
	vector<int>ans(Q);

	for (int R = 0; R < Width; R++) {
		for (int L : ranges[R]) {
			bit.add(L, 1);
		}
		for (PII L : querys[R]) {
			ans[L.second] = bit.sum(L.first, R + 1);
		}
	}

	return ans;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, M, Q; cin >> N >> M >> Q;
	vector<PII> seg(M);
	for (int i = 0; i < M; ++i) {
		cin >> seg[i].first >> seg[i].second;
	}
	vector<PII> Qseg(Q);
	for (int i = 0; i < Q; ++i) {
		cin >>Qseg[i].first >> Qseg[i].second;
	}
	auto ans = RangeInRangeCount(seg, Qseg, N + 1);

	for (auto it : ans) {
		cout << it << endl;
	}



	return 0;
}
