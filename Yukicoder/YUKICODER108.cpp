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

/* -----  2018/04/23  Problem: yukicoder 108  / Link: http://yukicoder.me/problems/no/108  ----- */
/* ------問題------

あなたは「yu☆ki☆王」というトレーディングカードゲームにハマっている。
このゲームには N 種類のカードがあり、あなたは既に何枚かを持っている。
あなたは全種類のカードをコンプリートしたい。
ただし、このゲームは同種類のカードを 3 枚までデッキに組み込めるので、各種類とも最低 3 枚ずつ集めたい。
あなたは 1 枚ずつカードを買うが、どの種類が手に入るかは完全にランダムである。
（手持ちのカードによらず、各種類とも 1/N の確率で手に入る。）
さて、コンプリートするまでにあなたが買うことになるカードの枚数の期待値はいくつか？

-----問題ここまで----- */
/* -----解説等-----

自己ループがあるときは、
（期待値）＝（自己ループを除いた次の状態の平均期待値）＋１÷（自己ループから脱出する確率）

----解説ここまで---- */

LL N;

double dp[102][102][102];
double f(int a, int b, int c) {
	if (dp[a][b][c] >-1)return dp[a][b][c];

	double &ret = dp[a][b][c];
	ret = 0;
	if (a || b || c)ret = 1.0*N / (a + b + c);

	if (a)ret += f(a - 1, b + 1, c)*a / (a + b + c);
	if (b)ret += f(a, b - 1, c + 1)*b / (a + b + c);
	if (c)ret += f(a, b, c - 1) *c / (a + b + c);


	return ret;
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	VI a(3, 0);
	FOR(i, 0, N) {
		int x; cin >> x;
		if (x < 3) {
			a[x]++;
		}
	}
	fill(**dp, **dp + 102 * 102 * 102, -1);
	double ans = f(a[0], a[1], a[2]);
	cout << fixed << setprecision(10) << ans << "\n";

	return 0;
}
