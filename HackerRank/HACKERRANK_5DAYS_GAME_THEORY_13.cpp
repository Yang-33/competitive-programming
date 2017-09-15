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

/* -----  2017/09/15  Problem: hackerrank_5days_game_theory_13  / Link: https://www.hackerrank.com/contests/5-days-of-game-theory/challenges/powers-of-two-game  ----- */
/* ------問題------

*2^1*2^2*2^3*2^4*2^5*....*2^nがある。
両者は*を+/-のどちらかに変更できる。
その結果mod17が0なら後手の価値である。
どちらが勝つか。

-----問題ここまで----- */
/* -----解説等-----

周期8から、後手は相手に対応する手を選択することで常にmod17を0にできる。
しかし周期8ではない数の場合は何をしても勝てない。（全探索をした）
勝てる手が存在しても必勝ではないので先手の選択でこれを回避できることが分かる。
したがってmod8をみればよい。

----解説ここまで---- */

LL N;

LL ans = 0LL;
LL powmod(LL x, LL n, LL mod) {
	LL res = 1;
	while (n > 0) {
		if (n & 1) {
			res = (res*x) % mod;
		}
		x = (x*x) % mod;
		n >>= 1;
	}
	return res;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int T; cin >> T;
	FOR(t, 0, T) {
		cin >> N;
		cout << ((N%8!=0)?"First":"Second") << "\n";
	}

	//FOR(i, 0, N) {
	//	cout<< powmod(2, i + 1, LLONG_MAX)<<" "<< powmod(2, i + 1, 17)<<endl;
	//}


	/*VI v = { 2,4,8,16,15,13,9,1 };
	FOR(k, 1, 4) {
		int X = 2 * k;
		FOR(i, 0, 1 << X) {
			int sum = 0;
			FOR(j, 0, X) {
				if (i&(1 << j))sum += v[j];
				else sum -= v[j];
			}
			if (sum % 17 == 0) {
				cout << "FOUND" << endl;
				FOR(j, 0, X) {
					if (i&(1 << j))cout << v[j] << " ";
					else cout << -v[j] << " ";
				}
				cout << endl;
			}
		}
	}*/

	return 0;
}
