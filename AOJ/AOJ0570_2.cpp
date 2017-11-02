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
const LL MOD = 10000;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2017/11/01  Problem: ketadp5 / Link: https://www.ioi-jp.org/joi/2011/2012-yo-prob_and_sol/2012-yo-t6/2012-yo-t6.html  ----- */
/* ------問題------

正の整数を (先頭に 0 をつけずに) 10 進法で書いて桁の数字を順番に見ていくと増加と減少を交互に繰り返しているとき，その数は「ジグザグ数」であると呼ぶことにしよう．
たとえば，2947 は桁の数字が 2 → 9 → 4 → 7 と，増加 → 減少 → 増加 の順になっているのでジグザグ数である．
また，71946 は 減少 → 増加 → 減少 → 増加 の順なのでジグザグ数である．一方，123 や 71446 や 71442 や 88 はジグザグ数ではない．
なお，1 桁の正の整数はジグザグ数であると考えることとする．
A 以上 B 以下の M の倍数のうち，ジグザグ数の個数を 10000 で割った余りを求めるプログラムを作成せよ．

-----問題ここまで----- */
/* -----解説等-----

情報が多いだけで今までのことを使えば簡単。
dp[i番目を見ている][mの倍数か][前の桁の数は何か][数字の遷移はup?down?-?][less]:=総数
としてやればよい。
これをforループとして書くのは大変そう

----解説ここまで---- */

LL N;
int mod;
LL ans = 0LL;
LL dp[502][502][10][3][2];

LL f(string &target, int i, int m, int bef, int ud, int less) {
	if (i == SZ(target)) {
		if (m%mod == 0)return 1;
		else return 0;
	}
	LL &res = dp[i][m][bef][ud][less];
	if (res != -1)return res;
	res = 0;
	int num = target[i] - '0';
	int Max = less ? 9 : num;
	// ud:= 0:決まってない  1:下がってきた  2:上がってきた
	FOR(nx, 0, Max + 1) {
		if (ud == 0) {
			if (bef == 0)// leading zero
				res += f(target, i + 1, (10 * m + nx) % mod, nx, 0, less | (nx < Max));
			else if (bef < nx)
				res += f(target, i + 1, (10 * m + nx) % mod, nx, 2, less | (nx < Max));
			else if (bef > nx)
				res += f(target, i + 1, (10 * m + nx) % mod, nx, 1, less | (nx < Max));
		}
		else if (ud == 1) {
			if (bef < nx)
				res += f(target, i + 1, (10 * m + nx) % mod, nx, 2, less | (nx < Max));
		}
		else if (ud == 2) {
			if (bef > nx)
				res += f(target, i + 1, (10 * m + nx) % mod, nx, 1, less | (nx < Max));
		}
		res=(res+10000)% 10000;
	}
	return res;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string A, B; cin >> A >> B;
	int M; cin >> M; mod = M;
	// f(B)-f(A-1)
	int id = SZ(A) - 1;
	int dw = 0;
	if (A[id] == '0')A[id] = '9', dw = 1;
	else A[id]--;
	id--;
	while (id >= 0) {
		if (dw == 1) {
			if (A[id] == '0')A[id] = '9';
			else A[id]--, dw = 0;
		}
		id--;
	}
	if (A[0] == '0')A = A.substr(1, SZ(A));
	//debug(A);

	ans = 0;
	LL ret1 = 0, ret2 = 0;

	fill(****dp, ****dp + 502 * 502 * 10 * 3 * 2, -1);
	ret1 += f(B, 0, 0, 0, 0, 0);
	//debug(ret1);
	if (A != "0") {
		fill(****dp, ****dp + 502 * 502 * 10 * 3 * 2, -1);
		ret2 = f(A, 0, 0, 0, 0, 0);
	}
	//debug(ret2);
	ans = ret1 - ret2;
	ans = (ans + 30000) % 10000;
	cout << ans << "\n";

	return 0;
}
