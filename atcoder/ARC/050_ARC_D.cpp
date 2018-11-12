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

/* -----  2018/11/12  Problem: ARC 050 D / Link: http://arc050.contest.atcoder.jp/tasks/arc050_d  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

文字列集合をつなげて辞書順最小をつくるときは、si<sjなら、si+sj<sj+siであるようにすればよい。
大小関係を求めたいが、連結すると当然TLEする。suffixを並べるので、LCPやらrankが使えそう。
i<jとすると、連結されたものについて、区間が3つに分かれる。
それぞれ場合分けすれば解ける。
1.先頭のa.bの共通部分がbの長さ未満の時：suffix[a],suffix[b]の大小関係を見ればよく、rank[a],rank[b]を見れば良い。
2.suffix[a]のaと、suffix[b]の続きのsuffix[a]の共通部分がその長さ未満の時：suffix[a]のprefixをlen(b)だけ削ったものはsuffix(c)と考えられる。
これについて、suffix[c],suffix[a]のrankを比べれば良い。
3.ソレ以降までlcpがあるとき：一致する(一致しないならば最初の比較に失敗しなければならないため)
結局、suffix集合であることによってO(1)の比較が可能。

----解説ここまで---- */

struct SuffixArray {
	vector<int> SA;
	string s;

	void Build_SA(const string& str) {
		s = str;
		SA.resize(s.size());
		iota(begin(SA), end(SA), 0);
		sort(begin(SA), end(SA), [&](const int& a, const int& b)
		{
			if (s[a] == s[b]) return(a > b);
			return (s[a] < s[b]);
		});
		vector<int> classes(s.size()), c(s.size()), cnt(s.size());
		for (int i = 0; i < s.size(); i++) {
			c[i] = s[i];
		}
		for (int len = 1; len < s.size(); len <<= 1) {
			for (int i = 0; i < s.size(); i++) {
				if (i > 0 && c[SA[i - 1]] == c[SA[i]] && SA[i - 1] + len < s.size() && c[SA[i - 1] + len / 2] == c[SA[i] + len / 2]) {
					classes[SA[i]] = classes[SA[i - 1]];
				}
				else {
					classes[SA[i]] = i;
				}
			}
			iota(begin(cnt), end(cnt), 0);
			copy(begin(SA), end(SA), begin(c));
			for (int i = 0; i < s.size(); i++) {
				int s1 = c[i] - len;
				if (s1 >= 0) SA[cnt[classes[s1]]++] = s1;
			}
			classes.swap(c);
		}
	}

	vector<int> res_sa() {
		return SA;
	}
};

template< typename MeetSemilattice>
struct SparseTable {
	using T = typename MeetSemilattice::t;
	vector<vector<T>> st;

	SparseTable() {}

	SparseTable(const vector<T> &v) {
		int b = 0;
		while ((1 << b) <= v.size()) ++b;
		st.assign(b, vector<T>(1 << b));
		for (int i = 0; i < v.size(); i++) {
			st[0][i] = v[i];
		}
		for (int i = 1; i < b; i++) {
			for (int j = 0; j + (1 << i) <= (1 << b); j++) {
				st[i][j] = MeetSemilattice::op(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
			}
		}
	}
	inline T query(int l, int r) {
		if (l > r)swap(l, r);
		int b = 32 - __builtin_clz(r - l) - 1;
		return (MeetSemilattice::op(st[b][l], st[b][r - (1 << b)]));
	}
};

VI make_lcp(const string s, const VI &sa, const VI&rank) {
	VI LCP;
	LCP.resize(s.size());
	LCP[0] = 0;
	for (int i = 0, h = 0; i < s.size(); i++) {
		if (rank[i] + 1 < s.size()) {
			for (int j = sa[rank[i] + 1]; max(i, j) + h < s.length() && s[i + h] == s[j + h]; ++h);
			LCP[rank[i] + 1] = h;
			if (h > 0) --h;
		}
	}
	return LCP;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N; cin >> N;
	string s; cin >> s;
	SuffixArray Sa; Sa.Build_SA(s);
	VI sa = Sa.res_sa();
	VI rank(N, 0);
	FOR(i, 0, N) {
		rank[sa[i]] = i;
	}
	DD(De(s, sa, rank));
	VI LCP = make_lcp(s, sa, rank);
	struct M {
		using t = int;
		static t op(const t&l, const t&r) { return min(l, r); }
	};
	SparseTable<M> rangelcp(LCP);
	VI ans(N);
	iota(ALL(ans), 0);


	// suffix(a)+suffix(b) < suffix(b)+suffix(a)であるか？
	auto comp = [&](const int a, const int b) {
		if (a == b)return false;
		DD(de(a,b,rank[a] + 1, rank[b] + 1));
		int abLcp = rangelcp.query(rank[a] + 1, rank[b] + 1);
		int bLen = N - b;
		// b]a]
		if (abLcp < bLen)return rank[a] < rank[b];
		// b]a ~ a[b

		// a[[b]+1..]
		int aexb = a + bLen;
		int aftBLcp = rangelcp.query(rank[a] + 1, rank[aexb] + 1);
		int abDiff = b-a;
		if (aftBLcp < abDiff)return rank[aexb] < rank[a];
		// line B:[b][a[b..]
		return rank[b] < rank[b]; // 一致するので、どっちでも良い(これの順序は問われてない
	};
	sort(ALL(ans), [&](const int i, const int j) {
		if (i > j)return !comp(j, i);
		return comp(i, j);
	});

	FOR(i, 0, N) {
		cout << ans[i] + 1 << endl;
	}
	return 0;
}
