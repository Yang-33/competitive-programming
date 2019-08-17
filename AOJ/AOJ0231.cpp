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

/* -----  2019/08/17  Problem: AOJ 0231 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0231  ----- */

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

	int N;
	while (cin >> N, N) {
		using tp = tuple<int, int, int>;
		vector<tp>events;
		FOR(i, 0, N) {
			int m, s, t; cin >> m >> s >> t;
			events.emplace_back(s, 1, m);
			events.emplace_back(t, 0, m);
		}
		SORT(events);
		LL sum = 0;
		bool ok = 1;
		for (auto it : events) {
			int mode, w;
			tie(ignore, mode, w) = it;
			if (mode == 0) {
				sum -= w;
			}
			else {
				sum += w;
				if (sum > 150)ok = 0;
			}
		}
		puts(ok ? "OK" : "NG");
	}

	return 0;
}
