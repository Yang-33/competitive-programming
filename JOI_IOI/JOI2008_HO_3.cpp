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

/* -----  2017/10/16  Problem: nagoya_19_10 JOI2008本戦3 / Link: http://joi2008ho.contest.atcoder.jp/tasks/joi2008ho_c  ----- */
/* ------問題------

あなたは以下のルールでダーツゲームをすることになった．
あなたは，矢を的（まと）に向かって 4 本まで投げることができる．必ず
しも 4 本全てを投げる必要はなく，1 本も投げなくてもかまわない．的
は N 個の部分に区切られていて，各々の部分に点数 P1, · · · , PN が書か
れている．矢が刺さった場所の点数の合計 S があなたの得点の基礎とな
る．S があらかじめ決められたある点数 M 以下の場合は S がそのまま
あなたの得点となる．しかし，S が M を超えた場合はあなたの得点は
0 点となる．
的に書かれている点数と M の値が与えられたとき，あなたが得ることのできる
点数の最大値を求めるプログラムを作成せよ．

-----問題ここまで----- */
/* -----解説等-----

N^4は間に合わないが、半分全列挙的なノリで書けばよい。
選択しないのは0を選択するのと一緒。
これを実装すればよい。

----解説ここまで---- */

LL N, M;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	VL p(N);
	FOR(i, 0, N) {
		cin >> p[i];
	}
	SORT(p);
	VL sum;
	int N1 = N ;
	FOR(i, 0, N1 + 1) {
		FOR(j, 0, N1 + 1) {
			if (i == N1&&j == N1) { sum.push_back(0); }
			else if (i == N1)sum.push_back(p[j]);
			else if (j == N1)sum.push_back(p[i]);
			else {
				sum.push_back(p[i] + p[j]);
			}
		}
	}
	SORT(sum);
	int N2 = N;

	FOR(i, 0, N2 + 1) {
		FOR(j, 0, N2 + 1) {
			LL ret = 0;
			if (i == N2&&j == N2) { ret = 0; }
			else if (i == N2)ret = p[j];
			else if (j == N2)ret = p[i];
			else { ret = p[i] + p[j]; }
			int id = upper_bound(ALL(sum), M - ret) - sum.begin();
			id--;
			if (id >= 0) {
				ans = max(ans, sum[id] + ret);
			}

		}
	}



	cout << ans << "\n";

	return 0;
}