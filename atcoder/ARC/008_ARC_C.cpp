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
//#pragma GCC optimize ("-O3") 
#ifdef YANG33
#include "mydebug.hpp"
#else
#define DD(x) 
#endif
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/12/06  Problem: ARC 008 C / Link: http://arc008.contest.atcoder.jp/tasks/arc008_c  ----- */
/* ------問題------

たこ焼き屋の開店にあたって、たこ焼きの味を皆に分かってもらうために試食イベントを行うことにしました。
しかし、高橋社長はたこ焼きをより多くの人に食べてもらいたいので、試食イベントを兼ねたお祭り『THE☆たこ焼き祭り2012』をすることを提案してきました。高橋社長が提案してきた『THE☆たこ焼き祭り2012』の試食イベント内容は以下のようになっています。
会場にはあなたと参加者を足して N 人の人がいます。あなたはたこ焼きを N 個持っており、それを全員に 1 人 1 個ずつ行き渡るようにします。
会場は広いのであなたはたこ焼きを投げて配らないといけません。 あなただけで全員に配ることは大変なので、参加者にも協力してもらうことにし、参加者は受け取ったたこ焼きを別の参加者へと投げることもできます。
あなたと参加者はつまようじを1 人につき 1 本しか持っていないので同じタイミングで複数のたこ焼きを投げることはできず、たこ焼きを投げてから 1 秒間は次のたこ焼きを投げることができません。受け取る側はいつでも何個でも受け取ることができます。
さらに、あなたと参加者は立っている位置から動いてはいけません。
参加者は大人から子供までいるのでそれぞれにはたこ焼きをキャッチできる速度の上限があり、たこ焼きを投げる側にも投げられる速度の上限があります。投げられたたこ焼きの速度は減衰することなく受け取り手に届きます。
たこ焼きはなるべく出来立てを食べて欲しいので、たこ焼きを全員に配り切るために必要な時間の最小値を答えなさい。

-----問題ここまで----- */
/* -----解説等-----

chokudaiからの最短路が求まっているとする。
最後にスコアをちいさくしたいとき、1秒に1個しか配れないのでdist[v]+tryCntのうちの最大値となる。
tryCntは単調増加として、dist[v]は降順であればよい。

----解説ここまで---- */

vector<double> Dijkstra(vector<vector<pair<int, double >>>& G, int s) {
	vector<double> dist(SZ(G), LINF);
	dist[s] = 0;
	using PDL = pair<double, int>;
	priority_queue<PDL, vector<PDL>, greater<PDL>> que;
	que.push(PLL(0LL, s));

	while (!que.empty()) {
		PDL p = que.top(); que.pop();
		int v; /* 頂点*/ double d; /* 頂点vまでの距離 */
		tie(d, v) = p;

		if (d > dist[v]) continue;

		FOR(i, 0, (int)G[v].size()) {
			int nv = G[v][i].first;
			if (dist[nv] > dist[v] + G[v][i].second) {
				dist[nv] = dist[v] + G[v][i].second;
				que.push(PDL(dist[nv], nv));
			}
		}
	}
	return dist;
}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N; cin >> N;
	vector<double> x(N), y(N), t(N), r(N);
	FOR(i, 0, N) {
		cin >> x[i] >> y[i] >> t[i] >> r[i];
	}
	auto dis = [&x, &y](int a, int b) {
		auto p2 = [](double x) {
			return x * x;
		};
		return sqrt(p2(x[a] - x[b]) + p2(y[a] - y[b]));
	};
	using T = pair<int, double>;
	vector<vector<T>>G(N);
	FOR(i, 0, N) {
		FOR(j, 0, N) {
			if (i == j)continue;
			G[i].push_back(T(j, dis(i, j) / min(t[i], r[j])));
		}
	}
	auto dist = Dijkstra(G, 0);
	vector<double>dd;
	FOR(i, 1, N) {
		dd.push_back(dist[i]);
	}
	RSORT(dd);
	double ans = 0;
	FOR(i, 0, SZ(dd)) {
		ans = max(ans, dd[i] + i);
	}
	cout << fixed << setprecision(10) << ans << endl;

	return 0;
}
