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

/* -----  2018/02/24  Problem: ddcc-2016-qual_c / Link: https://ddcc2016-qual.contest.atcoder.jp/tasks/ddcc_2016_qual_c?lang=en  ----- */
/* ------問題------

N 枚のカードが 1 列に並べられており、i(1≦i≦N) 番目のカードには整数 Ai が書かれています。
この N 枚のカードを使ったロト 2 という宝くじがあります。 ロト 2 は 1 番から N 番までの番号から異なる 2 つの番号 i, j(i<j) を選び、選ばれた 2 つの番号のカードにそれぞれ書かれた値の積 AiAjが K の倍数となるとき当選するというルールで行われます。
AiAj が K の倍数となるような i と j の組合せ (i, j) を良い組合せと呼ぶことにします。良い組合せは何通りあるか求めなさい。

-----問題ここまで----- */
/* -----解説等-----

O(N^2)しか思いつかないけど昔のABCを思い出すとGcdは以外に小さいものしか出てこないのでこれで全探索。
正当性はわかるので割愛
next(it)とか使おうとしてたけど重複するときに対応してなくて、結局場合分けになった

----解説ここまで---- */

long long  gcd(long long  a, long long  b) { return b ? gcd(b, a%b) : a; }

LL N,K;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N>>K;
	VL a(N);
	FOR(i, 0, N) {
		cin >> a[i];
	}
	map<LL, LL>Map;
	FOR(i, 0, N) {
		Map[gcd(a[i], K)]++;
	}
	for (auto it : Map) {
		for (auto it2 : Map) {
			if ((it.first * it2.first) % K == 0) {
				if (it.first == it2.first) {
					ans += it.second * (it.second - 1) / 2;
				}
				else if(it.first < it2.first){
					ans += it.second * it2.second;
				}
			}

		}
	}

	cout << ans << endl;
	return 0;
}
