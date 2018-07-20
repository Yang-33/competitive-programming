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

/* -----  2018/07/23  Problem: AOJ 0297 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0297  ----- */
/* ------問題------

K 個の石から、P 人が順番に１つずつ石を取るゲームがあります。P 人目が石を取った時点で、まだ石が残っていれば、また１人目から順番に１つずつ石を取っていきます。このゲームでは、最後の石を取った人が勝ちとなります。K とP が与えられたとき、何人目が勝つか判定するプログラムを作成してください。

-----問題ここまで----- */
/* -----解説等-----

剰余で考えれば良い。0->Pにして問題ない。

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N; cin >> N;
	FOR(sh, 0, N) {
		int k, p; cin >> k >> p;
		cout << (k % p ? k%p : p) << endl;
	}

	return 0;
}