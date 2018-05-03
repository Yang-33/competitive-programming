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

/* -----  2018/05/03  Problem: yukicoder 144  / Link: http://yukicoder.me/problems/no/144  ----- */
/* ------問題------

「エラトステネスのふるい」は、与えられた自然数 N 以下の素数を列挙する古典的アルゴリズムである。
以下にそのアルゴリズムを示す。

まず、2 から N までの整数からなる「候補リスト」と、空の「素数リスト」を用意する。
候補リストが空になるまで、次のステップを繰り返す。

候補リストに含まれる最小の数を x とする。
x を素数リストへ移動し、2x, 3x, 4x, ... を候補リストから削除する。
候補リストが空になったとき、素数リストに含まれる数が素数である。

ゆきこちゃんはこのアルゴリズムを実行し、N 以下の素数を列挙しようとしている。
ただし、うっかり者のゆきこちゃんは、ステップによっては下線部の処理を丸々飛ばしてしまう。
つまり、x を素数リストへ移動した後、すぐに次のステップへ移ってしまう。
このため、素数として列挙される数は正しくない可能性がある。

さて、各ステップで下線部の処理が行われる確率が p であるとする。
このとき、素数として列挙される数の個数の期待値を求めよ。

-----問題ここまで----- */
/* -----解説等-----

(1-p)^(印をつけられる回数) :=一回もふるいにかけられない
なので、これをふるいにかけるのと一緒の書き方でシュミレーションする。

----解説ここまで---- */
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N;
	double d, ans = 0;
	cin >> N >> d;
	VI cnt(N + 1, 0);
	FOR(i, 2, N + 1) {
		ans += pow(1 - d, cnt[i]);
		for (int j = 2 * i; j <= N; j += i) {
			cnt[j]++;
		}
	}
	cout << fixed << setprecision(10) << ans << "\n";

	return 0;
}
