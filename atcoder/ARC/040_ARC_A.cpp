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
//#pragma GCC optimize ("-O3") 
#ifdef YANG33
#include "mydebug.hpp"
#else
#define DEBUG(x) 
#endif
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/10/17  Problem: ARC 040 A / Link: http://arc040.contest.atcoder.jp/tasks/arc040_a  ----- */
/* ------問題------

イカの高橋君は床を塗るのが大好きです。N×N のマス目状に区切られた床を、友人の青木君と一緒に塗ることにしました。ただ塗るだけでは面白くないので、以下のようなゲームをしながら床を塗ることにしました。

高橋君は赤のインクを使い、青木君は青のインクを使って床を塗る。
塗り終わったら、赤のインクで塗られたマスと青のインクで塗られたマスの個数を数える。
赤のマスが青のマスよりも多ければ高橋君の勝ち、青のマスが赤のマスよりも多ければ青木君の勝ち、そうでなければ引き分け。
高橋君と青木君は今床を塗り終わりましたが、勝敗を判定するのに手間取っています。2 人の代わりに勝敗を判定してください。

-----問題ここまで----- */
/* -----解説等-----

数えます

----解説ここまで---- */

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N; cin >> N;
	int A = 0;
	int B = 0;
	FOR(_, 0, N) {
		string s; cin >> s;
		FOR(i, 0, SZ(s)) {
			if (s[i] == 'R')A++;
			else if (s[i] == 'B')B++;

		}
	}

	if (A != B) {
		cout << (A > B ? "TAKAHASHI" : "AOKI") << endl;
	}
	else { cout << "DRAW" << endl; }
	

	return 0;
}
