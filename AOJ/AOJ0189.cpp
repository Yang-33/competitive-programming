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

/* -----  2018/07/23  Problem: AOJ 0189 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0189  ----- */
/* ------問題------

来春卒業するAさんは、就職を機に引越しをすることにしました。就職する会社は、オフィスがいくつかの町にあって、日によって出勤するオフィスが違います。そこでAさんは,どこのオフィスに 行くにも時間の短い町に住もうと考えました。
そこであなたは、Aさんを助けるため、住むのに一番便利な町を探すことになりました。
町には 0 から始まる番号が振られており、町と町の間には道があります。それぞれの道に対して通勤時間が決まっています。Aさんがある町に住んでいる場合に、自分の町のオフィスまでの通勤時間は 0 とします。このときに全ての町までの通勤時間の総和を考えます。例えば、町と道の配置が上の図のようになっていて、Aさんが町1に住んだ場合には、それぞれの町までの通勤時間は
道の数と、全ての道の情報を入力とし、それぞれの町に住んだ場合の通勤時間の総和を計算し、それが最小となる町の番号と、そのときの通勤時間の総和を出力するプログラムを作成してください。ただし、通勤時間の総和が最小となる町が複数ある場合は、一番小さい町の番号及びその時の通勤時間の総和を出力してください。町の総数は 10 以下、道の総数は 45 以下とし、全ての道は双方向に移動でき、通勤時間は方向によって変わらないものとします。また、どの町からでもその他全ての町への 経路があるものとします。

-----問題ここまで----- */
/* -----解説等-----

WF

----解説ここまで---- */

int main() {

	int N, M; ;
	while (cin >>M,M) {
		N = 10;
		VVI dist(N, VI(N, INF));
		VVI sp(N, VI(N, INF));
		FOR(i, 0, N)dist[i][i] = 0;
		N = 0;
		FOR(i, 0, M) {
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			dist[a][b] = dist[b][a] = min(dist[a][b], c);
			N = max({ N,a,b });
		}
		N++;
		FOR(k, 0, N)FOR(i, 0, N)FOR(j, 0, N)dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
		int ans = INF;
		int id = 0;

		FOR(i, 0, N) {
			int sum = 0;
			FOR(j, 0, N) {
				sum += dist[i][j];
			}
			if (sum < ans) {
				ans = sum;
				id = i;
			}
		}
		cout << id << " " << ans << endl;
	}
	return 0;
}
