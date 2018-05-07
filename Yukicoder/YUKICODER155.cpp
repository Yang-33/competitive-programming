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

/* -----  2018/05/05  Problem: yukicoder 156  / Link: http://yukicoder.me/problems/no/156  ----- */
/* ------問題------

ユキさんは生放送で配信する際に，BGMとしてクララーリスというグループの曲を流しています．
ユキさんのミュージックプレイヤーには，クララーリスの曲が N 曲登録されており，その k 曲目の長さは Sk です．
また，ユキさんが生放送で配信する時間は L 分です．
ミュージックプレイヤーはランダム再生機能があり，まず，登録されている曲をランダムに並べ替えて，順番に再生されます．
また，全ての曲が再生された後は，再びランダムに並び替えて，順番に再生されます．
ユキさんの放送中に 1 秒でも流れる曲は何曲になるかという期待値を求めるプログラムを書いて下さい．
ランダムに並べ替える際は，N! パターンの並び替え方が等確率で起こるものとし，毎回独立に並び替えるとして下さい．
また，ユキさんは生放送が始まると同時に再生し始めます．

-----問題ここまで----- */
/* -----解説等-----

長い戦いだった。  
まず愚直では状態数が多すぎるので、状態をまとめる。  
合計p分の状態は、それぞれk個合わさってできるので、これら2つを状態を持つDPでまとめることができる。  
L分でかかる曲数が知りたい。これは、ある曲iを使用したときに、L分未満の状態から、L分を超えるかどうかを判定したい。
そこで、次のdpと計算が思いつく。  
dp[k][l] := k曲で、合計l分かかるときの組合せ  
として、一つの値を使用せずdptableを作成し、\sum k*dp[k][l-a[i]] / N! ただし、l-a[i]は L-a[i]< l-a[i]<L  
a[i]でL分を達成するように計算をする。計算量はO(N * N^2L)で、TLEする(実際にはギリギリ間に合う。)  

そこで、dptableのa[i]を使った更新は、path上に一つしか無いことを利用してdptableを一つ前の状態に戻すことを考える。  
これは以外にも簡単にできる。具体的には、dp[k+1][l]+=dp[k][l-a[i]]のように更新しているとき、  
dp[k+1][l]-=dp[k][l-a[i]]とするだけ。(本当に戻している感じがする)
これは戻すdpと呼ばれているらしく、操作的にはdpの逆元を扱う動作に見える。(ex:部分和dpは多項式の積とみれる話)

他の人の戻すdp解法はよくわからない…

----解説ここまで---- */

int main() {


	int N, L; cin >> N >> L;
	L *= 60;
	VI a(N);
	FOR(i, 0, N) {
		int m, s; char c;
		scanf("%d:%d", &m, &s);
		a[i] = 60 * m + s;
	}
	int sum = accumulate(ALL(a), 0);

	if (sum <= L) {
		cout << N << endl; return 0;
	}

	VVL dp(N + 1, VL(L + 4000, 0));
	dp[0][0] = 1;
	FOR(i, 0, N) {
		FORR(j, N - 1, 0 - 1) {
			FOR(k, a[i], L + 1) {
				dp[j + 1][k] += dp[j][k - a[i]];
			}
		}
	}
	vector<double>fact(52);
	fact[0] = fact[1] = 1;
	FOR(i, 1, 50) {
		fact[i + 1] = fact[i] * (i + 1);
	}

	double ans = 0;

	FOR(i, 0, N) {
		VVL diffdp = dp;
		FOR(j, 0, N) {
			FOR(k, 0, L) {
				diffdp[j + 1][k + a[i]] -= diffdp[j][k];
			}
		}
		FOR(j, 0, N) {
			FOR(k, max(0, L - a[i]), L) {
				ans += (j+1)*diffdp[j][k]* fact[j] *fact[N - j - 1];
			}
		}
	}

	ans /= fact[N];
	cout << fixed << setprecision(15) << ans << "\n";

	return 0;
}
