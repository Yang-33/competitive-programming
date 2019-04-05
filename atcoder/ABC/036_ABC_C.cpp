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

/* -----  2019/04/05  Problem: ABC 036 C / Link: http://abc036.contest.atcoder.jp/tasks/abc036_c  ----- */

template<class T>
vector<int> compress_elements(const vector<T>& a) {
	vector<T> b = a;
	sort(b.begin(), b.end());
	b.erase(unique(b.begin(), b.end()), b.end());
	vector<int>res((int)a.size());
	for (int i = 0; i < (int)a.size(); i++) {
		res[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
	}
	return res;
}
// 要素を圧縮する


template<class T>
map<T, int> make_compress_elements_map(const vector<T>& a) {
	vector<T> b = a;
	map<T, int>compress_map;
	int N = (int)b.size();
	vector<T> rev_map(N);
	SORT(b);
	UNIQ(b);
	FOR(i, 0, (int)b.size()) {
		compress_map[b[i]] = i;
		rev_map[i] = b[i];
	}
	return compress_map;
	// return rev;
}
// 要素を圧縮するmapと圧縮した値から復元するやつ



int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N; cin >> N;
	vector<LL> a(N);
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
	}
	auto compress_map = make_compress_elements_map(a);
	for (auto it : a) {
		cout << compress_map[it] << endl;
	}


	return 0;
}
