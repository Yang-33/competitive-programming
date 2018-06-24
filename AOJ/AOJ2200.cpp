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

/* -----  2018/06/24  Problem: AOJ 2200 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2200  ----- */
/* ------問題------

あなたは離島の郵便局に勤めるプログラマである．あなたの住んでいる地域は，複数の島々からなる．各島には一つ以上の港町がある．それらに加えて他の町や村があるかもしない．ある島から別の島に向かうためには船を使わなければならない．一つの島の中を回るには陸路が使えるが，海路を利用した方が速いこともある．
近年行われた郵便局の民営化をきっかけに，経費削減に向けて郵便配達員の人員整理が全国的に行われた．離島の郵便局もその例外ではなく，結果として郵便配達員は利藤さんただ一人となってしまった．その郵便局が集配を担当する地域は非常に広いため，一人で集配するのは大変な作業である．なので，どのようにすれば効率的に集配を行えるのか，利藤さんがあなたに助けを求めてきた．
あなたの仕事は，利藤さんがたどるべき町や村の集配順序が与えられたときに，最短巡回経路を求めるプログラムを書くことである．
利藤さんは，決して指定された順序以外で集配業務を行うことができない．しかし，ある町や村から別の町や村へ移動する際に，他の町や村を経由して移動することは許可されている．また，利藤さんは島々を巡るための一隻の船を持っている．
例えば，町A，町B，村Cという集配順序が与えられた場合，町Aから町Bへ向かう際にどの町や村を経由してもかまわない．このとき，村Cを経由しても構わないが，集配順序を守るためには，一度町Bに行って集配をおこなってから，改めて村Cを訪れて集配をおこなわなければならない．また，町Aから海路を用いて町Bに向かい，町Bから陸路を用いて村Cに向かった場合，船を町Bに置いたままになる．したがって，次に海路を使いたい場合は町Bに戻る必要がある．
一つの町や村において複数回集配をしなければならない場合もある．たとえば，町A，村B，町C，村Bという集配順序が与えられるかもしれない．このとき，町Aから村Bをたどらずに町Cに向かった場合は，町Cでいきなり集配をおこなうことはできない．最初の村Bでの集配が終わっていないからである．町Cで集配を済ませた後で村Bを訪れて集配しても，一回目の村Bの集配を終わらせたことにはならない．
利藤さんは，はじめに必ずある港町に船とともにいる．利藤さんはベテランであるため，移動時間以外の集配作業にかかる時間は無視してよい．また，最後の町または村での集配業務が完了するまでの時間だけが問題であり，船をもとの位置に戻して郵便局に帰るまでの時間は考慮しなくてよい．

-----問題ここまで----- */
/* -----解説等-----

これを拡張ダイクストラとは呼ばないことに疑問が湧く…

最短路上で区別しないといけないのは、船の位置。
したがってこれを持てばよく、
// dp(r,n):=rを配達し終えて、船がnにいるときの最短距離みたいにすれば良い。
すると各iについて遷移はN^2で、O(RN^2)で間に合う。

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);


	int N, M;
	while (cin >> N >> M, N || M) {
		VVL Ldist(N, VL(N, LINF));
		VVL Sdist(N, VL(N, LINF));
		FOR(i, 0, N)Ldist[i][i] = Sdist[i][i] = 0;
		FOR(i, 0, M) {
			LL x, y, t; char c[2];
			cin >> x >> y >> t >> c;
			x--, y--;
			if (c[0] == 'S') {
				Sdist[x][y] = Sdist[y][x] = min(Sdist[y][x], t);
			}
			else {
				Ldist[x][y] = Ldist[y][x] = min(Ldist[y][x], t);
			}
		}
		FOR(k, 0, N)FOR(i, 0, N)FOR(j, 0, N) {
			Sdist[i][j] = min(Sdist[i][j], Sdist[i][k] + Sdist[k][j]);
			Ldist[i][j] = min(Ldist[i][j], Ldist[i][k] + Ldist[k][j]);
		}
		int R; cin >> R;
		VI a(R);
		FOR(i, 0, R) {
			cin >> a[i];
			a[i]--;
		}
		VVL dp(R + 1, VL(N + 1, LINF));
		FOR(i, 0, N) {
			dp[0][i] = min(dp[0][i], Sdist[a[0]][i] + Ldist[i][a[0]]);
		}


		FOR(i,0, R-1) {
			FOR(j, 0, N) {
				FOR(k, 0, N) {
					// 陸路のみで直行
					dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + Ldist[a[i]][a[i + 1]]);
					
					// 船を動かしマン(j to k)
					dp[i + 1][j] = min(dp[i + 1][j], dp[i][k] + Ldist[a[i]][k]+Sdist[k][j] + Ldist[j][a[i+1]]);
				}
			}
		}
		LL ans = LINF;
		FOR(i, 0, N) {
			ans = min(ans, dp[R-1][i]);
		}
		cout << ans << "\n";
	}


	return 0;
}
