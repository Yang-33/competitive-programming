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

/* -----  2018/06/11  Problem: AOJ 2197 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2197  ----- */
/* ------問題------

あなたは数か月に渡る受験戦争を勝ち抜き，晴れてICPC大学に入学することができた．入学手続きの日，大学のキャンパス内では熱狂的なサークルの勧誘活動が行われており，あなたは大量のパンフレットを受け取って帰ってきた．部屋に戻ってきたあなたは受け取ったパンフレットの中から気になる一枚を見つけた．そのパンフレットは大学の広報部から渡されたものだった．

パンフレットには以下のような問題が記されていた．

和が N となるような，連続する2つ以上の正の整数の組み合わせは，何組存在するでしょうか？例えば， 9 は 2+3+4 と 4+5 の 2通りの組み合わせがあります．
この問題の答えが気になったあなたは，プログラムを書いてその答えを調べることにした．したがって，あなたの仕事は，入力として与えられる正の整数 N に対して，問題の答えを出力するプログラムを書くことである．

-----問題ここまで----- */
/* -----解説等-----

全探索すれば良い

----解説ここまで---- */

void solve() {
	int N;
	while (cin >> N, N) {
		int ans = 0;
		VL csum(N + 1, 0);// f(i)=[0,i]の和
		FOR(i, 0, N + 1) {
			csum[i] = i;
			if (i)csum[i] += csum[i - 1];
		}
		FOR(i, 0, N + 1) {
			FOR(j, i + 2, N + 1) {
				LL s = csum[j] - csum[i];
				if (s == N) {
					ans++;
				}
			}
		}
		cout << ans << endl;
	}
}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	solve();
	return 0;
}