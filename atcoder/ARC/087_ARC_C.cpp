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

/* -----  2017/12/16  Problem: ARC 087 C / Link: http://arc087.contest.atcoder.jp/tasks/arc087_c  ----- */
/* ------問題------

文字列 s, t について、s が t の prefix でなく、t が s の prefix でないとき、s, t は prefix-free であると言います。
L を正の整数とします。 文字列集合 S が 良い文字列集合 であるとは、次の条件が成り立つことです。
S の各文字列は、長さ 1 以上 L 以下であり、文字 0, 1 のみからなる。
S の相異なる 2 つの文字列のペアはいずれも prefix-free である。
良い文字列集合 S={s1,s2,…,sN} があります。 Alice と Bob が次のゲームで勝負します。 二人は交互に次の操作を行います。 Alice が先手です。

S に新しい文字列をひとつ追加する。 ただし、追加後の S は良い文字列集合のままでなければならない。
先に操作を行えなくなった方が負けです。 二人が最適に行動するとき、どちらが勝つか判定してください。

-----問題ここまで----- */
/* -----解説等-----

完全二分木の値がわかると深いとこから値を取ってくるだけで、それのXORの値がゲーム値
Trieっぽくやると良い

----解説ここまで---- */

LL N, L;

LL ans = 0LL;
LL gameval(LL x) {
	//FOR(i, 0, 65) {
	//	if (x &(1LL << i))return 1LL << i;
	//}
	//assert(0);
	return x & -x;
}

int tr[1000006][2];


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> L;
	// 0, 1 graph
	fill(*tr, *tr + 1000006 * 2, -1);
	VL h(2*1000006, 0);
	int nsize = 0;
	FOR(kim, 0, N) {
		int cnt = 0;
		string s; cin >> s;

		FOR(i, 0, SZ(s)) {
			int to = s[i] - '0';
			if (tr[cnt][to] == -1) {
				tr[cnt][to] = ++nsize,
				h[nsize] = h[cnt] + 1;
			}
			cnt = tr[cnt][to];
		}
	}
	VL subg;
	for (int i = 0; i <= nsize; ++i){
		int xx = min(tr[i][0], tr[i][1]);
		int yy = max(tr[i][0], tr[i][1]);
		if (xx == -1 && yy > -1) {
			subg.push_back(gameval(L - h[i]));
		}
	}

	FOR(i, 0, SZ(subg)) {
		ans ^= subg[i];
	}
	cout << (ans ? "Alice" : "Bob") << "\n";

	return 0;
}
