#include <bits/stdc++.h>
using namespace std;

using VS = vector<string>;    using LL = long long;
using VI = vector<int>;       using VVI = vector<VI>;
using PII = pair<int, int>;   using PLL = pair<LL, LL>;
using VL = vector<LL>;        using VVL = vector<VL>;

#define ALL(A)  begin((A)),end((A))
#define RALL(A) (A).rbegin(), (A).rend()
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define SZ(A) int((A).size())
#define SORT(c) sort(ALL((c)))
#define RSORT(c) sort(RALL((c)))
#define UNIQ(c) (c).erase(unique(ALL((c))), end((c)))
#define FOR(i, s, e) for (int(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (int(i) = (s); (i) > (e); (i)--)
#define debug(x) cerr << #x << ": " << x << endl
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/03/11  Problem: ARC 091 C / Link: http://arc091.contest.atcoder.jp/tasks/arc091_c  ----- */
/* ------問題------

1,2,…,N を並べ替えてできる列であって、以下の条件を満たすものがあるかどうか判定し、あればその例をひとつ構成してください。

最長増加部分列の長さは A である
最長減少部分列の長さは B である
注釈
列 P の部分列とは P の要素をいくつか抜き出して元の順に並べてできる列のことを指し、 また、列 P の最長増加部分列とは、P の単調増加な部分列の中で列の長さが最大のものを指します。

同様に、列 P の最長減少部分列とは、P の単調減少な部分列の中で列の長さが最大のものを指します。

-----問題ここまで----- */
/* -----解説等-----

ぐぐったら出てきた…
不可能な場合はLISをつくるときを考えるとわかる。
列を作るとき、A+B-1の長さは必要でかつ、A*B以下の長さでなければならない。
あとは適当にmapがあれば構築できる

----解説ここまで---- */

LL N,A,B;

LL ans = 0LL;
LL sz, arr[1000005];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >>A >>B;

	if (N < A + B - 1 || N > A*B) {
		cout << "-1\n";
		return 0;
	}
	map<LL, int> compress;
	LL rem = N - (A + B - 1);
	sz = 0;
	for (LL i = B; i >= 1; i--) {
		arr[++sz] = i;
		compress[i];
	}
	for (LL i = 2; i <= A; i++) {
		arr[++sz] = i*B;
		compress[i*B];
		for (LL j = i*B - 1; j>(i - 1)*B&&rem>0; j--, rem--) {
			arr[++sz] = j;
			compress[j];
		}
	}

	int cc = 0;
	for (map<LL, int>::iterator it = compress.begin(); it != compress.end(); it++)
		it->second = ++cc;

	for (int i = 1; i <= N; i++)
		cout << compress[arr[i]] << " ";

	return 0;
}
