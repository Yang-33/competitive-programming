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

/* -----  2018/06/30  Problem: AOJ 2018 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/2018  ----- */
/* ------問題------

ある貧乏な国のおてんばで勇敢なお姫様は，ある日部屋の壁を壊してお城を抜け出し，競馬などのギャンブルが行われている賭博場に入っていった．ところが，ギャンブルなどやったことのないお姫様は，非常に負けが込んでしまった．この状況をおもしろくないと思ったお姫様は，一体どのような仕組みでギャンブルが行われているかを調べてみた．すると，このようなギャンブルではパリミュチュエル方式と呼ばれる方式で配当が決定されていることを突き止めた．
パリミュチュエル方式とは，競走を対象としたギャンブルにおいて配当を決定するために使用する計算方法である．この方式では，全ての掛け金をプールし，一定の割合を控除した上で，当選者に掛け金に比例した金額を分配する．
現在お姫様が熱中しているギャンブルは，参加者は競技前にどの競技者が優勝するかを予想する 1枚100ゴールドの投票券を購入し，競技の結果が予想と一致すれば当選金を受け取る権利を得るというものである．なお，ゴールドはこの国の通貨単位である．あなたの仕事は入力として与えられる競技の情報をもとに，投票券一枚あたりの配当を計算するプログラムを書くことである．
先述の方法で計算される配当額が整数にならない場合は，切り捨てによって整数にすること．

-----問題ここまで----- */
/* -----解説等-----

問題文を読んでやっていく。

----解説ここまで---- */


void solve() {
	int N, M, P;
	while (cin >> N >> M >> P, N) {
		vector<int>a(N);
		FOR(i, 0, N) {
			cin >> a[i];
		}
		long long sum = accumulate(a.begin(), a.end(), 0LL);
		M--;
		sum *= 100;
		if (a[M] == 0)cout << 0 << endl;
		else 		cout << max(0LL, sum *(100 - P) / a[M] / 100) << endl;

	}

}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	solve();

	return 0;
}