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

#define ALL(a)  a.begin(),a.end()
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

/* -----  2017/11/11  Problem: POJ 3187 / Link: http://poj.org/problem?id=3187  ----- */
/* ------問題------

1-Nまでの数字を使って、それを種にしたパスカルの三角形を構築した際、最後の値がsumになるもので、
種の辞書順最小は。

-----問題ここまで----- */
/* -----解説等-----

全探索をする。
作成した値は三角形になるようにたせばよい。

----解説ここまで---- */

VI solve(LL N, LL sum) {
	VI a(N);
	FOR(i, 0, N)a[i] = i + 1;

	do {
		VI dp = a;
		FORR(i, N - 1, 0) {
			FOR(j, 0, i) {
				dp[j] += dp[j + 1];
			}
		}
		if (dp[0] == sum)return a;
	} while (next_permutation(ALL(a)));

}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	LL sum,N;
	cin >> N>>sum;
	VI a = solve(N, sum);
	FOR(i, 0, N ) {
		cout << a[i] << ((i != N - 1) ? ' ' : '\n');
	}

	return 0;
}
