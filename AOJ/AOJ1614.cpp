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

/* -----  2019/07/10  Problem: AOJ 1614 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/1614  ----- */

#include<chrono>
#include<random>
struct randgen {
	mt19937_64 rng;
	randgen() :rng((int)std::chrono::steady_clock::now().time_since_epoch().count()) {}
	LL getrand(LL s, LL t) {
		return rng() % (t - s) + s;
	}
};
bool shuffleCompleted = false;
int hashprimes[10] = { 10007, 10009, 10037, 10039, 10061, 10067, 10069, 10079, 10091, 10093 };
template< unsigned mod >
struct RollingHash {
	vector< unsigned > hashed, power;

	inline unsigned mul(unsigned a, unsigned b) const {
		unsigned long long x = (unsigned long long) a * b;
		unsigned xh = (unsigned)(x >> 32), xl = (unsigned)x, d, m;
		asm("divl %4; \n\t" : "=a" (d), "=d" (m) : "d" (xh), "a" (xl), "r" (mod));
		return m;
	}

	RollingHash(const string &s, int spec = 0) {
		randgen rng;
		if (!shuffleCompleted) {
			for (int i = 0; i < 101; ++i) {
				unsigned int a = rng.getrand(0, 10), b = rng.getrand(0, 10);
				swap(hashprimes[a], hashprimes[b]);
			}
			shuffleCompleted = true;
		}
		unsigned base = hashprimes[spec];

		int sz = (int)s.size();
		hashed.assign(sz + 1, 0);
		power.assign(sz + 1, 0);
		power[0] = 1;
		for (int i = 0; i < sz; i++) {
			power[i + 1] = mul(power[i], base);
			hashed[i + 1] = mul(hashed[i], base) + s[i];
			if (hashed[i + 1] >= mod) hashed[i + 1] -= mod;
		}
	}
	// [l,r)
	unsigned get(int l, int r) const {
		unsigned ret = hashed[r] + mod - mul(hashed[l], power[r - l]);
		if (ret >= mod) ret -= mod;
		return ret;
	}
	// merge hash:h1 + hash:h2
	unsigned connect(unsigned h1, unsigned int h2, int h2len) const {
		unsigned ret = mul(h1, power[h2len]) + h2;
		if (ret >= mod) ret -= mod;
		return ret;
	}

	int LCP(const RollingHash< mod > &b, int l1, int r1, int l2, int r2) {
		int len = min(r1 - l1, r2 - l2);
		int low = -1, high = len + 1;
		while (high - low > 1) {
			int mid = (low + high) / 2;
			if (get(l1, l1 + mid) == b.get(l2, l2 + mid)) low = mid;
			else high = mid;
		}
		return (low);
	}
};
using RH1 = RollingHash< 1000000007 >;
using RH2 = RollingHash< 1000000009 >;

// ギャグ。Tを実際に|T|*51書き換えてhash値を見る。
// LCPとして解きたいときは、s+*+t,rev(s)+"+rev(t)としてlcpを求める。和が唯一|t|-1ならOK(|t|なら一致してるからダメ)

int main() {
	string s, t; cin >> s >> t;
	RH1 sh(s), th(t);
	RH1 sh2(s, 1), th2(t, 1);
	using PUU = pair<unsigned, unsigned>;
	map<PUU, LL>smap; {
		FOR(i, 0, SZ(s)) {
			int j = i + SZ(t);
			if (j > SZ(s))break;
			smap[{sh.get(i, j), sh2.get(i, j)}]++;
		}
	}
	LL ans = 0; {
		auto alphas = [](char c) {
			vector<char>cs;
			FOR(i, 0, 26) {
				if ('a' + i != c)cs.push_back('a' + i);
				if ('A' + i != c)cs.push_back('A' + i);
			}
			return cs;
		};
		// i番目を書き換えたときのhash値51個
		auto tdash_hash = [&](int i) {
			vector<PUU>res;
			vector<char>cs = alphas(t[i]);
			if (i == 0 && SZ(t) == 1) {
				for (auto it : cs) {
					res.push_back({ it,it });
				}
			}
			else if (i == 0) {
				unsigned back = th.get(i + 1, SZ(t));
				unsigned back2 = th2.get(i + 1, SZ(t));
				for (auto h : cs) {
					unsigned hh = h;
					unsigned all = th.connect(hh, back, SZ(t) - 1);
					unsigned all2 = th2.connect(hh, back2, SZ(t) - 1);
					res.push_back({all,all2});
				}
			}
			else if (i + 1 == SZ(t)) {
				unsigned front = th.get(0, i);
				unsigned front2 = th2.get(0, i);
				for (auto h : cs) {
					unsigned hh = h;
					unsigned all = th.connect(front, hh, 1);
					unsigned all2 = th2.connect(front2, hh, 1);
					res.push_back({all,all2});
				}
			}
			else {
				unsigned front = th.get(0, i);
				unsigned back = th.get(i + 1, SZ(t));
				unsigned front2 = th2.get(0, i);
				unsigned back2 = th2.get(i + 1, SZ(t));
				for (auto h : cs) {
					unsigned hh = h;
					unsigned all = th.connect(front, hh, 1);
					all = th.connect(all, back, SZ(t) - i - 1);
					unsigned all2 = th2.connect(front2, hh, 1);
					all2 = th2.connect(all2, back2, SZ(t) - i - 1);
					res.push_back({all,all2});
				}
			}
			return res;
		};
		FOR(i, 0, SZ(t)) {
			auto ss = tdash_hash(i);
			for (auto &x : tdash_hash(i)) {
				auto it = smap.find(x);
				if (it != smap.end()) {
					ans += it->second;
				}
			}
		}
	}

	cout << (ans) << "\n";

	return 0;
}
