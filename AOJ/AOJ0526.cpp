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

/* -----  2018/07/23  Problem: AOJ 0526 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0526  ----- */
/* ------問題------

JOI国には，n 島の島があり，各島には 1 から n までの番号が付けられている．現在，JOI国では各島の間を結ぶ航路網の整備が進んでいる．
あなたは，船舶の切符を扱っているチケットセンターに勤務している．JOI国には船舶を使って，できる限り安価に，島と島の間を旅行したいと考えている人が沢山おり，彼らは，出発地と目的地を注文票に記入して，あなたのところに送ってくる．
あなたの仕事は，客から注文票を受け取ったらすぐに，いくつかの船舶を乗り継いで，出発地と目的地を結ぶ航路の中で，もっとも安価な運賃を計算し，客に伝えることである． ただし，旅程によっては，船舶を使って旅行することが出来ない場合もある．そのときは『船舶を使って旅行することが出来ない』と客に伝える必要がある．また，JOI国では，島と島の間を結ぶ新しい船舶が，次々と運航を開始しており，あなたには，その情報が随時伝えられる．客に返事をする際には，最新の情報に留意しなければならない．
入力として，客の注文票や新たに運航を開始した船舶の運航情報が与えられたときに，客への返事を求めるプログラムを作成せよ．
なお，入力例１と出力例１に対する実行状況を，図１として図示している．

-----問題ここまで----- */
/* -----解説等-----

ワーシャルフロイドを思い出すと、更新は経由地を決めたときだけなので、a,bの二点を更新の要素にする。
更新されるのは1000回しか無いので、10^7ぐらいの計算で間に合う。

----解説ここまで---- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, K;
	while (cin >> N >> K, N) {

		VVI dist(N, VI(N, INF));
		FOR(i, 0, N)dist[i][i] = 0;
		FOR(_, 0, K) {
			int q; cin >> q;
			if (!q) {
				int a, b; cin >> a >> b;
				a--, b--;
				cout << (dist[a][b] != INF ? dist[a][b] : -1) << endl;
			}
			else {
				int a, b, c; cin >> a >> b >> c; a--, b--;
				if (dist[a][b] > c) {
					dist[a][b] = dist[b][a] = c;
					int kth[] = { a,b };
					FOR(k, 0, 2) {
						FOR(i, 0, N) {
							FOR(j, 0, N) {
								dist[i][j] = min(dist[i][j], dist[i][kth[k]] + dist[kth[k]][j]);
							}
						}
					}
				}
			}
		}
	}



	return 0;
}
