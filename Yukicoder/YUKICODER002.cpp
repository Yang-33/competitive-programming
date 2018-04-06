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

/* -----  2018/04/06  Problem: yukicoder 002  / Link: http://yukicoder.me/problems/no/002  ----- */
/* ------問題------

最近素因数を習ったばかりのAliceとBobが数字に関するゲームをします。

ゲームの内容は以下のとおりです。
・まず初めに、先攻のプレイヤーに2以上の自然数Nが与えられます。
・その番のプレイヤーは、Nに対して、「Nの素因数」のどれかで割り、相手にその商になる数を渡します。
・この時、同じ数であれば、割り切れる限り１回以上であれば何回割ってもいいこととします。
例えば、24の素因数は 2,3 (24=2×2×2×3) であるため 24を2で2回わった数6を相手に渡すことが出来ます。
・次のプレイヤーは渡された数を新たなNとし、以上の手順を繰り返します。
・渡された数が1になったプレイヤーが負けです。

まずAliceが先攻となりゲームを始めます。
この時、どちらも最善を尽くすと考えたとき、自然数Nが与えられた時の勝者を求めてください。

-----問題ここまで----- */
/* -----解説等-----

基本となる素数をNIMの山として、ある素数の数はあるNIMの山の石の数に対応する。
素因数は sqrt(N)で、
Nimは素因数の各個数を列挙したもののXORを取ればよい。

初心者WAを出しました。

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	VI a;
	LL NN = N;
	for (int i = 2; i*i <= NN; i++) {
		int cnt = 0;
		while (N%i == 0) {
			cnt++;
			N /= i;
		}
		if (cnt)a.push_back(cnt);
	}
	if (N> 1) {
		a.push_back(1);
	}
	FOR(i, 0, SZ(a)) {
		ans ^= a[i];
	}


	cout << (ans==0?"Bob":"Alice") << "\n";

	return 0;
}
