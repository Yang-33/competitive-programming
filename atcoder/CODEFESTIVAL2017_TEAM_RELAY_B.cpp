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

/* -----  2017/12/04  Problem: codefestival2017_team_relay B / Link: https://cf17-relay-open.contest.atcoder.jp/tasks/relay2_b ----- */
/* ------問題------

整数 N が与えられます。下図のような、無限に伸びる完全 N 分木を考えます。
図で示されているように、各頂点には重複しない正の整数の番号が付いており、どの正の整数に対してもそれを頂点番号として持つ頂点が存在します。木の根の頂点番号は 1 です。その他の頂点には、上の段にある頂点ほど小さな番号が付けられています。同じ段にある頂点には、左に位置するほど小さな番号が付けられています。
この木に関して、以下の形式の Q 個の問いに答えてください。i 番目の問い (1≤i≤Q) は次の通りです。
頂点 vi と wi の最近共通祖先（注釈を参照）の頂点番号を求めよ。

-----問題ここまで----- */
/* -----解説等-----

まず1を引いておく。
上の段について考えると、さらに値を-1したもので、Nで割れば親番号が求まる気がするので実験をするとできる。
それによって0までの祖先がわかるので、一致しなくなるまで降りていけば良い。
これが通用しないのは N=1のときだが、これは一列にしかならないので簡単で値の小さいほうが祖先。

----解説ここまで---- */

LL N, Q;

LL ans = 0LL;

void kim(VL & a, LL val) {
	while (val) {
		a.push_back(val);
		val = (val - 1) / N;
	}
	a.push_back(val);
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> Q;
	FOR(i, 0, Q) {
		LL v, w;
		cin >> v >> w;
		if (N == 1) {
			ans = min(v, w);
		}
		else {
			v--; w--;
			VL a, b;
			kim(a, v); kim(b, w);
			int kima = SZ(a);
			int kimb = SZ(b);
			int depmin = min(kima, kimb);
			int k = 1;
			while (k < depmin&&a[kima - 1 - k] == b[kimb - 1 - k]) {
				k++;
			}
			ans = a[kima - k] + 1;
		}

		cout << ans << "\n";
	}

	return 0;
}
