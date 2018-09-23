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

/* -----  2018/09/19  Problem: yukicoder 263  / Link: http://yukicoder.me/problems/no/263  ----- */
/* ------問題------

かつて、Common Palindromesという、その名の通り2個の文字列の共通部分回文のペアの個数を求める問題があった。この問題は当時の参加者たちを大いに苦しめた。 あれから3年以上の月日が流れ、CPUの性能も競技プログラマの質も格段に向上した。 Common Palindromesでの最速実行時間は0.05秒を切るという。したがって文字列の長さを10倍にしてもきっと解けるはずだ。

2個の文字列S,Tが与えられるので、以下の条件をすべて満たす組(i,j,k,l)の個数を求めよ。なお、文字列Uのx文字目以降y文字目以前の連続部分文字列をU[x,y]で表す。

1≤i≤j≤(Sの長さ).
1≤k≤l≤(Tの長さ).
S[i,j]=T[k,l].
S[i,j]は回文。

-----問題ここまで----- */
/* -----解説等-----

回分木もってますか？という問題。私は以前学習しました。(NJCC2017A)
回分の頻度計算がO(|回分数|)とかでできるので、Sの回分数は求まりそう。
Tについても同様にしたいが、一緒のものを見つけるのに二乗時間かかりそうなので考える。
割と良くない方法として、同じ回文だけ計算したいので回分木のカウントを一回クリアしてしまうと同じやつだけカウントできる。
submitをみたらみんなそんな感じだった。もっとうまくできそう。

----解説ここまで---- */


struct PalindromicTree {
	struct node {
		map<char, int> link;
		int suffix_link, len, count;
	};

	vector<node> c;
	string s;
	int active_idx;

	node* create_node() {
		c.emplace_back();
		node* ret = &c.back();
		ret->count = 0;
		return ret;
	}

	int find_prev_palindrome_idx(int node_id) {
		const int pos = int(s.size()) - 1;
		while (true) {
			const int opposite_side_idx = pos - 1 - c[node_id].len;
			if (opposite_side_idx >= 0 && s[opposite_side_idx] == s.back()) break;
			node_id = c[node_id].suffix_link;
		}
		return node_id;
	}

public:
	PalindromicTree() {
		node* size_m1 = create_node();
		size_m1->suffix_link = 0;
		size_m1->len = -1;
		node* size_0 = create_node();
		size_0->suffix_link = 0; // 親
		size_0->len = 0;

		active_idx = 0;
	}

	void add(char ch) {
		s.push_back(ch);

		const int a = find_prev_palindrome_idx(active_idx);
		const auto inserted_result = c[a].link.insert(make_pair(ch, int(c.size())));
		active_idx = inserted_result.first->second;
		if (!inserted_result.second) {
			c[active_idx].count++;
			return;
		}

		node* nnode = create_node();
		nnode->count = 1;
		nnode->len = c[a].len + 2;
		if (nnode->len == 1) {
			nnode->suffix_link = 1;
		}
		else {
			const int b = find_prev_palindrome_idx(c[a].suffix_link);
			nnode->suffix_link = c[b].link[ch];
		}
	}
};

VL f(const PalindromicTree & eertree) {
	VL freq(SZ(eertree.c));
	FORR(i, SZ(eertree.c) - 1, 0) {
		freq[i] += eertree.c[i].count;
		freq[eertree.c[i].suffix_link] += freq[i];
	}
	return freq;
}
void clearCnt(PalindromicTree & eertree) {
	FOR(i, 0, SZ(eertree.c)) {
		eertree.c[i].count = 0;
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string s, t;
	cin >> s >> t;
	PalindromicTree eertree;
	for (auto c : s) {
		eertree.add(c);
	}
	VL cnt1 = f(eertree);
	clearCnt(eertree);
	eertree.add('#');
	eertree.add('@');
	for (auto c : t) {
		eertree.add(c);
	}
	VL cnt2 = f(eertree);
	LL ans = 0;
	FOR(i, 2, SZ(cnt1)) { //最初の2つは特殊
		ans += cnt1[i] * cnt2[i];
	}
	cout << ans << "\n";

	return 0;
}
