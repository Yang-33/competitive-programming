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
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
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

/* -----  2017/11/09  Problem: POJ 2068 / Link: http://poj.org/problem?id=2068  ----- */
/* ------問題------

複数人で一山Nimをし、Sこ石がある。それぞれはa[i]ことれる。
1indexで、奇数番目が仲間のときかてますか？

-----問題ここまで----- */
/* -----解説等-----

ゲーム木たんさくをする。
なんかAOJにもあったきがする。

----解説ここまで---- */

LL N;

LL ans = 0LL;
int dp[20][(1 << 13) + 1];
VI a;
int dfs(int p, int s) {
	int &res = dp[p][s];
	if (res != -1)return res;
	// ゲームの末尾は？
	if (s == 1)return res = 0;
	res = 0;
	FOR(i, 1, a[p] + 1) {
		if (s - i >= 1)
			if (dfs((p + 1) % (2 * N), s - i) == 0)return res = 1;
	}
	return res = 0;

}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	while (cin >> N, N) {
		int S; cin >> S;
		a = VI(2 * N);
		FOR(i, 0, 2 * N)cin >> a[i];
		fill(*dp, *dp + 20 * ((1 << 13) + 1), -1);
		cout << dfs(0, S) << endl;
	}

	return 0;
}
