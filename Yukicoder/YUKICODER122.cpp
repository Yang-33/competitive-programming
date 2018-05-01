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
#define debug(x) cerr << #x << ": " << x<<", "
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/04/26  Problem: yukicoder 122  / Link: http://yukicoder.me/problems/no/122  ----- */
/* ------問題------

ここ数日で門松列に関する問題が頻出しております．
ここでは演習を通じて，門松列に対する理解を深め，門松列の問題が出題された時に解けるようになっておきましょう．
門松列対策講座を受講される皆様は既にご存知かと思いますが，門松列とは 3 個の要素からなる数列 a,b,c で以下の 2 つの条件を満たすものです．
・a,b,c は全て異なる
・3 つの要素の中で b が最も大きい，または，b が最も小さい
この問題では通常の門松列ではなく，最近ブームになりつつあるスーパーリッチ門松列を考えましょう．
スーパーリッチ門松列とは 7 個の要素からなる数列 a,b,c,d,e,f,g で以下の 2 つの条件を満たすものです．
・a,b,c,d,e,f,g は全て異なる
・min(b,d,f)>max(a,c,e,g) または max(b,d,f)<min(a,c,e,g)
（直感的には，全要素異なり，偶数番目の要素が小さい方から3つ，または，大きい方から3つになっているということです．ジグジグザグザグ）
由岐さんは得体の知らないものをよく知るための第一歩は数えることだと思っています．
そこで，各要素 x=a,b,c,d,e,f,g の下限 xmin と上限 xmax が与えられるので，xmin≤x≤xmax を満たし，更に全ての要素が整数からなるスーパーリッチ門松列の数を数えるプログラムを書いてください．
ただし，答えは大きくなるかもしれないので答えを 109+7 で割った余りを出力してください．

-----問題ここまで----- */
/* -----解説等-----

a,c,e,g:=group1 b,d,f:=group2とする。
F(i,j):=group j について、最大値がiで、残りの数はuniqueとなる場合の数  
G(i,j):=group j について、最小値がiで、残りの数はuniqueとなる場合の数  
とすると答えは以下  
ans = sum_{k=1}^{Xmax} (sum_{i=1}^{k-1}F(i,1))*G(k,2) + (sum_{i=1}^{k-1}F(i,2))*G(k,1) 
内側のsumは、前計算すれば良いので,O(Xmax*2^{N/2})で解ける。



----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int in[7][2];
	VI ord({ 0,4,1,5,2,6,3 });
	for (int i : ord) {
		cin >> in[i][0] >> in[i][1];
	}

	VVL Fset(20004, VL(2, 0));// a,c,e,g / b,d,f
	VVL Gset(20004, VL(2, 0));
	FOR(i, 1, 20000 + 1) {
		FOR(j, 0, 4) { // a,c,e,g
			int a = j % 4, c = (j + 1) % 4, e = (j + 2) % 4, g = (j + 3) % 4;
			if (in[a][0] <= i && i <= in[a][1]) { // base

				{ // F(i):=1つの数をiにして、i未満の選択をする組合せ
					LL s1 = max(0, min(i - 1 + 1, in[c][1] + 1) - in[c][0]);
					LL s2 = max(0, min(i - 1 + 1, in[e][1] + 1) - in[e][0]);
					LL s3 = max(0, min(i - 1 + 1, in[g][1] + 1) - in[g][0]);
					LL s12 = max(0, min({ i - 1 + 1,in[c][1] + 1,in[e][1] + 1 }) - max(in[c][0], in[e][0]));
					LL s23 = max(0, min({ i - 1 + 1,in[e][1] + 1,in[g][1] + 1 }) - max(in[e][0], in[g][0]));
					LL s31 = max(0, min({ i - 1 + 1,in[g][1] + 1,in[c][1] + 1 }) - max(in[g][0], in[c][0]));
					LL s123 = max(0, min({ i - 1 + 1, in[c][1] + 1,in[e][1] + 1,in[g][1] + 1 }) - max({ in[c][0],in[e][0],in[g][0] }));

					if (s1 > 0 && s2 > 0 && s3 > 0) {
						Fset[i][0] += s1*s2*s3;
						Fset[i][0] -= s12*s3;
						Fset[i][0] -= s23*s1;
						Fset[i][0] -= s31*s2;
						Fset[i][0] += 2 * s123;
					}
				}

				{ // G(i):=1つの数をiにして、iより大きい選択をする組合せ
					LL s1 = max(0, in[c][1] - max(i + 1 - 1, in[c][0] - 1));
					LL s2 = max(0, in[e][1] - max(i + 1 - 1, in[e][0] - 1));
					LL s3 = max(0, in[g][1] - max(i + 1 - 1, in[g][0] - 1));
					LL s12 = max(0, min(in[c][1], in[e][1]) - max({ i + 1 - 1, in[c][0] - 1,in[e][0] - 1 }));
					LL s23 = max(0, min(in[e][1], in[g][1]) - max({ i + 1 - 1, in[e][0] - 1,in[g][0] - 1 }));
					LL s31 = max(0, min(in[g][1], in[c][1]) - max({ i + 1 - 1, in[g][0] - 1,in[c][0] - 1 }));
					LL s123 = max(0, min({ in[c][1],in[e][1],in[g][1] }) - max({ i + 1 - 1,in[c][0]-1,in[e][0]-1,in[g][0]-1}));


					if (s1 > 0 && s2 > 0 && s3 > 0) {
						Gset[i][0] += s1*s2*s3;
						Gset[i][0] -= s12*s3;
						Gset[i][0] -= s23*s1;
						Gset[i][0] -= s31*s2;
						Gset[i][0] += 2 * s123;
					}
				}

			}
		}

		FOR(j, 0, 3) { // b,d,e

			int b = j % 3 + 4, d = (j + 1) % 3+ 4, f = (j + 2) % 3 + 4;
			if (in[b][0] <= i && i <= in[b][1]) { // base

				{ // F(i):=1つの数をiにして、i未満の選択をする組合せ
					LL s1 = max(0, min(i - 1 + 1, in[d][1] + 1) - in[d][0]);
					LL s2 = max(0, min(i - 1 + 1, in[f][1] + 1) - in[f][0]);
					LL s12 = max(0, min({ i - 1 + 1,in[d][1] + 1,in[f][1] + 1 }) - max(in[d][0], in[f][0]));

					if (s1 > 0 && s2 > 0) {
						Fset[i][1] += s1*s2;
						Fset[i][1] -= s12;
					}
				}

				{ // G(i):=1つの数をiにして、iより大きい選択をする組合せ
					LL s1 = max(0, in[d][1] - max(i + 1 - 1, in[d][0] - 1));
					LL s2 = max(0, in[f][1] - max(i + 1 - 1, in[f][0] - 1));
					LL s12 = max(0, min(in[d][1], in[f][1]) - max({ i + 1 - 1, in[d][0] - 1,in[f][0] - 1 }));

					if (s1 > 0 && s2 > 0) {
						Gset[i][1] += s1*s2;
						Gset[i][1] -= s12;
					}
				}

			}


		}

		// mod
		FOR(j, 0, 2) {
			Fset[i][j] %= MOD;
			(Fset[i][j] += MOD) %= MOD;
			Gset[i][j] %= MOD;
			(Gset[i][j] += MOD) %= MOD;
		}
	}

	// cumsum
	VVL Fsum(20004, VL(2, 0));
	FOR(i, 1, 20000 + 1) {
		FOR(j, 0, 2) {
			(Fsum[i][j] += Fsum[i - 1][j] + Fset[i][j]) %= MOD;
		}
	}

	FOR(i, 1, 20000 + 1) {
		FOR(j, 0, 2) {
			ans += Fsum[i][!j] * Gset[i + 1][j];
		}

		ans %= MOD;
		(ans += MOD) %= MOD;
	}



	cout << ans << "\n";

	return 0;
}
