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

/* -----  2018/06/10  Problem: AOJ 2582 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2582  ----- */
/* ------問題------

JAG大学に通う一樹君，通称カー君は，この夏友達であるあなたに誘われて，ICPC (International Collegiate Potchari Contest) に出場することになった． ICPCは，スポーツ系のコンテストであり，高度な運動能力が必要とされる． しかし，カー君はいつもパソコンの前にいてばかりで，少し動くだけでも疲れてしまうほどに運動不足だった． そこでカー君は，ICPCでいい成績を残すための第1ステップとして，手軽に始められる運動，「踏み台昇降」を始めることにした．
踏み台昇降とは，その名の通り，踏み台と床との上り下りをただひたすら繰り返すだけの単純な運動である． ただし，踏み台昇降では，正しい足の昇降を行わなければ，その効果を得ることはできない． 正しい昇降とは，以下の2種類の内いずれかを満たす足の動きである．
両足が床についた状態から，左足と右足を踏み台の上に上げて，踏み台の上に両足ともついた状態になる．左足と右足どちらを先に上げてもよい．
踏み台の上に両足ともついた状態から，左足と右足を床に下げて，両足が床についた状態になる．左足と右足どちらを先に下げてもよい．
以上からわかるように，床または踏み台の上にいる状態から連続で片足だけを上げ下げしても，正しい昇降とはならない． 踏み台昇降運動では，上記の正しい昇降の動きのいずれかを満たすとき，1回とカウントし，そのカウント数が大きければ大きいほど，効果を得ることができる． 床と踏み台を往復しなくても，片道だけで1回とカウントすることに注意してほしい．
あなたは，チームメイトであるカー君に少しでも強くなってほしいと考えている． そこであなたは，カー君が踏み台昇降をさぼっていないか，プログラムを書いてチェックしてあげることにした． カー君が踏み台昇降で動かした足の情報が与えられるので，正しく昇降を行った回数を求めよ． ただし，両足とも床についている状態から踏み台昇降を始めるものとする．

-----問題ここまで----- */
/* -----解説等-----

結局連続しないとダメなのでそれを見れば良い(フラグをやるとあたまこわれる)

----解説ここまで---- */


template<class T> using V = vector<T>; template<class T> using VV = V<V<T>>;
void solve() {
	int N;
	while (cin >> N, N) {
		V<string> vs(N);
		FOR(i, 0, N) {
			cin >> vs[i];
		}
		int ans = 0;
		int L = 0, R = 0;
		int state = 0;
		FOR(i, 1, N) {
			if (vs[i] == "lu") {
				if (vs[i - 1] == "ru")ans++;
			}
			else if (vs[i] == "ru") {
				if (vs[i - 1] == "lu")ans++;
			}
			else if (vs[i] == "ld") {
				if (vs[i - 1] == "rd")ans++;
			}
			else if (vs[i] == "rd") {
				if (vs[i - 1] == "ld")ans++;
			}
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
