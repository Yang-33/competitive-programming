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

/* -----  2018/02/27  Problem: 074_arc_b / Link: https://abc062.contest.atcoder.jp/tasks/arc074_b?lang=en  ----- */
/* ------問題------

N を 1 以上の整数とします。
長さ 3N の数列 a=(a1,a2,…,a3N) があります。 すぬけ君は、a からちょうど N 個の要素を取り除き、残った 2N 個の要素を元の順序で並べ、長さ 2N の数列 a' を作ろうとしています。 このとき、a' のスコアを (a'の前半N要素の総和)−(a'の後半N要素の総和) と定義します。
a' のスコアの最大値を求めてください。

-----問題ここまで----- */
/* -----解説等-----

priority_queueのやつ
両側から区間を作っていくとできる
dp1[i]:= iまでを使ってできる最大値
dp2[i]:= i以降を使ってできる最小値
探索区間は[N-1,2*N)なのでN-1を忘れない(戒め)

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	VI a(3 * N);
	FOR(i, 0, 3 * N) {
		cin >> a[i];
	}

	VL dp1(3 * N, 0);
	{
		priority_queue<int, VI, greater<int>>pq;
		LL sum = 0;
		FOR(i, 0, 3 * N) {

			sum += a[i];
			pq.push(a[i]);
			if (SZ(pq)== (N + 1)) {
				LL val = pq.top(); pq.pop();
				sum -= val;
			}
			dp1[i] = sum;
		}
		//FOR(i, 0, 3 * N) {
		//	cout << dp1[i] << " ";
		//}cout << endl;
	}
	VL dp2(3 * N, 0);
	{
		priority_queue<int>pq;
		LL sum = 0;
		FORR(i, 3*N-1, 0-1) {

			sum += a[i];
			pq.push(a[i]);
			if (SZ(pq) ==(N + 1)) {
				LL val = pq.top(); pq.pop();

				sum -= val;
			}
			dp2[i] = sum;
		}
		//FOR(i, 0, 3 * N) {
		//	cout << dp2[i] << " ";
		//}cout << endl;
	}
	ans = -LINF;
	FOR(i, N-1, 2 * N) {
		ans = max(ans, dp1[i] - dp2[i+1]);
	}
	cout << ans << "\n";

	return 0;
}
