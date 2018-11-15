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

/* -----  2018/11/15  Problem: ARC 020 B / Link: http://arc020.contest.atcoder.jp/tasks/arc020_b  ----- */
/* ------問題------

小学生の高橋君は、縞模様が大好きです。今、高橋君は、左から右に一直線上に並んだ n 枚の色画用紙を眺めています。高橋君は縞模様がとても好きなので、いくつかの画用紙を絵の具で新しい色に塗り替えることで、全体に見て縞模様になっているようにしたいと思っています。
全体的に見て縞模様であるとは、全体で使用される色がちょうど 2 つであって、全ての画用紙についてそれと隣り合う画用紙との色が異なっている状態のことを指します。
あなたの仕事は、既に配置されている画用紙の枚数 n と、1 枚の画用紙を別の色に塗り替えるためにかかる絵の具の費用 c が与えられるので、縞模様の達成に必要な合計費用の最小値を出力するプログラムを作ってあげることです。 この問題では便宜上、それぞれの色が 1 ～ 10 の 10 種類の数として与えられます。塗り替えるために使える絵の具の色もこの 10 種類のみです。

-----問題ここまで----- */
/* -----解説等-----

最初の2色を全探索する。2ずつやらなくても良かった(%2でよい。)

----解説ここまで---- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, C; cin >> N >> C;
	VI a(N);
	LL ans = LINF;
	FOR(i, 0, N) {
		cin >> a[i];
		a[i]--;
	}

	FOR(i, 0, 10) {
		FOR(j, 0, 10) {
			if (i == j)continue;
			// 2ずつやる
			LL sum = 0;
			for (int id = 0; id < N; id += 2) {
				if (a[id] != i)sum += C;
				if (id + 1 < N && a[id + 1] != j)sum += C;
			}

			ans = min(ans, sum);

		}
	}

	cout << ans << "\n";

	return 0;
}