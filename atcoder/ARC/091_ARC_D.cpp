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

/* -----  2018/03/11  Problem: ARC 091 D / Link: http://arc091.contest.atcoder.jp/tasks/arc091_d  ----- */
/* ------問題------

高橋君と青木君は、石取りゲームをしています。最初、山が N 個あり、i 個目の山には Ai 個の石があり、整数 Ki が定まっています。

高橋君と青木君は、高橋君から始めて、交互に以下の操作を繰り返します。

山を 1 つ選ぶ。i 個目の山を選び、その山に X 個の石が残っている場合、1 個以上 floor(X⁄Ki) 個以下の任意の個数の石を i 個目の山から取り除く。
先に操作ができなくなったプレイヤーが負けです。両者最善を尽くしたとき、どちらのプレイヤーが勝つか判定してください。 ただし、floor(x) で x 以下の最大の整数を表します。

-----問題ここまで----- */
/* -----解説等-----

†実験するだけ†
割り切れれば N / K
そうでないとき山は N - 1 -N/kに変化
変化がないときは上手に遷移を計算する

----解説ここまで---- */

LL N,a,k;

LL ans = 0LL;

LL grundy(LL p) {
	if (p%k == 0)return p / k;
	LL nx = p - (p / k) - 1;
	if (nx / k != p / k) {
		return grundy(nx);
	}
	LL x = p / k + 1;
	LL y = (p / k)*k;
	LL z = (p - y) / x;
	return grundy(p - x*z);
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	FOR(i, 0, N) {
		cin >> a >> k;
		ans ^= grundy(a);
	}



	cout << (ans==0?"Aoki":"Takahashi") << "\n";

	return 0;
}
