#include "bits/stdc++.h"
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

/* -----  2018/09/29  Problem: yukicoder 305  / Link: http://yukicoder.me/problems/no/305  ----- */
/* ------問題------

yukiくんは金庫の鍵の暗証番号を忘れてしまいました。 適当にyukiくんに番号を伝えて、なんとか解錠を手伝ってあげてください。

暗証番号は10桁の数字(0000000000 ～ 9999999999)です。 10桁の数字(先頭のゼロを含む)を標準出力に出力してください。
出力が暗証番号と異なる場合、

X locked
がジャッジから標準入力に返されます。 ここでXは金庫の暗証番号と一致した数字の数です。
鍵はまだ解錠できていないので、Xを参考に別の数字を試しましょう。 

出力が暗証番号と一致する場合、
10 unlocked
がジャッジから標準入力に返されます。
鍵が解錠出来たのでプログラムを終了してください。解錠したクエリより後に余計な出力があるとWAになります。

時間制限内なら何度でも挑戦可能です。 (7000クエリ程度でTLEになるそうです)

-----問題ここまで----- */
/* -----解説等-----

ある数字について質問をしたときに、i桁目だけを変えて質問をする。すると差分が1だけかわりうる。
ここを起点に変えていけばよい。100回以内に必ず答えを得ることができる。

最適化すればかなり回数を減らせそう？

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);


	auto ask = [](LL x) {
		cout << setw(10) << setfill('0') << x << endl;
		LL num; string s; cin >> num >> s;
		return PII(num, s == "unlocked");
	};

	LL val = 0;
	FOR(i, 0, 10) {
		LL state = -1;
		int opt = -1;
		FOR(j, 0, 10) {
			LL candidate = val + pow(10, i)*j;
			PII res = ask(candidate);
			if (res.second) { return 0; }
			if (res.first > opt) {
				opt = res.first;
				state = candidate;
			}
		}
		val = state;
		//debug(val);
	}
	assert(0);

	return 0;
}
