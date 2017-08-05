#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define FOR(i, s, e) for (ll(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (ll(i) = (s); (i) > (e); (i)--)
#define debug(x) cout << #x << ": " << x << endl
#define mp make_pair
#define pb push_back
const ll MOD = 1000000007;
const int INF = 1e9;
const ll LINF = 1e16;
const double PI = acos(-1.0);
int dx[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2017/08/05  Problem: JNCC17_summer A  / Link:  https://www.hackerearth.com/ja/challenge/hiring/jnccsummer17/ ----- */
/* ------問題------

文字列S中の部分回分の個数は(|S|≦130172)
ex: apple -> 5 (a,p,pp,l,e) 

-----問題ここまで----- */
/* -----解説等-----

回文木を書く。おわり(前日に書いていたので写経するだけだった)

----解説ここまで---- */

ll N;

ll ans = 0LL;

struct palindromic_tree {
	struct node {
		int next[26], fail, len;
		int cnt, num;
		node(int l = 0) :fail(0), len(l), cnt(0), num(0) {
			for (int i = 0; i < 26; ++i)next[i] = 0;
		}
	};
	std::vector<node >St;
	std::vector<char >s;
	int last, n;
	palindromic_tree() :St(2), last(1), n(0) {
		St[0].fail = 1;
		St[1].len = -1;
		s.push_back(-1);
	}
	inline void clear() {
		St.clear();
		s.clear();
		last = 1;
		n = 0;
		St.push_back(0);
		St.push_back(-1);
		St[0].fail = 1;
		s.push_back(-1);
	}
	inline int get_fail(int x) {
		while (s[n - St[x].len - 1] != s[n])x = St[x].fail;
		return x;
	}
	inline void add(int c) {
		s.push_back(c -= 'a');
		++n;
		int cur = get_fail(last);
		if (!St[cur].next[c]) {
			int now = St.size();
			St.push_back(St[cur].len + 2);
			St[now].fail = St[get_fail(St[cur].fail)].next[c];
			St[cur].next[c] = now;
			St[now].num = St[St[now].fail].num + 1;
		}
		last = St[cur].next[c];
		++St[last].cnt;
	}
	inline void count() {
		std::vector<node>::reverse_iterator i = St.rbegin();
		for (; i != St.rend(); ++i) {
			St[i->fail].cnt += i->cnt;
		}
	}
	inline int Node_size() {
		return St.size() - 2;
	}
};

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;

	palindromic_tree tr;
	FOR(i, 0, s.size())
		tr.add(s[i]);

	ans =(tr.Node_size());
	cout << ans << endl;

	return 0;
}
