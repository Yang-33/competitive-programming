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

/* -----  2018/04/24  Problem: yukicoder 112  / Link: http://yukicoder.me/problems/no/112  ----- */
/* ------問題------

N 匹の動物がいる。
動物たちは 1 から N まで番号が振られている。
また、動物たちはそれぞれ鶴か亀のいずれかである。
ご存知の通り、鶴の足は 2 本、亀の足は 4 本である。

ある日、動物たちは鶴亀算を勉強することにした。
そのためにまず、動物たちは各自で「全員の足の総本数」を集計した。
しかし、うっかり者の動物たちは皆、自分自身の足を数え忘れてしまった。

あなたの仕事は、以上の集計結果から鶴と亀の匹数を求めることである。

-----問題ここまで----- */
/* -----解説等-----

つるかめ算をしなくてもO(N^2)で全探索すれば良い。

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N; cin >> N;
	VI a(N);
	FOR(i, 0, N) {
		cin >> a[i];
	}
	PII ans;
	FOR(kame, 0, N + 1) {
		int sum = 4 * kame + 2 * (N - kame);
		int kamecnt = 0, tsurucnt = 0;
		FOR(i, 0, N) {
			if (a[i] == sum - 4)kamecnt++;
			else if (a[i] == sum - 2) tsurucnt++;
		}
		if (kame == kamecnt && (N-kame)==tsurucnt) {
			ans = PII(tsurucnt, kamecnt);
		}

	}

	cout << ans.first << " " << ans.second << "\n";

	return 0;
}
