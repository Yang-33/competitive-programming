#include "bits/stdc++.h"
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

/* -----  2017/10/23  Problem: nu_2  / Link: http://joi2009ho.contest.atcoder.jp/tasks/joi2009ho_a  ----- */
/* ------問題------

整数 n に対し，n + 1 個の I と n 個の O を I から始めて交互に並べてでき
る文字列を Pn とする．ここで I と O はそれぞれ英大文字のアイとオーである．
P1 IOI
P2 IOIOI
P3 IOIOIOI
整数 n と，I と O のみからなる文字列 s が与えられた時，s の中に Pn が何ヶ所含ま
れているかを出力するプログラムを作成せよ．
-----問題ここまで----- */
/* -----解説等-----

手前の情報があれば解けるのでDP的なノリで解きます。

----解説ここまで---- */

LL N,M;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	string S;
	cin >> N>>M>>S;
	VI cnt(M * 2,0);
	FOR(i, 2, SZ(S)) {
		if (S[i] == 'I'&&S[i - 1] == 'O'&&S[i - 2] == 'I') {
			cnt[i] = cnt[i - 2] + 1;
		}
	}

	FOR(i, 0, SZ(S)) {
		if (cnt[i] >= N)ans++;
		//cout << cnt[i] << " ";
	}
	cout << ans << "\n";

	return 0;
}
