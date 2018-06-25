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

/* -----  2018/06/26  Problem: AOJ ALDS1_14_D / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_D  ----- */
/* ------問題------

文字列 T の中に文字列 P が出現するかどうかを判定してください。
最初に T が与えられたうえで、質問として Q 個の Pi が与えられます。

-----問題ここまで----- */
/* -----解説等-----

困ったらSAしかないんじゃあないんだよね

----解説ここまで---- */

struct SuffixArray {
	vector< int > SA;
	const string s;

	SuffixArray(const string &str) : s(str) {
		SA.resize(s.size());
		iota(begin(SA), end(SA), 0);
		sort(begin(SA), end(SA), [&](int a, int b) {
			return s[a] == s[b] ? a > b : s[a] < s[b];
		});
		vector< int > classes(s.size()), c(s.begin(), s.end()), cnt(s.size());
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

	int operator[](int k) const {
		return SA[k];
	}

	size_t size() const {
		return s.size();
	}

	bool lt_substr(const string &t, int si = 0, int ti = 0) {
		int sn = (int)s.size(), tn = (int)t.size();
		while (si < sn && ti < tn) {
			if (s[si] < t[ti]) return true;
			if (s[si] > t[ti]) return false;
			++si, ++ti;
		}
		return si >= sn && ti < tn;
	}

	int lower_bound(const string &t) {
		int low = -1, high = (int)SA.size();
		while (high - low > 1) {
			int mid = (low + high) / 2;
			if (lt_substr(t, SA[mid])) low = mid;
			else high = mid;
		}
		return high;
	}
	// lower_upper_bound(t):= 文字列 t を含む接尾辞のindexの下限と上限(半開区間)を返す。
	pair< int, int > lower_upper_bound(string &t) {
		int idx = lower_bound(t);
		int low = idx - 1, high = (int)SA.size();
		t.back()++;
		while (high - low > 1) {
			int mid = (low + high) / 2;
			if (lt_substr(t, SA[mid])) low = mid;
			else high = mid;
		}
		t.back()--;
		return { idx, high };
	}

	void output() {
		for (int i = 0; i < size(); i++) {
			cout << i << ": " << s.substr(SA[i]) << endl;
		}
	}
};


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string T;
	cin >> T;
	int Q;
	cin >> Q;
	SuffixArray sa(T);
	FOR(i, 0, Q) {
		string s;
		cin >> s;
		PII a = sa.lower_upper_bound(s);
		if (a.second - a.first) {
			puts("1");
		}
		else {
			puts("0");
		}
//		cout << a.first << "," << a.second << endl;
	}


	return 0;
}
