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

/* -----  2018/04/12  Problem: yukicoder 058  / Link: http://yukicoder.me/problems/no/058  ----- */
/* ------問題------

太郎君と二郎君はサイコロで勝負することになりました。

太郎君と二郎君は、お互いにN個のサイコロを持ち、一斉に転がします。
そして、出た目の合計が大きいほうが勝ち、また、合計が等しければ引き分けという取り決めになっています。

ところが太郎君は卑怯にも、イカサマなサイコロを使ってしまいます。

普通のサイコロは、立方体の6面に1から6までの目が刻印されていますが、
イカサマなサイコロは、立方体の6面に4から6までの目が2つずつ刻印されており、
1から3の目は絶対に出ません。

二郎君はN個の普通のサイコロを使用しますが、
太郎君はN個のサイコロのうちK個に、このイカサマなサイコロを使用し、
(N−K)個は普通のサイコロを使用します。

普通のサイコロもイカサマなサイコロも、6面のうちどの面が出るかは均等であるとしたとき、
太郎君が「勝つ」確率を求めてください。


-----問題ここまで----- */
/* -----解説等-----

イカサマサイドは場合分けがあるけど、基本的には
dp(i,sum):=i個サイコロをふってその出目の合計値がsumになる確率
としてDPしてあげればよい。


----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, K;
	cin >> N >> K;
	vector<vector<double>>dpTaro(N + 1, vector <double>(61, 0));
	vector<vector<double>>dpJiro = dpTaro;
	dpJiro[0][0] = dpTaro[0][0] = 1;

	//Jiro
	FOR(i, 0, N) {
		FOR(d, 1, 6 + 1) {
			FORR(sum, 60, 0 - 1) {
				dpJiro[i + 1][sum + d] += dpJiro[i][sum] / 6.0;
			}
		}
	}

	// Taro
	FOR(i, 0, N) {
		if (i < K) {
			FOR(d, 4, 6 + 1) {
				FORR(sum, 60, 0 - 1) {
					dpTaro[i + 1][sum + d] += 2.0*dpTaro[i][sum] / 6.0;
				}
			}
		}
		else {
			FOR(d, 1, 6 + 1) {
				FORR(sum, 60, 0 - 1) {
					dpTaro[i + 1][sum + d] += dpTaro[i][sum] / 6.0;
				}
			}
		}
	}
	double ans = 0;
	FOR(i, 0, 61) {
		FOR(j, 0, i) {
			ans += dpJiro[N][j] * dpTaro[N][i];
		}
	}
	cout <<fixed<<setprecision(10)<< ans << "\n";

	return 0;
}
