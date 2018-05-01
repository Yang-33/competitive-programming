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

/* -----  2018/04/26  Problem: yukicoder 123  / Link: http://yukicoder.me/problems/no/123  ----- */
/* ------問題------

1からNまでの数字を描いたカードが各1枚、合計N枚あります。
カードは1からNまで順に上から積まれています。いちばん上が1のカードです。
上からAi番目のカードを抜いていちばん上に積みます。これを1回のシャッフルとします。
M回のシャッフルが行われた後にいちばん上にあるカードの数字はいくつでしょう？

-----問題ここまで----- */
/* -----解説等-----

はいはいーと思ったら効率的な解法が存在する。
逆から見ると…の問題で、後ろ側からシュミレーションするとNにかかわらずO(M)


----解説ここまで---- */

LL ans = 0LL;
LL solve(int M) {
	VI ms(M);
	FOR(i, 0, M) {
		cin >> ms[i];
	}
	int pos = 1;
	FORR(i, M - 1, 0 - 1) {
		if (pos == 1) {
			pos = ms[i];
		}
		else {
			if (pos <= ms[i])pos--;
		}
	}
	return pos;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, M; cin >> N >> M;

	const int effective = 1;
	if (effective) { // O(M)
		ans = solve(M);
	}
	else { // naive O(NM)
		VI a(N);
		iota(ALL(a), 1);
		FOR(i, 0, M) {
			int pos; cin >> pos;
			int x = a[pos - 1];
			a.erase(a.begin() + pos - 1);
			a.insert(a.begin(), x);
		}
		ans = a.front();
	}
	cout << ans << "\n";

	return 0;
}
