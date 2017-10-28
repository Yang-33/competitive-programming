#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define FOR(i, s, e) for (int(i) = (s); (i) < (e); (i)++)
#define debug(x) cout << #x << ": " << x << endl
#define ALL(x) (x).begin(),(x).end()

const int INF = 1e9;
const ll LINF = 1e16;

/* -----  2017/10/28  Problem: ICPC2013国内予選 B / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1187  ----- */
/* ------問題------
ICPC (International Collegiate Programming Contest) の解答提出のログが与えられたとき， 各チームの順位を決定するプログラムを書きなさい．
ログはプログラム提出の記録を提出順に並べたものである． 一つの記録は，経過時間，チーム番号，問題番号，判定結果， の四つの情報からなる． 経過時間は，コンテスト開始から提出までに要した時間を意味する． 判定結果は，プログラムが正解を出したか否か， また不正解だった場合の間違いの種類を表す．
チームの順位は，次に示す規則に従って決められる． なお，この規則は，本物のICPCで使われている規則から 一部の細則を削除して簡単化したものである．
より多くの問題に正解したチームを上位とする．
正解した問題数が同じ場合は，所要時間合計の少ないチームを上位とする．
複数のチームが同数の問題に正解し，所要時間合計も同じなら，それらのチームを同順位とする．
所要時間合計とは，正解した問題それぞれの所要時間の合計である． 問題の所要時間とは，その問題に正解したプログラム提出の経過時間に，それ以前に提出された同じ問題に対する不正解一つにつき20分ずつのペナルティを加えたものである．
正解に達しなかった問題の所要時間はゼロと見なされ，不正解がいくつあったとしても，ペナルティは発生しない．
ある問題に正解した後に， 同じ問題に対するプログラムを提出することはないと仮定してよい．

-----問題ここまで----- */
/* -----解説等-----

正解していないとペナルティが課されないことが競プロ経験者ならよくわかる。
正解していない場合にはペナルティは課されないので先に判定しておくと楽だと思った。
flag[チーム名][問題名]で管理した。

----解説ここまで---- */

int m[3000];
int t[3000];
int p[3000];
int j[3000];

int ans[60];
int tim[60];
bool flag[60][15];
#define tp pair<pair<int,int>,int>
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);


	while (1) {
		int M, T, P, R;

		cin >> M >> T >> P >> R;
		if (M == 0 && T == 0 && P == 0 && R == 0)break;
		FOR(i, 0, 3000)m[i] = t[i] = p[i] = j[i] = 0;
		FOR(i, 0, 60)FOR(j, 0, 15)flag[i][j] = 0;
		FOR(i, 0, 60)ans[i] = tim[i] = 0;
		FOR(i, 0, R) {
			cin >> m[i] >> t[i] >> p[i] >> j[i];
			if (j[i] == 0)flag[t[i]][p[i]] = 1;
		}

		FOR(i, 0, R) {
			if (flag[t[i]][p[i]]) {
				if (j[i] == 0) {
					ans[t[i]]++;
					tim[t[i]] += -m[i];
				}
				else {
					tim[t[i]] += -20;
				}

			}
		}

		vector<tp>q(T + 1);
		FOR(i, 1, T + 1) {
			q[i] = tp(pii(ans[i], tim[i]), i);
		}
		q[0] = tp(pii(-1, -10000), -1);
		sort(ALL(q));
		int s = 0;


		for (int i = q.size() - 1; i >= 0; i--) {
			int sol = q[i].first.first;
			int tm = q[i].first.second;
			int team = q[i].second;

			int nsol = q[i - 1].first.first;
			int ntm = q[i - 1].first.second;
			int nteam = q[i - 1].second;

			if (i == 1) {
				cout << team << endl;
				break;
			}
			if (sol == nsol&&tm == ntm) {
				cout << team << "=";
			}
			else {
				cout << team << ",";
			}

		}

	}

	return 0;
}