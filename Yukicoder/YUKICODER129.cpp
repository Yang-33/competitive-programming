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
const LL MOD = 1000000000;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/04/26  Problem: yukicoder 129  / Link: http://yukicoder.me/problems/no/129  ----- */
/* ------問題------

Yasuoは、予算がN円しかないが、親戚の子供M人にお年玉をあげたいと思っている。
お年玉の中に入れる種類は1000円紙幣だけにしたいと思っているが、なるべく平等でかつ最大の金額をあげたいと思っています。

今回は、前回のように配って予算が余った分も配り「当たり」とすることにした。

準備として、すべてのお年玉袋に、平等で最大な額の1000円紙幣を入れた後に、予算が余っているなら、「当たり」として、
１つの同じ袋には、1000円をいれるかいれないかとして、ランダムにそれぞれのお年玉袋に追加で振り分けることにした。

この時、誰がどのお年玉袋がもらえるかはわからないとして、
M人のそれぞれのもらえるお年玉の額の組み合わせは、何通りあるか求めてください。
1000円紙幣にできるなら余りを全て使うものとする。
答えが非常に大きくなるので1000000000=10^9（素数ではないことに注意）で割った余りを求めてください。

-----問題ここまで----- */
/* -----解説等-----

modを考慮しないとO(M)だけど、逆元があるかわからないので、パスカルの三角形で愚直nCkをだす。O(M^2)
10^9なので、互いに素であるように分解する。
nCk = 2^? * 5^? * r1 * r2^-1 mod 10^9 とできるので、このように分解すれば良い。(ref:https://yukicoder.me/submissions/9074)

----解説ここまで---- */
int  comb[10004][10004];
int calcomb(int M, int left) {
	int  i, j;
	for (i = 0; i <= M; i++) {
		for (j = 0; j <= i; j++) {
			if (j == 0 || j == i)
				comb[i][j] = 1;
			else
				comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j])%MOD;
		}
	}
	return comb[M][left];
}
LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, M; cin >> N >> M;
	LL left = (N / 1000) % M;
	ans = calcomb(M, left);
	// leftをM人に配る(空を配りうる)
	cout << ans << "\n";

	return 0;
}
