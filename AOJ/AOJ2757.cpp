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

/* -----  2018/06/10  Problem: AOJ 2757 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2757  ----- */
/* ------問題------

1 か月前のことである． 小学生の肉西君は夏休みの宿題をやっていなかった． そこで自由研究は家にあった卵の強度を調べることにした．
この研究において，卵を高さ H から落としても割れず， 高さ H+1 から落とすと割れるとき， その卵の強度は H であると定義する． ここで H は非負整数であり，非負整数以外の高さから落とすことは無いとする． 肉西くんは卵を 1 つ落下させる実験を行う． 実験の結果は割れるか割れないかのいずれかである． また，卵の強度は全て同じである．つまり，どの卵を用いても実験の結果は同じである．
肉西くんは高さ 1 から N までの整数の高さの段からなる階段と， 強度が不明な E 個の卵を用意した． 高さ 0 では割れず，高さ N+1 では割れるということは既にわかっている． 肉西くんは各段と同じ高さから地面に向かって落とし，その度に卵が割れたか割れなかったかを調べる． このとき割れた卵は二度と使えないが，割れなかった場合は再利用できる． この実験を卵が残っている限り続けることができる． 何度か実験を繰り返し，上に定めた H が求まったとき，卵の強度が求まったとする．
夏休み終了まで後数日しか無い． 最小の回数で実験を終わらせないと間に合わない． そこで，肉西くんの兄であるあなたは，卵の強度を知るために 落とす回数が少なくなるように最適な方法をとった場合に 必要な実験回数の最大値を求めるプログラムを書くことにした．

-----問題ここまで----- */
/* -----解説等-----

egg drop problem n eggsと呼ばれている問題になる。
dp[i][k]:=i段目でk個の卵で強度を調べる最小回数というdpが簡単に浮かぶ。
しかしこれでは間に合わない。
解が小さくてdpのindexがでかいときは交換できうるので考える。
dp[k][j]:=k個の卵を用いてj回落として調べられる最大の段数(高さ)
とすれば解は50で抑えられるのでできる。
入力Eggs,Heightに対してdp[Eggs][idx]>=Height
を満たすようなidxを小さい方からしらべれればよい。

遷移は卵が割れるときと割れないときで変化するのがミソ。

----解説ここまで---- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	VVL dp(51, VL(51, 0));
	FOR(k, 0, 51) {
		FOR(j, 0, 51) {
			if (k == 0 || j == 0)dp[k][j] = 0;
			else dp[k][j] = 1 + dp[k - 1][j - 1] + dp[k][j-1];
		}
	}


	int Case;
	cin >> Case;
	FOR(q, 0, Case) {
		LL N, E;
		cin >> N >> E;
		int idx = 1;
		while (dp[E][idx] < N)idx++;
		cout << idx << endl;
	}
		
	return 0;
}
