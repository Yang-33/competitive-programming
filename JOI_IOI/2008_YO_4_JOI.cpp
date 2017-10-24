#include "bits/stdc++.h"
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

/* -----  2017/10/18  Problem: 20_a  / Link: http://joi2010yo.contest.atcoder.jp/tasks/joi2010yo_d  ----- */
/* ------問題------

花子さんは n 枚（4 ≦ n ≦ 10）のカードを並べて遊んでいる． それぞれのカードには 1 以上 99 以下の整数が 1 つずつ書かれている． 花子さんは，これらのカードの中から k 枚（2 ≦ k ≦ 4）を選び， 横一列に並べて整数を作ることにした． 花子さんは全部で何種類の整数を作ることができるだろうか．
例えば，1, 2, 3, 13, 21 の 5 枚のカードが与えられ，そこから 3 枚を選び整数を作ることを考える． 2, 1, 13 をこの順に並べると，整数 2113 を作ることができる． また，21, 1, 3 をこの順に並べても，同じ整数 2113 を作ることができる． このように，異なるカードの組み合わせから同じ整数が作られることもある．
n 枚のカードに書かれた整数が与えられたとき， その中から k 枚を選び，横一列に並べることで作ることができる整数の個数を求めるプログラムを作成せよ．

-----問題ここまで----- */
/* -----解説等-----

4つしかないので筋肉？

----解説ここまで---- */

LL N,K;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N>>K;
	string a[10];
	FOR(i, 0, N) {
		cin >> a[i];
	}
	set<string >se;
	if (K == 2) {
		FOR(i, 0, N) {
			FOR(j, 0, N) {
				if (i == j)continue;
				se.insert(a[i] + a[j]);
			}
		}
	}
	else if (K == 3) {
		FOR(k, 0, N) {
			FOR(i, 0, N) {
				FOR(j, 0, N) {
					if (k == i)continue;
					if (k == j)continue;
					if (i == j)continue;
					se.insert(a[k]+a[i] + a[j]);
				}
			}
		}
	}
	else if (K == 4) {
		FOR(l,0,N)
		FOR(k, 0, N) {
			FOR(i, 0, N) {
				FOR(j, 0, N) {
					if (l == k)continue;
					if (l == i)continue;
					if (l == j)continue;
					if (k == i)continue;
					if (k == j)continue;
					if (i == j)continue;
					se.insert(a[l]+a[k] + a[i] + a[j]);
				}
			}
		}
	}
	ans = SZ(se);
	cout << ans << "\n";

	return 0;
}