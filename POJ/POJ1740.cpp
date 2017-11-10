#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <set>
#include <sstream>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <climits>
#include <list>
#include <fstream>
using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef vector<string> VS;

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

/* -----  2017/11/10  Problem: POJ 1740 / Link: http://poj.org/problem?id=1740  ----- */
/* ------問題------

N山の石取りゲームをする。
2人のプレイヤーは1つの山から少なくとも一つ石を取り除き、その後残った石をほかの山においてもよい。
このとき与えられた盤面は先手必勝か。

-----問題ここまで----- */
/* -----解説等-----

組合せはかなり大きいので計算はむり、
手元で小さいケースを全探索させたところ、N=偶数、pileは同値なペアのみで構成されるときのみgrundy数が0になった。

証明を思いつくまでかなりしんどかった

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N;
	while (cin >> N, N) {
		vector<int>a(N);

		FOR(i, 0, N) {
			cin >> a[i];
		}
		sort(a.begin(), a.end());

		int ans = 0;

		if (N % 2 == 1) { ans = 1; }
		else {
			for (int i = 0; i<N; i += 2) {
				if (a[i] != a[i + 1])ans = 1;
			}
		}

		cout << ans << endl;
	}


	return 0;
}
