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

/* -----  2018/04/17  Problem: yukicoder 090  / Link: http://yukicoder.me/problems/no/090  ----- */
/* ------問題------

ここに0番〜(N-1)番の品物がある。
また、
item1 item2 score
という形式で書かれた得点表がある。
品物を並べた時、item1がitem2よりも前であればscore点を獲得できるという意味である。

得点表が与えられるので、品物を適切に並び替えた時、獲得できる得点を最大化したい。そのときの得点を出力せよ。

注意：LL系の言語だと工夫しないといけないかもしれません。

-----問題ここまで----- */
/* -----解説等-----

N!が間に合うので全探索する。
O(N!MN)

----解説ここまで---- */

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, M; cin >> N >> M;
	using tp = tuple<int, int, int>;
	vector<tp>rules(M);
	FOR(i, 0, M) {
		int a, b, c; cin >> a >> b >> c;
		rules[i] = tp(a, b, c);
	}

	VI a(N, 0);
	iota(ALL(a), 0);

	do {
		LL ret = 0;
		for (tp& rule : rules) {
			VI b(N);
			FOR(j, 0, N) {
				b[a[j]] = j;
			}
			int x, y, z; tie(x, y, z) = rule;
			if (b[x] < b[y]) {
				ret += z;
			}
		}

		ans = max(ans, ret);
	} while (next_permutation(ALL(a)));



	cout << ans << "\n";

	return 0;
}
