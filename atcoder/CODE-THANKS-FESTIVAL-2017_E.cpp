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

/* -----  2018/02/24  Problem: code-thanks-festival-2017-_e / Link: https://code-thanks-festival-2017.contest.atcoder.jp/tasks/code_thanks_festival_2017_e?lang=en  ----- */
/* ------問題------

これはインタラクティブな問題です。
イルカは街中でコインが入った N 個の袋を見つけました。
i(1≦i≦N) 番目の袋の中に重さ wi グラムのコインが 10000 枚入っています。

ここで、イルカは街で偽物コインが多く流通していることを思い出しました。
N 個の袋のうち、いくつかの袋は偽物コインだけが入った袋かもしれません。
イルカは本物コインの袋を探そうとしています。

これらのコインの見た目は全く同じですが、本物コインと偽物コインでその重さが異なります。
本物コインの重さは 9 グラム、または 11 グラムであり、偽物コインの重さは 8 グラム、10 グラム、または 12 グラムであることが知られています。
イルカは袋に入っているコインの重さ wi を全く知りません。

イルカは友達のシャチから、はかりを借りることにしました。
はかりを利用して、コインの計測は以下の手順で行います。

それぞれの袋について、整数 0≦si≦10000(1≦i≦N) を決めます。
i 番目の袋から si 枚のコインを取り出して、はかりに乗せます。
その後に計測を行い、はかりの上に乗せたコインの重さの合計を知ることができます。
最後に、はかりに乗せたコインを元の袋に戻します。
しかし、シャチはとても忙しいのでイルカは 高々 10 回のコイン計測しかできません。
どの袋に本物コインが含まれているかを判定してください。

-----問題ここまで----- */
/* -----解説等-----

5進数で質問すると50/6回で質問が完了する

----解説ここまで---- */

LL N;


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	int id = 0;
	VI ans;
	while (id < N) {
		cout << "? ";
		FOR(i, 0, id)cout << "0 ";
		int ak = 1;
		LL mm = 0;
		int q = 0;
		FOR(kim, id, min((int)N, id + 5)) {
			cout << ak << " ";
			mm += 8 * ak;
			ak *= 5;
			q++;
		}
		id += q;
		FOR(i, id, N)cout << "0 ";
		cout << endl;

		LL acc; cin >> acc;
		acc -= mm;
		while (q--) {
			ans.push_back((acc % 5)%2);
			acc /= 5;
		}

	}
	cout << "! ";
	FOR(i, 0, N) {
		cout << ans[i] << " ";
	}cout << endl;

	return 0;
}
