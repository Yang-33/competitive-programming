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

/* -----  2018/07/26  Problem: AOJ 0262-2 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0262-2  ----- */
/* ------問題------

太郎君は、子供会の催しでみんなで遊べるようにすごろくを作りました。ゲームをおもしろくするために、「ふりだし」と「あがり」以外のすごろくのマスのいくつかに「６つ進む」、「５つ戻る」のように指示を書き込んでいきました。ルーレットを回して出た数だけ進み、止まったマスに指示が書き込んであれば、その指示に従って移動します。ただし、指示に従って進んだ先のマスの指示には従いません。
ルーレットは１からある数までの間の数を等確率で出すことができるものとします。また、「あがり」に達するより大きな数が出たときや、指示に従うと「あがり」より先に進んでしまうときは「あがり」に移動します。指示に従って戻るときに「ふりだし」より前に戻ってしまうときは「ふりだし」に戻ることにします。
ところが、ルーレットとマスの指示によっては「あがり」にたどりつけない場合が出てきてしまいます。たとえば、図のようなすごろくを作ったとしましょう。１と２しか出ないルーレットを使うと、１，２の順に出れば「あがり」に行けますが、はじめに２が出たらその後は何が出ても永久に「あがり」にはたどり着けません。太郎君は、そうとは知らずに調子に乗ってあちこちのマスに指示を書き込んでしまいました。
そこで、太郎君に代わって、ルーレットとマスの指示によっては、「あがり」にたどり着けない場合が生じるかどうか判定するプログラムを作成してください。

-----問題ここまで----- */
/* -----解説等-----

ワーシャルフロイドでもできた…
こういう判定もできるというのを覚えておこう。

----解説ここまで---- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int Hi;
	while (cin >> Hi, Hi) {
		int N; cin >> N;
		VI a(N + 2, 0);
		FOR(i, 0, N) {
			cin >> a[i + 1];
		}
		VVI dist(N + 2, VI(N + 2, 0));
		FOR(i, 0, N + 1) {
			FOR(j, 1, Hi + 1) {
				int to = i + j;
				if (to > N + 1)to = N + 1;
				to += a[to];
				if (to > N + 1)to = N + 1;
				if (to < 0)to = 0;
				dist[i][to] = 1;
			}
		}
		FOR(i, 0, N + 2)dist[i][i] = 1;
		FOR(k, 0, N + 2)FOR(i, 0, N + 2)FOR(j, 0, N + 2)if (dist[i][k] && dist[k][j])dist[i][j] = 1;
		int f = 1;
		FOR(i, 0, N + 1) {
			if (dist[0][i] && !dist[i][N + 1])f = 0;
		}
		cout << (f ? "OK" : "NG") << endl;

	}

	return 0;
}
