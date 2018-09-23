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

/* -----  2018/09/19  Problem: yukicoder 262  / Link: http://yukicoder.me/problems/no/262  ----- */
/* ------問題------

Carol は特殊なすごろくをしようとしている。
1 から N の番号がふられている一直線に並べられている N 個のマスがある。
1 から開始のマスとして、ゴールは N が書かれているマスとする。
その場に書かれている数字の2進数で表現した時の 1 のビット数 だけ「前」に進むことができる。
(1 未満と N+1 以上のマスには移動することは出来ない、正確に N にならないとゴールできない）
正整数 N を与えられた時、ゴールに到達できる最短の移動数（開始のマスへも移動にカウントする）を求めてください。
到達できない場合は -1 を出力してください。

-----問題ここまで----- */
/* -----解説等-----

全然進まなくないですかという気持ちになると、これは移動をまとめて行いたいという気持ちになる。
まとめて行う際に、2^20ぐらいでやるといいかんじっぽそうという風になると、平方分割っぽく解ける。
具体的には2^20ぐらいずつ進むが、上位桁と下位桁にわけてやる。
上位桁と、全体の和のbit数だけがキーとなるのでこれを分けて先にテーブルを作っておくと、sqrt(N)ぐらいでできて嬉しい。

----解説ここまで---- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N; cin >> N;
	VVL cntMemo(30, VL(41, 0));
	VVL addValue = cntMemo;
	const LL sqrtDecompValue = 1 << 20;
#define b(x) __builtin_popcountll(x)

	FOR(i, 0, 21) {
		FOR(j, 0, 41) {
			if (!i && !j)continue;
			LL curValue = j;
			int steps = 0;
			while (curValue < sqrtDecompValue) {
				curValue += b(curValue) + i;
				steps++;
			}
			cntMemo[i][j] = steps;
			addValue[i][j] = curValue - j;
		}
	}

	LL ans = 1;
	LL curValue = 1;
	// skip simulation
	while (curValue + addValue[b(curValue >> 20)][curValue & 63]< N) {
		ans += cntMemo[b(curValue >> 20)][curValue & 63];
		curValue += addValue[b(curValue >> 20)][curValue & 63];
	}

	while (curValue < N) {
		ans++;
		curValue += b(curValue);
	}

	if (curValue != N)ans = -1;

	cout << ans << "\n";

	return 0;
}
