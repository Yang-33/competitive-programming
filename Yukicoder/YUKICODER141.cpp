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

/* -----  2018/05/03  Problem: yukicoder 141  / Link: http://yukicoder.me/problems/no/141  ----- */
/* ------問題------

魔法少女のコバは数を変化させる魔法を覚えました。コバが使える魔法は以下の2種類です:
(1)数aに1を加えてa+1に変える。
(2)数aが0でない時、aをその逆数1/aに変える。
数1に魔法をかけて次々に変化させていくとき、与えられた数M/Nにするまでに必要な最小の魔法の回数を出力してください。 もし1をどのように変化させてもM/Nが得られない場合は、−1を出力してください。
MとNは互いに素とは限りませんが、互いに素でない場合は、M/Nを約分した分数に変化させればよいです。 例えば,M=4,N=6の場合は、2/3に変化させるための最小の回数を出力してください。

-----問題ここまで----- */
/* -----解説等-----

BFSだと気が狂うぐらい遅い。
値の反転と追加しかできないので、ギリギリのとこまでは追加ばかりが繰り返される。
後はこれをまとめて再帰に投げればよい。

----解説ここまで---- */


int solve(int m, int n) {
	if (n == 1)return m - 1;
	if (m > n)return m / n + solve(m%n, n);
	return 1 + solve(n, m);
}

long long  gcd(long long  a, long long  b) { return b ? gcd(b, a%b) : a; }

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N, M;
	cin >> M >> N;
	{
		int g = gcd(N, M);
		M /= g, N /= g;
	}
	ans = solve(M, N);

	cout << ans << "\n";

	return 0;
}
