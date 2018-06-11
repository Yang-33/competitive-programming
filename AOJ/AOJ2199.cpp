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

/* -----  2018/06/10  Problem: AOJ 2199 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2199  ----- */
/* ------問題------

差分パルス符号変調は主に音声信号を圧縮する際に用いられる圧縮手法の一つである．
音声信号は計算機上では整数列(インパルス列)として扱われる．整数列は入力信号を一定時間間隔で標本化(サンプリング)し，振幅を記録したものである．一般にこの整数列は前後の値が近いという傾向がある．これを利用し，前後の値の差分を符号化し，圧縮率を向上させるのが差分パルス符号変調である．
本問題では差分の値をあらかじめ定められた値の集合から選ぶことを考える．この値の集合をコードブックと呼ぶことにする．復号化後の音声信号 yn は以下の式で定められる．
yn = yn - 1 + C[kn]
ここで kn はプログラムによって出力される出力系列， C[j] はコードブックの j 番目の値である．ただし yn は加算によって0未満の値となった場合は0に，255より大きい値となった場合は255にそれぞれ丸められる．また， y0 の値は128とする．
あなたの仕事は，入力信号とコードブックが与えられたときに，元の入力信号と復号化後の出力信号との差の二乗和が最小となるように出力系列を選んで，そのときの差の二乗和を出力するプログラムを書くことである．
例えば，コードブックとして {4, 2, 1, 0, -1, -2, -4} という値のセットを使って 131, 137 という列を圧縮する場合， y0 = 128, y1 = 128 + 4 = 132, y2 = 132 + 4 = 136 という列に圧縮すると 二乗和が (131 - 132)^2 + (137 - 136)^2 = 2 と最小になる．
また，同じくコードブックとして {4, 2, 1, 0, -1, -2, -4} という値のセットを使って 131, 123 という列を圧縮する場合， y0 = 128, y1 = 128 + 1 = 129, y2 = 129 - 4 = 125 と，先程の例とは違って 131 により近づく +2 を採用しない方が (131 - 129) ^ 2 + (123 - 125) ^ 2 = 8 というより小さな二乗和が得られる．
上記 2つの例は sample input の最初の 2例である．

-----問題ここまで----- */
/* -----解説等-----

DPする
範囲を適当に広げすぎると死ぬので注意

----解説ここまで---- */
template<class T> using V = vector<T>; template<class T> using VV = V<V<T>>;
LL dist[20004][260];
inline int cha(int s) {
	if (s >= 255)return 255;
	if (s <= 0)return 0;
	return s;
}
inline LL cost(int y, int x) {
	return (y - x)*(y - x);
}
void init() {
	fill(*dist, *dist + 20004 * 260, LINF);
}
void solve() {
	int N, M;
	while (cin >> N >> M, N) {
		init();
		V<int> c(M);
		FOR(i, 0, M) {
			cin >> c[i];
		}
		V<int>x(N);
		FOR(i, 0, N) {
			cin >> x[i];
		}
		// dpとかdijkstraっぽく
		dist[0][128] = 0;
		FOR(i, 0, N) {
			FOR(j, 0, M) {
				FOR(p, 0, 255 + 1) {
					dist[i + 1][cha(p + c[j])] = min(
						dist[i + 1][cha(p + c[j])],
						dist[i][cha(p)] + cost(x[i], cha(p + c[j])));
				}
			}
		}
		LL ans = LINF;
		FOR(i, 0, 260) {
			ans = min(ans, dist[N][i]);
		}
		cout << ans << endl;
	}


}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	solve();

	return 0;
}