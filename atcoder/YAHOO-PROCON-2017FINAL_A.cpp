#include <bits/stdc++.h>
using namespace std;

using VS = vector<string>;    using LL = long long;
using VI = vector<int>;       using VVI = vector<VI>;
using PII = pair<int, int>;   using PLL = pair<LL, LL>;
using VL = vector<LL>;        using VVL = vector<VL>;

#define ALL(a)  begin((a)),end((a))
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define EB emplace_back
#define MP make_pair
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

/* -----  2018/02/24  Problem: yahoo-procon-final_a / Link: https://yahoo-procon2017-qual.contest.atcoder.jp/tasks/yahoo_procon2017_qual_c?lang=en  ----- */
/* ------問題------

高橋君は Yafoo という検索エンジンをよく利用しています。
Yafoo には N 個のサイトが登録されており、i 個目のサイトの登録名は Si です。 また、文字列 T を検索ワードとして検索を行うと、登録されている N 個のサイトのうち、 登録名の長さが |T| 以上でかつ登録名の先頭 |T| 文字が T に一致するようなサイト全てが検索結果として得られます。
今、高橋君は検索結果として A1, A2, …, AK 番目のサイトが得られるようにしたいです。 そのような検索結果がちょうど得られるような検索ワードが存在するかどうかを判定し、存在する場合はその中で長さが最小のものを求めてください。

-----問題ここまで----- */
/* -----解説等-----

最悪なのでTrieでパンチ
ダメなものを境界にしないように、ノードの重みを変更すれば境界を検索できる。

----解説ここまで---- */

LL N, K;

LL ans = 0LL;

const int Alphabets = 26;
const int AlphabetBase = 'a';

class Trie {
	struct node {
		bool isleaf;
		node *children[Alphabets];
		LL has;
		int id;
		node() :isleaf(0), has(0), id(nodesize++) { memset(children, 0, sizeof children); }
	} *root;
	static int nodesize;

public:
	Trie() { root = new node(); }

	int getnodesize() { return nodesize; }
	void insert(string &s, LL val) {
		node *n = root;
		for (int level = 0; level < (int)s.size(); level++) {
			int idx = s[level] - AlphabetBase;
			if (n->children[idx] != NULL) {
				n = n->children[idx];
				n->has += val;

			}
			else {
				n->children[idx] = new node();
				n = n->children[idx];
				n->has += val;
			}
		}
		n->isleaf = 1;
	}


	int track(string &s, int k) {
		node *n = root;
		for (int level = 0; level < (int)s.size(); level++) {
			int idx = s[level] - AlphabetBase;
			n = n->children[idx];
			if (n->has == k)return level;
		}
		return -1;
	}

};
int Trie::nodesize = 0;


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> K;
	VI a(K);
	VI accept(N, 0);
	FOR(i, 0, K) {
		cin >> a[i];
		a[i]--;
		accept[a[i]] = 1;
	}

	VS s(N);
	FOR(i, 0, N) {
		cin >> s[i];
	}

	if (N == K) {
		cout << "" << endl;
		return 0;
	}

	Trie trie;
	FOR(i, 0, N) {
		if (!accept[i])trie.insert(s[i], -1e6);
		else trie.insert(s[i], 1);
	}

	int res = trie.track(s[a[0]], K);
	if (res < 0) {
		cout << -1 << endl;
		return 0;
	}

	cout << s[a[0]].substr(0, res + 1) << endl;


	return 0;
}
