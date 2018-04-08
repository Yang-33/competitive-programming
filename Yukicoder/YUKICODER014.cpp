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

/* -----  2018/04/08  Problem: yukicoder 014  / Link: http://yukicoder.me/problems/no/014  ----- */
/* ------問題------

最小公倍数を習ったばかりのLarryは、最小公倍数ソートというのを思いついた。
ここで「最小公倍数ソート」とは、
N個の整数（重複を含む）が与えられ、それぞれai (1≤i≤N)とする。
a1を固定し、a2〜aNをそれぞれa1に対して最小公倍数を取り、最小公倍数が小さい順に並べ変えるソートのことであるとする。
（最小公倍数の最小が複数ある場合は、元の数が少ない方が優先される）

Larryは、
この時出来た配列を新たにa1…aNの名前をつけなおして操作を続ける。
次にa2を固定し(a1も固定したまま）、a3〜aNを「最小公倍数ソート」していく。
次にa3を固定し...と続けていった時にaNまで行った時になる数列を求めてください。

-----問題ここまで----- */
/* -----解説等-----

男は黙って非naive解法！
本番ならnaive解法！

ベースとなる左端の値をBaseとする。
今一番左に動かしたいのは、 Base * a[x] / gcd(Base,a[x])
が最小となるa[x]である。
愚直にやると$O(N)$だが、ここで約数について考える。
a[i]の約数の上限はたぶん100種ぐらい。
Baseの持つ約数の集合は、gcd(Base,a[x])を必ず含んでいる。
ここで、ある約数を含む、最小のa[x]を簡単に検索することができれば
この問題はBaseの約数を全て試すことで次のa[x]を決定することができる。
これは最小値の検索が$O(logN)$でできるデータ構造があると高速になる。
最初はヒープでいいじゃんとなったけど、削除も必要なのでsetだと簡単にできる。

----解説ここまで---- */

LL N;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	VI a(N);
	VVI divs(N);

	vector<set<PII>> S(10001);
	FOR(i, 0, N) {
		cin >> a[i];
		for (int j = 1; j*j <= a[i]; j++) {
			if (a[i] % j == 0) {
				divs[i].push_back(j);
				S[j].insert(PII(a[i], i));
				if (j*j != a[i]) {
					divs[i].push_back(a[i] / j);
					S[a[i] / j].insert(PII(a[i], i));
				}
			}
		}
	}

	int id = 0;
	FOR(_, 0, N) {
		cout << a[id] << (_ == N - 1 ? "\n" : " ");

		PII Min = PII(INF, INF);
		int tempid = -1;
		FOR(i, 0, SZ(divs[id])) {
			S[divs[id][i]].erase(PII(a[id], id));//使っちゃいけないので
			if (S[divs[id][i]].empty())continue;
			PII b = *S[divs[id][i]].begin();
			PII comp = PII(a[id] / divs[id][i] * a[b.second], b.first);
			if (Min > comp) {
				Min = comp;
				tempid = b.second;
			}
		}
		id = tempid;
	}

	return 0;
}
