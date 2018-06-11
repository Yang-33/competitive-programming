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

/* -----  2018/06/10  Problem: AOJ 2001 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2001  ----- */
/* ------問題------

奇跡の都市アミダ（Amida, the City of Miracle）の市長は他の市のように選挙で選ぶのではない．かつて長い政権闘争と天変地異により疲弊したこの都市は，候補者全員を公平に選び，かつ幸運の星の下に生まれた者を市長にするために，候補者全員の運命をくじにゆだねることにしたのである．後にあみだくじと呼ばれるくじである．

選挙は以下のように行われる．候補者数と同数の長い縦線が引かれ，さらにいくつかの横線がそこに引かれる．横線は隣接した縦線の途中同士を結ぶように引かれる．いずれかの縦線の下には「当選」と書かれている．どの縦線が当選であるかは候補者からわからないように隠される．それぞれの候補者は縦線を 1 つ選択する．全ての候補者の選択が終わると，各候補者は線を上から下に向かってたどる．ただし，移動途中に横線が見つかったときは，横線の接続された反対側の縦線に移り，また下に向かってたどる．縦線の一番下までたどり着いたときに，そこに「当選」と書かれていた者が当選して，次期市長となる．

この方法はうまくいった．幸運な市長の下に，争いも災害も少ない平和な時代が続いた．しかし近年，人口増加のためにこの手法に限界が見えてきた．候補者が増えたため，あみだくじが大規模になり，手作業による集計では非常に時間がかかるようになったのである．そこで市では，市役所のプログラマーであるあなたにあみだくじの電算化を依頼した．

あなたの仕事は，あみだくじの構造と，選択された縦線の位置が与えられたときに，最終的にどの縦線にたどり着くかを求めるプログラムを書くことである．

-----問題ここまで----- */
/* -----解説等-----

読解をして、swapをします

----解説ここまで---- */

using ll = LL;

typedef pair<ll, ll> pll;
ll solve(ll n, ll m, ll a) {
	ll res = -1;
	vector<pair<ll, pll>> x;
	vector<ll> amida(n + 1, 0);
	iota(amida.begin(), amida.end(), 0);
	for (int i = 0; i < m; i++) {
		ll h, p, q; cin >> h >> p >> q;
		x.push_back({ h,{ p,q } });
	}
	sort(x.begin(), x.end());
	for (int i = 0; i < m; i++) {
		swap(amida[x[i].second.first], amida[x[i].second.second]);
	}
	res = amida[a];
	return res;
}

int main() {

	int n, m, a;
	while (cin >> n >> m >> a, n | m | a) {
		cout << solve(n, m, a) << endl;
	}
	return 0;
}